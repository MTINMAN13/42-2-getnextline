// #include <aio.h>
// #include <fcntl.h>  // For file control options like O_RDONLY
// #include <unistd.h> // For system calls like open()
// #include <stdio.h>

// int main() {
// 	char **buffer;
// 	int fd = open("example.txt", O_RDONLY);
// 	if (fd == -1) {
// 		perror("Error opening the file");
// 		return 1;
// 	}
// 	ssize_t bytesRead = read(fd, buffer[1], 123);
// 	buffer[1][bytesRead] = '\0';
// 	printf("Read from the file: %s", buffer[1]);
// 	close(fd);
// 	return 0;
// }


#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 10 // Maximum number of strings to read
#define MAX_STRING_LENGTH 1024 // Maximum string length

int main() {
    char buffer[MAX_STRINGS][MAX_STRING_LENGTH]; // Array to store multiple strings
    int fd = open("example.txt", O_RDONLY);

    if (fd == -1) {
        perror("Error opening the file");
        return 1;
    }

    int stringCount = 0; // Counter for the number of strings read

    // Read strings until we reach the end of the file or reach the limit
    while (stringCount < MAX_STRINGS) {
        ssize_t bytesRead = read(fd, buffer[stringCount], MAX_STRING_LENGTH);

        if (bytesRead == -1) {
            perror("Error reading from the file");
            close(fd);
            return 1;
        } else if (bytesRead == 0) {
            // End of file reached
            break;
        } else {
            buffer[stringCount][bytesRead] = '\0'; // Null-terminate the string
            printf("Read from the file: %s", buffer[stringCount]);
            stringCount++;
        }
    }

    close(fd);

    // Now you have stringCount strings in the buffer array.
    for (int i = 0; i < stringCount; i++) {
        printf("Array[%d]: %s\n", i, buffer[i]);
    }

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
