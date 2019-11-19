#include <stdio.h>
#include <stdlib.h>
#include <string.h> //gestione delle stringhe
#include <ctype.h> //funzione che testa e mappa i caratteri
#define SIZE 256 //variabile definita di valore 256 e non modificabole all'interno del programma
#define MESCOLATO 26//variabile definita di valore 26 e non modificabole all'interno del programma

int main(void) {
	system("clear");

	//dichiarazioni delle variabili
	char frase_criptata[SIZE];//frase criptata con il cifrario di cesare
	char parola_da_criptare[SIZE];//frase inserita da tastiera
	char alfabeto_mescolato[MESCOLATO];//alfabeto creato dall'utente
	const char alfabeto_inglese[MESCOLATO]= "abcdefghijklmnopqrstuvwxyz";//alfabeto inglese
	int key = 0;//chiave per il cifrario di Cesare
	int scelta;//scelta del cifrario che si vuole usare
	char verifica[MESCOLATO];// variabile che controlla le posizioni di una lettera o consonante

	//volevo usare un while per la funzione islower
	/*int contatore = 0 ;
	while (contatore == 0){*/

	printf("Inserisci la frase da codificare in minuscolo gentilmente:\n");
	fgets(parola_da_criptare, sizeof(parola_da_criptare), stdin);

  //Ho provato con islower ma mi usciva un ciclo infinito e ho usato tolower, stessa cosa
	//con l'inserimento di caratteri numerici nella frase iniziale

	/*if (islower(parola_da_criptare) == 1 ) {
			printf("è scritto con il carattere minuscolo\n");
			contatore = 1;
				}else if(contatore = 0){
					printf("Non è scritto in carattere miniscolo\n" );
				}*/

  //strlen calcola la lunghezza della stringa
  //tolower trasforma la parola da criptare in minuscolo
	int lunghezza_stringa = sizeof(parola_da_criptare) -1;
	for (size_t i = 0; i < lunghezza_stringa; ++i)
	parola_da_criptare[i] = tolower (parola_da_criptare[i]);

	//seleziona la cifratura che vuoi usare
	printf("decidere la modalità di cifratura:\n");
	printf("Scegli 1 se vuoi usare il cifrario di Cesare.\n");
	printf("Scegli 2 se vuoi usare il crifrario a Sostituzione.\n");
	scanf("%d", &scelta);

	switch (scelta) {
		//Cifario di Cesare
		case 1:

		printf("Hai scelto il Cifrario di Cesare\n" );

		int contatore = 0;
		while (contatore == 0) {

			//inserimento chiave
			printf("inserisci la chiave con cui si vuole codificare:" );
			scanf("%d", &key );

			if (key < 26 && key > 0 ) {
   				//strlen è una funzione che viene usata per calcolare la lunghezza della stringa
					for (size_t i = 0; i < sizeof(parola_da_criptare) - 1; i++) {
						if (parola_da_criptare[i] >= 97 && parola_da_criptare[i] <= 122)
							frase_criptata[i] = 97 + (((parola_da_criptare[i] % 97) + key) %26);
					}
							printf("La frase cifrata è: >%s\n", frase_criptata );
								contatore = 1;
			}else{
			 	printf("Hai inserito %d, UTONTO riprova con un numero tra 1 e 25\n", key );
			}
		}
	 break;
	 		//Cifrario a Sostituzione
		case 2:
		//inserimento alfabeto mescolato
		printf("Hai scelto il Cifrario a Sostituzione\n" );
		printf("Inserisci l'alfabeto mescolato a tuo piacere: " );


		   for (size_t i = 0; i < MESCOLATO; ++i){
				 	scanf("%c\n", &alfabeto_mescolato[i]);
			}
					//verifica le posizioni dell'alfabeto
			 		for (size_t i = 0; i < sizeof(parola_da_criptare); ++i) {
			 			for (size_t j = 0; j < 25; ++j) {
			 				 if (parola_da_criptare[i] == alfabeto_inglese[j]) {
			 				 verifica[i] = j;
						 }
						}
			 		}

			 for (size_t i = 0; i < lunghezza_stringa; i++){
					if (parola_da_criptare[i] >= 97 && parola_da_criptare[i] <= 122){
					parola_da_criptare[i] = (alfabeto_mescolato[parola_da_criptare[i] - 96]);
				}
			}
				printf("La frase inserita è stata criptata tramite il cifrario di sostituzione:\n\n>%s\n", parola_da_criptare);

		break;
	}
}
