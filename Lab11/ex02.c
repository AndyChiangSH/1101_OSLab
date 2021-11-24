#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int gresult = 0;
void* child(void* arg) {
	printf("child thread:\n");
	int* input = (int*) arg;
	int* result = malloc(sizeof(int)*1);
	// result[0] = input[0] + input[1];
	gresult = input[0] + input[1];
	sleep(5);
	pthread_exit((void*) result);
}

int main() {
	pthread_t t;
	void *ret;
	int input[2] = {1, 2};
	
	pthread_create(&t, NULL, child, (void*) input);
	
	int i = 1;
	for(i = 1; i <= 3; i++) {
		sleep(1);
		printf("sleep: %d\n", i);
	}
	int r = pthread_cancel(t);
	printf("r = %d\n", r);
	printf("pthread_cancel successfully\n");
	
	printf("main thread:\n");
	
	// pthread_join(t, &ret);
	
	int* result = (int*) ret;
	// printf("%d + %d = %d\n", input[0], input[1], result[0]);
	printf("%d + %d = %d\n", input[0], input[1], gresult);
	
	// free(result);
	
	return 0;
}
