#include <pthread.h>
#include <stdio.h>

struct thread_args {
	pthread_mutex_t* mutex;
	double* sum;
	int radius;
};

void* add_volume_of_sphere_to_sum(void* args) {
	struct thread_args* casted_args = (struct thread_args*) args;
	int r = casted_args->radius;
	double volume = 4.0 / 3.0 * 3.141592 * r * r * r;


	// A critical section is a section of code wherein you want to
	// access a shared resource (or set of shared resources),
	// and you need that shared resource to be "consistent" or
	// "predictable" within that section.

	// We can fix this by using locks
	
	// This is a critical section
	// We lock the mutex
	pthread_mutex_lock(casted_args->mutex);
	*(casted_args->sum) += volume; // Addition is not atomic
	// We unlock the mutex
	pthread_mutex_unlock(casted_args->mutex);


	return NULL;
}

int main() {
	pthread_mutex_t mutex = {0};
	pthread_mutex_init(&mutex, NULL);
	double sum = 0.0;
	struct thread_args args[100];
	pthread_t threads[100];

	int i;
	for (i = 0; i < 100; ++i) {
		args[i].radius = i;
		args[i].mutex = &mutex;
		args[i].sum = &sum;
		pthread_create(&(threads[i]), NULL, add_volume_of_sphere_to_sum, (void*) &(args[i]));
	}


	for (i = 0; i < 100; ++i) {
		void* return_value;
		pthread_join(threads[i], &return_value);
	}

	//pthread_mutex_destroy(&mutex);

	printf("The sum of all the volumes is %.5f\n", sum);
}
