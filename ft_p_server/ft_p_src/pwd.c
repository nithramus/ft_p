/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nithramir <nithramir@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 17:30:45 by nithramir         #+#    #+#             */
/*   Updated: 2018/07/25 21:58:56 by nithramir        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int pwd(int cs)
{
    char    buff[4097];
    char    *response;

    response = getcwd(buff + 1, 4096);
    if (!response)
    {
        ft_putendl("error getting path");
        return semessage(cs, "Unable to get current path");
    }
    else
        buff[0] = 3;
    if (screquest(cs, buff, -1) == -1)
        return (-1);
    return (0);
}