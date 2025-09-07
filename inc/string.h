/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:45:44 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/07 12:44:43 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include <stddef.h>

size_t		ft_strlen(const char *s);
size_t		ft_splitlen(char **split);

size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);

void		ft_reverse(char *s);

char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *big, const char *little, size_t len);

int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

int			ft_atoi(const char *nptr);
long		ft_atol(const char *nptr);
long long	ft_atoll(const char *nptr);
int			ft_atoi_overflow(const char *nptr, int *error);

#endif
