/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:25:59 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/02 12:19:51 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/memory.h"
#include "../../inc/string.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*str;

	if (!s || !f)
		return (NULL);
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		str[i] = f(i, str[i]);
		i++;
	}
	return (str);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;
	size_t	len;

	if (!s || !f)
		return ;
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}
