/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctype.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:42:10 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/08/30 17:43:49 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTYPE_H
# define CTYPE_H

# include <stdbool.h>

bool	ft_isalpha(int c);
bool	ft_isdigit(int c);
bool	ft_isalnum(int c);
bool	ft_isspace(int c);
bool	ft_isxdigit(int c);
bool	ft_isascii(int c);
bool	ft_isprint(int c);
bool	ft_isupper(int c);
bool	ft_islower(int c);
bool	ft_isgraph(int c);

#endif
