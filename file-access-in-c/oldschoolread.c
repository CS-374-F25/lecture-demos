#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fd = open("movies_sample_1.csv", O_RDONLY, 0777);

	// Very important thing about read() and also write():
	// The third argument (n) is an upper bound on the number of bytes
	// to read / write, but it doesn't always read/write that many bytes.

	// In practice, what you'd probably actually do, is call the read()
	// function over and over again until you have read one or more \n
	// characters.

	// Goal: Read characters from the file until we've encountered
	// \n
	char buffer[1024] = {0};
	size_t total_bytes_read = 0;
	while (strchr(buffer, '\n') == NULL) {
		ssize_t n_bytes_read = read(
			fd,
			buffer + total_bytes_read,
			1
			//1023 - total_bytes_read
		);
		total_bytes_read += n_bytes_read;

		if (n_bytes_read == 0) {
			break;
		}
	}

	buffer[strlen(buffer) - 1] = '\0';
	printf("%s\n", buffer);



	close(fd);
}
