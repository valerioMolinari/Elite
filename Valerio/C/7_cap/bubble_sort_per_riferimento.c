#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

void swap(int *ptr1, int *ptr2) {
	int hold = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = hold;
}

void bubbleSort(int * const array, const size_t size) {
	int change;
	for (size_t i = 0; i < size - 1; i++) {
		change = 0;
		for (size_t j = 0; j < size - 1; j++)
			if (array[j] > array[j + 1]) {
				swap(&array[j], &array[j + 1]);
				change = 1;
			}
		if (!change) break;
	}
}

void printArray(const int * nPtr, const size_t size) {
	for (size_t i = 0; i < size; i++)
		printf("%3d ", *nPtr++);
}

int main(void) {
	system("clear");
	srand(time(NULL));
	int a[SIZE];
	for (size_t i = 0; i < SIZE; i++)
		a[i] = rand() % 50 + 1;
	printf("Unsorted array\t:  ");
	printArray(a, SIZE);

	printf("\nSorted array\t:  ");
	bubbleSort(a, SIZE);
	printArray(a, SIZE);
	puts("\n");
}
