/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nithramir <nithramir@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 12:31:56 by nithramir         #+#    #+#             */
/*   Updated: 2018/07/24 15:25:47 by nithramir        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int     send_file(int fd, int cs)
{
    char    buff[4097];
    int     r;

    buff[0] = 6;
    while ((r = read(fd, buff + 1, 4095)))
    {
        buff[r] = '\0';
        ft_putendl(buff);
        if (r < 4095)
            buff[0] = 7;
        if (screquest(cs, buff))
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

    ft_putendl(request + 1);
    fd = open(request + 1, O_RDONLY);
    if (fd == -1)
    {
        ft_putendl("Unable to open file");
        return (-1);
    }
    ft_putendl("sending file");
    if (send_file(fd, cs) == -1)
    {
        ft_putendl("connection error2");
        return (-1);
    }
    close(fd);
    return (0);
}