/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 17:38:29 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/07 18:06:39 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fd_printf.h"
#include "../../inc/memory.h"
#include "../../inc/extra.h"
#include "../../inc/string.h"
#include <stdlib.h>

static char	*get_var(const char *s, t_flag f)
{
	char	*var;

	if (f.precision == -1)
		var = ft_strdup(s);
	else if (f.precision != -1 && f.specifier == 's')
		var = cut_text(s, f.precision);
	else
		var = add_zero(s, f.precision);
	return (var);
}

static char	*get_prefix(t_flag f)
{
	if (f.sign)
		return (ft_char_to_string(f.symbol_sign));
	if (f.space)
		return (ft_strdup(" "));
	if (f.alter && f.specifier == 'X')
		return (ft_strdup("0X"));
	if (f.alter)
		return (ft_strdup("0x"));
	return (ft_strdup(""));
}

static char	*fill_width(const char *var, int width, char c, bool condition)
{
	int		length;
	char	*fill;

	length = width - (int)ft_strlen(var);
	if (length <= 0 || !condition)
		return (ft_strdup(""));
	fill = ft_calloc(length + 1, sizeof(char));
	if (!fill)
		return (NULL);
	ft_memset(fill, c, length);
	return (fill);
}

static char	*add_half_flags(char *var, t_flag f)
{
	char	*front;
	char	*prefix;
	char	*zero;
	char	*ret;

	front = fill_width(var, f.width, ' ', !f.minus && !f.zero);
	if (!front)
		return (NULL);
	prefix = get_prefix(f);
	if (!prefix)
		return (NULL);
	zero = fill_width(var, f.width, '0', !f.minus && f.zero);
	if (!prefix)
		return (NULL);
	ret = ft_threejoin(front, prefix, zero);
	return (free(front), free(prefix), free(zero), ret);
}

char	*add_flags(const char *s, t_flag f)
{
	char	*var;
	char	*back;
	char	*ret;
	char	*tmp;

	var = get_var(s, f);
	if (!var)
		return (NULL);
	back = fill_width(var, f.width, ' ', f.minus);
	if (!back)
		return (NULL);
	tmp = add_half_flags(var, f);
	ret = ft_threejoin(tmp, var, back);
	free(tmp);
	free(var);
	free(back);
	return (ret);
}
