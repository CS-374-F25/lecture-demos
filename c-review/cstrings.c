#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	// In C, strings are complicated
	
	// In C, a string is an array of characters whose content ends in
	// one or more null terminators.
	
	// There are at least three easy ways of creating C strings.
	
	// Method 1:
	// This creates an array of characters that is just big enough to
	// store the desired C string. It then populates that array with
	// the characters from the string literal, and it puts a null terminator
	// at the end. It then gives you the base address of that array.
	
	// IMPORTANT: When you create a C string like this, the C string is
	// IMMUTABLE (its contents cannot be changed).
	const char* my_c_string_1 = "Hello";

	// my_c_string_1[0] = 'J'; // Now, this is a compilation error

	// Method 2:
	// This creates an array of characters that is just big enough to
	// store the desired C string. It then populates that array with
	// the characters from the string literal, and it puts a null terminator
	// at the end. It then gives you the base address of that array.
	
	// If you want to print a C string:
	printf("%s\n", my_c_string_1);

	// HOWEVER, it's mutable
	char my_c_string_2[] = "Hello";
	my_c_string_2[0] = 'J'; // This is perfectly fine
	
	printf("%s\n", my_c_string_2);

	// Method 3:
	// This creates an array of characters of the specified size. It then
	// populates the first N+1 elements of that array with the contents of
	// the given string literal followed by a null terminator (N is the
	// number of characters in the string literal). The remaining characters
	// in the array are undefined.
	char my_c_string_3[256] = "Hello";
	my_c_string_3[5] = ' ';
	my_c_string_3[6] = 'W';
	my_c_string_3[7] = 'o';
	my_c_string_3[8] = 'r';
	my_c_string_3[9] = 'l';
	my_c_string_3[10] = 'd';
	my_c_string_3[11] = '\0';
	printf("%s\n", my_c_string_3);

	char user_input[256];
	printf("Enter your name: ");
	fgets(user_input, 256, stdin);
	user_input[strlen(user_input) - 1] = '\0';
	printf("%s\n", user_input);
	// \n // line feed, ASCII value 13
	// In windows, \n is actually an alias for a sequence of two characters:
	// 	carriage return, line feed
	char age_string[256];
	printf("Enter your age: ");
	fgets(age_string, 256, stdin);
	age_string[strlen(age_string) - 1] = '\0';
	int age = strtol(age_string, NULL, 10);
	printf("%d\n", age * 2);
	

}
