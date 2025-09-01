/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:17:13 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/01 13:57:02 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	check_strings(const char *s1, const char *s2)
{
	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (-1);
	else if (!s2)
		return (1);
	return (42);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	const int	tmp = check_strings(s1, s2);
	size_t		i;

	if (tmp != 42)
		return (tmp);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const int	tmp = check_strings(s1, s2);
	size_t		i;

	if (tmp != 42)
		return (tmp);
	i = 0;
	while (i < n)
	{
		if ((!s1[i] || !s2[i]) || s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
