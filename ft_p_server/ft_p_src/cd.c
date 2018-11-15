/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <bandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 23:53:11 by nithramir         #+#    #+#             */
/*   Updated: 2018/11/15 22:15:46 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_p.h"

int	valid_path(char *mwd, char *path)
{
	int	len;

	len = ft_strlen(mwd);
	if (ft_strncmp(mwd, path, len) == 0)
		return (0);
	return (-1);
}

int	cd(int cs, char *path, char *mwd)
{
	char	buff[4097];
	char	*response;

	if (chdir(path) == -1)
		return (semessage(cs, "Path not valid"));
	response = getcwd(buff, 4096);
	if (!response)
		return (semessage(cs, "Path not valid"));
	if (valid_path(mwd, response) == -1)
	{
		if (chdir(mwd) == -1)
			exit_error(5);
		return (semessage(cs, "Path not valid"));
	}
	return (svmessage(cs));
}
