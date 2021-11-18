#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define SERVER_PORT 5555

int main(int argc, char **argv[]) {
	struct sockaddr_in address, client_address;
	int sock, address_len = sizeof(address), client_address_len = sizeof(client_address), msg_size, res_size;
	char msg[50];
	int res;

	sock = socket(PF_INET, SOCK_DGRAM, 0);
	if(!sock) {
		printf("ERROR: Can't create socket\n");
		exit(1);
	}

	bzero(&address, address_len);
	address.sin_family = AF_INET;
	address.sin_port = htons(SERVER_PORT);
	address.sin_addr.s_addr = INADDR_ANY;
	if(bind(sock, (struct sockaddr*)&address, address_len) < 0) {
		printf("ERROR: Can't bind\n");
		exit(1);
	}

	int server_num = 7;

	printf("server number is %d\n", server_num);
	while(1) {
		res_size = recvfrom(sock, &res, sizeof(res), 0, (struct sockaddr*)&client_address, &client_address_len);
		if(res_size < 0) {
			printf("ERROR: Receive fail\n");
			exit(1);
		}
		printf("client: %d\n", res);

		if(res < server_num) {
			msg_size = sendto(sock, "wrong!", 10, 0, (struct sockaddr*)&client_address, client_address_len);
			if(msg_size < 0) {
				printf("ERROR: Send fail\n");
				exit(1);
			}
		}
		else {
			msg_size = sendto(sock, "correct!", 10, 0, (struct sockaddr*)&client_address, client_address_len);
			if(msg_size < 0) {
				printf("ERROR: Send fail\n");
				exit(1);
			}
			break;
		}
		
	}

	return 0;
}
