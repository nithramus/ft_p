/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semessage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nithramir <nithramir@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 19:20:01 by nithramir         #+#    #+#             */
/*   Updated: 2018/07/26 01:06:15 by nithramir        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int svmessage(int cs)
{
    char buff[4];

    buff[0] = 42;
    ft_strcpy(buff + 1, "ok");
    if (screquest(cs, buff, -1) == -1)
        return (-1);
    return (0);
}

int semessage(int cs, char *string)
{
    char *msg;

    if (!(msg = malloc(2 + ft_strlen(string))))
        return (-1);
    msg[0] = 51;
    ft_strcpy(msg + 1, string);
    if (screquest(cs, msg, -1) == -1)
    {
        free(msg);
        return (-1);
    }
    free(msg);
    return (-1);
}