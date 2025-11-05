#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
	
	pid_t fork_result = fork();

	FILE* my_file = fopen("my_file.txt", "r");

	// A race condition is a problem that occurs because two or more
	// concurrent threads / processes are trying to access the same
	// underlying resource at the same time

	// Undefined behavior if two processes aren't synchronized
	if (fork_result == 0) {
		// I am the child process
		char buffer[11];
		fgets(buffer, 11, my_file);
		printf("Child: %s\n", buffer);
	} else {
		// I am the parent process
		int exit_info;
		waitpid(fork_result, &exit_info, 0);
		char buffer[11];
		fgets(buffer, 11, my_file);
		printf("Parent: %s\n", buffer);
	}
}
