/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alphanum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:18:08 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/08/30 17:29:20 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

bool	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

bool	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

bool	ft_isspace(int c)
{
	return (c == ' ');
}

bool	ft_isxdigit(int c)
{
	return (ft_isdigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'));
}
