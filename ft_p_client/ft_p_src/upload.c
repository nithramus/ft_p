/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nithramir <nithramir@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 22:33:40 by nithramir         #+#    #+#             */
/*   Updated: 2018/07/20 01:06:56 by nithramir        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void    freechartab(char **tab)
{
    int i;

    if (!tab)
        return ;
    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
}

char    *get_filename(char *request)
{
    char    **tab;
    int     i;
    char    *filename;

    tab = ft_strsplit(request, ' ');
    i = 0;
    if (!tab)
        return (NULL);
    while (tab[i])
        i++;
    if (i != 2)
        return (NULL);
    filename = ft_strdup(tab[1]);
    freechartab(tab);
    return (filename);
}


int     send_filename(char *filename, int cs)
{
    char    buff[4096];

    buff[0] = 4;
    ft_strcpy(&buff[1], filename);
    if (screquest(buff, cs) == -1)
        return (-1);
    return (0);
}

int     send_file(int fd, int cs)
{
    char    buff[4096];
    int     r;

    buff[0] = 5;
    while ((r = read(fd, &buff[1], 4095)))
    {
        buff[r] = '\0';
        if (r < 4095)
            buff[0] = 6;
        if (screquest(buff, cs))
            return (-1);
    }
    return (0);
}

/*
    Function used to upload a file
*/
int    upload(char *request, int cs)
{
    char    *filename;
    int     fd;

    filename = get_filename(request);
    if (filename == NULL)
    {
        ft_putendl("Problem getting filename");
        return -1;
    }
    ft_putendl(filename);
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        ft_putendl("Unable to open file");
        return (-1);
    }
    if (send_filename(filename, cs) == -1)
    {
        ft_putendl("connection error1");
        return (-1);
    }
    if (send_file(fd, cs) == -1)
    {
        ft_putendl("connection error2");
        return (-1);
    }
    close(fd);
    return (0);
}