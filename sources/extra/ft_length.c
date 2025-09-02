/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:28:42 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/02 13:15:23 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_base_longlen(size_t n, size_t base)
{
	size_t	size;

	size = 1;
	while (n >= base)
	{
		n = n / base;
		size++;
	}
	return (size);
}

size_t	ft_longlen(size_t n)
{
	size_t	size;

	size = 1;
	while (n >= 10)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

size_t	ft_base_nbrlen(int n, int base)
{
	size_t	size;

	if (base < 0)
		return (0);
	size = 1;
	while (n >= base || n <= -base)
	{
		n = n / base;
		size++;
	}
	return (size);
}

size_t	ft_nbrlen(int n)
{
	size_t	size;

	size = 1;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		size++;
	}
	return (size);
}
