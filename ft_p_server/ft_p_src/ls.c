/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <bandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 18:08:58 by nithramir         #+#    #+#             */
/*   Updated: 2018/11/21 18:20:08 by bandre           ###   ########.fr       */
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

void	exec_function(char *params, int link[2])
{
	char	**parsed;
	char	*final_params;

	parsed = ft_strsplit(params, ' ');
	if (parsed && parsed[0] && parsed[0][0] == '-')
		final_params = parsed[0];
	else
		final_params = NULL;
	dup2(link[1], STDOUT_FILENO);
	close(link[0]);
	close(link[1]);
	execl("/bin/ls", "ls", final_params, NULL);
}

int		ls(int cs, char *params)
{
	int		link[2];
	pid_t	pid;
	char	foo[4096];
	int		nbytes;

	nbytes = 0;
	pipe(link);
	pid = fork();
	if (pid == 0)
	{
		exec_function(params, link);
	}
	else
	{
		close(link[1]);
		nbytes = read(link[0], foo, sizeof(foo));
		wait4(pid, NULL, 0, NULL);
	}
	screquest(cs, foo, nbytes);
	return (0);
}
