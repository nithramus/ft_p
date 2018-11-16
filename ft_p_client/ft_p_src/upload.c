/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <bandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 22:33:40 by nithramir         #+#    #+#             */
/*   Updated: 2018/11/15 22:44:34 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_p.h"

int	send_filename(char *filename, int cs)
{
	char	buff[4096];
	char	*real_filename;

	buff[0] = 4;
	if ((real_filename = get_real_filename(filename)) == NULL)
		return (-1);
	ft_strcpy(buff + 1, real_filename);
	if (screquest(buff, cs, -1) == -1)
		return (-1);
	if (!(garequest(cs, NULL)))
		return (-1);
	free(real_filename);
	return (0);
}

int	send_file(int fd, int cs)
{
	char	buff[32000];
	int		r;

	buff[0] = 6;
	while ((r = read(fd, buff + 1, 31998)) > 0)
	{
		if (screquest(buff, cs, r + 1))
			return (-1);
	}
	buff[0] = 7;
	if (r == 0)
		screquest(buff, cs, 1);
	return (0);
}

int	upload(char *request, int cs)
{
	char	*filename;
	int		fd;

	filename = get_filename(request);
	if (filename == NULL)
	{
		ft_putendl("No filename");
		return (-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("Unable to open file");
		return (-1);
	}
	if (send_filename(filename, cs) == -1)
		return (-1);
	if (send_file(fd, cs) == -1)
	{
		ft_putendl("connection error2");
		return (-1);
	}
	free(filename);
	close(fd);
	return (0);
}
