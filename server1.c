#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>
#define PORT 8080
#define MAX_BUFFER 1024
int main() {
	int sockfd;
	struct sockaddr_in servaddr, cliaddr;
	char buffer[MAX_BUFFER];
	socklen_t len = sizeof(cliaddr);
	// Create socket
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0) {
		perror("Socket creation failed");
		exit(EXIT_FAILURE);
	}
	// Fill server information
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);
	// Bind the socket
	if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) )
			{	perror("Bind failed");
			close(sockfd);
			exit(EXIT_FAILURE);
			}
			printf("UDP Server is running on port %d...\n", PORT);
			while (1) {
			// Receive message from client
			int n = recvfrom(sockfd, buffer, MAX_BUFFER, MSG_WAITALL,
					(struct sockaddr *)&cliaddr, &len);
			buffer[n] = '\0';
			// Get current date and time
			time_t now = time(NULL);
			char *time_str = ctime(&now); // Convert to string format
						      // Send the current date and time back to the client
			sendto(sockfd, time_str, strlen(time_str), MSG_CONFIRM,
					(const struct sockaddr *)&cliaddr, len);
			printf("Sent current time to client: %s", time_str);
			}
			close(sockfd);
			return 0;
	}

