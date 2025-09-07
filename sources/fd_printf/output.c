/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 17:39:38 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/07 18:07:10 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/structs.h"
#include "../../inc/extra.h"
#include "../../inc/memory.h"
#include "../../inc/fd_printf.h"
#include <stdlib.h>

void	write_output(t_printf *data)
{
	data->length = ft_putstr_fd(data->output, data->fd);
	free(data->output);
}

void	save_string(const char *s, t_printf *data)
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
