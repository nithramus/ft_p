/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   download.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nithramir <nithramir@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:01:54 by nithramir         #+#    #+#             */
/*   Updated: 2018/07/26 01:28:57 by nithramir        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int request_file(char *filename, int cs)
{
    char buff[1096];

    buff[0] = 5;
    ft_strcpy(buff + 1, filename);
    if (screquest(buff, cs, -1) == -1)
        return (-1);
    if (!(garequest(cs, NULL)))
        return (-1);
    return (1);
}

int create_file(char *filename)
{
    int fd;

    if ((fd = open(filename, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR)) == -1)
    {
        ft_putendl("Failed creating file");
        return (-1);
    }
    return (fd);
}

int receive_file(char *filename, int cs)
{
    char *data;
    int con;
    int fd;
    int size;

    con = 1;
    size = 1;
    if ((fd = create_file(filename)) == -1)
        return (-1);
    while (con)
    {
        data = garequest(cs, &size);
        if (data)
        {
            if (data[0] != 6)
                con = 0;
            write(fd, data + 1, size - 1);
            free(data);
        }
        else
            return (-1);
    }
    close(fd);
    return (0);
}

int download(char *request, int cs)
{
    char    *filename;

    filename = get_filename(request);
    if (!filename)
    {
        ft_putendl("No filename");
        return (-1);
    }
    if (request_file(filename, cs) == -1)
        return (-1);
    if (receive_file(filename, cs) == -1)
        return (-1);
    return (0);
}