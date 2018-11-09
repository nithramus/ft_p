/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <bandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 00:39:02 by nithramir         #+#    #+#             */
/*   Updated: 2018/11/09 21:17:14 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_p.h"

int		cd(char *request, int cs)
{
	char	*filename;
	char	*tmp;
	int		ret;

	filename = get_filename(request);
	if (!filename)
		return (-1);
	tmp = malloc(ft_strlen(filename) + 2);
	if (!tmp)
		return (-1);
	tmp[0] = 2;
	ft_strcpy(tmp + 1, filename);
	if ((ret = screquest(tmp, cs, -1)) == -1)
		return (-1);
	if (!(garequest(cs, NULL)))
		return (-1);
	free(filename);
	free(tmp);
	return (0);
}
