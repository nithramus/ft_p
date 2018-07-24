/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nithramir <nithramir@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 00:39:02 by nithramir         #+#    #+#             */
/*   Updated: 2018/07/24 16:28:47 by nithramir        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

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