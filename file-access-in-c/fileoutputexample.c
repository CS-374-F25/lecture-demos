#include <stdio.h>

int main() {
	// mode "w" means truncate / overwrite
	// mode "a" means append
	FILE* output_file = fopen("out.csv", "w");

	fprintf(output_file, "Name,Age\n");

	int age = 72;
	fprintf(output_file, "John,%d\n", age);

	char my_string[100];
	

	fclose(output_file);
}
