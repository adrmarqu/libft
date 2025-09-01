/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:19:41 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/01 13:52:18 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

bool	ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}

bool	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

bool	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

bool	ft_isgraph(int c)
{
	return (c >= '!' && c <= '~');
}
