/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:20:00 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/07 18:12:48 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fd_printf.h"
#include <stdio.h>
#include <stdarg.h>

static void	set_flags(t_flag *f)
{
	f->minus = false;
	f->zero = false;
	f->alter = false;
	f->space = false;
	f->sign = false;
	f->symbol_sign = '0';
	f->precision = -1;
	f->width = 0;
	f->specifier = '0';
}

static void	set_struct(t_printf *data, int fd)
{
	t_flag	flags;

	set_flags(&flags);
	data->fd = fd;
	data->error = false;
	data->output = NULL;
	data->length = 0;
	data->flags = flags;
}

static void	handle_format(va_list lst, t_printf *data)
{
	const int	type = data->flags.specifier;

	if (type == '%')
		put_char('%', data);
	else if (type == 'c')
		put_char(va_arg(lst, int), data);
	else if (type == 's')
		put_str(va_arg(lst, char *), data);
	else if (type == 'p')
		put_dir(va_arg(lst, unsigned long), data);
	else if (type == 'd' || type == 'i')
		put_nbr(va_arg(lst, int), data);
	else if (type == 'u')
		put_unbr(va_arg(lst, unsigned int), data);
	else if (type == 'x' || type == 'X')
		put_hex(va_arg(lst, unsigned int), data);
	else
		data->error = 1;
}

static void	ft_read(va_list lst, t_printf *data, const char *s)
{
	while (*s && !data->error)
	{
		if (*s == '%')
		{
			if (!s[1])
			{
				data->error = 1;
				return ;
			}
			s += handle_flags(s, data);
			handle_format(lst, data);
			set_flags(&data->flags);
		}
		else
			s += handle_text(s, data);
	}
}

int	fd_printf(int fd, const char *s, ...)
{
	va_list		lst;
	t_printf	data;

	if (fd < 0 || !s || fd > FOPEN_MAX)
		return (-1);
	va_start(lst, s);
	set_struct(&data, fd);
	ft_read(lst, &data, s);
	va_end(lst);
	write_output(&data);
	if (data.error)
		return (-1);
	return (data.length);
}
