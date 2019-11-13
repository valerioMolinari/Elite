#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int array[], size_t size) {
	int hold;
	int change = 0;
	for (size_t i = 0; i < size-1; i++) {
		change = 0;
		for (size_t j = 0; j < size-1; j++)
			if (array[j] > array[j+1]) {
				hold = array[j];
				array[j] = array[j + 1];
				array[j + 1] = hold;
				change = 1;
			}
		size--;
		if (!change) break;
	}
}

void printArray(int array[], size_t size) {
	printf("{ ");
	for (size_t i = 0; i < size; i++) {
		if (i == size - 1)
			printf("%d", array[i]);
		else
			printf("%d, ", array[i]);
	}
	printf(" }\n");
}

int main(void) {
	system("clear");

	int array[15] = {1, 95, 3, 85, 4, 7, 24, 33, 13, 6, 24, 21, 19, 97, 12};

	printf("Unordered array:\t");
	printArray(array, 15);

	printf("\nOrdered array:\t\t");
	bubbleSort(array, 15);
	printArray(array, 15);
	puts("");
}
