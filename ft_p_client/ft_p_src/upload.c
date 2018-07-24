/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nithramir <nithramir@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 22:33:40 by nithramir         #+#    #+#             */
/*   Updated: 2018/07/24 12:12:05 by nithramir        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int     send_filename(char *filename, int cs)
{
    char    buff[4096];

    buff[0] = 4;
    ft_strcpy(buff + 1, filename);
    if (screquest(buff, cs) == -1)
        return (-1);
    return (0);
}

int     send_file(int fd, int cs)
{
    char    buff[4097];
    int     r;

    buff[0] = 6;
    while ((r = read(fd, &buff[1], 4095)))
    {
        buff[r] = '\0';
        if (r < 4096)
            buff[0] = 7;
        if (screquest(buff, cs))
            return (-1);
    }
    return (0);
}

/*
    Function used to upload a file
*/
int    upload(char *request, int cs)
{
    char    *filename;
    int     fd;

    filename = get_filename(request);
    if (filename == NULL)
    {
        ft_putendl("Problem getting filename");
        return -1;
    }
    ft_putendl(filename);
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        ft_putendl("Unable to open file");
        return (-1);
    }
    if (send_filename(filename, cs) == -1)
    {
        ft_putendl("connection error1");
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