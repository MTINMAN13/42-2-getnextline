/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:28:27 by mman              #+#    #+#             */
/*   Updated: 2023/11/09 18:39:27 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1024
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *saved_str, char *buffer);
char	*ft_line_parsed(char *current_storage);
char	*ft_overwrite_static(char *current_str);
char	*ft_read_and_append(int fd, char *saved_str);
char	*get_next_line(int fd);
#endif
