/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:50:16 by mman              #+#    #+#             */
/*   Updated: 2023/11/08 18:41:13 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *saved_str, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!saved_str)
	{
		saved_str = (char *)malloc(1 * sizeof(char));
		saved_str[0] = '\0';
	}
	if (!saved_str || !buffer)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(saved_str)
					+ ft_strlen(buffer)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (saved_str)
		while (saved_str[++i] != '\0')
			str[i] = saved_str[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[ft_strlen(saved_str) + ft_strlen(buffer)] = '\0';
	free(saved_str);
	return (str);
}

char	*ft_line_parsed(char *current_storage)
{
	int		i;
	char	*line;

	i = 0;
	if (!current_storage[i])
		return (NULL);
	while (current_storage[i] && current_storage[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (current_storage[i] && current_storage[i] != '\n')
	{
		line[i] = current_storage[i];
		i++;
	}
	if (current_storage[i] == '\n')
	{
		line[i] = current_storage[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
