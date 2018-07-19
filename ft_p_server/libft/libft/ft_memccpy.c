/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nithramir <nithramir@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:59:11 by bandre            #+#    #+#             */
/*   Updated: 2018/07/18 12:52:33 by nithramir        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*debut;
	char	*fin;
	size_t	i;

	i = 0;
	debut = (char*)src;
	fin = (char*)dest;
	while (i < n)
	{
		fin[i] = debut[i];
		if (debut[i] == c)
			return ((void*)&(fin[i + 1]));
		i++;
	}
	return (NULL);
}
