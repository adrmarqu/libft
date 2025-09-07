/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:18:23 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/07 16:53:16 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FD_PRINTF_H
# define FD_PRINTF_H

# define NUMBR "0123456789abcdef"

# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>

typedef struct s_flag
{
	bool	minus;
	bool	zero;
	bool	alter;
	bool	space;
	bool	sign;
	char	symbol_sign;
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
void	put_str(const char *str, t_printf *data);
void	put_dir(unsigned long n, t_printf *data);
void	put_nbr(int n, t_printf *data);
void	put_unbr(unsigned int n, t_printf *data);
void	put_hex(unsigned int n, t_printf *data);

void	put_string(const char *str, t_printf *data);
void	ft_write(t_printf *data);

#endif
