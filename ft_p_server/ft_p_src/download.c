/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   download.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nithramir <nithramir@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 12:31:56 by nithramir         #+#    #+#             */
/*   Updated: 2018/07/25 01:11:57 by nithramir        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int     send_file(int fd, int cs)
{
    char    buff[32000];
    int     r;

    buff[0] = 6;
    while ((r = read(fd, buff + 1, 31998)))
    {
        if (r < 31998)
            buff[0] = 7;
        if (screquest(cs, buff, r + 1))
            return (-1);
    }
    return (0);
}

/*
    Function used to download a file
*/
int    download(int cs, char *request)
{
    int     fd;

    if (ft_strchr(request, '/'))
    {
        ft_putendl("invalid caractere");
        return (-1);
    }
    fd = open(request + 1, O_RDONLY);
    if (fd == -1)
    {
        ft_putendl("Unable to open file");
        return (-1);
    }
    if (send_file(fd, cs) == -1)
    {
        ft_putendl("connection error2");
        return (-1);
    }
    close(fd);
    return (0);
}