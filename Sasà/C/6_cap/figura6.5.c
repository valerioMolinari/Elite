#include <stdio.h>
#include <stdlib.h>
#define SIZE 5 //dimensione dell'array

int main(void) {
	system("clear");

//la costante simbolica"SIZE" specifica la dimensione dell'array
int s[SIZE]; //l'array s ha un numero di elementi uguali a size_

for (size_t j = 0; j < SIZE; ++j) {
	s[j] = 2 + 2 * j;
}

printf("%s%13s\n", "Elemento", "Valore" );

//invia in uscita i contenuti dell'array n in formato tabellare
for (size_t j = 0; j < SIZE; ++j) {
 	printf("%7lu%13d\n", j, s[j] );
}

}
