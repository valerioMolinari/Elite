#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 256
#define MESCOLATO 26

int main(void) {
	system("clear");

char frase_criptata[SIZE];//frase criptata con il cifrario di cesare
char parola_da_criptare[SIZE];//frase inserita da tastiera
char alfabeto_mescolato[MESCOLATO];
int key = 0;
int scelta;

int contatore = 0 ;
while (contatore == 0){

printf("Immetti la frase da codificare in minuscolo gentilmente:\n");
fgets(parola_da_criptare, sizeof(parola_da_criptare), stdin);

if (contatore == 1 ) {
	printf("è scritto con il carattere minuscolo\n"/*, parola_da_criptare */);
	contatore = 1;
}else if(contatore = 0){
	printf("Non è scritto in carattere miniscolo\n"/*, parola_da_criptare*/ );

}
}
/*int lunghezza_stringa = strlen(parola_da_criptare) -1;
for (size_t i = 0; i < lunghezza_stringa; ++i)
	parola_da_criptare[i] = tolower (parola_da_criptare[i]);*/

printf("decidere la modalità di cifratura:\n");
printf("Scegli 1 se vuoi usare il cifrario di Cesare.\n");
printf("Scegli 2 se vuoi usare il crifrario a Sostituzione.\n");
scanf("%d", &scelta);

	switch (scelta) {
		case 1:

		printf("Hai scelto il Cifrario di Cesare\n" );

		int contatore = 0;
		while (contatore == 0) {

		printf("inserisci la chiave con cui si vuole codificare:" );
		scanf("%d", &key );

			if (key < 26 && key > 0 ) {

					for (size_t i = 0; i < strlen(parola_da_criptare) - 1; i++) {
						if (parola_da_criptare[i] >= 97 && parola_da_criptare[i] <= 122)
							frase_criptata[i] = 97 + (((parola_da_criptare[i] % 97) + key) %26);
					}
							printf("La frase cifrata è: %s\n", frase_criptata );
								contatore = 1;
			}
			   				else  {
			   					printf("Hai inserito %d, UTONTO riprova con un numero tra 1 e 25\n", key );
			 				  }
		}
	 break;

		 case 2:

		 printf("Hai scelto il Cifrario a Sostituzione\n" );
		 printf("Inserisci l'alfabeto mescolato a tuo piacere: " );
		 scanf("%s", alfabeto_mescolato );

			   for (size_t i = 0; i < MESCOLATO; ++i)
				    for (size_t j = i + 1 ; j < 25; ++j)
							if (alfabeto_mescolato[j] > alfabeto_mescolato[j + 1]){



						}
						if (isalpha(alfabeto_mescolato)) {
							printf("%s è un alfabeto valido", alfabeto_mescolato );
						}
						else
							printf("%s non è un alfabeto valido ", alfabeto_mescolato );









	}




}
