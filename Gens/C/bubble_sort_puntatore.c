#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void bubblesort(int *const array, const size_t b);
void swap(int *element1Ptr, int *element2Ptr);

int main(void) {
	system("clear");

	int a = 0;
	int numeri[a];
	printf("Quanti numeri vuoi inserire?\n");
	scanf("%d", &a);
	printf("Inserisci fino a %d interi in modo sparso ed io li rimetterò in ordine crescente:\n", a);
	 for(unsigned int i = 0; i < a; ++i){
		 scanf("%d", &numeri[i]);
	 }

	 bubblesort(numeri, a);

	 puts("");
	 puts("I numeri in ordine crescente sono:");
	 for(unsigned int i = 0; i < a; ++i){
		 printf("%d\n", numeri[i]);
	 }
	 puts("");
}

void bubblesort(int *const array, const size_t b){
		for(unsigned int i = 0; i < b - 1; ++i){
			for(size_t j = 0; j < b - 1; ++j){
				if(array[j] > array[j + 1]){
					swap(&array[j], &array[j + 1]);
				}
			}
		}
}

void swap(int *element1Ptr, int *element2Ptr){
	int inverti = 0;
	inverti = *element1Ptr;
	*element1Ptr = *element2Ptr;
	*element2Ptr = inverti;
}
