/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 17:41:04 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/07 17:44:30 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>

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

#endif
