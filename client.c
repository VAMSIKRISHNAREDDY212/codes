#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#define SERVER_FIFO "/tmp/req_fifo"
#define MAX_PATH 1000
int main() {
	pid_t pid = getpid();
	char response_fifo[MAX_PATH];
	sprintf(response_fifo, "/tmp/client_fifo_%d", pid); // Unique FIFO for this client
							    // Create client FIFO
	mkfifo(response_fifo, 0666);
	char file_path[MAX_PATH];
	printf("Enter the path of the file to request: ");
	scanf("%s", file_path);
	// Send client's FIFO name and requested file path to server
	int server_fd = open(SERVER_FIFO, O_WRONLY);
	write(server_fd, response_fifo, sizeof(response_fifo));
	write(server_fd, file_path, sizeof(file_path));
	close(server_fd);
	// Wait for response from server
	char buffer[1024];
	int client_fd = open(response_fifo, O_RDONLY);
	read(client_fd, buffer, sizeof(buffer));
	printf("Received from server:\n%s\n", buffer);
	close(client_fd);
	// Clean up: remove client FIFO
	unlink(response_fifo);
	return 0;
}
