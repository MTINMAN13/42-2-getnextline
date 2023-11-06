/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:28:32 by mman              #+#    #+#             */
/*   Updated: 2023/11/06 19:27:10 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// BONUS ONE * Implementing get_next_line() using only one static variable.
// BONUS DUO * Ensure that get_next_line() can manage multiple file descriptors
//             simultaneously, allowing for reading from different file descrip-
//             tors without losing the reading context of each file descriptor
//             or returning a line from another file descriptor. array[A][1]

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 69

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	char	*dupe;
	size_t	i;

	dupe = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (dupe == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (str[i] != '\0')
	{
		dupe[i] = str[i];
		i++;
	}
	dupe[i] = '\0';
	return (dupe);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*temp;
	char	*result;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = (char *)malloc(len_s1 + len_s2 + 1);
	temp = result;
	if (!result)
		return (NULL);
	if (s1)
		while (*s1)
			*result++ = *s1++;
	if (s2)
		while (*s2)
			*result++ = *s2++;
	*result = '\0';
	free (s1);
	return (temp);
}

// i want to read until ft_strchr(swap, '/n'); doesnt return NULL.
char	*ft_read_raw(int fd)
{
	char	*swap;
	ssize_t	bytes_read;

	swap = (char *)malloc(BUFFER_SIZE + 1);
	if (swap == NULL)
	return (NULL);
	bytes_read = read(fd, swap, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		free(swap);
		return (NULL);
	}
	swap[bytes_read] == '\0';
	return (swap);
}

char	*ft_update_static_str(char str, int fd)
{
	char	*temporary_storage;
	while (ft_strchr(str, '/n') == NULL)
	{
		temporary_storage = ft_read_raw(fd);
		str = ft_strjoin(str, temporary_storage);
			if (ft_strlen(temporary_storage) < BUFFER_SIZE)
				{
					free(temporary_storage);
					return(str);
				}
		free(temporary_storage);
	}
}

// i want to dupe the part from first byte up until /n into the line which is
// returned
// it should not include the terminating /n character
char	*ft_return_line(char *raw_mess)
{
	char	*swap;
	char	*line_start;

	line_start = raw_mess;
	swap = line_start;
	while (*raw_mess != '/n' && *raw_mess != '\n')
	{
		*swap = *raw_mess;
		raw_mess++;
		swap++;
	}
	if (*raw_mess == '\n') {
		*swap = *raw_mess;
		raw_mess++;
		swap++;
	}
	*swap = '\0';
	if (*line_start == '\0')
		return (NULL);
	return (line_start);
}

// i want to remove the first line and reallocate the next line at the start
// i want it to end with
char	*ft_clean_line(char raw_mess)
{

}
