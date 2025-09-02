/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:28:01 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/02 12:59:53 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/memory.h"
#include "../../inc/extra.h"
#include <limits.h>

static size_t	is_negative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static char	*convert_number(char *s, int n, size_t len, int sign)
{
	int	i;

	i = (int)len - 1;
	while (i >= 0)
	{
		s[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	if (sign)
		s[0] = '-';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	size_t	len;
	int		sign;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	sign = 0;
	if (is_negative(n))
	{
		n = -n;
		sign = 1;
	}
	len = ft_nbrlen(n) + sign;
	nbr = ft_calloc(len + 1, sizeof(char));
	if (!nbr)
		return (NULL);
	return (convert_number(nbr, n, len, sign));
}
