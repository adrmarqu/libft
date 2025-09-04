/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:13:27 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/04 20:56:52 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fd_printf.h"
#include "../../inc/extra.h"
#include "../../inc/memory.h"
#include <stdlib.h>

void	put_string(const char *str, t_printf *data)
{
	char	*s;
	char	*prev;
	
	prev = data->output;
	s = ft_strdup(str);
	//s = add_flags(str, data->flags);
	if (!s)
		data->error = true;
	else
	{
		data->output = ft_strjoin(prev, s);
		free(prev);
		free(s);
		if (!data->output)
			data->error = true;
	}
}

void	put_char(char c, t_printf *data)
{
	char	str[2];

	str[0] = c;
	str[1] = '\0';
	put_string(str, data);
}

void	ft_write(t_printf *data)
{
	data->length = ft_putstr_fd(data->output, data->fd);
	free(data->output);
}
