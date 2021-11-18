#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
	if(fork() == 0) {
		printf("I'm child process E.\n");
		printf("PID: %d\tParent PID: %d\n", getpid(), getppid());
		return 0;
	}
	wait(NULL);
	if(fork() == 0) {
		printf("I'm child process D.\n");
		printf("PID: %d\tParent PID: %d\n", getpid(), getppid());
		return 0;
	}
	wait(NULL);
	if(fork() == 0) {
		if(fork() == 0) {
			printf("I'm child process C.\n");
			printf("PID: %d\tParent PID: %d\n", getpid(), getppid());
			return 0;
		}
		wait(NULL);
		printf("I'm child process B.\n");
		printf("PID: %d\tParent PID: %d\n", getpid(), getppid());
		return 0;
	}
	wait(NULL);
	
	printf("I'm child process A.\n");
	printf("PID: %d\tParent PID: %d\n", getpid(), getppid());
	return 0;
}
