/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   download.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <bandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:01:54 by nithramir         #+#    #+#             */
/*   Updated: 2018/11/21 18:35:56 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_p.h"

int	semessage(int cs, char *string)
{
	char	*msg;

	if (!(msg = malloc(2 + ft_strlen(string))))
		return (-1);
	msg[0] = 51;
	ft_strcpy(msg + 1, string);
	if (screquest(msg, cs, -1) == -1)
	{
		free(msg);
		return (-1);
	}
	free(msg);
	return (-1);
}

int	request_file(char *filename, int cs)
{
	char	buff[1096];
	char	*data;

	buff[0] = 5;
	ft_strcpy(buff + 1, filename);
	if (screquest(buff, cs, -1) == -1)
		return (-1);
	if (!(data = garequest(cs, NULL)))
		return (-1);
	free(data);
	return (1);
}

int	create_file(char *filename, int cs)
{
	int	fd;

	if ((fd = open(filename, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR)) == -1)
	{
		ft_putendl("Failed creating file");
		semessage(cs, "failed creating file");
		return (-1);
	}
	return (fd);
}

int	receive_file(char *filename, int cs)
{
	char	*data;
	int		con;
	int		fd;
	int		size;

	con = 1;
	size = 1;
	fd = create_file(filename, cs);
	while (con)
	{
		data = garequest(cs, &size);
		if (data)
		{
			if (data[0] != 6)
				con = 0;
			if (fd != -1)
				write(fd, data + 1, size - 1);
			free(data);
		}
		else
			return (-1);
	}
	close(fd);
	return (0);
}

int	download(char *request, int cs)
{
	char	*filename;

	filename = get_filename(request);
	if (!filename)
	{
		ft_putendl("No filename");
		return (-1);
	}
	if (request_file(filename, cs) == -1)
		return (-1);
	if (receive_file(filename, cs) == -1)
		return (-1);
	return (0);
}
