/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:21:21 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/09/07 17:15:04 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"
#include "../../inc/memory.h"
#include "../../inc/extra.h"
#include "../../inc/string.h"
#include <unistd.h>
#include <stdlib.h>

static char	*read_line(int fd, char *s)
{
	char	*buffer;
	char	*tmp;
	int		n;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	n = 1;
	while (n > 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n < 0)
			return (free(buffer), NULL);
		tmp = s;
		s = ft_strnjoin(tmp, buffer, n);
		free(tmp);
		if (ft_memchr(buffer, '\n', n))
			break ;
	}
	return (free(buffer), s);
}

static char	*clean_line(char *s)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	if (s[i] && s[i] == '\n')
		str[i++] = '\n';
	return (str);
}

static char	*get_next_buffer(char *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
		return (free(s), NULL);
	str = ft_calloc(ft_strlen(s) - i + 1, sizeof(char));
	if (!str)
		return (NULL);
	j = 0;
	i++;
	while (s[i])
		str[j++] = s[i++];
	return (free(s), str);
}

char	*get_next_line(int fd)
{
	static char	*buffer[300];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_calloc(1, 1);
	buffer[fd] = read_line(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = clean_line(buffer[fd]);
	buffer[fd] = get_next_buffer(buffer[fd]);
	return (line);
}
