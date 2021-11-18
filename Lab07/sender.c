#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <fcntl.h>
#include <mqueue.h>
#define NAME "/msgq1"
#define MSG_STOP "/0"
#define MAX_SIZE 1000

int main(int argc, char **argv) {
	mqd_t mq1;
	char buffer[MAX_SIZE];
	struct mq_attr attr;
	attr.mq_flags = 0;
	attr.mq_maxmsg = 10;
	attr.mq_msgsize = MAX_SIZE;
	attr.mq_curmsgs = 0;

	mq1 = mq_open(NAME, O_WRONLY|O_CREAT, 0644, &attr);
	if(mq1 == -1) {
		perror("mq1 error:\n");
		exit(1);
	}
	printf("send to receiver:\n");
	while(1) {
		for(int i = 0; i < sizeof(buffer); i++) {
			buffer[i] = '\0';
		}
		printf("> ");
		fgets(buffer, MAX_SIZE, stdin);
		int send = mq_send(mq1, buffer, strlen(buffer)+1, 0);
		if(send < 0) {
			perror("message:\n");
		}
		if(strncmp(buffer, "exit", 4) == 0) {
			break;
		}
	}
	printf("sender close\n");

	return 0;
}
