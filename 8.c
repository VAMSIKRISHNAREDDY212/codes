#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define BUFFER_SIZE 5 // Size of the buffer
#define NUM_ITEMS 20 // Total items to produce/consume
int buffer[BUFFER_SIZE];
int count = 0; // Number of items in the buffer
sem_t put; // Semaphore for producer
sem_t get; // Semaphore for consumer
pthread_mutex_t mutex; // Mutex for protecting access to the buffer
void* producer(void* arg) {
	for (int i = 0; i < NUM_ITEMS; i++) {
		sem_wait(&put); // Wait on the Put semaphore
		pthread_mutex_lock(&mutex); // Lock the mutex
					    // Produce an item
		buffer[count] = i;
		printf("Produced: %d\n", i);
		count++;
		pthread_mutex_unlock(&mutex); // Unlock the mutex
		sem_post(&get); // Signal that an item is available
		sleep(1); // Simulate time taken to produce an item
	}
	return NULL;
}
void* consumer(void* arg) {
	for (int i = 0; i < NUM_ITEMS; i++) {
		sem_wait(&get); // Wait on the Get semaphore
		pthread_mutex_lock(&mutex); // Lock the mutex
					    // Consume an item
		int item = buffer[count - 1];
		printf("Consumed: %d\n", item);
		count--;
		pthread_mutex_unlock(&mutex); // Unlock the mutex
		sem_post(&put); // Signal that space is available
		sleep(2); // Simulate time taken to consume an item
	}
	return NULL;
}
int main() {
	pthread_t prod_thread, cons_thread;
	// Initialize semaphores and mutex
	sem_init(&put, 0, 1); // Initial value of Put = 1
	sem_init(&get, 0, 0); // Initial value of Get = 0
	pthread_mutex_init(&mutex, NULL);
	// Create producer and consumer threads
	pthread_create(&prod_thread, NULL, producer, NULL);
	pthread_create(&cons_thread, NULL, consumer, NULL);
	// Wait for threads to finish
	pthread_join(prod_thread, NULL);
	pthread_join(cons_thread, NULL);
	// Clean up
	pthread_mutex_destroy(&mutex);
	sem_destroy(&put);
	sem_destroy(&get);
	return 0;
}


