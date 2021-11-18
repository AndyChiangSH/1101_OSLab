#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#define NAME "sharememory"

int main(int argc, char **argv) {
	int shm_fd;
	char *shm_base, *ptr, buffer[1024];

	shm_fd = shm_open(NAME, O_RDONLY, 0666);
	if(shm_fd < 0) {
		perror("open error:\n");
		exit(1);
	}
	shm_base = mmap(0, 1024, PROT_READ, MAP_SHARED, shm_fd, 0);
	if(shm_base == MAP_FAILED) {
		perror("shm_base error:\n");
		exit(1);
	}
	printf("Content in share memory:\n");
	printf("%s", shm_base);

	if(munmap(shm_base, 1024) == -1) {
                perror("munmap error:\n");
                exit(1);
        }
	if(close(shm_fd) == -1) {
                perror("close error:\n");
                exit(1);
        }

	return 0;
}
