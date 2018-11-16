/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <bandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 01:05:51 by nithramir         #+#    #+#             */
/*   Updated: 2018/11/15 22:45:14 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_p.h"

int	sbrequest(char value, int cs)
{
	char	*response;
	int		size;

	size = 5;
	if (write(cs, &size, 4) == -1)
		return (-1);
	if (write(cs, &value, 1) == -1)
		return (-1);
	if (!(response = garequest(cs, NULL)))
		return (-1);
	ft_putstr(response + 1);
	return (0);
}

int	exitr(char value, int cs)
{
	int		size;

	size = 5;
	if (write(cs, &size, 4) == -1)
		return (-2);
	if (write(cs, &value, 1) == -1)
		return (-2);
	return (-2);
}

int	ls(char *request, int cs)
{
	int		ret;
	char	*response;

	request[1] = 1;
	ret = screquest(request + 1, cs, -1);
	if (ret == -1)
		return (-1);
	if (!(response = garequest(cs, NULL)))
		return (-1);
	ft_putstr(response);
	free(response);
	return (ret);
}
