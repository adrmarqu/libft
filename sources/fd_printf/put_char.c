/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 17:39:21 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/07 18:07:59 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fd_printf.h"

void	put_char(char c, t_printf *data)
{
	char	str[2];

	data->flags.precision = -1;
	data->flags.space = false;
	data->flags.sign = false;
	data->flags.zero = false;
	data->flags.alter = false;
	str[0] = c;
	str[1] = '\0';
	save_string(str, data);
}

void	put_str(const char *str, t_printf *data)
{
	data->flags.space = false;
	data->flags.sign = false;
	data->flags.zero = false;
	data->flags.alter = false;
	save_string(str, data);
}
