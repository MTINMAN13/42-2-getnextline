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
