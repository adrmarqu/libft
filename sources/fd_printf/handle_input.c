/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:40:17 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/04 20:48:18 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fd_printf.h"
#include "../../inc/string.h"
#include "../../inc/extra.h"
#include "../../inc/memory.h"
#include <stdlib.h>

size_t	handle_flags(const char *s, t_printf *data)
{
	size_t	len;

	len = 1;
	len += get_flags(s + 1, &data->flags);
	len += get_width(s + len, &data->flags);
	len += get_precision(s + len, &data->flags);
	data->flags.specifier = s[len++];
	nullify_flags(&data->flags);
	return (len);
}

void	handle_format(va_list lst, t_printf *data)
{
	const int	type = data->flags.specifier;

	if (type == '%')
		put_char('%', data);
	else if (type == 'c')
		put_char(va_arg(lst, int), data);
	else if (type == 's')
		put_string(va_arg(lst, char *), data);
	/*else if (type == 'p')
		put_dir(va_arg(lst, unsigned long), data);
	else if (type == 'd' || type == 'i')
		put_nbr(va_arg(lst, int), data);
	else if (type == 'u')
		put_unbr(va_arg(lst, unsigned int), data);
	else if (type == 'x' || type == 'X')
		put_hex(va_arg(lst, unsigned int), data);*/
	else
		data->error = 1;
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
