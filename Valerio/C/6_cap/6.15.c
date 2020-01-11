#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#define SIZE 20

void nonStampareDuplicati(int array[], size_t size) {
	printf("{ ");
	int b;
	for (size_t i = 0; i < size; i++) {
		b = 0;
		for (size_t j = 0; j < i; j++)
			if (array[j] == array[i]) {
				b = 1;
				break;
			}
		if (!b)
			printf("%d ", array[i]);
	}
	printf(" }\n");
}

void printArray(int array[], size_t size) {
	printf("{ ");
	for (size_t i = 0; i < size; i++)
			printf("%d ", array[i]);
	printf("}\n");
}

int main(void) {
	srand(time(NULL));
	system("clear");

	int array[SIZE];

	for (size_t i = 0; i < SIZE; i++)
		array[i] = rand() % 91 + 10;

	printf("Array in forma normale:\t");
	printArray(array, SIZE);

	printf("\nArray senza duplicati:  ");
	nonStampareDuplicati(array, SIZE);
	puts("");
}
