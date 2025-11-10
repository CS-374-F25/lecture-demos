#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
	FILE* my_file = fopen("my_file.txt", "r");
	
	pid_t fork_result = fork();

	// A race condition is a problem that occurs because two or more
	// concurrent threads / processes are trying to access the same
	// underlying resource at the same time

	// Undefined behavior if two processes aren't synchronized
	if (fork_result == 0) {
		// I am the child process
		char buffer[11];

		// Here is the start of our critical section
		
		// TODO Protect the critical section by acquiring the lock
		int fd = open("lock.lock", O_WRONLY | O_CREAT | O_EXCL, 0777);
		while (fd == -1) {
			sleep(1);
			fd = open("lock.lock", O_WRONLY | O_CREAT | O_EXCL, 0777);
		}
		

		fgets(buffer, 11, my_file);
		close(fd);

		// TODO Release the lock that we acquired
		remove("lock.lock");

		// Here is the end of our critical section
		

		printf("Child: %s\n", buffer);
	} else {
		// I am the parent process
		char buffer[11];
		
		// Here is the start of our critical section
		
		// TODO Protect the critical section by acquiring the lock
		int fd = open("lock.lock", O_WRONLY | O_CREAT | O_EXCL, 0777);
		while (fd == -1) {
			sleep(1);
			fd = open("lock.lock", O_WRONLY | O_CREAT | O_EXCL, 0777);
		}
		close(fd);
		
		fgets(buffer, 11, my_file);
		
		
		// TODO Release the lock that we acquired
		remove("lock.lock");

		// Here is the end of our critical section

		printf("Parent: %s\n", buffer);
	}
}
