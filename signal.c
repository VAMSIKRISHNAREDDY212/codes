#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <mqueue.h>
#include <unistd.h>
#define QUEUE_NAME "/my_queue"
#define MAX_SIZE 1024
#define MSG_STOP "exit"
// Global variable to store message queue descriptor
mqd_t mq;
// Signal handler function
void signal_handler(int sig) {
	char buffer[MAX_SIZE];
	unsigned int priority;
	// Attempt to receive messages from the queue
	// Receive the message from the queue
	ssize_t bytes_received = mq_receive(mq, buffer, MAX_SIZE, &priority);
	if (bytes_received == -1) {
		perror("mq_receive");
		exit(1);
	}
	printf("Received message: %s\n", buffer);
}
int main() {
	struct mq_attr attr;
	// Set up attributes for the message
	attr.mq_flags = 0; // Blocking mode
	attr.mq_maxmsg = 10; // Maximum number of messages in the queue
	attr.mq_msgsize = MAX_SIZE; // Maximum size of each message
	attr.mq_curmsgs = 0; // Currently queued messages
			     // Unlink any existing queue before creating a new one
	mq_unlink(QUEUE_NAME);
	// Set up the signal handler for SIGUSR1
	if (signal(SIGUSR1, signal_handler) == SIG_ERR) {
		perror("signal");
		exit(1);
	}
	// Create and open the message queue with specified attributes
	mq = mq_open(QUEUE_NAME, O_CREAT | O_RDWR | O_NONBLOCK, 0644,&attr);
	if (mq == (mqd_t)-1) {
		perror("mq_open");
		exit(1);
	}
	char input[MAX_SIZE];
	printf("Enter messages (type 'exit' to quit):\n");
	while (1) {
		// Read input from the user
		scanf("%s",input);
		if (mq_send(mq, input, strlen(input) + 1, 0) == -1) {
			perror("mq_send");
			continue;
		}
		// Send a signal to notify the handler
		kill(getpid(), SIGUSR1);
		// Exit condition
		if (strcmp(input, MSG_STOP) == 0) {
			break;
		}
	}
	// Clean up and close the message queue
	mq_close(mq);
	mq_unlink(QUEUE_NAME);
	return 0;
}

