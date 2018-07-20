/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nithramir <nithramir@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 16:25:50 by nithramir         #+#    #+#             */
/*   Updated: 2018/07/20 16:47:49 by nithramir        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void exit_error(int err)
{
    if (err == 1)
        ft_putendl("usage: ./ft_p [PORT]");
    if (err == 2)
        ft_putendl("Failed to create socket");
    if (err == 3)
        ft_putendl("Failed to write");
    if (err == 4)
        ft_putendl("Failed to get current working directory");
    exit(1);
}