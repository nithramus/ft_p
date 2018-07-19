/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nithramir <nithramir@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:54:34 by bandre            #+#    #+#             */
/*   Updated: 2018/07/18 12:27:29 by nithramir        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*debut;
	size_t	i;
	char	*fin;

	i = 0;
	debut = (char*)src;
	fin = (char*)dest;
	while (i < n)
	{
		fin[i] = debut[i];
		i++;
	}
	return (dest);
}
