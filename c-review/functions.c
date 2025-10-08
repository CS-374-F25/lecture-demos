#include <stdio.h>

// Syntax for creating functions in C:
double volume_of_sphere(double radius) {
	// Function body goes here
	return 4.0 / 3.0 * 3.141592 * radius * radius * radius;
}

void print_hello_world() {
	printf("Hello, World!\n");
}

int main() {
	double volume = volume_of_sphere(5.0);
	printf("The volume of a sphere with radius 5 is %lf\n", volume);

	print_hello_world();
}
