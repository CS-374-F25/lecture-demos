#include <stdio.h>
#include <string.h>

int main() {
	const char* my_c_string = "The epic highs and lows of high school football";
	char my_c_string_2[strlen(my_c_string) + 1];
	strncpy(my_c_string_2, my_c_string, 10);
	printf("%s\n", my_c_string_2);

	my_c_string_2 == my_c_string_1;

	strcat(my_c_string_2, my_c_string_1)
}
