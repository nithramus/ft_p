/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <bandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 12:21:11 by nithramir         #+#    #+#             */
/*   Updated: 2018/11/09 21:32:56 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_H
# define FT_P_H
# include "libft/libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft_chained_list/libft_chained_list_src/libft_chained_list.h"
# include <sys/types.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

void	exit_error(int err);
int		upload(char *request, int cs);
int		screquest(char *s, int cs, int size);
int		request(char *request, int cs);
char	*get_filename(char *request);
int		cd(char *request, int cs);
char	*garequest(int cs, int *size);
int		download(char *request, int cs);
int		ls(int cs);
int		pwd(int cs);
int		screquest(char *response, int cs, int size);
int		sbrequest_nr(char value, int cs);

#endif
