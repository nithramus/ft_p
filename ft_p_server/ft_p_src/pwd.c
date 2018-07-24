/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nithramir <nithramir@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 17:30:45 by nithramir         #+#    #+#             */
/*   Updated: 2018/07/24 22:37:01 by nithramir        ###   ########.fr       */
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
        buff[0] = 42;
        ft_strcpy(buff + 1, "Unable to get working directory");
    }
    else
        buff[0] = 3;
    if (screquest(cs, buff, -1) == -1)
        return (-1);
    return (0);
}