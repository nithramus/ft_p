/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <bandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 18:08:58 by nithramir         #+#    #+#             */
/*   Updated: 2018/11/15 22:25:40 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_p.h"

int	ls(int cs, char *params)
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
		dup2(link[1], STDOUT_FILENO);
		close(link[0]);
		close(link[1]);
		execl("/bin/ls", "ls", ft_strsplit(params, ' ')[0], NULL);
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
