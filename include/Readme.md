# A good start
##### A WISE MAN ONCE SAID... _"it would be pretty noice to know what a static variable is"_

###### Static Variable

Imagine you have a magical cookie jar. This cookie jar is like a special container where you can keep information. But there's something unique about it - it never disappears, even when you're not using it.

In the world of programming, a static variable is a bit like that cookie jar. It's a special kind of variable that keeps its value between different uses of a function. When you use a function, it's like taking a cookie from the jar. The next time you use that function, it remembers the cookies you took out before.

So, let's say you have a function that counts how many times you've visited a park. You use a static variable in this function to remember the count. Every time you go to the park, you take a cookie (the count increases), and the jar (the static variable) remembers how many times you've been to the park.

In a nutshell, a static variable is a special type of memory in your computer that remembers its value even when you're not using it, just like your magical cookie jar remembers how many times you've visited the park.

###### read | function

SO read can be used to READ.  4Head

- ssize_t read(int fildes, void *buf, size_t nbyte);
- a.k.a.  read(0, *buffer*, sizeof(*buffer*));

*buffer* =  ... a pointer to the memory location _where_ the *data* read from the file descriptor will be *stored* =*.

###### ssize_t | variable type
- can store [-1, SSIZE_MAX] ---->  okay (SSIZE_MAX is equal to 2147483647)
- is of a signed integer (type)

######  File Descriptors
File descriptors are typically represented as integers, and the operating system uses them to keep track of open files and communication channels.

Standard File Descriptors:
In C, there are three standard file descriptors:

0 (stdin): Standard input, typically the keyboard.
1 (stdout): Standard output, where your program can send output, often the console.
2 (stderr): Standard error, used for error messages.

_*le example has arive 🥇*_
```
#include <stdio.h>
#include <unistd.h>

int main() {
    char buffer[100];
    ssize_t bytesRead = read(0, buffer, sizeof(buffer));

    if (bytesRead == -1) {
        perror("Error reading from standard input");
        return 1;
    }

    buffer[bytesRead] = '\0';
    printf("You typed: %s", buffer);

    return 0;
}
```

> (_... in this example we OBVIOUSLY read from keyboard input_)
###### A SIDE NOTE :

_In C, you typically don't need to manually find the file descriptor of an already open file. When you open a file using functions like fopen or open, the operating system automatically assigns a file descriptor to the opened file. You can then use this file descriptor to perform read and write operations on the file._

> deja vu ? exmaple arive? OKAY

```
#include <fcntl.h>

int main() {
    char buffer[100];
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening the file");
        return 1;
    }
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
    buffer[bytesRead] = '\0';
    printf("Read from the file: %s", buffer);
    close(fd);
    return 0;
}
```

______________________
## Program reqs. 🙂

- Program reqs.

1. Implementing a `get_next_line()` function for reading a text file line by line.
2. The function should return the read line or `NULL` on error or when there's nothing left to read.
3. Ensure it works for both file and standard input.
4. Return lines with a trailing `\n` character unless it's the end of the file without `\n`.
5. The `get_next_line.h` header must contain the function prototype.
6. Adding necessary helper functions in `get_next_line_utils.c`.
7. Define the buffer size for `read()` using a compiler flag: `-D BUFFER_SIZE=n`.

!! • Global variables are forbidden. !!

Freebies

1. • We consider that get_next_line() has an undefined behavior if the file pointed to by the file descriptor changed since the last call whereas read() didn’t reach the end of file.
2. • We also consider that get_next_line() has an undefined behavior when reading a binary file. However, you can implement a logical way to handle this behavior if you want to

#### Bonus Plus parte

8. Implementing `get_next_line()` using only one static variable.
9. Ensure that `get_next_line()` can manage multiple file descriptors simultaneously, allowing for reading from different file descriptors without losing the reading context of each file descriptor or returning a line from another file descriptor.


______________________________________________

1. I want to find the newline character and read until that part

read(fd, buffer, sizeof(buffer));

so the fd is being passed in from get/next/line

buffer is the place where we store the chars up until the first /n (NEWLINE)


```
read() attempts to read up to count bytes from file descriptor fd
into the buffer starting at buf.
```
##### Return Values
###### ssize_t read(int fd, void *buf, size_t count);

/ According to POSIX.1, if count is greater than SSIZE_MAX, the
result is implementation-defined; see NOTES for the upper limit
on Linux.


/ On error, -1 is returned.

ssize_t is a signed integer type that is often used to represent the number of bytes read or written.

///////////////////////////////

we should RETURN THE LINE THAT WAS READ

get_next_line shoud return NULL on error

also

We probably want to implement a Structure which will be the Static Variable
nah

gon be pointer to pointer aka 2D array

or something

## RETURN VALUE FR FR NO CAP BUSSIN
As for the Return value, that will be ALWAYS including the /n charracter

UNLESS there is none AND we hit END OF FILE.


//////

### Thoughts.

#### #ifndef
```
#ifndef Buffer_Size
#define Buffer_Size 1024  // Default buffer size
#endif
```
```
```
In this code, we use #ifndef to check if Buffer_Size is defined. If it's not defined, we set a default value (in this case, 1024) using #define. This allows you to use Buffer_Size in your code, and when you compile the program with -D Buffer_Size=42, it will override the default value.

The #ifndef directive in C is a preprocessor directive that stands for "if not defined."
