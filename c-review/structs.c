#include <stdio.h>

void print_person(struct person p) {
	printf("%d\n", p.age);
	printf("%lf\n", p.favorite_number);
}

// Structure types are basically POD (plain old data) types
// A structure is a group of smaller, related data
struct person {
	int age;
	double favorite_number;
}; // Mind the semicolon!!!

int main() {
	// C is not an object-oriented programming language
	struct person p;
	int x;

	p.age = 12;
	p.favorite_number = 3.1415;

	print_person(p);
}
