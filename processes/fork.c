#include <stdio.h>
#include <unistd.h>

int main() {
	printf("Hello, World!\n");

	// The parent process will create, or fork, a child process
	pid_t fork_result = fork();

	if (fork_result == 0) {
		// This is the child process.
		printf("Goodbye, World! I'm the child.\n");
	} else {
		// This is the parent process.
		printf("Goodbye, World! I'm the parent.\n");
	}

	fork_result = fork();

	// Question: If I run this program, how many times will Hello, World
	// be printed to the terminal? 1.
	//
	// Goodbye, world will be printed twice.
}
