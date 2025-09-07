/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:19:26 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/07 12:44:21 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_splitlen(char **split)
{
	size_t	size;

	size = 0;
	while (split && split[size])
		size++;
	return (size);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && (i < size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	j = ft_strlen(dst);
	if (j >= size)
		return (size + ft_strlen(src));
	while (src[i] && (j + 1 < size))
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (j + ft_strlen(&src[i]));
}

void	ft_reverse(char *s)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		c = s[i];
		s[i++] = s[j];
		s[j--] = c;
	}
}
