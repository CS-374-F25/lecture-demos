#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fd = open("sentence.txt", O_WRONLY | O_CREAT, 0664); // rw-rw-r--

	// Very important thing about read() and also write():
	// The third argument (n) is an upper bound on the number of bytes
	// to read / write, but it doesn't always read/write that many bytes.

	const char* sentence = "The epic highs and lows of high school football\n";
	size_t length_of_sentence = strlen(sentence);
	size_t total_bytes_written = 0;
	while (total_bytes_written < length_of_sentence) {
		ssize_t n_bytes_written = write(
			fd,
			sentence + total_bytes_written,
			length_of_sentence - total_bytes_written
			//1023 - total_bytes_read
		);
		total_bytes_written += n_bytes_written;
	}

	close(fd);
}
