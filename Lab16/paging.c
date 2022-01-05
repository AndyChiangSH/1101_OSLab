#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int freeframe[16] = {0};
	char logmem1[3][2] = {{'a', 'b'}, {'e', 'f'}, {'c', 'd'}};
	int pt1[3] = {-1, -1, -1};
	
	for(int i = 0; i < 3; i++) {
		srand(time(NULL));
		while(1) {
			int is_dup = 0;
			int t = rand()%16;
			if(freeframe[t] == 0) {
				pt1[i] = t;
				freeframe[t] = 1;
				break;
			}
		}
	}
	
	printf("process1's logical memory:\n");
	printf("page\tdata\n");
	for(int i = 0; i < 3; i++) {
		printf("%d\t%c%c\n", i+1, logmem1[i][0], logmem1[i][1]);
	}
	
	printf("process1's page table:\n");
	printf("page\tframe\n");
	for(int i = 0; i < 3; i++) {
		printf("%d\t%d\n", i+1, pt1[i]);
	}
	
	char logmem2[3][2] = {{'r', 'x'}, {'y', 'y'}, {'z', 'z'}};
	int pt2[3] = {-1, -1, -1};
	
	for(int i = 0; i < 3; i++) {
		srand(time(NULL));
		while(1) {
			int is_dup = 0;
			int t = rand()%16;
			if(freeframe[t] == 0) {
				pt2[i] = t;
				freeframe[t] = 1;
				break;
			}
		}
	}
	
	printf("process2's logical memory:\n");
	printf("page\tdata\n");
	for(int i = 0; i < 3; i++) {
		printf("%d\t%c%c\n", i, logmem2[i][0], logmem2[i][1]);
	}
	
	printf("process2's page table:\n");
	printf("page\tframe\n");
	for(int i = 0; i < 3; i++) {
		printf("%d\t%d\n", i, pt2[i]);
	}
	
	printf("physical memory is:\n");
	printf("frame\toffset\tdata\n");
	for(int i = 0; i < 16; i++) {
		int process = -1;
		int page = -1;
		for(int j = 0; j < 3; j++) {
			if(i == pt1[j]) {
				process = 1;
				page = j;
				break;
			}
			if(i == pt2[j]) {
				process = 2;
				page = j;
				break;
			}
		}
		if(process == 1) {
			printf("%d\t0\t%c\n", i, logmem1[page][0]);
			printf("%d\t1\t%c\n", i, logmem1[page][1]);
		}
		else if(process == 2) {
			printf("%d\t0\t%c\n", i, logmem2[page][0]);
			printf("%d\t1\t%c\n", i, logmem2[page][1]);
		}
		else {
			printf("%d\t0\t\n", i);
			printf("%d\t1\t\n", i);
		}
	}
	
	printf("free-frame table is:\n");
	for(int i = 0; i < 16; i++) {
		if(freeframe[i] == 0) {
			printf("%d ", i);
		}
	}
	printf("\n");
	
	return 0;
}
