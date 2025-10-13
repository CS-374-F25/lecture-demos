#include <stdlib.h>
#include <stdio.h>

int main() {
	FILE* movies_file = fopen("movies_sample_1.csv", "r");
	if (movies_file == NULL) {
		printf("Failed to open the file");
		return 1;
	}

	// File offset: A sort of imaginary cursor that traverse
	// the file as you read from it.

	while (1) {
		// General strategy: Read a line
		char* line = NULL;
		size_t n = 0;
		size_t string_length = getline(&line, &n, movies_file);
		if (feof(movies_file)) {
			free(line);
			break;
		}

		// Tokenize the line using strtok, extracing pieces from it
		
		// Create COPIES of those tokens, on the HEAP. Use strcpy()
		//
		// Store the pointers in your movie structure's attributes
		//
		// Add the movie structure to your linked list

		/*
		line[string_length - 1] = '\0';

		printf("%s\n", line);
		*/

		free(line);
	}

	fclose(movies_file);

	// At the end of the program, for assignment 1, free all your movies
}
