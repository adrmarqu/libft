/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:18:23 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/02 14:53:41 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FD_PRINTF_H
# define FD_PRINTF_H

# define NUMBR "0123456789abcdef"

# include <stdbool.h>

/*

   % -> c s p d i u x X %

   ' ': d i
   '.': s d i u x X
   '#': x X
   '-': all
   '0': d i u x X; si esta '-' no funciona
   '+': d i

   Combinations

   "0-": Se ignora 0
   "+ ": Se ignora ' '
   "0.": Se ignora el width ej: %08.5d(42) -> "   00042"
   "+ 0#": Estos flags con %cs se ignoran

*/

typedef struct s_flag
{
	bool	left;
	bool	zero;
	int		precision;
	bool	alternative;
	bool	space;
	bool	sign;
}	t_flag;

typedef struct s_format
{
	t_flag	flags;
	int		width;
	char	type;
	int		fd;
	int		length;
	bool	error;
}	t_format;

int	fd_printf(int fd, char const *s, ...);

#endif
