#include <pthread.h>
#include <stdio.h>

struct thread_args {
	pthread_mutex_t* mutex;
	pthread_cond_t* cv;
	int* printed_hello;
	int* printed_space;
};

void* foo(void* args) {
	struct thread_args* casted_args = (struct thread_args*) args;
	printf("Hello,");

	pthread_mutex_lock(casted_args->mutex);
	*(casted_args->printed_hello) = 1;
	pthread_mutex_unlock(casted_args->mutex);
	pthread_cond_signal(casted_args->cv);

	
	// Wait until the main function has printed a space
	pthread_mutex_lock(casted_args->mutex);
	while (!(*casted_args->printed_space)) {
		pthread_cond_wait(casted_args->cv, casted_args->mutex);
	}
	pthread_mutex_unlock(casted_args->mutex);
	

	printf("World!\n");
	return NULL;
}

int main() {
	int printed_hello = 0;
	int printed_space = 0;

	pthread_mutex_t mutex;
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_t cv;
	pthread_cond_init(&cv, NULL);

	pthread_t secondary_thread = {0};
	struct thread_args args;
	args.mutex = &mutex;
	args.cv = &cv;
	args.printed_hello = &printed_hello;
	args.printed_space = &printed_space;
	pthread_create(&secondary_thread, NULL, foo, &args);

	// Wait until the secondary thread has printed Hello,
	pthread_mutex_lock(&mutex);
	while (!printed_hello) {
		pthread_cond_wait(&cv, &mutex);
	}
	pthread_mutex_unlock(&mutex);


	printf(" ");
	
	pthread_mutex_lock(&mutex);
	printed_space = 1;
	pthread_mutex_unlock(&mutex);
	pthread_cond_signal(&cv);

	void* return_value;
	pthread_join(secondary_thread, &return_value);
}
