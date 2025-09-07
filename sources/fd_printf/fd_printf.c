/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:20:00 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/07 15:07:44 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fd_printf.h"
#include "../../inc/extra.h"
#include "../../inc/memory.h"
#include "../../inc/string.h"
#include "../../inc/ctype.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

size_t	get_flags(const char *s, t_flag *flags)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '0')
			flags->zero = true;
		else if (s[i] == '-')
			flags->minus = true;
		else if (s[i] == ' ')
			flags->space = true;
		else if (s[i] == '#')
			flags->alter = true;
		else if (s[i] == '+')
			flags->sign = true;
		else
			break ;
		i++;
	}
	return (i);
}

size_t	get_width(const char *s, t_flag *flags)
{
	size_t	len;

	len = 0;
	while (s[len] && ft_isdigit(s[len]))
	{
		flags->width = flags->width * 10 + (s[len] - '0');
		len++;
	}
	return (len);
}

size_t	get_precision(const char *s, t_flag *flags)
{
	size_t	len;

	len = 0;
	if (s[len++] != '.')
		return (0);
	while (s[len] == '.')
		len++;
	flags->precision = 0;
	while (s[len] && ft_isdigit(s[len]))
	{
		flags->precision = flags->precision * 10 + (s[len] - '0');
		len++;
	}
	return (len);
}

void	nullify_flags(t_flag *f)
{
	if (f->minus)
		f->zero = false;
	if (f->sign)
		f->space = false;
}

size_t	handle_flags(const char *s, t_printf *data)
{
	size_t	len;

	len = 1;
	len += get_flags(s + 1, &data->flags);
	len += get_width(s + len, &data->flags);
	len += get_precision(s + len, &data->flags);
	data->flags.specifier = s[len++];
	nullify_flags(&data->flags);
	return (len);
}

char	get_char(unsigned long n, char x)
{
	char	c;

	c = NUMBR[n];
	if (x == 'X' && n >= 10)
		c -= 32;
	return (c);
}

void	convert_nbr(unsigned long n, size_t base, t_printf *data)
{
	int		i;
	char	*nbr;

	nbr = ft_calloc(ft_base_longlen(n, base) + 1, sizeof(char));
	if (!nbr)
	{
		data->error = true;
		return ;
	}
	i = 0;
	while (n >= base)
	{
		nbr[i++] = get_char(n % base, data->flags.specifier);
		n /= base;
	}
	nbr[i] = get_char(n, data->flags.specifier);
	ft_reverse(nbr);
	put_string(nbr, data);
}

void	put_nbr(int n, t_printf *data)
{
	long int	aux;

	data->flags.alter = false;
	if (data->flags.precision != -1)
		data->flags.zero = false;
	aux = (long int)n;
	if (aux >= INT_MIN && aux <= INT_MAX)
	{
		if (aux < 0)
		{
			data->flags.sign = true;
			data->flags.symbol_sign = '-';
			data->flags.space = false;
			aux = -aux;
		}
		else
			if (data->flags.sign)
				data->flags.symbol_sign = '+';
		if (data->flags.sign || data->flags.space)
			data->flags.width--;
		convert_nbr((unsigned long)aux, 10, data);
	}
}

void	put_unbr(unsigned int n, t_printf *data)
{
	data->flags.space = false;
	data->flags.alter = false;
	data->flags.sign = false;
	if (data->flags.precision != -1)
		data->flags.zero = false;
	convert_nbr((unsigned long)n, 10, data);
}

void	put_hex(unsigned int hex, t_printf *data)
{
	data->flags.space = false;
	data->flags.sign = false;
	if (data->flags.precision != -1)
		data->flags.zero = false;
	if (hex == 0)
		data->flags.alter = false;
	if (data->flags.alter)
		data->flags.width -= 2;
	convert_nbr((unsigned long)hex, 16, data);
}

void	put_dir(unsigned long p, t_printf *data)
{
	data->flags.precision = -1;
	data->flags.alter = true;
	data->flags.width -= 2;
	convert_nbr(p, 16, data);
}

void	handle_format(va_list lst, t_printf *data)
{
	const int	type = data->flags.specifier;

	if (type == '%')
		put_char('%', data);
	else if (type == 'c')
		put_char(va_arg(lst, int), data);
	else if (type == 's')
		put_str(va_arg(lst, char *), data);
	else if (type == 'p')
		put_dir(va_arg(lst, unsigned long), data);
	else if (type == 'd' || type == 'i')
		put_nbr(va_arg(lst, int), data);
	else if (type == 'u')
		put_unbr(va_arg(lst, unsigned int), data);
	else if (type == 'x' || type == 'X')
		put_hex(va_arg(lst, unsigned int), data);
	else
		data->error = 1;
}

size_t	handle_text(const char *s, t_printf *data)
{
	char	*str;
	char	*tmp;
	size_t	len;

	len = 0;
	while (s[len] && s[len] != '%')
		len++;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
	{
		data->error = true;
		return (0);
	}
	ft_strlcpy(str, s, len + 1);
	tmp = data->output;
	data->output = ft_strjoin(tmp, str);
	return (free(tmp), free(str), len);
}

char	*set_zero(char *ret, const char *s, int n)
{
	size_t	i;
	size_t	length;

	i = 0;
	length = n - ft_strlen(s);
	while (i < length)
		ret[i++] = '0';
	length = ft_strlen(s);
	while (length)
	{
		ret[i++] = *s;
		s++;
		length--;
	}
	return (ret);
}

char	*add_zero(const char *s, int n)
{
	char	*ret;

	if (n > (int)ft_strlen(s))
	{
		ret = ft_calloc(ft_strlen(s) + n + 1, sizeof(char));
		if (!ret)
			return (NULL);
		return (set_zero(ret, s, n));
	}
	return (ft_strdup(s));

}

char	*cut_text(const char *s, int n)
{
	char	*ret;
	int		i;

	if (n > (int)ft_strlen(s))
		return (ft_strdup(s));
	ret = ft_calloc(n + 1, sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < n)
	{
		ret[i] = s[i];
		i++;
	}
	return (ret);
}

char	*add_front(char *str, char c, int width)
{
	char	*front;
	char	*ret;
	size_t	length;
	size_t	i;

	length = width - ft_strlen(str);
	front = ft_calloc(length + 1, sizeof(char));
	if (!front)
		return (free(str), NULL);
	i = 0;
	while (i < length)
		front[i++] = c;
	ret = ft_strjoin(front, str);
	return (free(front), free(str), ret);
}

char	*get_var(const char *s, t_flag f)
{
	char	*var;

	if (f.precision == -1)
		var = ft_strdup(s);
	else if (f.precision != -1 && f.specifier == 's')
		var = cut_text(s, f.precision);
	else
		var = add_zero(s, f.precision);
	return (var);
}

char	*get_front(const char *var, t_flag f)
{
	int		length;
	char	*front;

	length = f.width - (int)ft_strlen(var);
	if (length <= 0 || f.minus || f.zero)
		return (ft_strdup(""));
	front = ft_calloc(length + 1, sizeof(char));
	if (!front)
		return (NULL);
	ft_memset(front, ' ', length);
	return (front);
}

char	*get_prefix(t_flag f)
{
	if (f.sign)
		return (ft_char_to_string(f.symbol_sign));
	if (f.space)
		return (ft_strdup(" "));
	if (f.alter && f.specifier == 'X')
		return (ft_strdup("0X"));
	if (f.alter)
		return (ft_strdup("0x"));
	return (ft_strdup(""));
}

char	*get_zero(const char *var, t_flag f)
{
	int		length;
	char	*zero;

	length = f.width - (int)ft_strlen(var);
	if (length <= 0 || !f.zero || f.minus)
		return (ft_strdup(""));
	zero = ft_calloc(length + 1, sizeof(char));
	if (!zero)
		return (NULL);
	ft_memset(zero, '0', length);
	return (zero);
}

char	*get_back(const char *var, t_flag f)
{
	int		length;
	char	*back;

	length = f.width - (int)ft_strlen(var);
	if (length <= 0 || !f.minus)
		return (ft_strdup(""));
	back = ft_calloc(length + 1, sizeof(char));
	if (!back)
		return (NULL);
	ft_memset(back, ' ', length);
	return (back);
}

// [front][sign/space/alter][zero][var(with precision)][back]

char	*add_flags(const char *s, t_flag f)
{
	char	*front;
	char	*prefix;
	char	*zero;
	char	*var;
	char	*back;
	char	*ret;

	var = get_var(s, f);
	if (!var)
		return (NULL);
	front = get_front(var, f);
	if (!front)
		return (NULL);
	prefix = get_prefix(f);
	if (!prefix)
		return (NULL);
	zero = get_zero(var, f);
	if (!prefix)
		return (NULL);
	back = get_back(var, f);
	if (!back)
		return (NULL);

	printf("FRONT: |%s|\n", front);
	printf("PREFIX: |%s|\n", prefix);
	printf("ZERO: |%s|\n", zero);
	printf("VAR: |%s|\n", var);
	printf("BACK: |%s|\n", back);

	// Juntarlo
	


	return (NULL);
}

void	put_string(const char *s, t_printf *data)
{
	char	*prev;
	char	*str;
	char	*final;

	prev = data->output;
	str = ft_strdup(s);
	final = add_flags(str, data->flags);
	free(str);
	if (!final)
		data->error = true;
	else
	{
		data->output = ft_strjoin(prev, final);
		free(prev);
		free(final);
		if (!data->output)
			data->error = true;
	}
}

void	put_char(char c, t_printf *data)
{
	char	str[2];

	data->flags.precision = -1;
	data->flags.space = false;
	data->flags.sign = false;
	data->flags.zero = false;
	data->flags.alter = false;
	str[0] = c;
	str[1] = '\0';
	put_string(str, data);
}

void	put_str(const char *str, t_printf *data)
{
	data->flags.space = false;
	data->flags.sign = false;
	data->flags.zero = false;
	data->flags.alter = false;
	put_string(str, data);
}

void	ft_write(t_printf *data)
{
	data->length = ft_putstr_fd(data->output, data->fd);
	free(data->output);
}

static void	ft_read(va_list lst, t_printf *data, const char *s)
{
	while (*s && !data->error)
	{
		if (*s == '%')
		{
			if (!s[1])
				return ;
			s += handle_flags(s, data);
			handle_format(lst, data);
		}
		else
			s += handle_text(s, data);
	}
}

static void	init_struct(t_printf *data, int fd)
{
	t_flag	flags;

	flags.minus = false;
	flags.zero = false;
	flags.alter = false;
	flags.space = false;
	flags.sign = false;
	flags.symbol_sign = '0';
	flags.precision = -1;
	flags.width = 0;
	flags.specifier = '0';
	data->fd = fd;
	data->error = false;
	data->output = NULL;
	data->length = 0;
	data->flags = flags;
}

int	fd_printf(int fd, const char *s, ...)
{
	va_list		lst;
	t_printf	data;

	if (fd < 0 || !s || fd > FOPEN_MAX)
		return (-1);
	va_start(lst, s);
	init_struct(&data, fd);
	ft_read(lst, &data, s);
	va_end(lst);
	ft_write(&data);
	if (data.error)
		return (-1);
	return (data.length);
}
