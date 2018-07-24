/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nithramir <nithramir@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:56:17 by nithramir         #+#    #+#             */
/*   Updated: 2018/07/24 23:38:59 by nithramir        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int receivef(int cs, int fd)
{
    char *data;
    int size;

    if (!(data = garequest(cs, &size)))
        return (0);
    if (write(fd, data + 1, size - 1) == -1)
        return (-1);
    if (data[0] == 6)
        return (1);
    else
        return (0);
}


int upload(int cs, char *buff)
{
    int contin;
    int fd;

    contin = 1;
    if (ft_strchr(buff + 1, '/'))
    {
        ft_putendl("invalid caractere");
        return (-1);
    }
    fd = open(buff + 1, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    while (contin)
        contin = receivef(cs, fd);
    close(fd);
    return (0);
}
