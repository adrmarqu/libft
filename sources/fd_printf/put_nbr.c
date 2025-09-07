/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 17:39:26 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/07 17:48:37 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fd_printf.h"
#include <limits.h>

void	put_nbr(int n, t_printf *data)
{
	long int	aux;

	data->flags.alter = false;
	if (data->flags.precision != -1)
		data->flags.zero = false;
	aux = (long int)n;
	if (aux >= INT_MIN && aux <= INT_MAX)
	{
		if (aux < 0)
		{
			data->flags.sign = true;
			data->flags.symbol_sign = '-';
			data->flags.space = false;
			aux = -aux;
		}
		else
			if (data->flags.sign)
				data->flags.symbol_sign = '+';
		if (data->flags.sign || data->flags.space)
			data->flags.width--;
		convert_nbr((unsigned long)aux, 10, data);
	}
}

void	put_unbr(unsigned int n, t_printf *data)
{
	data->flags.space = false;
	data->flags.alter = false;
	data->flags.sign = false;
	if (data->flags.precision != -1)
		data->flags.zero = false;
	convert_nbr((unsigned long)n, 10, data);
}

void	put_hex(unsigned int hex, t_printf *data)
{
	data->flags.space = false;
	data->flags.sign = false;
	if (data->flags.precision != -1)
		data->flags.zero = false;
	if (hex == 0)
		data->flags.alter = false;
	if (data->flags.alter)
		data->flags.width -= 2;
	convert_nbr((unsigned long)hex, 16, data);
}

void	put_dir(unsigned long p, t_printf *data)
{
	data->flags.precision = -1;
	data->flags.alter = true;
	data->flags.width -= 2;
	convert_nbr(p, 16, data);
}
