#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
void *map_file(const char *filename, size_t *length) 
{
 int fd = open(filename, O_RDONLY);
 if (fd == -1) 
 {
 perror("Error opening file");
 exit(EXIT_FAILURE);
 }
 struct stat sb;
 if (fstat(fd, &sb) == -1)
 {
 perror("Error getting file size");
 close(fd);
 exit(EXIT_FAILURE);
 }
 *length = sb.st_size;
 void *mapped = mmap(NULL, *length, PROT_READ, MAP_PRIVATE, fd, 0);
 if (mapped == MAP_FAILED)
 {
 perror("Error mapping file");
 close(fd);
 exit(EXIT_FAILURE);
 }
 close(fd);
 return mapped;
}
void print_mapped_file(void *mapped, size_t length) 
{
 for (size_t i = 0; i < length; i++) 
 {
putchar(((char *)mapped)[i]);
 }
}
void unmap_file(void *mapped, size_t length) 
{
 if (munmap(mapped, length) == -1) 
 {
perror("Error unmapping file");
 }
}
int main(int argc, char *argv[]) 
{
 if (argc != 2) 
 {
 fprintf(stderr, "Usage: give file name after %s \n", argv[0]);
 exit(EXIT_FAILURE);
 }
 size_t length;
 void *mapped = map_file(argv[1], &length);
 print_mapped_file(mapped, length);
 unmap_file(mapped, length);
 return EXIT_SUCCESS;
}

