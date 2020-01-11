#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

size_t getSize(const float * const ptr) {
	return sizeof(ptr);
}

int main(void) {
	system("clear");
	float array[SIZE];

	printf("The number of bytes in the array is %lu\n"
				 "The number of bytes returned by getSize is %lu\n\n"
				 "The number of elements in the array can be calculated\n"
				 "dividing sizeof(array) by sizeof(array[0]): %lu\n\n",
			 	 sizeof(array), getSize(array), sizeof(array) / sizeof(array[0]));

}
