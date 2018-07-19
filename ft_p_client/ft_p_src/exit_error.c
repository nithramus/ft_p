/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nithramir <nithramir@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 22:01:20 by nithramir         #+#    #+#             */
/*   Updated: 2018/07/19 22:01:33 by nithramir        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void exit_error(int err)
{
    if (err == 1)
        ft_putendl("usage: ./ft_p [ADDR] [PORT]");
    if (err == 2)
        ft_putendl("Failed to create socket");
    if (err == 3)
        ft_putendl("Failed to connect");
    if (err == 4)
        ft_putendl("Failed to write");
    if (err == 5)
        ft_putendl("Failed to read");
    exit(1);
}