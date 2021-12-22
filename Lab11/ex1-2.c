#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void SIGALRM_handler() {
	kill(getpid(), SIGTERM);
}

int main(void) {
	signal(SIGALRM, SIGALRM_handler);
	pid_t pid = fork();
	if(pid < 0) {
		printf("error");
		return 0;
	}
	else if(pid == 0) {
		printf("I am child, pid = %d, ppid = %d\n", getpid(), getppid());
		alarm(3);
		for(;;) {
			pause();
		}
		exit(0);
	}
	else {
		printf("I am parent, pid = %d, ppid = %d\n", getpid(), getppid());
		alarm(5);
		for(;;) {
			pause();
		}
	}

	return 0;
}
