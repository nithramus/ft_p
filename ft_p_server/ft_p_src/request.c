/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nithramir <nithramir@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 16:41:20 by nithramir         #+#    #+#             */
/*   Updated: 2018/07/21 00:36:14 by nithramir        ###   ########.fr       */
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
    if (buff[0] == 1)
        r = ls(cs, cwd);
    if (buff[0] == 2)
        r= cd(cs, buff + 1, mwd, cwd);
    if (buff[0] == 3)
        r = pwd(cs);
    // if (buff[0] == 4)
    // if (buff[0] == 5)
    // if (buff[0] == 6)
    return (r);
}

int wrequest(int cs, char *mwd, char **cwd)
{
    char buff[4096];
    int r;

    r = read(cs, buff, 4095);
    if (r <= 0)
        return (-1);
    buff[r] = '\0';
    if (list_request(cs, buff, mwd, cwd) == -1)
        return (-1);
    return (0);
}

int grequest(int cs, char *mwd)
{
    int con;
    char cwd[4097];
    char *response;

    con = 1;
    response = getcwd(cwd, 4096);
    if (!response)
        return (-1);
    while (con != -1)
    {
        con = wrequest(cs, mwd, &cwd);
    }
    return (0);
}