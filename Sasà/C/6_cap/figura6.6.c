#include <stdio.h>
#include <stdlib.h>
#define SIZE 12

int main(void) {
	system("clear");

//usa una lista di inizializzatori per inizializzare l'array
int a[SIZE] = {1, 3, 5, 4, 7, 2, 99, 16, 45, 67, 89, 45};
int totale = 0; //somma dell'array

//somma i valori contenuti nell'array a
for (size_t i = 0; i < SIZE; ++i) {
	totale += a[i];
 		}

	printf("gli elemnti totali all'interno dell'array valgono:%d\n",totale );
}
