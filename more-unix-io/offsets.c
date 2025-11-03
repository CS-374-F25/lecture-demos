#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
	FILE* my_file = fopen("my_file.txt", "r");
	
	pid_t fork_result = fork();

	// Undefined behavior if two processes aren't synchronized
	if (fork_result == 0) {
		// I am the child process
		char buffer[11];
		fgets(buffer, 11, my_file);
		printf("Child: %s\n", buffer);
	} else {
		// I am the parent process
		int exit_info;
		// TODO explain: synchronize two processes
		waitpid(fork_result, &exit_info, 0);
		char buffer[11];
		fgets(buffer, 11, my_file);
		printf("Parent: %s\n", buffer);
	}
}
