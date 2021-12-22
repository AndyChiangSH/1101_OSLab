#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static __thread int glob = 0;

void *incr(void* arg) {
	int* tmp = (int*)arg;
	// printf("tmp = %d\n", *tmp);
	int loc, i = 0;
	for(i = 0; i < *tmp; i++) {
		loc = glob;
		loc++;
		glob = loc;
	}
	printf("thread_ID = %ld, glob = %d\n", pthread_self(), glob);
	pthread_exit(NULL);
}

int main(void) {
	int p1 = 50, p2 = 100;
	pthread_t id[2];
	
	printf("(main thread) glon value before running 2 thread: %d\n", glob);
	pthread_create(&id[0], NULL, incr, &p1);
	pthread_create(&id[1], NULL, incr, &p2);
	
	pthread_join(id[0], NULL);
	pthread_join(id[1], NULL);
	printf("(main thread) glon value after running 2 thread: %d\n", glob);
	
	return 0;
}
