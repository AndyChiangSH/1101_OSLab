#include <stdio.h>
#include "myc.h"

int main(void) {
	int arr[5] = {5, 4, 2, 9, 6};
	
	sort(arr, 5);
	
	for(int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	return 0;
}
