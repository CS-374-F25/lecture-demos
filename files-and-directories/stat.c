#include <stdio.h>
#include <sys/stat.h>

int main() {
	struct stat result = {0};
	stat("a.out", &result);
	printf("Inode number: %ld\n", result.st_ino);
	printf("Size: %ld\n", result.st_size);
}
