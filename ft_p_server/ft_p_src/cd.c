/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nithramir <nithramir@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 23:53:11 by nithramir         #+#    #+#             */
/*   Updated: 2018/07/21 00:35:37 by nithramir        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"



int cd(int cs, char *path, char *mwd, char **cwd)
{
    char buff[4097];
    int size;
    char *response;

    // ft_strcpy(buff, path);
    // size = ft_strlen(buff);
    // buff[size] = '/';
    // ft_strcpy(buff + size + 1, path);
    chdir(path);
    response = getcwd(buff, 4096);
    if (!response)
        return (-1);
    ft_putendl(buff);
    //chwdr
    // testvalidpath
}