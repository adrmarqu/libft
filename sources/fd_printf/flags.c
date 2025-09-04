/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 19:09:50 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/04 20:05:57 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fd_printf.h"
#include "../../inc/ctype.h"

size_t	get_flags(const char *s, t_flag *flags)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '0')
			flags->zero = true;
		else if (s[i] == '-')
			flags->minus = true;
		else if (s[i] == ' ')
			flags->space = true;
		else if (s[i] == '#')
			flags->alter = true;
		else if (s[i] == '+')
			flags->sign = true;
		else
			break ;
		i++;
	}
	return (i);
}

size_t	get_width(const char *s, t_flag *flags)
{
	size_t	len;

	len = 0;
	while (s[len] && ft_isdigit(s[len]))
	{
		flags->width = flags->width * 10 + (s[len] - '0');
		len++;
	}
	return (len);
}

size_t	get_precision(const char *s, t_flag *flags)
{
	size_t	len;

	len = 0;
	if (s[len++] != '.')
		return (0);
	while (s[len] == '.')
		len++;
	flags->precision = 0;
	while (s[len] && ft_isdigit(s[len]))
	{
		flags->precision = flags->precision * 10 + (s[len] - '0');
		len++;
	}
	return (len);
}

void	show(t_flag *f)
{
	printf("Minus: %d\n", f->minus);
	printf("Zero: %d\n", f->zero);
	printf("Alter: %d\n", f->alter);
	printf("Space: %d\n", f->space);
	printf("Sign: %d\n", f->sign);
	printf("Precision: %d\n", f->precision);
	printf("Width: %d\n", f->width);
	printf("Letter: %c\n\n", f->specifier);
}

void	nullify_flags(t_flag *f)
{
	if (f->minus)
		f->zero = false;
	if (f->sign)
		f->space = false;
}
