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

#include <unistd.h>

#ifndef Buffer_Size
#define Buffer_Size 1024  // Default buffer size
# endif

char	*get_next_line(int fd)
{
	static int	**line_counter;

	read(fd, buffer, sizeof(Buffer_Size));
}

// So i WANT TO SOMEHOW PASS IN THE BUFFER_SIZE from my compiler call
A; by ifndef we set default
// I will Compile like this
//
//cc -Wall -Wextra -Werror -D Buffer_Size=42 <files>.c


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
