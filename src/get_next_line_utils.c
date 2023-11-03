/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:28:27 by mman              #+#    #+#             */
/*   Updated: 2023/10/29 19:28:28 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>

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
