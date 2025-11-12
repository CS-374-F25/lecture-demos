#include <pthread.h>
#include <stdio.h>

void* foo(void* some_parameter) {
	printf("Hello, ");
	return NULL;
}

int main() {
	pthread_t secondary_thread = {0};
	pthread_create(&secondary_thread, NULL, foo, NULL);

	void* return_value;
	pthread_join(secondary_thread, &return_value);
	printf("World!\n");

}
