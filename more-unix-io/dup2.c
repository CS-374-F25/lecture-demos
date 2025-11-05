#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	int out_file = open("out.txt", O_WRONLY | O_CREAT, 0644);

	pid_t fork_result = fork();

	if (fork_result == 0) {
		// This is the child
		dup2(out_file, STDOUT_FILENO);

		printf("Hello, World!\n");
	} else {
		// This is the parent
		printf("Hello, I'm the parent!\n");
	}
}
