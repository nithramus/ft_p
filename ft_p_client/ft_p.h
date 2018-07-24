/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nithramir <nithramir@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 12:21:11 by nithramir         #+#    #+#             */
/*   Updated: 2018/07/25 00:07:13 by nithramir        ###   ########.fr       */
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
#include <sys/stat.h>
#include <fcntl.h>
void exit_error(int err);
int    upload(char *request, int cs);
int   screquest(char *s, int cs, int size);
int     request(char *request, int cs);
char    *get_filename(char *request);
int     cd(char *request, int cs);
char *garequest(int cs, int *size);
int download(char *request, int cs);

#endif