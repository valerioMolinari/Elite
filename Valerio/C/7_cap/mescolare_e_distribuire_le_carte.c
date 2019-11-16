#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SUITS 4
#define FACES 13
#define CARDS 52

void shuffle(unsigned int wDeck[][FACES]) {
	// Per ogni carta del mazzo
	for (size_t card = 1; card <= CARDS; card++) {
		// Dichiariamo internamente row e column per rispettare il privilegio minimo
		size_t row;
		size_t column;
		do {
			// Continuiamo a cercare finché l'elemento di wDeck che si trova alla
			// posizione [row][column] non è uguale a 0
			row = rand() % SUITS;
			column = rand() % FACES;
		} while(wDeck[row][column] != 0);

		// Trovato l'elemento vuoto ci mettiamo dentro il (1 <= numero <= 52) della carta
		wDeck[row][column] = card;
	}
}

void deal(unsigned int wDeck[][FACES], const char *wFace[], const char *wSuit[]) {
	// Per ogni carta
	for (size_t card = 1; card <= CARDS; card++)
		// Per ogni seme
		for (size_t row = 0; row < SUITS; row++)
			// Per ogni figura
			for (size_t column = 0; column < FACES; column++)
				// Se l'elemento dell'array corrisponde alla carta, stamparla
				if (wDeck[row][column] == card)
					printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 ? '\t' : '\n');
}

int main(void) {
	system("clear");
	srand(time(NULL));

	unsigned int deck[SUITS][FACES] = {0};
	const char *suit[SUITS] = {"Heart", "Diamonds", "Clubs", "Spades"};
	const char *face[FACES] = {
		"Axe", "Deuce", "Three", "Four", "Five", "Six", "Seven",
		"Eight", "Nine", "Ten", "Jack", "Queen", "King"
	};

	shuffle(deck);
	deal(deck, face, suit);
	puts("");
}
