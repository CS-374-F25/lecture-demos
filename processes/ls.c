#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	putenv("HOME=/nfs/stak/users/guyert");
	char* home_directory = getenv("HOME");
	printf("%s\n", home_directory);

	pid_t fork_result = fork();
	if (fork_result == 0) {
		// This is the child process.
		// execlp("ls", "ls", "my_folder/", "-l", (char*) NULL);
		char* args[4];
		args[0] = "ls";
		args[1] = "my_folder/";
		args[2] = "-l";
		args[3] = NULL;
		execvp("ls", args); // Replaces the program with a new one.

		// The child process will not make it this far in the program.
		// Code here / below is dead code to the child process.
	}
	
	// This is the parent process. Only the parent will make it this far.
	// (the child's program gets replaced by execvp)
	
	int exit_result;

	// If you pass WNOHANG as the third argument, then this will CHECK
	// whether the child process has terminated instead of WAITING for
	// it to terminate. In such a case, it returns 0 if the child has not
	// yet terminated. Else, it returns the PID of the terminated child.
	pid_t wait_result = waitpid(fork_result, &exit_result, 0);
	printf("Hello, World!\n");
	
	if (WIFEXITED(exit_result)) {
		printf("The child process exited \"normally\"\n");
		// In this case, you can extract its exit code
		int actual_exit_status = WEXITSTATUS(exit_result);
		printf("The child exited with status %d\n", actual_exit_status);
	} else if (WIFSIGNALED(exit_result)) {
		printf("The child process was killed abruptly by a signal\n");
		// In this case, you can extract the signal number of the
		// signal that killed it
		int signal_number = WTERMSIG(exit_result);
		printf(
			"The child was killed by a signal with number %d\n",
			signal_number
		);
	}
}
