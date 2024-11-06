#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
	const char *name = "/my_shared_memory";
	int fd;
//	Attempt to create a new shared memory object
		fd = shm_open(name, O_CREAT | O_EXCL | O_RDWR, 0666);
	if (fd == -1) {
		// If shm_open fails due to existing object
		perror("shm_open");
		printf("The shared memory object already exists.\n");
		// Open the existing object instead
		fd = shm_open(name, O_RDWR, 0);
	} else {
		printf("A new shared memory object was created.\n");
		// Initialize the shared memory or perform other setup here
	}
	// Cleanup and close
	close(fd);
	return 0;
}

