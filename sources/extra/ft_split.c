/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:22:11 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/02 13:15:02 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/memory.h"
#include "../../inc/string.h"

static int	ft_count_words(const char *str, char c)
{
	int	num_words;
	int	new_word;

	num_words = 0;
	new_word = 0;
	while (*str)
	{
		if (*str != c && new_word == 0)
		{
			new_word = 1;
			num_words++;
		}
		else if (*str == c)
			new_word = 0;
		str++;
	}
	return (num_words);
}

static char	*ft_make_str(const char *str, int first, int last)
{
	char	*r;
	int		i;

	i = 0;
	r = ft_calloc((last - first + 1), sizeof(char));
	if (!r)
		return (NULL);
	while (first < last)
	{
		r[i] = str[first];
		i++;
		first++;
	}
	return (r);
}

static int	init(char const *s, int *len)
{
	if (!s)
		return (0);
	*len = (int)ft_strlen(s);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	size_t	j;
	int		index_word;
	char	**split;
	int		len;

	if (!init(s, &len))
		return (NULL);
	split = ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
	i = -1;
	j = 0;
	index_word = -1;
	while (split && ++i <= len)
	{
		if (s[i] != c && index_word < 0)
			index_word = i;
		else if ((s[i] == c || i == len) && index_word >= 0)
		{
			split[j] = ft_make_str(s, index_word, i);
			if (!split[j++])
				return (ft_free_split(split), NULL);
			index_word = -1;
		}
	}
	return (split);
}
