#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define SERVER_PORT 5555
#define SERVER_ADDRESS "10.0.2.15"

int main(int argc, char **argv[]) {
	struct sockaddr_in address;
	int sock, address_len = sizeof(address), msg_size, res_size;
	char res[50];

	sock = socket(PF_INET, SOCK_DGRAM, 0);
	if(!sock) {
		printf("ERROR: Can't create socket\n");
		exit(1);
	}

	bzero(&address, address_len);
	address.sin_family = AF_INET;
	address.sin_port = htons(SERVER_PORT);
	address.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);

	int client_num = 0;
	printf("client number is %d\n", client_num);
	while(1) {
		msg_size = sendto(sock, &client_num, sizeof(client_num), 0, (struct sockaddr*)&address, address_len);
		if(msg_size < 0) {
			printf("ERROR: Send fail\n");
			exit(1);
		}
		printf("msg is %d\n", client_num);

		res_size = recvfrom(sock, res, sizeof(res), 0, (struct sockaddr*)&address, &address_len);
		if(res_size < 0) {
			printf("ERROR: Receive fail\n");
			exit(1);
		}
		printf("server: %s\n", res);
		if(strcmp(res, "correct!") == 0) {
			break;
		}
		client_num++;
	}

	return 0;
}


