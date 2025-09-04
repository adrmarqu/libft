/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:26:25 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/04 20:53:11 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/string.h"
#include "../../inc/extra.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (write(fd, "(null)", 6));
	return (write(fd, s, ft_strlen(s)));
}

int	ft_putendl_fd(char *s, int fd)
{
	int	len;

	len = ft_putstr_fd(s, fd);
	if (len == -1)
		return (-1);
	if (write(fd, "\n", 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_putnbr_fd(int n, int fd)
{
	char	*nbr;
	int		len;

	nbr = ft_itoa(n);
	len = ft_putstr_fd(nbr, fd);
	return (free(nbr), len);
}
