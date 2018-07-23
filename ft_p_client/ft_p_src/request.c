/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nithramir <nithramir@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 19:51:47 by nithramir         #+#    #+#             */
/*   Updated: 2018/07/23 15:40:32 by nithramir        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_p.h"

/*
    Function used for basic request like cd, ls and pwd
*/
int    sbrequest(char value, int cs)
{
    char    buff[4097];
    int     r;
    int size;

    size = 5;
    ft_strncpy(buff, &size, 4);
    buff[4] = 1;
    if (write(cs, buff, 5) == -1)
        exit_error(4);
    if ((r = read(cs, buff, 4096)) == -1)
    {
        return (-1);
    }
    buff[r] = '\0';
    ft_putstr(buff);
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

int     cd(char *request, int cs)
{
    char *filename;
    char *tmp;

    filename = get_filename(request);
    if (!filename)
        return (-1);
    tmp = malloc(ft_strlen(filename));
    if (!tmp)
        return (-1);
    tmp[0] = 2;
    ft_strcpy(tmp + 1, filename);
    screquest(tmp, cs);
    free(filename);
    free(tmp);
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
    // else if (ft_strncmp(request, "get", 3) == 0)
    //     download();
    else if (ft_strncmp(request, "put", 3) == 0)
        upload(request, cs);
    else
        ft_putendl("No such command");
    return (1);
}