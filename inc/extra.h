/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:28:32 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/02 13:56:42 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRA_H
# define EXTRA_H

# include <stddef.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnjoin(const char *s1, const char *s2, size_t n);
char	*ft_threejoin(char const *s1, const char *s2, char const *s3);

char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

size_t	ft_base_longlen(size_t n, size_t base);
size_t	ft_longlen(size_t n);
size_t	ft_base_nbrlen(int n, int base);
size_t	ft_nbrlen(int n);

#endif
