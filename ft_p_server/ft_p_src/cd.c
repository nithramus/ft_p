/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nithramir <nithramir@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 23:53:11 by nithramir         #+#    #+#             */
/*   Updated: 2018/07/26 01:15:21 by nithramir        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"


int valid_path(char *mwd, char *path)
{
    if (ft_strncmp(mwd, path, ft_strlen(mwd)) == 0)
        return (0);
    return (-1);
}

int cd(int cs, char *path, char *mwd)
{
    char buff[4097];
    int size;
    char *response;

    // ft_strcpy(buff, path);
    // size = ft_strlen(buff);
    // buff[size] = '/';
    // ft_strcpy(buff + size + 1, path);
    if (chdir(path) == -1)
        return semessage(cs, "Path not valid");
    response = getcwd(buff, 4096);
    if (!response)
        return semessage(cs, "Path not valid");
    if (valid_path(mwd, response) == -1)
    {
        if (chdir(mwd) == -1)
            exit_error(5);
        return semessage(cs, "Path not valid");;
    }
    return (svmessage(cs));
}