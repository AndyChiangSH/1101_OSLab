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
	char msg[50], res[50];

	sock = socket(PF_INET, SOCK_DGRAM, 0);
	printf("Client socket: %d\n", sock);
	if(!sock) {
		printf("Error: Can't creat socket!\n");
		return 0;
	}
	bzero(&address, address_len);
	address.sin_family = AF_INET;
	address.sin_port = htons(SERVER_PORT);
	address.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
	printf("server socket port: %d\n", address.sin_port);
	printf("server socket address: %d\n", address.sin_addr.s_addr);
	printf("Ready, start to send message:\n");

	printf("client: ");
	scanf("%s", msg);
	msg_size = sendto(sock, msg, 50, 0, (struct sockaddr*)&address, address_len);
	if(msg_size < 0) {
		printf("Error: Send fail.\n");
		return 0;
	} 
	res_size = recvfrom(sock, res, sizeof(res), 0, (struct sockaddr*)&address, &address_len);
	if(res_size < 0) {
		printf("Error: Receiving.\n");
		exit(1);
	}
	printf("server socket port: %d\n", address.sin_port);
	printf("server socket address: %d\n", address.sin_addr.s_addr);
	printf("server: %s\n", res);

	return 0;
}
