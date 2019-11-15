#include <stdio.h>
#include <stdlib.h>

int main(void){
	system("clear");
	int a = 7;
	int *aPtr = &a;

	printf("The address of \"a\" is %p\nThe value of \"aPtr\" is %p\n\n", &a, aPtr);
	printf("The value of \"a\" is %d\nThe value of \"*aPtr\" is %d\n\n", a, *aPtr);
	puts("Showing that * and & are complements of each other:\n");
	printf("&*aPtr = %p\n*&aPtr = %p\n\n", &*aPtr, *&aPtr);
}
