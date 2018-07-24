/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nithramir <nithramir@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 19:51:47 by nithramir         #+#    #+#             */
/*   Updated: 2018/07/24 14:46:13 by nithramir        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_p.h"

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

/*
    Function used for basic request like cd, ls and pwd
*/
int    sbrequest(char value, int cs)
{
    char    *response;
    int     r;
    int size;

    size = 5;
    if (write(cs, &size, 4) == -1)
        exit_error(4);
    if (write(cs, &value, 1) == -1)
        exit_error(4);
    if (!(response = garequest(cs)))
    {
        return (-1);
    }
    ft_putstr(response);
    ft_putstr("\n");
    return (0);
}

/*
    Function used for complexe request like get and put
*/
int   screquest(char *s, int cs)
{
    char    buff[1096];
    int     r;
    int     value;


    value = ft_strlen(s) + 4;
    if (write(cs, &value, 4) == -1)
        exit_error(4);
    if (write(cs, s, ft_strlen(s)) == -1)
        exit_error(4);
    // r = read(cs, buff, 1095);
    // if (r == -1)
    // {
    //     ft_putendl("Erreur reseau");
    //     return (r);
    // }
    // if (ft_strcmp(buff, "ok") != 0)
    // {
    //     ft_putendl(buff);
    //     return (-1);
    // }
    return (0);
}

int     request(char *request, int cs)
{
    ft_putendl(request);
    if (ft_strcmp(request, "ls") == 0)
        sbrequest(1, cs);
    else if (ft_strncmp(request, "cd", 2) == 0)
        cd(request, cs);
    else if (ft_strcmp(request, "pwd") == 0)
        sbrequest(3, cs);
    else if (ft_strncmp(request, "get", 3) == 0)
        download(request, cs);
    else if (ft_strncmp(request, "put", 3) == 0)
        upload(request, cs);
    else
        ft_putendl("No such command");
    return (1);
}