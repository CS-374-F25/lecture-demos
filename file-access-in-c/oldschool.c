#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fd = open("movies_sample_1.csv", O_RDONLY, 0777);

	// In practice, what you'd probably actually do, is call the read()
	// function over and over again until you have read one or more \n
	// characters.
	char first_line[20];
	ssize_t n_bytes_read = read(fd, first_line, 13);
	first_line[n_bytes_read - 1] = '\0';

	printf("%s\n", first_line);

	char second_line[20];
	n_bytes_read = read(fd, second_line, 15);
	second_line[n_bytes_read - 1] = '\0';

	printf("%s\n", second_line);

	close(fd);
}
