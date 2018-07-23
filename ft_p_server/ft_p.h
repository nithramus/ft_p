/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nithramir <nithramir@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 12:21:11 by nithramir         #+#    #+#             */
/*   Updated: 2018/07/21 15:20:42 by nithramir        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_H
#define FT_P_H
#include "libft/libft/libft.h"
#include "libft/ft_printf/ft_printf.h"
#include "libft_chained_list/libft_chained_list_src/libft_chained_list.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int cd(int cs, char *buff, char *mwd, char **cwd);
void exit_error(int err);
int grequest(int cs, char *mwd);
int screquest(int cs, char *response);
int pwd(int cs);
int ls(int cs);
int upload(int cs, char *buff);

#endif