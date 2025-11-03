#include <unistd.h>
#include <signal.h>
#include <stdio.h>



// Lots of functions are non-reentrant
// Not reentrant
// Reentrant: The function can be paused in the middle, restarted at the top,
// 	then resumed where it left off afterward, without anything bad happening

/*
void my_function(int signum) {
	// a bunch of code goes here
	my_global = 0
	// maybe some more here
	my_global = 1
}
*/

volatile sig_atomic_t foreground_only_mode = 0;

void say_hello(int signum) {
	// printf is nonreentrant
	write(1, "Hello, World!\n", 14);

	if (foreground_only_mode == 0) {
		// Pauses
		// 1. Make sure that this signal handler is the only
		// place in your program where you modify this global variable
		// 2. Make sure this global variable is volatile sigatomic_t
		// 3. Make sure the sa_mask attribute of the sigaction
		// structure used to configure this signal handler contains
		// the same signal as is being configured
		foreground_only_mode = 1;
	} else {
		foreground_only_mode = 0;
	}
}

int main() {
	struct sigaction sigint_config = {0};
	sigfillset(&sigint_config.sa_mask);
	sigint_config.sa_flags = SA_RESTART | SA_RESETHAND;
	sigint_config.sa_handler = say_hello;
	// sigint_config.sa_handler = SIG_DFL; // Signal default
	// sigint_config.sa_handler = SIG_IGN; // Signal ignore
	// sigint_config.sa_sigaction = NULL; // DONT DO THIS
	sigaction(SIGINT, &sigint_config, NULL);

	// CTRL+C is SIGINT
	// CTRL+Z is SIGTSTP
	/*pid_t fork_result = fork();

	if (fork_result == 0) {
		execv(executes some other program);
	}*/

	pause();
	pause();
}
