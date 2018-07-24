/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nithramir <nithramir@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 01:05:51 by nithramir         #+#    #+#             */
/*   Updated: 2018/07/25 01:09:08 by nithramir        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

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
        return (-1);
    if (write(cs, &value, 1) == -1)
        return (-1);
    if (!(response = garequest(cs, NULL)))
        return (-1);
    ft_putstr(response + 1);
    return (0);
}

int ls(int cs)
{
    int ret;

    ret = sbrequest(1, cs);
    return (ret);
}