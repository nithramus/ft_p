/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nithramir <nithramir@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 16:41:20 by nithramir         #+#    #+#             */
/*   Updated: 2018/07/24 01:26:06 by nithramir        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int screquest(int cs, char *response)
{
    if (write(cs, response, ft_strlen(response)) == -1)
        return (-1);
    return (0);
}

int list_request(int cs, char *buff, char *mwd, char **cwd)
{
    int r;

    r = 0;
    ft_putendl("mais what");
    ft_printf("%d\n", (int)(char)buff[0]);
    if (buff[0] == 1)
        r = ls(cs);
    if (buff[0] == 2)
        r= cd(cs, buff + 1, mwd, cwd);
    if (buff[0] == 3)
        r = pwd(cs);
    if (buff[0] == 4)
        upload(cs, buff);
    // if (buff[0] == 5)
    // if (buff[0] == 6)
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
            return (NULL);
        tmp += r;
        paquet_size -= r;
    }
    ft_putendl(data);
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
    ft_printf("yolo %d\n", paquet_size);
    return (paquet_size);
}

char *garequest(int cs)
{
    int paquet_size;
    char    *data;

    if ((paquet_size = wrequest(cs)) == -1)
        return (NULL);
    if ((data = gfrequest(cs, paquet_size)) == NULL)
        return (NULL);
    return (data);
}

int grequest(int cs, char *mwd)
{
    int con;
    char cwd[4097];
    char *response;
    char    *data;

    con = 1;
    response = getcwd(cwd, 4096);
    if (!response)
        return (-1);
    while (con != -1)
    {
        if (!(data = garequest(cs)))
            return (NULL);
        if (list_request(cs, data, mwd, &cwd) == -1)
            return (-1);
    }
    return (0);
}