/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:28:32 by mman              #+#    #+#             */
/*   Updated: 2023/10/31 19:10:21 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// BONUS ONE * Implementing get_next_line() using only one static variable.
// BONUS DUO * Ensure that get_next_line() can manage multiple file descriptors
//             simultaneously, allowing for reading from different file descrip-
//             tors without losing the reading context of each file descriptor
//             or returning a line from another file descriptor. array[A][1]

int BUFFER_SIZE = 1;

#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int			s_len;
	const char	*end;

	s_len = ft_strlen(s);
	end = s + s_len - 1;
	if (c == '\0')
		return ((char *)s + s_len);
	while (end >= s)
	{
		if (*end == (char)c)
			return ((char *)end);
		end--;
	}
	return (NULL);
}

// char	*ft_strdup(const char *str)
// {
// 	char	*dupe;
// 	size_t	i;

// 	dupe = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
// 	if (dupe == NULL)
// 	{
// 		return (NULL);
// 	}
// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		dupe[i] = str[i];
// 		i++;
// 	}
// 	dupe[i] = '\0';
// 	return (dupe);
// }

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

char	*ft_newline_parser(char *available_text)
{
	int		i;
	int		j;
	char	*parsed_line;

	i = 0;
	while (available_text[i] && available_text[i] != '\n')
		i++;
	if (!available_text[i])
	{
		free(available_text);
		return (NULL);
	}
	parsed_line = (char *)malloc(sizeof(char) * (ft_strlen(available_text) - i + 1));
	if (!parsed_line)
		return (NULL);
	i++;
	j = 0;
	while (available_text[i])
		parsed_line[j++] = available_text[i++];
	parsed_line[j] = '\0';
	free(available_text);
	return (parsed_line);
}

char	*ft_overwrite_buffer(char *whatever)
{
	int		i;
	int		j;
	char	*new_left_str;

	i = 0;
	while (whatever[i] && whatever[i] != '\n')
		i++;
	if (!whatever[i])
	{
		free(whatever);
		return (NULL);
	}
	new_left_str = (char *)malloc(sizeof(char)
			* (ft_strlen_v(whatever) - i + 1));
	if (!new_left_str)
		return (NULL);
	i++;
	j = 0;
	while (whatever[i])
		new_left_str[j++] = whatever[i++];
	new_left_str[j] = '\0';
	free(whatever);
	return (new_left_str);
}

char	*add_one_raw_line(int fd, char *prev_line)
{
	char	*temp;
	int		bytes_read;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	bytes_read = 1;
	while (!ft_strrchr(prev_line, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[bytes_read] = '\0';
		prev_line = ft_strjoin(prev_line, temp);
	}
	free(temp);
	return (prev_line);
}

char	*get_next_line(int fd)
{
	static char		*whatever;
	char			*produced_line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	whatever = add_one_raw_line(fd, whatever);
	if (!whatever)
		return (NULL);
	produced_line = ft_newline_parser(whatever);
	whatever = ft_overwrite_buffer(produced_line);
	return (produced_line);
}

// So i WANT TO SOMEHOW PASS IN THE BUFFER_SIZE from my compiler call
// A; by ifndef we set default
// I will Compile like this
//
//cc -Wall -Wextra -Werror -D Buffer_Size=42 <files>.c


// Always remember ERROR HANDLING

// I want to RETURN the VALUE / LINE which WAS READ
// malloc gon happen
// free gon happen when itl be supposed to
// maybe in a separate function (handler)

// we want to work on two options, as i might
// skip over the /n
// as cant directly influence the buffer size
// so we will always have to back track (unless 1 is the value)

// - 00 - i will probably want to recode things like strrchr
// as I want a thing which will locate the line end
// -- 01 -- i want a function which will allocate the memory necessary to
// accomplish this shit
// -- 02 -- i want a function which moves the Buffer (USED FOR LINE LOCATOR UP and DOWN)
//

// as we have read(fd, buffer, sizeof(Buffer_Size));
// we probably want to have the ?? array as the buffer ??
// -- or -- we want to have what

// and how the FUCK do we want to start reading the next fucking line tho
// where do we even pass that shit in

// we want to read text --> check for next line --> if no, repeat - if yes, close out the cycle.
//

//
