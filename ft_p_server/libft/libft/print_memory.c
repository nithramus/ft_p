/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <bandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 20:35:29 by bandre            #+#    #+#             */
/*   Updated: 2018/05/07 18:26:19 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_itoa2(unsigned char value, char ret[2])
{
	int div;

	div = value / 16;
	if (div >= 0 && div <= 9)
		ret[0] = div + '0';
	else
		ret[0] = div + 'a' - 10;
	div = value % 16;
	if (div >= 0 && div <= 9)
		ret[1] = div + '0';
	else
		ret[1] = div + 'a' - 10;
}

void	print_carac(char value)
{
	if (value >= 33 && value <= 126)
		write(1, &value, 1);
	else
		write(1, ".", 1);
}

void	first_part(size_t *i, size_t *j, size_t size, char *addrchar)
{
	char ret[2];

	while (*i < size)
	{
		ft_itoa2(addrchar[*i], ret);
		write(1, ret, 2);
		if ((*i + 1) % 2 == 0)
			write(1, " ", 1);
		if ((*i + 1) % 16 == 0)
		{
			*j = *i - 15;
			while (*j <= *i)
			{
				print_carac(addrchar[*j]);
				(*j)++;
			}
			write(1, "\n", 1);
		}
		(*i)++;
	}
}

void	print_memory(char *addrchar, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	continuer;

	i = 0;
	continuer = 0;
	first_part(&i, &j, size, addrchar);
	while ((i) % 16 != 0)
	{
		write(1, "  ", 2);
		if ((i + 1) % 2 == 0)
			write(1, " ", 1);
		i++;
		continuer = 1;
	}
	if (continuer)
	{
		j = i - 16;
		while (j < size)
		{
			print_carac(addrchar[j]);
			j++;
		}
		write(1, "\n", 1);
	}
}
