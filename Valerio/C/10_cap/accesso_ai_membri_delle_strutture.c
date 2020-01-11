#include <stdio.h>
#include <stdlib.h>

struct card {
	char *suit;
	char *face;
}; // Ricorda il punto fottuto e virgola

int main(void) {
	system("clear");

	struct card aCard; // Dichiarazione della variabile aCard di tipo struct card

	aCard.face = "Ace"; // Accesso alle proprietà di aCard tramite notazione a punto
	aCard.suit = "Spades";

	struct card *cardPtr = &aCard;

	printf("%s%s%s\n%s%s%s\n%s%s%s\n",
	 	aCard.face, " of ", aCard.suit, // Stampa tramite notazione a punto per le variabili
		cardPtr->face, " of ", cardPtr->suit, // Stampa tramite notazione a freccia per i puntatori
		(*cardPtr).face, " of ", (*cardPtr).suit // Stampa tramite notazione a punto per puntatori dereferenziati
	);
}
