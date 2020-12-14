/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoracho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:57:14 by amoracho          #+#    #+#             */
/*   Updated: 2020/12/13 17:57:33 by amoracho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char 	*load_in_cache(char *cache, char *buf, int bytes_read);
int 	count_line(char *cache);
int		get_empty(char **line);
char	*extract_one_line(char **line, char *cache);
int		get_next_line(int fd, char **line);
int		ft_strlen(const char *s);
char	*ft_strdup(char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);

#endif
