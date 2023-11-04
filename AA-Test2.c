/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AA-Test2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:28:27 by mman              #+#    #+#             */
/*   Updated: 2023/11/04 19:23:46 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define BUFFER_SIZE 128

size_t	ft_strlen(const char *s)
{
	size_t i = 0;
	while (s[i])
		i++;
	return i;
}

char *ft_strrchr(const char *s, int c)
{
	int s_len;
	const char *end;

	s_len = ft_strlen(s);
	end = s + s_len - 1;
	if (c == '\0')
		return (char *)s + s_len;
	while (end >= s)
	{
		if (*end == (char)c)
			return (char *)end;
		end--;
	}
	return NULL;
}

char *ft_strjoin(char *s1, char *s2)
{
	size_t len_s1 = ft_strlen(s1);
	size_t len_s2 = ft_strlen(s2);
	char *temp;
	char *result;

	result = (char *)malloc(len_s1 + len_s2 + 1);
	temp = result;
	if (!result)
		return NULL;
	if (s1)
		while (*s1)
			*result++ = *s1++;
	if (s2)
		while (*s2)
			*result++ = *s2++;
	*result = '\0';
	free(s1);
	return temp;
}

char *ft_newline_parser(char *available_text)
{
	int		i = 0;
	int		j;
	char	*parsed_line;

	while (available_text[i] && available_text[i] != '\n')
		i++;
	if (!available_text[i])
	{
		free(available_text);
		return NULL;
	}
	parsed_line = (char *)malloc(sizeof(char) * (ft_strlen(available_text) - i + 1));
	if (!parsed_line)
		return NULL;
	i++;
	j = 0;
	while (available_text[i])
		parsed_line[j++] = available_text[i++];
	parsed_line[j] = '\0';
	free(available_text);
	return parsed_line;
}

char *ft_overwrite_static(char *whatever)
{
	int i = 0;
	int j;
	char *new_return;

	while (whatever[i] && whatever[i] != '\n')
		i++;
	if (!whatever[i])
	{
		free(whatever);
		return NULL;
	}
	new_return = (char *)malloc(sizeof(char) * (ft_strlen(whatever) - i + 1));
	if (!new_return)
		return NULL;
	i++;
	j = 0;
	while (whatever[i])
		new_return[j++] = whatever[i++];
	new_return[j] = '\0';
	free(whatever);
	return new_return;
}

char *get_next_line(int fd)
{
	static char		*whatever;
	char			*produced_line;
	static int		first_call = 1;

	if (first_call)
	{
		first_call = 0;
		whatever = ft_strjoin("", ""); // Initialize whatever
	}
	else if (fd < 0 || BUFFER_SIZE < 0)
		return NULL;
	whatever = ft_overwrite_static(produced_line);
	return ft_newline_parser(whatever);
}

int main(void)
{
	int fd = open("example.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	return 0;
}
