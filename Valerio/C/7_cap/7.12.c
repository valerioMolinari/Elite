#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SUITS 4
#define FACES 13
#define CARDS 52
#define HAND 5

void mischia(unsigned int *wDeck);

void swap(unsigned int *ptr1, unsigned int *ptr2);

void module13Sort(unsigned int * const array, const size_t size);

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

	do {
		mischia(deck);
		creaMano(deck, hand);
		stampaCarte(hand, face, suit, HAND);

		printf("\n%s\n", coppia(hand) ? "Coppia" : "Nessuna coppia");
		printf("\n%s\n", tris(hand) ? "Tris" : "Nessun tris");
		printf("\n%s\n", scala(hand) ? "Tris" : "Nessuna scala");
		for (size_t i = 0; i < CARDS; i++)
			deck[i] = 0;
	} while(!scala(hand));

	puts("");
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

void swap(unsigned int *ptr1, unsigned int *ptr2) {
	unsigned int hold = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = hold;
}

void module13Sort(unsigned int * const array, const size_t size) {
	for (size_t i = 0; i < size - 1; i++) {
		for (size_t j = 0; j < size - 1; j++)
			if (array[j] % 13 > array[j + 1] % 13) {
				swap(&array[j], &array[j + 1]);
			}
	}
}

void stampaCarte(unsigned int *wDeck, const char *wFace[], const char *wSuit[], size_t size) {
	for (size_t card = 0; card < size; card++) {
		const char *face = wFace[(wDeck[card] - 1) % 13];
		const char *suit = wSuit[(wDeck[card] - 1) / 13];
		printf("%5s di %-8s\n", face, suit);
	}
	puts("");
}

void creaMano(unsigned int *wDeck, unsigned int *wHand) {
	for (size_t i = 0; i < 5; i++)
		wHand[i] = wDeck[i];
	module13Sort(wHand, 5);
}

unsigned int coppia(unsigned int *wHand) {
	for (size_t i = 0; i < 4; i++)
		if (wHand[i] % 13 == wHand[i + 1] % 13)
			return 1;
	return 0;
}

unsigned int tris(unsigned int *wHand) {
	unsigned int count = 0;
	for (size_t i = 0; i < 4; i++) {
		if (wHand[i] % 13 == wHand[i + 1] % 13) {
			count++;
			if (count == 2) break;
		} else
			count = 0;
	}
	return count == 2 ? 3 : 0;
}

unsigned int scala(unsigned int *wHand) {
	unsigned int count = 0;
	for (size_t i = 0; i < 4; i++) {
		if (wHand[i] % 13 == wHand[i + 1] % 13 + 1)
			count++;
		else
			count = 0;
	}
	return count == 4 ? 4 : 0;
}
