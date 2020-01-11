#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define FACES 13

struct card {
	const char *face;
	const char *suit;
};

typedef struct card Card;

void fillDeck(Card * const wDeck, const char *wFace[], const char *wSuit[]);
void shuffle(Card * const wDeck);
void deal(const Card * const wDeck);

int main(void) {
	system("clear");
	srand(time(NULL));

	Card deck[CARDS];

	const char *suit[] = {"Cuori", "Quadri", "Fiori", "Picche"};

	const char *face[] = {
		"Asso", "Due", "Tre", "Quattro", "Cinque", "Sei", "Sette",
		"Otto", "Nove", "Dieci", "Jack", "Regina", "Re"
	};

	fillDeck(deck, face, suit);
	shuffle(deck);
	deal(deck);
}

void fillDeck(Card * const wDeck, const char *wFace[], const char *wSuit[]) {
	for (size_t i = 0; i < CARDS; i++) {
		wDeck[i].suit = wSuit[i / FACES];
		wDeck[i].face = wFace[i % FACES];
	}
}

void shuffle(Card * const wDeck) {
	for (size_t i = 0; i < CARDS; i++) {
		size_t j = rand() % CARDS;
		Card temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	}
}

void deal(const Card * const wDeck) {
	for (size_t i = 0; i < CARDS; i++)
		printf("%6s di %-8s%c", wDeck[i].face, wDeck[i].suit, (i + 1) % 4 ? ' ' : '\n');
}
