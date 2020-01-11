#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SUITS 4
#define FACES 13
#define CARDS 20
#define HAND 5
#define POINTS 8

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

unsigned int point(unsigned int *wHand, unsigned int (*arrayFun[])(unsigned int *), size_t arrayFunSize);

void printPoint(unsigned int point);

int main(void) {
	system("clear");
	srand(time(NULL));

	unsigned int deck[CARDS] = {0};
	unsigned int hand[5] = {0};
	const char *suit[SUITS] = {"Cuori", "Quadri", "Fiori", "Picche"};
	const char *face[FACES] = {
		"Due", "Tre", "Quattro", "Cinque", "Sei", "Sette",
		"Otto", "Nove", "Dieci", "Jack", "Regina", "Re",  "Asso"
	};
	unsigned int (*pointArray[POINTS])(unsigned int *) = {
		scalaReale, poker, full, colore, scala, tris, doppiaCoppia, coppia
	};

	mischia(deck);
	creaMano(deck, hand);
	stampaCarte(hand, face, suit, HAND);

	printPoint(point(hand, pointArray, POINTS));

	puts("");
}


void mischia(unsigned int *wDeck) {
	for (size_t card = 0; card < 52; card++)
		if (card % 13 >= 8) {
			size_t slot;
			do {
				slot = rand() % 20;
			} while(wDeck[slot] != 0);
			wDeck[slot] = card + 1;
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
			if ((array[j] - 1) % 13 > (array[j + 1] - 1) % 13) {
				swap(&array[j], &array[j + 1]);
			}
	}
}

void stampaCarte(unsigned int *wDeck, const char *wFace[], const char *wSuit[], size_t size) {
	for (size_t card = 0; card < size; card++) {
		const char *face = wFace[(wDeck[card] - 1) % 13];
		const char *suit = wSuit[(wDeck[card] - 1) / 13];
		printf("%6s di %-6s\n", face, suit);
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

unsigned int doppiaCoppia(unsigned int *wHand) {
	unsigned int checked = 0;
	for (size_t i = 0; i < 4; i++) {
		if (!checked) {
			if (wHand[i] % 13 == wHand[i + 1] % 13)
				checked = wHand[i] % 13;
		} else {
			if (wHand[i] % 13 == wHand[i + 1] % 13 && wHand[i] % 13 != checked)
				return 2;
		}
	}
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
		if ((wHand[i] - 1) % 13 + 1 == (wHand[i + 1] - 1) % 13 )
			count++;
		else
			count = 0;
	}
	return count == 4 ? 4 : 0;
}

unsigned int colore(unsigned int *wHand) {
	unsigned int count = 0;
	for (size_t i = 0; i < 4; i++) {
		if ((wHand[i] - 1) / 13 == (wHand[i + 1] - 1) / 13 )
			count++;
		else
			count = 0;
	}
	return count == 4 ? 5 : 0;
}

unsigned int full(unsigned int *wHand) {
	unsigned int trisCount = 0;
	unsigned int trisFace = 0;
	for (size_t i = 0; i < 4; i++) {
		if (wHand[i] % 13 == wHand[i + 1] % 13) {
			trisCount++;
			if (trisCount == 2) {
				trisFace = wHand[i] % 13;
				break;
			}
		} else
			trisCount = 0;
	}
	if (trisFace) {
		for (size_t i = 0; i < 4; i++)
			if (wHand[i] % 13 == wHand[i + 1] % 13 && trisFace != wHand[i] % 13)
				return 6;
	}
	return 0;
}


unsigned int poker(unsigned int *wHand) {
	unsigned int count = 0;
	for (size_t i = 0; i < 4; i++) {
		if (wHand[i] % 13 == wHand[i + 1] % 13) {
			count++;
			if (count == 3) break;
		} else
			count = 0;
	}
	return count == 3 ? 7 : 0;
}

unsigned int scalaReale(unsigned int *wHand) {
	return scala(wHand) && colore(wHand) ? 8 : 0;
}

unsigned int point(unsigned int *wHand, unsigned int (*arrayFun[])(unsigned int *), size_t arrayFunSize) {
	for (size_t i = 0; i < arrayFunSize; i++)
		if (arrayFun[i](wHand))
			return arrayFun[i](wHand);
	return 0;
}

void printPoint(unsigned int point) {
	printf("Punto: ");
	switch (point) {
		case 1: puts("Coppia"); break;
		case 2: puts("Doppia coppia"); break;
		case 3: puts("Tris"); break;
		case 4: puts("Scala"); break;
		case 5: puts("Colore"); break;
		case 6: puts("Full"); break;
		case 7: puts("Poker"); break;
		case 8: puts("Scala Reale"); break;
		default: puts("Nessun punto");
	}
}
