#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cubeByValue(int n) {
	return pow(n, 3);
}

void cubeByReference(int *nPtr) {
	*nPtr = pow(*nPtr, 3);
}

int main(void){
	system("clear");
	int n1 = 4;
	int n2 = 5;

	printf("The original value of n1 is %d\n", n1);
	n1 = cubeByValue(n1);
	printf("The new value using cubeByValue is %d\n\n", n1);

	printf("The original value of n2 is %d\n", n2);
	cubeByReference(&n2);
	printf("The new value using cubeByReference is %d\n\n", n2);
}
