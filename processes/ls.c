#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t fork_result = fork();
	if (fork_result == 0) {
		// This is the child process.
		// execlp("ls", "ls", "my_folder/", "-l", (char*) NULL);
		char* args[4];
		args[0] = "ls";
		args[1] = "my_folder/";
		args[2] = "-l";
		args[3] = NULL;
		execvp("ls", args);
	}
	
	// This is the parent process.
	int exit_result;
	pid_t wait_result = waitpid(fork_result, &exit_result, 0);
	/*
	if (wait_result != 0) {
		printf("The child has terminated!\n");
	} else {
		printf("The child has not terminated!\n");
	}
	*/
	printf("Hello, World!\n");
}
