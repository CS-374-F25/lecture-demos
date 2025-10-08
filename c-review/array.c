#include <stdio.h>

// Passing arrays to functions
double average(float* array, int size) {
	float sum = 0.0;
	for (int i = 0; i < size; ++i) {
		sum += array[i];
	}
	return sum;
}

int main() {
	float numbers[10] = {3.14, 5.28, -1.5};
	printf("%p\n", numbers);

	// 'numbers' decays to its base address (ptr to first element)
	float* p = numbers;

	*p = 5.4; // These two lines of code are the same
	p[0] = 5.4; // Pointers can be indexed like the arrays they point to

	printf("%f\n", numbers[0]); // Prints 5.4

	double av = average(numbers, 10);

	printf("The average is %f\n", av);
}
