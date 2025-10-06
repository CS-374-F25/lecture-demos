#include <stdio.h>

// The main function is the entry point and exit point of the program.
int main() {
	/*
	printf("Hello, World!\n");
	fflush(stdout);
	*/

	// Standard output is line-buffered
	
	// Primitive data types in C:
	// int: Integer
	// float: Floating point number
	// long int: Long integer
	// double: Double-precision floating point number
	// char: Character
	
	// Literals:
	// int: 12
	// float: 3.14f
	// long int: 12l
	// double: 3.14
	// char: '!' ','  'A'   'a'   '9'
	//
	
	// The first argument of printf is the format string
	// The format string is text with placeholders
	// Those placeholders are called format specifiers
	// %d is a placeholder for a whole decimal value
	// %f is a placeholder for floating point values
	// %lf is a placeholder for long floating point values (i.e., doubles)
	// %ld is a placeholder for long decimal values (i.e., long int)
	printf("%d %.1f\n", 12 * 3, 3.89f);

	// Arithmetic operators:
	// +
	// -
	// *
	// /
	// %
	// 
	// #include <math.h>
	// pow(2, 5)
	//
	
	// Floating point -> Integral. Rule is truncation
	// Integral type -> Floating point, rule is add a .0 on the end
	printf("%d\n", (int) (1.0 / 2));

	// Before you can use a variable, you must declare it
	// To declare a variable:
	int favorite_number;

	// VERY IMPORTANT: Using an uninitialized variable results in
	// undefined behavior
	printf("%d\n", favorite_number);

	// To assign a value to a variable, use the assignment operator
	// When you first assign a value to a variable, that "initializes"
	// the variable.
	favorite_number = 100;
	
	int x = 10;

	// Relational operators:
	// ==
	// !=
	// >
	// >=
	// <
	// <=
	
	// Logical operators
	// || logical or
	// && logical and
	// "Short circuiting"
	// !
	
	// If statements in C
	if (!(favorite_number == 7 || favorite_number == 42)) {
		// If statement body goes here
		printf("Hey, that's a good number!\n");
	} else if (1 + 1 == 2) {
		// Else if statement body
	} else if (1 + 1 == 3) {
		// Else if statement body
	} else {
		// Else statement body
	}

	// Loops in C
	// Three main kinds of loops in C:
	// While loops
	// Do while loops
	// For loops
	//
	
	int i = 0;
	while (i < 10) {
		// int i = 0; // This is legal. This shadows the outer i variable
		printf("Hello, World!\n");
		++i;
	}

	/*
	do {
		// Do-while loop body goes here
	} while(some condition);
	*/

	// Three things:
	// 1. Initialization statement
	// 2. Loop condition
	// 3. Post statement
	for (int i = 0; i < 5; ++i) {
		printf("Hello, World!\n");
	}

	// In C, scope is given by a pair of curly braces

	// To create an array in C
	int n = 5;
	char sentence[n];

	// To access an element, you index it
	sentence[0] = 'J';
	sentence[1] = 'e';
	sentence[2] = 'l';
	sentence[3] = 'l';
	sentence[4] = 'o';

	// Aggregate initialization. Left-out values are initialized to zero.
	int my_array[10] = {4, -1, 12, 3, 4, 5, 6, 7};

	int zeros[100] = {0};

	// This is a buffer over-read
	int some_int_var = my_array[10];

	// This is a buffer overflow
	my_array[100] = 5;

	// Buffer over-reads and overflows invoke undefined behavior in C.
	
	// Arbitrary code execution (ACE) exploit
	//
	// Valgrind is a dynamic analysis tool.
}
