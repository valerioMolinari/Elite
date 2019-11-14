#include <stdio.h>
#include <stdlib.h>

int main(void) {
	system("clear");


	int miglia;//miglia percorsi
	int galloni;//galloni consumati a ogni pieno inseriti dall'utente
	int media; //media del serbatoio per i (miglia/galloni)
	int media_totale;// media totale del serbatoio per i (miglia/galloni)
	int totale;

	int contatore= 0;
	totale= 0;
	
  while (galloni!=-1) {
		printf("%s", "inserisci i galloni usati: " );
		scanf("%d", &galloni );
    printf("%s", "inserisci le miglia percorsi: " );
		scanf("%d", &miglia );
		media= miglia/galloni;
		printf("la media per questo serbatoio è: %d\n", media );
		totale = totale + media;
		contatore++;
	}

	 if (galloni==-1){

		media_totale= totale/contatore;
		printf("la media totale del consumo del carburante fino ad ora è: %d\n", media_totale );
	}

}
