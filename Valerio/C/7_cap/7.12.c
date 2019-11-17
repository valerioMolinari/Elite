#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SUITS 4
#define FACES 13
#define CARDS 52
#define HAND 5

void mischia(unsigned int *wDeck);

void stampaCarte(unsigned int *wDeck, const char *wFace[], const char *wSuit[], size_t size);

void creaMano(unsigned int *wDeck, unsigned int *hand);

unsigned int coppia(unsigned int *wHand);

unsigned int doppiaCoppia(unsigned int *wHand);

unsigned int tris(unsigned int *wHand);

unsigned int scala(unsigned int *wHand);

unsigned int colore(unsigned int *wHand);

unsigned int full(unsigned int *wHand);

unsigned int poker(unsigned int *wHand);

unsigned int scalaReale(unsigned int *wHand);





int main(void) {
	system("clear");
	srand(time(NULL));

	unsigned int deck[CARDS] = {0};
	unsigned int hand[5] = {0};
	const char *suit[SUITS] = {"Cuori", "Quadri", "Fiori", "Picche"};
	const char *face[FACES] = {
		"Asso", "Due", "Tre", "Quattro", "Cinque", "Sei", "Sette",
		"Otto", "Nove", "Dieci", "Jack", "Regina", "Re"
	};

	mischia(deck);
	creaMano(deck, hand);

	stampaCarte(deck, face, suit, CARDS);
	stampaCarte(hand, face, suit, HAND);

	printf("\n%s\n", coppia(hand) ? "Coppia" : "Nessun punto");

	puts("");
	return 0;
}

void mischia(unsigned int *wDeck) {
	for (size_t card = 1; card <= CARDS; card++) {
		size_t row;
		size_t column;
		do {
			row = rand() % SUITS;
			column = rand() % FACES;
		} while(wDeck[row * FACES + column] != 0);
		wDeck[row * FACES + column] = card;
	}
}

void stampaCarte(unsigned int *wDeck, const char *wFace[], const char *wSuit[], size_t size) {
	for (size_t card = 0; card < size; card++) {
		const char *face = wFace[(wDeck[card] - 1) % 13];
		const char *suit = wSuit[(wDeck[card] - 1) / 13];
		printf("%5s di %-8s%c", face, suit, card % 2 ? '\n' : '\t');
	}
	puts("");
}

void creaMano(unsigned int *wDeck, unsigned int *wHand) {
	for (size_t i = 0; i < 5; i++)
		wHand[i] = wDeck[i];
}

unsigned int coppia(unsigned int *wHand) {
	for (size_t i = 0; i < 4; i++)
		for (size_t j = i + 1; j < 5; j++)
			if ((wHand[i] % 13) == (wHand[j] % 13))
				return 1;
	return 0;
}
