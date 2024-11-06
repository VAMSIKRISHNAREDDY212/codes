#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#define REQ "/tmp/req_fifo" //i FIFO for incoming requests
#define BUFFER_SIZE 1024 // Buffer size for file contents
int main() {
	// Create the FIFO for requests if it does not exist
	if (mkfifo(REQ, 0666) == -1 && errno != EEXIST) {
		perror("mkfifo");
		exit(EXIT_FAILURE);
	}
	printf("Server is running...\n");
	while (1) {
		char request[1000]; // Buffer to hold client's FIFO name
		char response_fifo[1000]; // Buffer to hold client's FIFO name
		char file_path[1000]; // Buffer to hold the requested file path
		char buffer[BUFFER_SIZE]; // Buffer to hold file contents
					  // Open the request FIFO for reading
		int rq_fd = open(REQ, O_RDONLY);
		if (rq_fd == -1) {
			perror("FIFO open");
			continue; // If opening fails, continue to next iteration
		}
		// Read client's FIFO name and requested file path
		read(rq_fd, response_fifo, sizeof(response_fifo));
		read(rq_fd, file_path, sizeof(file_path));
		close(rq_fd);
		printf("Received request from client FIFO: %s for file: %s\n", response_fifo, file_path);
		// Open the requested file and read its contents
		FILE *file = fopen(file_path, "r");
		if (file == NULL) {
			perror("Failed to open requested file");
			continue;
		}
		// Read contents of the file into buffer
		size_t bytesRead = fread(buffer, 1, BUFFER_SIZE - 1, file);
		buffer[bytesRead] = '\0'; // Null-terminate the string
		fclose(file);
		// Send the contents back to the client's FIFO
		int client_fd = open(response_fifo, O_WRONLY);
		if (client_fd != -1) {
			write(client_fd, buffer, strlen(buffer) + 1); // Include null terminator
			close(client_fd);
			printf("Sent response to client FIFO: %s\n", response_fifo);
		} else {
			perror("Failed to open client FIFO");
		}
	}
	return 0;
}
sdf
