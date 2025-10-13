#include <stdio.h>
#include <stdlib.h> // Gives you access to malloc(), free()
#include <string.h>

int main() {
	// Automatic variable. Automatic storage duration.
	// Automatic variables will always live at least as long as their
	// scopes.
	//
	
	// Dynamic memory has dynamic storage duration. Dynamic memory
	// exists until you delete it.

	// Arrays can NEVER be resized.
	// Trick: Create a NEW, bigger array. Copy the elements from the old
	// array to the new array. DELETE the old array. Update some pointers
	// and size variables.
	
	// "The Stack" is a stack data structure. It's LIFO (last-in-first-out).
	
	// To create an array on the heap:
	size_t size = 10;
	double* array = (double*) malloc(sizeof(double) * size);
	// printf("%lf\n", array[0]);
	array[0] = 3.14;
	array[1] = 9.81;



	// Suppose I want to add an 11th element to the array
	// 1. Create new bigger array
	double* new_array = (double*) malloc(sizeof(double) * (size + 1));

	// 2. Copy the elements from the old array to the new array
	memcpy(new_array, array, size * sizeof(double));

	// 3. Add your new element to the end of the new array
	new_array[10] = 3.14;

	// 4. Delete the old array. To free stuff from the heap, use the free()
	// function.
	free(array);

	// array is now a dangling pointer

	// 5. Update our original pointer, array, to have it point to the
	// NEW array
	array = new_array;

	// Memory leaks. you must remember to free all memory allocated
	// with malloc(). If you forget, then your program has a memory leak.
	// valgrind. Avoid all memory leaks.
	free(array);

	// free(array); // Free a dangling pointer. Invalid free. Undefined
	// behavior.
	
	array = NULL;

	free(array); // Does nothing.
}
