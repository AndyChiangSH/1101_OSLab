#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/msg.h>
#define MSG_FILE "/etc/passwd"
#define MAX_SIZE 1000

struct msg_form {
	long mtype;
	char mtext[MAX_SIZE];
};

int msqid;
pthread_t tsender, treceiver;

void *sender(void *arg) {
	struct msg_form msg;
	while(1) {
		msg.mtype = 1;
		printf("A:\n");
		scanf("%s", msg.mtext);
		msgsnd(msqid, &msg, sizeof(msg.mtext), 0);
		if(strcmp(msg.mtext, "exit") == 0) {
			printf("end A sender\n");
			break;
		}
	}
	pthread_cancel(treceiver);
	pthread_exit(NULL);
}

void *receiver(void *arg) {
	struct msg_form msg;
	while(1) {		
		msgrcv(msqid, &msg, MAX_SIZE, 2, 0);
		printf("B: %s\n", msg.mtext);
		if(strcmp(msg.mtext, "exit") == 0) {
			printf("end A receiver\n");
			break;
		}
	}
	pthread_cancel(tsender);
	pthread_exit(NULL);
}

int main() {
	key_t key;
	struct msg_form msg;

	if((key = ftok(MSG_FILE, 'z')) < 0) {
		perror("ftok error");
		exit(-1);
	}
	if((msqid = msgget(key, IPC_CREAT|0777)) == -1) {
		perror("msgget error");
                exit(-1);
	}

	// thread setting
	int r;
	r = pthread_create(&tsender, NULL, sender, NULL);
	if(r) {
		printf("CREATE ERROR");
		exit(-1);
	}
	r = pthread_create(&treceiver, NULL, receiver, NULL);
	if(r) {
		printf("CREATE ERROR");
		exit(-1);
	}

	void *ret;
	r = pthread_join(tsender, &ret);
	if(r) {
		printf("JOIN ERROR\n");
		exit(-1);
	}
	r = pthread_join(treceiver, &ret);
        if(r) {
                printf("JOIN ERROR\n");
                exit(-1);
        }

	printf("Done!\n");
	return 0;
}
