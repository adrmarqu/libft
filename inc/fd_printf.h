/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:18:23 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/04 20:51:08 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FD_PRINTF_H
# define FD_PRINTF_H

# define NUMBR "0123456789abcdef"

# include <stdbool.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdio.h>

/*

   %[flags][width][.precision][length]specifier

   length -> ll, l, h... ej: %lld

d, i → enteros con signo.

u → enteros sin signo.

x, X → hexadecimal (minúsculas/mayúsculas).

o → octal.

f, F → coma flotante (ej: 3.14).

e, E → notación científica (1.23e+02).

g, G → elige entre %f o %e.

c → un carácter.

s → string (char *).

p → puntero (dirección en memoria).

% → imprime % literal.


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
	bool	minus;
	bool	zero;
	bool	alter;
	bool	space;
	bool	sign;
	int		precision;
	int		width;
	char	specifier;
}	t_flag;

typedef struct s_printf
{
	int		fd;
	bool	error;
	char	*output;
	int		length;
	t_flag	flags;
}	t_printf;

int		fd_printf(int fd, char const *s, ...);

void	handle_format(va_list lst, t_printf *data);
size_t	handle_flags(const char *s, t_printf *data);
size_t	handle_text(const char *s, t_printf *data);

size_t	get_flags(const char *s, t_flag *flags);
size_t	get_width(const char *s, t_flag *flags);
size_t	get_precision(const char *s, t_flag *flags);
void	nullify_flags(t_flag *f);

void	put_char(char c, t_printf *data);
void	put_string(const char *str, t_printf *data);
void	put_dir(unsigned long n, t_printf *data);
void	put_nbr(int n, t_printf *data);
void	put_unbr(unsigned int n, t_printf *data);
void	put_hex(unsigned int n, t_printf *data);

void	ft_write(t_printf *data);

#endif
