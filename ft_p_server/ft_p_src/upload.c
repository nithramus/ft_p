/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <bandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:56:17 by nithramir         #+#    #+#             */
/*   Updated: 2018/11/13 18:55:36 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_p.h"

int	receivef(int cs, int fd)
{
	char	*data;
	int		size;
	int		ret;

	if (!(data = garequest(cs, &size)))
		return (-1);
	if (write(fd, data + 1, size - 1) == -1)
		return (semessage(cs, "Error while writing file"));
	if (data[0] == 6)
		ret = 1;
	else
		ret = 0;
	ft_printf("receivef data number %d\n", (int)data[0]);
	free(data);
	return (ret);
}

int	upload(int cs, char *buff)
{
	int	contin;
	int	fd;

	contin = 1;
	if (ft_strchr(buff + 1, '/'))
	{
		ft_putendl("invalid caractere");
		return (semessage(cs, "No / in file name"));
	}
	fd = open(buff + 1, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (semessage(cs, "Error creating file"));
	if (svmessage(cs) == -1)
		return (-1);
	while (contin)
		contin = receivef(cs, fd);
	close(fd);
	if (contin == -1)
		return (-1);
	return (1);
}
