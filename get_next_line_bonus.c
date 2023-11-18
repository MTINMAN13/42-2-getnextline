/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:25:13 by mman              #+#    #+#             */
/*   Updated: 2023/11/16 21:03:24 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_b_overwrite_static(char *current_str)
{
	int		i;
	int		j;
	char	*new_stuff;

	i = 0;
	while (current_str[i] && current_str[i] != '\n')
		i++;
	if (!current_str[i])
	{
		free(current_str);
		return (NULL);
	}
	new_stuff = (char *)malloc(sizeof(char)
			* (ft_strlen(current_str) - i + 1));
	if (!new_stuff)
		return (NULL);
	i++;
	j = 0;
	while (current_str[i])
		new_stuff[j++] = current_str[i++];
	new_stuff[j] = '\0';
	free(current_str);
	return (new_stuff);
}

char	*ft_b_read_and_append(int fd, char *saved_str)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(saved_str, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		saved_str = ft_strjoin(saved_str, buffer);
	}
	free(buffer);
	return (saved_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*saved_str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved_str[fd] = ft_b_read_and_append(fd, saved_str[fd]);
	if (!saved_str[fd])
		return (NULL);
	line = ft_b_line_parsed(saved_str[fd]);
	saved_str[fd] = ft_b_overwrite_static(saved_str[fd]);
	return (line);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <fcntl.h>
// #include <unistd.h>

// int main(void)
// {
// 	int		fd1;
// 	int		fd2;
// 	char	*line;

// 	fd1 = open("test.txt", O_RDONLY);
// 	fd2 = open("tesst.txt", O_RDONLY);
// 	while ((line = get_next_line(fd1)) != NULL)
// 	{
// 	printf("%s\n", line);
// 	free(line); // Remember to free the memory allocated by get_next_line
// 	}
// 	while ((line = get_next_line(fd2)) != NULL)
// 	{
// 	printf("%s\n", line);
// 	free(line); // Remember to free the memory allocated by get_next_line
// 	}
// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }
