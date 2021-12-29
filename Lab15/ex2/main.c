#include <stdio.h>

int main() {
	int array[] = {15, 22, 41, 8, 35};
	
	printf("Before sort is: ");
	for(int i = 0; i < 5; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	
	sort(array, 5);
	
	printf("After sort is: ");
	for(int i = 0; i < 5; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	
	return 0;
}
