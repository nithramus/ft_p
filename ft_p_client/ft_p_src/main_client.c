/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <bandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 21:23:47 by bandre            #+#    #+#             */
/*   Updated: 2018/11/21 18:47:03 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_p.h"

int	create_client(char *addr, int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	sock = socket(AF_INET, SOCK_STREAM, proto->p_proto);
	if (sock == -1)
	{
		ft_putendl("exit");
		exit_error(2);
	}
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	if (ft_strcmp(addr, "localhost") == 0)
		addr = "127.0.0.1";
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (struct sockaddr*)&sin, sizeof(sin)) == -1)
	{
		ft_putendl("connect problem");
		exit_error(3);
	}
	return (sock);
}

int	main(int argc, char **argv)
{
	int		sock;
	char	*command;
	int		r;
	int		con;

	con = 0;
	if (argc < 3)
		exit_error(1);
	sock = create_client(argv[1], atoi(argv[2]));
	ft_putstr("$> ");
	while ((r = get_next_line(0, &command)) != 0)
	{
		con = request(command, sock);
		free(command);
		if (con == -2)
		{
			close(sock);
			return (0);
		}
		ft_putstr("$> ");
	}
	close(sock);
	return (0);
}
