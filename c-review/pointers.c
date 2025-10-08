#include <stdio.h>
#include <stddef.h>

// Parameters are copies of their arguments
void change_me(int* p) {
	*p = 10;
}

struct person {
	int age;
};

int* return5() {
	int z = 5;
	return &z;
}

int main() {
	int x = 5;

	// & is the address-of operator

	// *p is the dereference operator. It dereferences p. Sometimes called
	// the indirection operator.
	
	change_me(&x);

	printf("%d\n", x); // Prints

	struct person john;
	struct person sally;
	
	struct person* john_ptr = &john;
	(*john_ptr).age = 27;
	john_ptr->age = 28;

	// DOuble pointers (pointers to pointers)
	struct person** john_ptr_ptr = &john_ptr;
	(*john_ptr_ptr)->age = 30;

	*john_ptr_ptr = &sally;
	(*(*john_ptr_ptr)).age = 15;

	// In C, NULL is typically a macro for 0
	int* my_ptr = NULL;

	// Last thing about pointers: Dangling pointers. A pointer that USED
	// to point to something, but now that thing is gone.
	int* some_ptr = return5();
	// some_ptr is a dangling pointer
	
	// Dereferencing a dangling pointer is known as a use-after-free error.
	// This invokes undefined behavior.
	printf("%d\n", *some_ptr);
}
