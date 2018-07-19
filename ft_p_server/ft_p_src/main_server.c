/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nithramir <nithramir@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 12:02:29 by nithramir         #+#    #+#             */
/*   Updated: 2018/07/20 01:05:00 by nithramir        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_p.h"

void exit_error(int err)
{
    if (err == 1)
        ft_putendl("usage: ./ft_p [PORT]");
    if (err == 2)
        ft_putendl("Failed to create socket");
    if (err == 3)
        ft_putendl("Failed to write");
    exit(1);
}

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
    ft_putendl(buff);
    if (write(cs, "cava", 4) == -1)
        exit_error(3);
}

int main(int argc, char **argv)
{
    int sock;
    int cs;
    unsigned int addrlen;
    struct sockaddr_in csin;
    int r;
    char buff[1024];
    if (argc < 2)
        exit_error(1);
    sock = create_server(atoi(argv[1]));
        cs = accept(sock, (struct sockaddr*) &csin, &addrlen);
    while (1)
    {
        r = read(cs, buff, 1023);
        buff[r] = '\0';
        ft_putendl("test");
        ft_putendl(buff);
        // if (r >= 0)
        //     send_response(buff, cs);
    }
    close(cs);
    close(sock);
    return (0);
}