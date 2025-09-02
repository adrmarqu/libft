/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:56:04 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/02 14:08:48 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/memory.h"
#include "../../inc/string.h"
#include <stdlib.h>

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
	return (free(a), b);
}

char	*ft_strnjoin(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*s;

	if (!s1 && !s2)
		return (NULL);
	else if (!s2)
		return (ft_strdup(s1));
	s = ft_calloc(ft_strlen(s1) + n + 1, sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < n)
		s[i++] = s2[j++];
	return (s);
}
