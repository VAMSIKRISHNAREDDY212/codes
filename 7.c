#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
void cleanup_handler(void *arg) {
	printf("Cleaning up: freeing memory......\n");
	free(arg); // Free allocated memory
}
void *thread_function(void *arg) {
	char *buffer = malloc(1000); // Allocate memory
	if (buffer == NULL) {
		return NULL; // Handle allocation failure
	}
	pthread_cleanup_push(cleanup_handler, buffer); // Register cleanup handler
						       // Simulate work
	printf("Thread is working...\n");
	// Simulate cancellation request
	pthread_testcancel(); // Check for pending cancellation requests
			      // More work...
	pthread_cleanup_pop(1); // Execute cleanup handler if not already popped
	return NULL;
}
int main() {
	pthread_t thread;
	pthread_create(&thread, NULL, thread_function, NULL);
	// Simulate some delay before canceling the thread
	sleep(1);
	pthread_cancel(thread); // Request cancellation
	pthread_join(thread, NULL); // Wait for the thread to finish
	return 0;
}

