#include <string.h>
#include <stdio.h>

int main() {
	char my_c_string[] = "Hello,World-Alex,25";
	char* token = strtok(my_c_string, ",-");
	printf("%s\n", token);
	token = strtok(NULL, ",-");
	printf("%s\n", token);
	token = strtok(NULL, ",-");
	printf("%s\n", token);
	token = strtok(NULL, ",-");
	printf("%s\n", token);
	token = strtok(NULL, ",-");
	if (token != NULL) {
		printf("%s\n", token);
	}

	printf("%s\n", my_c_string);
}
