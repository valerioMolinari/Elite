#include <stdio.h>
#include <stdlib.h>
#define risposte_SIZE 40// definisci le dimensione degli array
#define frequency_SIZE 11

int main(void) {
	system("clear");

//inizializza i contatori per le frequenze a a 0
int frequency[frequency_SIZE] = {0};

//inserisci le risposte del sondaggio nell'array delle risposte
int risposte[risposte_SIZE] = {1, 2, 6, 4, 8, 5, 9, 7, 8, 10,
			1, 6, 3, 8, 6, 10, 3, 8, 2, 7, 6, 5, 7, 6, 8, 6, 7, 5, 6, 6,
			5, 6, 7, 5, 6, 4, 8, 6, 8, 10};

/*per ogni risposta, seleziona il valore di un elemento dell'array risposte
e usa quel valore come indice nell'array frequency per determinare
l'elemnto da incrementare*/
for (size_t domanda = 0; domanda < risposte_SIZE; ++domanda) {
	++frequency[risposte [domanda]];
	}

//stampa i risultati
printf("%s%17s\n", "rating", "frequency" );

//stampa le frequenze in un formato tabellare
for (size_t rating = 1; rating < frequency_SIZE; ++rating) {
	printf("%6ld%17d\n", rating, frequency[rating]);
	}
}
