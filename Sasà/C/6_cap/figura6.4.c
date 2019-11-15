#include <stdio.h>
#include <stdlib.h>

int main(void) {
	system("clear");

//usa una lista di inializzatori per inializzare l'array n
int n[5] = {32, 27, 64, 18, 95};

printf("%s%13s\n", "Elemento", "Valore" );

//invia in uscita i contenuti dell'array n in formato tabellare
for (size_t i = 0; i < 5; ++i) {
 	printf("%7lu%13d\n", i, n[i] );
}

}
