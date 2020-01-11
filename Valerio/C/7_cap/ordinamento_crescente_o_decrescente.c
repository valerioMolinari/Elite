#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

void swap(int *ptr1, int *ptr2) {
	int hold = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = hold;
}

// int (*function)(int a, int b) è un puntatore a una funzione che
// riceve due interi e restituisce un intero.
// Le parentesi intorno a *function servono a distinguere da
// int *function(int a, int b) che sarebbe una funzione che
// riceve due interi e restituisce un puntatore a intero
void bubble(int work[], size_t size, int (*function)(int a, int b)) {
	int change;
	for (size_t i = 0; i < size - 1; i++) {
		change = 0;
		for (size_t j = 0; j < size - 1; j++) {
			if (function(work[j], work[j + 1])) {
				swap(&work[j], &work[j + 1])
				change = 1;
			}
		}
		if (!change) break;
	}
}

int ascending(int a, int b) {
	return a > b;
}

int descending(int a, int b) {
	return a < b;
}

void printArray(const int * nPtr, const size_t size) {
	for (size_t i = 0; i < size; i++)
		printf("%3d ", *nPtr++);
}

int main(void) {
	system("clear");
	srand(time(NULL));
	int a[SIZE];
	int order;
	for (size_t i = 0; i < SIZE; i++)
		a[i] = rand() % 50 + 1;

	do {
		printf("Enter 1 to sort in ascending order\n"
					 "Enter 2 to sort in descending order: ");
		scanf("%d", &order);
	} while(order != 1 && order != 2);

	printf("Unsorted array\t:  ");
	printArray(a, SIZE);

	switch (order) {
		case 1: bubble(a, SIZE, ascending); break;
		case 2: bubble(a, SIZE, descending);
	}

	printf("\nSorted array\t:  ");
	printArray(a, SIZE);
	puts("\n");
}
