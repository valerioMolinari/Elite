#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256

int main(void) {
	system("clear");

char frase_criptata[SIZE];//frase criptata con il cifrario di cesare
char parola_da_criptare[SIZE];//frase inserita da tastiera
int key = 0;
int scelta;

printf("Immetti la frase da codificare:\n");
fgets(parola_da_criptare, sizeof(parola_da_criptare), stdin);

printf("decidere la modalità di cifratura:\n");
printf("Scegli '1' se vuoi usare il cifrario di Cesare.\n");
printf("Scegli '2' se vuoi usare il crifrario a Sostituzione.\n");
scanf("%d", &scelta);

	switch (scelta) {
		case '1':

		printf("Hai scelto il Cifrario di Cesare\n" );

		printf("inserisci la chiave con cui si vuole codificare:" );
		scanf("%d", &key );

			if (key < 26 && key > 0 ) {

				for (size_t i = 0; i < strlen(parola_da_criptare) - 1; i++) {
					frase_criptata[i] = 97 + (((parola_da_criptare[i] % 97) + key) %26);
				}
					printf("La frase cifrata è: %d\n" );
					scanf("%s", frase_criptata[i] );

			}

		  else printf("Hai inserito %d, UTONTO riprova", key );

			break;


	}





}
