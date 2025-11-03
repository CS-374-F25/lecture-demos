#include <signal.h>

int main() {
	sigset_t my_signal_set = {0};
	sigemptyset(&my_signal_set);
	sigaddset(&my_signal_set, SIGINT);
	sigaddset(&my_signal_set, SIGTSTP);
}
