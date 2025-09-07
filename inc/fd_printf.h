/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:18:23 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/07 18:04:58 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FD_PRINTF_H
# define FD_PRINTF_H

# define NUMBR "0123456789abcdef"

# include "structs.h"
# include <stddef.h>

// fd_printf 

int		fd_printf(int fd, char const *s, ...);

// convert

void	convert_nbr(unsigned long n, size_t base, t_printf *data);

// flags

char	*add_flags(const char *s, t_flag f);

// output

void	write_output(t_printf *data);
void	save_string(const char *s, t_printf *data);

// parser

size_t	handle_flags(const char *s, t_printf *data);
size_t	handle_text(const char *s, t_printf *data);

// put

void	put_char(char c, t_printf *data);
void	put_str(const char *str, t_printf *data);
void	put_dir(unsigned long n, t_printf *data);
void	put_nbr(int n, t_printf *data);
void	put_unbr(unsigned int n, t_printf *data);
void	put_hex(unsigned int hex, t_printf *data);

// utils 

char	*cut_text(const char *s, int precision);
char	*add_zero(const char *s, int precision);

#endif
