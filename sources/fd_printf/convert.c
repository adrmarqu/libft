/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 17:37:35 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/07 18:05:21 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fd_printf.h"
#include "../../inc/string.h"
#include "../../inc/memory.h"
#include "../../inc/extra.h"

static char	get_char(unsigned long n, char x)
{
	char	c;

	c = NUMBR[n];
	if (x == 'X' && n >= 10)
		c -= 32;
	return (c);
}

void	convert_nbr(unsigned long n, size_t base, t_printf *data)
{
	int		i;
	char	*nbr;

	nbr = ft_calloc(ft_base_longlen(n, base) + 1, sizeof(char));
	if (!nbr)
	{
		data->error = true;
		return ;
	}
	i = 0;
	while (n >= base)
	{
		nbr[i++] = get_char(n % base, data->flags.specifier);
		n /= base;
	}
	nbr[i] = get_char(n, data->flags.specifier);
	ft_reverse(nbr);
	save_string(nbr, data);
}
