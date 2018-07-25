/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nithramir <nithramir@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 18:08:58 by nithramir         #+#    #+#             */
/*   Updated: 2018/07/25 21:57:54 by nithramir        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void    count(t_libft_chained_list *elem, void *param)
{
    int *value;

    value = (int*)param;
    *value += ft_strlen(elem->data) + 1;
}

void    concat(t_libft_chained_list *elem, void *param)
{
    char **string;
    int size;

    string = (char**)param;
    ft_strcpy((*string), elem->data);
    size = ft_strlen(elem->data);
    (*string)[size] = '\n';
    (*string)[size + 1] = '\0';
    *string += size + 1;
}

int cresponse(struct dirent *dir, t_libft_chained_list **first)
{
    char                    *file;

    file = ft_strdup(dir->d_name);
    if (!file)
        return (-1);
    add_back_maillon(first, file);
    return (0);
}

int list_files(int cs, t_libft_chained_list    **first)
{
    DIR *d;
    struct dirent *dir;

    d = opendir(".");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
            if (cresponse(dir, first) == -1)
                return (semessage(cs, "Malloc allocation failed"));
    }
    else
        return (semessage(cs, "Malloc allocation failed"));
    closedir(d);
    return (0);
}

int ls(int cs)
{
    t_libft_chained_list    *first;
    char *string;
    char *save;
    int     size;

    first = NULL;
    size = 0;
    if (list_files(cs, &first) == -1)
        return (-1);

    function_on_chained_list(&first, count, &size);
    string = malloc(size + 2);
    save = string;
    if (!string)
        return (semessage(cs, "Malloc allocation failed"));
    string[0] = 1;
    string += 1;
    function_on_chained_list(&first, concat, &string);
    ft_putendl(save);
    screquest(cs, save, -1);
    free(save);
    delete_chained_list(&first, free);
    return (1);
}