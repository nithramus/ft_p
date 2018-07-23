/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nithramir <nithramir@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:56:17 by nithramir         #+#    #+#             */
/*   Updated: 2018/07/24 01:26:57 by nithramir        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int receivef(int cs, int fd)
{
    char *data;

    if (!(data = garequest(cs)))
        return (0);
    if (write(fd, data + 1, ft_strlen(data)) == -1)
        return (-1);
    if (data[0] == 5)
        return (1);
    else
        return (0);
}


int upload(int cs, char *buff)
{
    int contin;
    int fd;

    contin = 1;
    ft_putendl("coucou");
    ft_putendl(buff);
    fd = open(buff + 1, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    while (contin)
    {
        ft_putendl("coucou2");
        contin = receivef(cs, fd);
    }
    close(fd);
    return (0);
}
