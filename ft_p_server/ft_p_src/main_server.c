/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nithramir <nithramir@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 12:02:29 by nithramir         #+#    #+#             */
/*   Updated: 2018/07/24 16:32:32 by nithramir        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_p.h"



int create_server(int port)
{
    int sock;
    struct protoent     *proto;
    struct sockaddr_in  sin;

    proto = getprotobyname("tcp");
    sock = socket(AF_INET, SOCK_STREAM, proto->p_proto);
    if (sock == -1)
        exit_error(2);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    sin.sin_addr.s_addr = INADDR_ANY;
    bind(sock, (struct sockaddr*)&sin, sizeof(sin));
    listen(sock, 42);
    return (sock);
}

void send_response(char buff[1024], int cs)
{
    if (write(cs, "cava", 4) == -1)
        exit_error(3);
}




int     get_connections(int sock, char *mwd)
{
    struct sockaddr_in csin;
    unsigned int addrlen;
    int pid;
    int cs;

    cs = accept(sock, (struct sockaddr*) &csin, &addrlen);
    pid = fork();
    if (pid == 0)
    {
        grequest(cs, mwd);
        close(cs);
        exit(0);
    }
    return (1);
}

int main(int argc, char **argv)
{
    int sock;
    char buff[4097];
    char *mwd;

    if (argc < 2)
        exit_error(1);
    mwd = getcwd(buff, 4096);
    if (!mwd)
        exit_error(4);
    sock = create_server(atoi(argv[1]));
    while (1)
        get_connections(sock, buff);
    close(sock);
    return (0);
}