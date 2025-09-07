/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 17:37:52 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/07 18:07:43 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/structs.h"
#include "../../inc/memory.h"
#include "../../inc/string.h"
#include "../../inc/extra.h"
#include "../../inc/ctype.h"
#include <stdlib.h>

static size_t	parse_flags(const char *s, t_flag *flags)
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

static size_t	parse_width(const char *s, t_flag *flags)
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

static size_t	parse_precision(const char *s, t_flag *flags)
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

size_t	handle_flags(const char *s, t_printf *data)
{
	size_t	len;

	len = 1;
	len += parse_flags(s + 1, &data->flags);
	len += parse_width(s + len, &data->flags);
	len += parse_precision(s + len, &data->flags);
	data->flags.specifier = s[len++];
	if (data->flags.minus)
		data->flags.zero = false;
	if (data->flags.sign)
		data->flags.space = false;
	return (len);
}

size_t	handle_text(const char *s, t_printf *data)
{
	char	*str;
	char	*tmp;
	size_t	len;

	len = 0;
	while (s[len] && s[len] != '%')
		len++;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
	{
		data->error = true;
		return (0);
	}
	ft_strlcpy(str, s, len + 1);
	tmp = data->output;
	data->output = ft_strjoin(tmp, str);
	return (free(tmp), free(str), len);
}
