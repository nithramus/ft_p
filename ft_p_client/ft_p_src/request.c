/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <bandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 19:51:47 by nithramir         #+#    #+#             */
/*   Updated: 2018/11/21 18:58:13 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_p.h"

char	*gfrequest(int cs, int paquet_size)
{
	char	*data;
	char	*tmp;
	int		r;

	if (!(data = malloc(paquet_size + 1)))
		return (NULL);
	data[paquet_size] = '\0';
	tmp = data;
	while (paquet_size > 0)
	{
		r = read(cs, tmp, paquet_size);
		if (r <= 0)
			return (NULL);
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
	if (r < 4)
		return (-1);
	paquet_size = *(int*)buff;
	paquet_size -= 4;
	return (paquet_size);
}

char	*garequest(int cs, int *size)
{
	int		paquet_size;
	char	*data;

	if ((paquet_size = wrequest(cs)) == -1)
		return (NULL);
	if ((data = gfrequest(cs, paquet_size)) == NULL)
		return (NULL);
	if (size)
		*size = paquet_size;
	if (data[0] == 51)
	{
		ft_putendl(data + 1);
		free(data);
		return (NULL);
	}
	return (data);
}

int		screquest(char *response, int cs, int size)
{
	int	value;

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

int		request(char *request, int cs)
{
	int	r;

	r = 1;
	if (ft_strncmp(request, "ls", 2) == 0)
		r = ls(request, cs);
	else if (ft_strncmp(request, "cd", 2) == 0)
		r = cd(request, cs);
	else if (ft_strcmp(request, "pwd") == 0)
		r = pwd(cs);
	else if (ft_strncmp(request, "get", 3) == 0)
		r = download(request, cs);
	else if (ft_strncmp(request, "put", 3) == 0)
		r = upload(request, cs);
	else if (ft_strcmp(request, "exit") == 0)
		r = exitr(8, cs);
	else
		ft_putendl("\nNo such command");
	if (r == 0)
		ft_putendl("\nSUCCESS");
	if (r == -1)
		ft_putendl("\nERROR");
	return (r);
}
