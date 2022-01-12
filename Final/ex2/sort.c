void sort(int* arr, int length) {
	for(int i = 0; i < length; i++) {
		int min_index = i;
		for(int j = i+1; j < length; j++) {
			if(arr[j] < arr[min_index]) {
				min_index = j;
			}
		}
		
		int temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
	}
}
