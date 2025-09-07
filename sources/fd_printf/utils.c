/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 17:38:03 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/07 18:08:49 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/memory.h"
#include "../../inc/string.h"

static char	*fill_zeros(char *ret, const char *s, int n)
{
	size_t	i;
	size_t	length;

	i = 0;
	length = n - ft_strlen(s);
	while (i < length)
		ret[i++] = '0';
	length = ft_strlen(s);
	while (length)
	{
		ret[i++] = *s;
		s++;
		length--;
	}
	return (ret);
}

char	*add_zero(const char *s, int precision)
{
	char	*ret;

	if (precision > (int)ft_strlen(s))
	{
		ret = ft_calloc(ft_strlen(s) + precision + 1, sizeof(char));
		if (!ret)
			return (NULL);
		return (fill_zeros(ret, s, precision));
	}
	return (ft_strdup(s));
}

char	*cut_text(const char *s, int precision)
{
	char	*ret;
	int		i;

	if (precision > (int)ft_strlen(s))
		return (ft_strdup(s));
	ret = ft_calloc(precision + 1, sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < precision)
	{
		ret[i] = s[i];
		i++;
	}
	return (ret);
}
