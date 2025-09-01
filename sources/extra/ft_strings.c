/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:25:34 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/01 14:51:52 by adrmarqu         ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	join = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
		join[i++] = s2[j++];
	return (join);
}

char	*ft_threejoin(char const *s1, const char *s2, char const *s3)
{
	char	*a;
	char	*b;

	a = ft_strjoin(s1, s2);
	if (!a)
		return (NULL);
	b = ft_strjoin(a, s3);
	free(a);
	return (b);
}
