#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

int main(void) {
	system("clear");
	int b[] = {10, 20, 30, 40};
	int *bPtr = b;

	puts("Array b printed with\narray index notation");
	for (size_t i = 0; i < SIZE; i++)
		printf("b[%lu] = %d\n", i, b[i]);

	puts("\nPointer/offset notation where\n"
			 "the pointer is the array name");
	for (size_t i = 0; i < SIZE; i++)
		printf("*(b + %lu) = %d\n", i, *(b + i));

	puts("\nPointer subscript notation");
	for (size_t i = 0; i < SIZE; i++)
		printf("bPtr[%lu] = %d\n", i, bPtr[i]);

	puts("\nPointer/offset notation");
	for (size_t i = 0; i < SIZE; i++)
		printf("*(bPtr + %lu) = %d\n", i, *(bPtr + i));
}
