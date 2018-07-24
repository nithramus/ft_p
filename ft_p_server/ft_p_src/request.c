/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nithramir <nithramir@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 16:41:20 by nithramir         #+#    #+#             */
/*   Updated: 2018/07/25 01:13:56 by nithramir        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int screquest(int cs, char *response, int size)
{
    int value;

    value = size;
    if (size == -1)
        value = ft_strlen(response) + 4;
    else
        value += 4;
    if (write(cs, &value, 4) == -1)
        return (-1);
    if (write(cs, response, value - 4) == -1)
        return (-1);
    return (0);
}

int list_request(int cs, char *buff, char *mwd)
{
    int r;

    r = 0;
    if (buff[0] == 1)
        r = ls(cs);
    if (buff[0] == 2)
        r= cd(cs, buff + 1, mwd);
    if (buff[0] == 3)
        r = pwd(cs);
    if (buff[0] == 4)
        r = upload(cs, buff);
    if (buff[0] == 5)
        r = download(cs, buff);
    return (r);
}

char *gfrequest(int cs, int paquet_size)
{
    char    *data;
    char    *tmp;
    int     r;

    if (!(data = malloc(paquet_size + 1)))
        return (NULL);
    data[paquet_size] = '\0';
    tmp = data;
    while (paquet_size > 0)
    {
        r = read(cs, tmp, paquet_size);
        if (r <= 0)
        {
            free(data);
            return (NULL);
        }
        tmp += r;
        paquet_size -= r;
    }
    return (data);
}

int wrequest(int cs)
{
    char buff[4];
    int r;
    int paquet_size;

    r = read(cs, buff, 4);
    if (r < 4)
        return (-1);
    paquet_size = *(int*)buff;
    paquet_size -= 4;
    return (paquet_size);
}

char *garequest(int cs, int *value)
{
    int paquet_size;
    char    *data;

    if ((paquet_size = wrequest(cs)) == -1)
        return (NULL);
    if ((data = gfrequest(cs, paquet_size)) == NULL)
        return (NULL);
    if (value)
        *value = paquet_size;
    return (data);
}

int grequest(int cs, char *mwd)
{
    int con;
    char    *data;

    con = 1;
    while (con != -1)
    {
        if (!(data = garequest(cs, NULL)))
            return (-1);
        if (list_request(cs, data, mwd) == -1)
            ft_putendl("Error happened");
        free(data);
    }
    return (0);
}