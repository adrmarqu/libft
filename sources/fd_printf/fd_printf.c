/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:20:00 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/04 20:53:27 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fd_printf.h"
#include <stdio.h>

static void	ft_read(va_list lst, t_printf *data, const char *s)
{
	while (*s && !data->error)
	{
		if (*s == '%')
		{
			if (!s[1])
				return ;
			s += handle_flags(s, data);
			handle_format(lst, data);
		}
		else
			s += handle_text(s, data);
	}
}

static void	init_struct(t_printf *data, int fd)
{
	t_flag	flags;

	flags.minus = false;
	flags.zero = false;
	flags.alter = false;
	flags.space = false;
	flags.sign = false;
	flags.precision = -1;
	flags.width = 0;
	flags.specifier = '0';
	data->fd = fd;
	data->error = false;
	data->output = NULL;
	data->length = 0;
	data->flags = flags;
}

int	fd_printf(int fd, const char *s, ...)
{
	va_list		lst;
	t_printf	data;

	if (fd < 0 || !s || fd > FOPEN_MAX)
		return (-1);
	va_start(lst, s);
	init_struct(&data, fd);
	ft_read(lst, &data, s);
	va_end(lst);
	ft_write(&data);
	if (data.error)
		return (-1);
	return (data.length);
}
