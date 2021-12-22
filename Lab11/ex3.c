#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void SIGALRM_handler1() {
	printf("Hello!\n");
	kill(getpid(), SIGTERM);
}

int main(void) {
	signal(SIGALRM, SIGALRM_handler1);
	alarm(1);
	alarm(2);
	alarm(3);
	
	// alarm後面會覆蓋前面的
	
	for(;;) {
		pause();
	}

	return 0;
}
