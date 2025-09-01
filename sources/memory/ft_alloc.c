/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:58:13 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/01 14:22:40 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/memory.h"
#include "../../inc/string.h"
#include <stdlib.h>
#include <stdint.h>

void	ft_free_split(char **split)
{
	size_t	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	if (nmemb && size && nmemb > SIZE_MAX / size)
		return (NULL);
	total = nmemb * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total);
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

char	**ft_splitdup(char **split)
{
	char	**ret;
	size_t	len;
	size_t	i;

	if (!split)
		return (NULL);
	len = ft_splitlen(split);
	ret = ft_calloc(len + 1, sizeof(char *));
	if (!ret)
		return (NULL);
	i = 0;
	while (split[i])
	{
		ret[i] = ft_strdup(split[i]);
		if (!ret[i])
			return (ft_free_split(ret), NULL);
		i++;
	}
	return (ret);
}
