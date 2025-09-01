/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:17:59 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/01 12:43:19 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/string.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	if (!s)
		return (NULL);
	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = s;
		s++;
	}
	if (!*s && *s == (char)c)
		last = s;
	return ((char *)last);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int const	len_lit = ft_strlen(little);
	unsigned int		i;
	unsigned int		j;

	if (len_lit == 0)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len && j < len_lit)
			j++;
		if (j == len_lit)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
