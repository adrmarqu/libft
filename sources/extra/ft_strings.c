/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:25:34 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/02 13:57:28 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/string.h"
#include "../../inc/memory.h"
#include <stdbool.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size;

	size = ft_strlen(s);
	if (size == 0 || start > size)
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

static bool	ft_found(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (true);
		i++;
	}
	return (false);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	first;
	size_t	last;

	if (!s1 || !set)
		return (NULL);
	first = 0;
	while (s1[first] && ft_found(s1[first], set))
		first++;
	last = ft_strlen(s1);
	while (last > first && ft_found(s1[last - 1], set))
		last--;
	str = ft_calloc(last - first + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + first, last - first + 1);
	return (str);
}
