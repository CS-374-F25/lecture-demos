#include <stdio.h>
#include <stdlib.h>


// Command-line arguments
int main(int argc, char* argv[]) {

	printf("%d\n", argc);

	for (int i = 0; i < argc; ++i) {
		printf("%s\n", argv[i]);
	}

	printf("%d\n", strtol(argv[3], NULL, 10) + 1);
}
