/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_filename.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <bandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:08:05 by nithramir         #+#    #+#             */
/*   Updated: 2018/11/09 21:23:27 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_p.h"

void	freechartab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}

char	*get_filename(char *request)
{
	char	**tab;
	int		i;
	char	*filename;

	tab = ft_strsplit(request, ' ');
	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
		i++;
	if (i != 2)
		return (NULL);
	filename = ft_strdup(tab[1]);
	freechartab(tab);
	return (filename);
}
