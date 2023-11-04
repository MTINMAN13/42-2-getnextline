#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


#define MAX_LINE_LENGTH 1024

char*	custom_getline(int fd) {
	char* buffer = (char*)malloc(MAX_LINE_LENGTH);
	if (buffer == NULL) {
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	int pos = 0;
	char c;

	while (1) {
		ssize_t result = read(fd, &c, 1);

		if (result == -1) {
			perror("Error reading from file descriptor");
			exit(EXIT_FAILURE);
		} else if (result == 0) {
			// End of file
			if (pos == 0) {
				free(buffer);
				return NULL; // No more lines to read
			} else {
				buffer[pos] = '\0'; // End of the last line
				return buffer;
			}
		} else if (c == '\n') {
			buffer[pos] = '\0';
			return buffer;
		} else {
			buffer[pos] = c;
			pos++;

			// Check if the buffer is full
			if (pos >= MAX_LINE_LENGTH - 1) {
				buffer[pos] = '\0';
				return buffer;
			}
		}
	}
}

int main() {
	int fd = open("test.txt", O_RDONLY);
	if (fd == -1) {
		perror("Error opening the file");
		return 1;
	}

	char *line, *line2, *line3, *line4;

	line = custom_getline(fd);
	printf("%s    (OH AND BTW, FD IS: %i)\n", line, fd);
	free(line);

	line2 = custom_getline(fd);
	printf("%s    (OH AND BTW, FD IS: %i)\n", line2, fd);
	free(line2);

	line3 = custom_getline(fd);
	printf("%s    (OH AND BTW, FD IS: %i)\n", line3, fd);
	free(line3);

	line4 = custom_getline(fd);
	printf("%s    (OH AND BTW, FD IS: %i)\n", line4, fd);
	free(line4);

	close(fd);
	return 0;
}
