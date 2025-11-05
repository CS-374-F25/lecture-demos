#include <string.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	int pipe_fds[2];
	// This creates a pipe.
	// Every pipe has two file descriptors associated with it:
	// 1. For reading (read())
	// 2. For writing (write())
	pipe(pipe_fds);

	pid_t fork_result = fork();

	// One of these two processes may write to pipe_fds[1]
	// The other of these two processes may read from pipe_fds[0]
	

	if (fork_result == 0) {
		// Child process
		close(pipe_fds[1]);

		char message[256];
		// If the parent process has not yet written any bytes
		// to the pipe, then the read() function will cause the
		// child process to pause and wait until the parent process
		// HAS done that. Once some bytes are available, it will
		// read up to 256 of them
		read(pipe_fds[0], message, 256);

		printf("%s\n", message);
	} else {
		// parent process
		close(pipe_fds[0]);

		char* message = "Don't forget your lunch!";
		write(pipe_fds[1], message, strlen(message) + 1);
	}

}
