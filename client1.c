#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 8080
#define MAX_BUFFER 1024
int main() {
	int sockfd;
	struct sockaddr_in servaddr;
	char buffer[MAX_BUFFER];
	// Create socket
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0) {
		perror("Socket creation failed");
		exit(EXIT_FAILURE);
	}
	// Fill server information
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	// Convert IPv4 and IPv6 addresses from text to binary form
	if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0) {
		perror("Invalid address/ Address not supported");
		close(sockfd);
		exit(EXIT_FAILURE);
	}
	// Send request to server
	const char *request_msg = "GET TIME";
	sendto(sockfd, request_msg, strlen(request_msg), MSG_CONFIRM,
			(const struct sockaddr *)&servaddr, sizeof(servaddr));
	// Receive response from server
	socklen_t len = sizeof(servaddr);
	int n = recvfrom(sockfd, buffer, MAX_BUFFER, MSG_WAITALL,
			(struct sockaddr *)&servaddr, &len);
	buffer[n] = '\0';
	printf("Current Date and Time from Server: %s", buffer);
	close(sockfd);
	return 0;
}
