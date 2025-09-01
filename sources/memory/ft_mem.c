/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:47:19 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/01 13:53:57 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest || !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (src == dest || n == 0)
		return (dest);
	if (src > dest)
		return (ft_memcpy(dest, src, n));
	else if (src < dest)
	{
		while (n > 0)
		{
			((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
			n--;
		}
	}
	return (dest);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned const char	*mem;

	if (!s)
		return (NULL);
	i = 0;
	mem = (unsigned const char *)s;
	while (i < n)
	{
		if (mem[i] == (unsigned char)c)
			return ((void *)&mem[i]);
		i++;
	}
	return (NULL);
}

void	*ft_memrchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned const char	*mem;
	unsigned const char	*last;

	if (!s)
		return (NULL);
	i = 0;
	last = NULL;
	mem = (unsigned const char *)s;
	while (i < n)
	{
		if (mem[i] == (unsigned char)c)
			last = &mem[i];
		i++;
	}
	return ((void *)last);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (a[i] != b[i])
			return ((int)(a[i] - b[i]));
		i++;
	}
	return (0);
}
