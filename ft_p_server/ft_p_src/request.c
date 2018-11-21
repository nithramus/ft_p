/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <bandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 16:41:20 by nithramir         #+#    #+#             */
/*   Updated: 2018/11/21 14:15:54 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_p.h"

int		list_request(int cs, char *buff, char *mwd)
{
	int	r;

	r = 0;
	if (buff[0] == 1)
		r = ls(cs, buff + 1);
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
