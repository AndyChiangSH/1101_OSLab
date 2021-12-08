#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void SIGALRM_handler2() {
	signal(SIGINT, SIG_DFL);
}

void SIGINT_handler2() {
	printf("I am fine!\n");
}

void SIGALRM_handler1() {
	signal(SIGINT, SIGINT_handler2);
	signal(SIGALRM, SIGALRM_handler2);
	alarm(3);
}

void SIGINT_handler1() {
	printf("How are you?\n");
}

int main(void) {
	signal(SIGINT, SIGINT_handler1);
	signal(SIGALRM, SIGALRM_handler1);
	alarm(3);
	
	for(;;) {
		pause();
	}

	return 0;
}
