#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int global = 10;

int main() {
	int local = 10;
	pid_t child_pid;

	child_pid = fork();

	switch(child_pid) {
		case -1:
			printf("fork error\n");	
			break;
		case 0:
			printf("-----This is child process----\n");
			printf("global = %d, local = %d\n", global, local);
			global += 10;
			local += 10;
			printf("global = %d, local = %d\n", global, local);
			printf("pid = %d, ppid = %d\n", getpid(), getppid());
			break;
		default:
			wait(NULL);
			printf("-----This is parent process----\n");
			printf("global = %d, local = %d\n", global, local);
			printf("pid = %d, ppid = %d\n", getpid(), getppid());
			break;
	}
	return 0;
}
