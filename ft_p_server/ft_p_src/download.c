/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   download.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <bandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 12:31:56 by nithramir         #+#    #+#             */
/*   Updated: 2018/11/13 18:41:41 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_p.h"

int	send_file(int fd, int cs)
{
	char	buff[32000];
	int		r;

	buff[0] = 6;
	while ((r = read(fd, buff + 1, 31998)))
	{
		if (screquest(cs, buff, r + 1) == -1)
			return (-1);
	}
	if (r == -1)
		return (semessage(cs, "Error while reading in file"));
	buff[0] = 7;
	if (r == 0)
		return (screquest(cs, buff, 1));
	return (0);
}

int	download(int cs, char *request)
{
	int	fd;

	if (ft_strchr(request, '/'))
	{
		ft_putendl("invalid caractere");
		return (semessage(cs, "No / accepted in file name"));
	}
	fd = open(request + 1, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("Unable to open file");
		return (semessage(cs, "Unable to open file, sure of the name ?"));
	}
	if (svmessage(cs) == -1)
		return (-1);
	if (send_file(fd, cs) == -1)
	{
		ft_putendl("Error while sending file");
		return (-1);
	}
	close(fd);
	return (0);
}
