
#include <aio.h>
#include <fcntl.h>  // For file control options like O_RDONLY
#include <unistd.h> // For system calls like open()
#include <stdio.h>



int main() {
	char buffer[6969];
	int fd = open("example.txt", O_RDONLY);
	if (fd == -1) {
		perror("Error opening the file");
		return 1;
	}
	ssize_t bytesRead = read(fd, buffer, 12313132123);
	buffer[bytesRead] = '\0';
	printf("Read from the file: %s", buffer);
	close(fd);
	return 0;
}

/*
SOO i REALLy want to implement soemthing liek sizeof()


I have no idea how to do the buffer in ordere to not lose the already allocated portions.. i have no fucking clue
it would be best if i could do the buffer as array and always allocate an array which will be in the array at a set position

e.g. having an array PENIS[1]
and when first line is read, allocating it to PENIS[1][0]
when second line i sread, we scratch the PENIS[1][0] part and we write to PENIS[1][1]... ETC..

*/
