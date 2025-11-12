#include <pthread.h>
#include <stdio.h>

struct thread_args {
	float* array;
	int index;
};

void* compute_volume_of_sphere(void* args) {
	struct thread_args* casted_args = (struct thread_args*) args;
	int r = casted_args->index;
	float volume = 4.0 / 3.0 * 3.141592 * r * r * r;
	casted_args->array[r] = volume;
	return NULL;
}

int main() {
	float volumes[100];
	struct thread_args args[100];
	pthread_t threads[100];

	int i;
	for (i = 0; i < 100; ++i) {
		args[i].index = i;
		args[i].array = volumes;
		pthread_create(&(threads[i]), NULL, compute_volume_of_sphere, (void*) &(args[i]));
	}


	for (i = 0; i < 100; ++i) {
		void* return_value;
		pthread_join(threads[i], &return_value);
	}

	printf("The volume of a sphere with radius 57 is %f\n", volumes[57]);
}
