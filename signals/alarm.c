#include <unistd.h>
#include <signal.h>

int main() {
	alarm(5);
	pause();
}
