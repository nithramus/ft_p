/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <bandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 16:41:20 by nithramir         #+#    #+#             */
/*   Updated: 2018/11/09 20:02:13 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_p.h"

int		screquest(int cs, char *response, int size)
{
	int value;

	value = size;
	if (size == -1)
		value = ft_strlen(response) + 4;
	else
		value += 4;
	if (write(cs, &value, 4) == -1)
		return (-1);
	if (write(cs, response, value - 4) == -1)
		return (-1);
	return (0);
}

char	*gfrequest(int cs, int paquet_size)
{
	char	*data;
	char	*tmp;
	int		r;

	if (!(data = malloc(paquet_size + 1)))
	{
		semessage(cs, "Malloc allocation failed");
		return (NULL);
	}
	data[paquet_size] = '\0';
	tmp = data;
	while (paquet_size > 0)
	{
		r = read(cs, tmp, paquet_size);
		if (r <= 0)
		{
			free(data);
			exit_error(6);
		}
		tmp += r;
		paquet_size -= r;
	}
	return (data);
}

int		wrequest(int cs)
{
	char	buff[4];
	int		r;
	int		paquet_size;

	r = read(cs, buff, 4);
	if (r < 0)
		exit_error(6);
	if (r < 4)
		return (semessage(cs, "Invalid size"));
	paquet_size = *(int*)buff;
	paquet_size -= 4;
	return (paquet_size);
}

char	*garequest(int cs, int *value)
{
	int		paquet_size;
	char	*data;

	if ((paquet_size = wrequest(cs)) == -1)
		return (NULL);
	if ((data = gfrequest(cs, paquet_size)) == NULL)
		return (NULL);
	if (value)
		*value = paquet_size;
	return (data);
}

int		list_request(int cs, char *buff, char *mwd)
{
	int	r;

	r = 0;
	if (buff[0] == 1)
		r = ls(cs);
	if (buff[0] == 2)
		r = cd(cs, buff + 1, mwd);
	if (buff[0] == 3)
		r = pwd(cs);
	if (buff[0] == 4)
		r = upload(cs, buff);
	if (buff[0] == 5)
		r = download(cs, buff);
	if (buff[0] == 8)
		return (-2);
	return (r);
}

int		grequest(int cs, char *mwd)
{
	int		con;
	char	*data;
	int		r;

	con = 1;
	while (con != -1)
	{
		if (!(data = garequest(cs, NULL)))
			return (-1);
		r = list_request(cs, data, mwd);
		free(data);
		if (r == -1)
			ft_putendl("Error happened");
		else if (r == -2)
			return (-1);
	}
	return (0);
}
