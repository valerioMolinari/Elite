#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SUITS 4
#define FACES 13
#define CARDS 20
#define HAND 5
#define POINTS 8
#define PLAYERS 2

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

unsigned int evaluatePoint(unsigned int *wHand1, unsigned int *wHand2, unsigned int (*arrayFun[])(unsigned int *));

void stampaPunto(unsigned int point);

int main(void) {
	system("clear");
	srand(time(NULL));

	unsigned int deck[CARDS] = {0};
	unsigned int hand1[5] = {0};
	unsigned int hand2[5] = {0};
	unsigned int player1, player2;
	const char *suit[SUITS] = {"Cuori", "Quadri", "Fiori", "Picche"};
	const char *face[FACES] = {
		"Due", "Tre", "Quattro", "Cinque", "Sei", "Sette",
		"Otto", "Nove", "Dieci", "Jack", "Regina", "Re",  "Asso"
	};
	unsigned int (*pointArray[POINTS])(unsigned int *) = {
		scalaReale, poker, full, colore, scala, tris, doppiaCoppia, coppia
	};
	int k = 0;
	do {
		mischia(deck);
		creaMano(deck, hand1);
		creaMano(deck, hand2);
		stampaCarte(hand1, face, suit, HAND);
		stampaCarte(hand2, face, suit, HAND);

		player1 = point(hand1, pointArray, POINTS);
		player2 = point(hand2, pointArray, POINTS);

		stampaPunto(player1);
		stampaPunto(player2);

		printf("Il giocatore %u ha la mano migliore\n",
						evaluatePoint(hand1, hand2, pointArray));
		puts("");
		for (size_t i = 0; i < CARDS; i++) {
			deck[i] = 0;
		}
		k++;
		printf("\nk: %d\n", k);
	} while(!(full(hand1) && full(hand2)));
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
	static unsigned int player = 0;
	for (size_t i = 0; i < 5; i++)
		wHand[i] = wDeck[i * PLAYERS + player];
	module13Sort(wHand, 5);
	player = !player;
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

void stampaPunto(unsigned int point) {
	printf("%6s :  ","Punto");
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
	puts("");
}

unsigned int evaluatePoint(unsigned int *wHand1, unsigned int *wHand2, unsigned int (*arrayFun[])(unsigned int *)) {
	unsigned int a = point(wHand1, arrayFun, POINTS);
	unsigned int b = point(wHand2, arrayFun, POINTS);
	unsigned int full1[3] = {0};
	unsigned int full2[3] = {0};
	if (a == b) {
		if (a == 8 || a == 5 || a == 4) {
			// SCALA REALE, COLORE, SCALA
			for (size_t i = HAND - 1; i >= 0; i--)
				// Continua finché le carte ordinate dei giocatori hanno lo stesso valore
				if ((wHand1[i] - 1) % FACES == (wHand2[i] - 1) % FACES)
					continue;
				// Il giocatore con la prima carta più alta vince
				else if ((wHand1[i] - 1) % FACES > (wHand2[i] - 1) % FACES)
					return 1;
				else
					return 2;
		} else if (a == 6) {
			// FULL
			for (size_t i = 0; i < 3; i++) {
				full1[i] = wHand1[HAND - i - 1];
				full2[i] = wHand2[HAND - i - 1];
			}
			// Nessuno dei due ha un tris tra le prime tre carte
			if (!(tris(full1) || tris(full2)))
				for (size_t i = 0; i < 3; i++) {
					full1[i] = wHand1[HAND - i - 3];
					full2[i] = wHand2[HAND - i - 3];
				}
			// Il giocatore 1 non ha un tris tra le prime 3 carte
			else if (!(tris(full1)))
				for (size_t i = 0; i < 3; i++)
					full1[i] = wHand1[HAND - i - 3];
			// Il giocatore 2 non ha un tris tra le prime 3 carte
			else if (!(tris(full2)))
				for (size_t i = 0; i < 3; i++)
					full2[i] = wHand2[HAND - i - 3];
			return full1[0] % FACES > full2[0] % FACES ? 1 : 2;
		}	else {
			// POKER, TRIS, DOPPIA COPPIA, COPPIA

			return 0;
		}
	}
	return a > b ? 1 : 2;
}
