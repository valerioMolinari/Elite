#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int main(void) {
	system("clear");

//usa la lista di inizializzatori per inizializzare l'array n
int n[SIZE]= {19, 3, 15, 7, 11};

printf("%s%13s%18s\n", "element", "Value", "Histogram" );

//per ogni elemento dell'array n, stampa una barra dell'istogramma
for (size_t i = 0; i < SIZE; ++i) {
	printf("%7lu%13d         ", i, n[i]);

	for (size_t j = 0; j <= n[i]; ++j) {//stampa una barra
		printf("%c", '*' );
	}
	puts(""); //termina la barra dell'istogramma con un newline
 }

}
