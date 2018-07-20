/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   download.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nithramir <nithramir@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:01:54 by nithramir         #+#    #+#             */
/*   Updated: 2018/07/20 13:13:57 by nithramir        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int request_file(char *filename, int cs)
{
    char buff[1096];

    buff[0] = 7;
    ft_strcpy(buff + 1, filename);
    if (screquest(buff, cs) == -1)
        return (-1);
    return (1);
}

int create_file(char *filename)
{
    int fd;

    if ((fd = open(filename, O_WRONLY || O_CREAT)) == -1)
    {
        ft_putendl("Failed creating file");
        return (-1);
    }
    return (fd);
}

int receive_file(char *filename, int cs)
{
    char buff[32000];
    int con;
    int fd;

    con = 1;
    if ((fd = create_file(filename)) == -1)
        return (-1);
    while (con)
    {
        con = read(cs, buff, 31999);
        if (con)
        {
            buff[con] = '\0';
            if (buff[0] != 5)
                con = 0;
            ft_putendl(buff);
        }
    }
    close_file(fd);
}

int download(char * request, int cs)
{
    char    *filename;

    filename = get_filename(request);
    if (!filename)
    {
        ft_putendl("No filename");
        return (-1);
    }
    if (request_file(filename, cs) == -1)
    {
        ft_putendl("error getting file");
        return (-1);
    }

}