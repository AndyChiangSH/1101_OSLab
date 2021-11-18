#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	if(fork() == 0) {	// B
		if(fork() == 0) {	// E
			if(fork() == 0) {	// H
				printf("I'm process H:\n");
				printf("PID: %d\n", getpid());
				printf("parent PID: %d\n", getppid());
				return 0;
			}
			wait(NULL);

			printf("I'm process E:\n");
			printf("PID: %d\n", getpid());
			printf("parent PID: %d\n", getppid());
			return 0;
		}
		if(fork() == 0) {       // F
			printf("I'm process F:\n");
		        printf("PID: %d\n", getpid());
		        printf("parent PID: %d\n", getppid());
			return 0;
		}
		wait(NULL);
		wait(NULL);

		printf("I'm process B:\n");
		printf("PID: %d\n", getpid());
		printf("parent PID: %d\n", getppid());
		return 0;
	}
	if(fork() == 0) {       // C
		if(fork() == 0) {       // G
			printf("I'm process G:\n");
			printf("PID: %d\n", getpid());
			printf("parent PID: %d\n", getppid());
			return 0;
		}
		wait(NULL);

		printf("I'm process C:\n");
                printf("PID: %d\n", getpid());
                printf("parent PID: %d\n", getppid());
		return 0;
        }
	if(fork() == 0) {       // D
		printf("I'm process D:\n");
                printf("PID: %d\n", getpid());
                printf("parent PID: %d\n", getppid());
		return 0;
        }
	wait(NULL);
	wait(NULL);
	wait(NULL);

	printf("I'm process A:\n");
        printf("PID: %d\n", getpid());
        printf("parent PID: %d\n", getppid());
       	
	return 0;
}
