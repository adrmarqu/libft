/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:20:00 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/02 14:59:18 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fd_printf.h"
#include <stdarg.h>
#include <stdio.h>

static void	init_struct(t_format *data, int fd)
{
	t_flag	flag;

	flag.left = false;
	flag.zero = false;
	flag.precision = -1;
	flag.alternative = false;
	flag.space = false;
	flag.sign = false;
	data->flags = flag;
	data->width = 0;
	data->type = 'a';
	data->fd = fd;
	data->length = 0;
	data->error = false;
}
/*
static void	ft_read(va_list lst, t_format data, const char *s)
{
	
}*/

int	fd_printf(int fd, const char *s, ...)
{
	va_list		lst;
	t_format	data;

	if (fd < 0 || !s || fd > FOPEN_MAX)
		return (-1);
	va_start(lst, s);
	init_struct(&data, fd);
	//ft_read(lst, data, s);
	va_end(lst);
	if (data.error)
		return (-1);
	return (data.length);
}
