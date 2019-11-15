#include <stdio.h>
#include <stdlib.h>

int main(void) {
	system("clear");

int n[5];//n è un array di 5 interi

//imposta gli elementi dell'array n a 0
for (size_t i = 0; i < 5; ++i) {
	n[i] = 0;//imposta a 0 l'elemento alla locazione i

}

printf("%s%13s\n", "Elemento", "Valore" );

//invia in uscita i contenuti dell'array n in formato tabellare
for (size_t i = 0; i < 5; ++i) {
 	printf("%7lu%13d\n", i, n[i] );
}


}
