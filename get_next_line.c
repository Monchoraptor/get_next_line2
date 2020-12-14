/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoracho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:57:49 by amoracho          #+#    #+#             */
/*   Updated: 2020/12/14 04:22:52 by amoracho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*load_in_cache(char *cache, char *buf, int bytes_read)
{
	char *new_cache;

	if (cache)
		new_cache = ft_strjoin(cache, buf);
	else
		return (ft_strdup(buf));
	free(cache);
	return (new_cache);
}

int		count_line(char *cache)
{
	int	i;

	i = 0;
	while ((cache[i] != '\n') && (cache[i] != '\0'))
		i++;
	if (cache[i] == '\n')
		return (i);
	return (i * -1);
}

int		get_empty(char **line)
{
	int i;

	i = 0;
	while (line[i] != 0)
		i++;
	return (i);
}

char	*extract_one_line(char **line, char *cache)
{
	char *aux;

	if (count_line(cache) > 0)
	{
		line[get_empty(line)] = ft_substr(cache, 0, count_line(cache));
		aux = ft_substr(cache, count_line(cache) + 1, ft_strlen(cache));
		free(cache);
		cache = aux;
		return (cache);
	}
	else
	{
		line[get_empty(line)] = ft_strdup(cache);
		free(cache);
		return ("");
	}
}

int		get_next_line(int fd, char **line)
{
	static char *cache;
	char		*buf;
	ssize_t		bytes_read;

	buf = malloc((sizeof(char) * BUFFER_SIZE) + 1);
	while (bytes_read = read(fd, buf, BUFFER_SIZE))
	{
		buf[bytes_read] = '\0';
		cache = load_in_cache(cache, buf, bytes_read);
	}
	free(buf);
	cache = extract_one_line(line, cache);
	if (ft_strlen(cache) > 0)
		return (1);
	return (0);
}
