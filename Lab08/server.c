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
	int sock, res_size, address_len, client_address_len = sizeof(client_address);
	char res[50];

	sock = socket(PF_INET, SOCK_DGRAM, 0);
	printf("Server socket: %d\n", sock);
	if(sock < 0) {
		printf("Error: Can't creat socket.\n");
		return 0;
	}
	bzero(&address, sizeof(address));
	// bzero(&address, sizeof(client_address));
	address.sin_family = AF_INET;
	address.sin_port = htons(SERVER_PORT);
	address.sin_addr.s_addr = INADDR_ANY;
	printf("server socket port: %d\n", address.sin_port);
	printf("server socket address: %d\n", address.sin_addr.s_addr);

	if(bind(sock, (struct sockaddr *)&address, sizeof(address)) == -1) {
		printf("Error: Bind file.\n");
		return 0;
	}

	printf("Server ready to receive:\n");
	res_size = recvfrom(sock, res, sizeof(res), 0, (struct sockaddr *)&client_address, &client_address_len);
	if(res_size < 0) {
		printf("Error: Receiving\n");
		exit(1);
	}
	printf("client socket port: %d\n", client_address.sin_port);
	printf("client socket address: %d\n", client_address.sin_addr.s_addr);
	printf("client: %s\n", res);

	int msg_size;
	msg_size = sendto(sock, "server OK!", 50, 0, (struct sockaddr*)&client_address, client_address_len);
	if(msg_size < 0) {
		printf("Error: Send fail.\n");
		exit(1);
	}
	printf("server: server OK!\n");

	return 0;
}
