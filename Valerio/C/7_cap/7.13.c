#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SUITS 4
#define FACES 13
#define CARDS 20
#define HAND 5
#define POINTS 8
#define PLAYERS 2

enum enumPoint {ZERO, COPPIA, DOPPIA_COPPIA, TRIS, SCALA, COLORE, FULL, POKER, SCALA_REALE};

void mischia(unsigned int *wDeck);

void swap(unsigned int *ptr1, unsigned int *ptr2);

void module13Sort(unsigned int * const array, const size_t size);

unsigned int m13(unsigned int cardNumber);

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
		printf("k: %u\nprobabilità: %f%%\n", k, ((float) 1 / k)*100);
	} while(!(colore(hand1) || colore(hand2)));
}


void mischia(unsigned int *wDeck) {
	for (size_t card = 0; card < 52; card++)
		if (m13(card) >= 8) {
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

unsigned int m13(unsigned int cardNumber) {
	return cardNumber % 13;
}

void module13Sort(unsigned int * const array, const size_t size) {
	for (size_t i = 0; i < size - 1; i++) {
		for (size_t j = 0; j < size - 1; j++)
			if (m13(array[j] - 1) > m13(array[j + 1] - 1)) {
				swap(&array[j], &array[j + 1]);
			}
	}
}

void stampaCarte(unsigned int *wDeck, const char *wFace[], const char *wSuit[], size_t size) {
	for (size_t card = 0; card < size; card++) {
		const char *face = wFace[m13(wDeck[card] - 1)];
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
		if (m13(wHand[i]) == m13(wHand[i + 1]))
			return COPPIA;
	return ZERO;
}

unsigned int doppiaCoppia(unsigned int *wHand) {
	unsigned int checked = 0;
	for (size_t i = 0; i < 4; i++) {
		if (!checked) {
			if (m13(wHand[i])== m13(wHand[i + 1]))
				checked = m13(wHand[i]);
		} else {
			if (m13(wHand[i]) == m13(wHand[i + 1]) && m13(wHand[i]) != checked)
				return DOPPIA_COPPIA;
		}
	}
	return ZERO;
}

unsigned int tris(unsigned int *wHand) {
	unsigned int count = 0;
	for (size_t i = 0; i < 4; i++) {
		if (m13(wHand[i]) == m13(wHand[i + 1])) {
			count++;
			if (count == 2) break;
		} else
			count = 0;
	}
	return count == 2 ? TRIS : ZERO;
}

unsigned int scala(unsigned int *wHand) {
	unsigned int count = 0;
	for (size_t i = 0; i < 4; i++) {
		if (m13((wHand[i] - 1)) + 1 == m13((wHand[i + 1] - 1)))
			count++;
		else
			count = 0;
	}
	return count == 4 ? SCALA : ZERO;
}

unsigned int colore(unsigned int *wHand) {
	unsigned int count = 0;
	for (size_t i = 0; i < 4; i++) {
		if ((wHand[i] - 1) / 13 == (wHand[i + 1] - 1) / 13)
			count++;
		else
			count = 0;
	}
	return count == 4 ? COLORE : ZERO;
}

unsigned int full(unsigned int *wHand) {
	unsigned int trisCount = 0;
	unsigned int trisFace = 0;
	for (size_t i = 0; i < 4; i++) {
		if (m13(wHand[i]) == m13(wHand[i + 1])) {
			trisCount++;
			if (trisCount == 2) {
				trisFace = m13(wHand[i]);
				break;
			}
		} else
			trisCount = 0;
	}
	if (trisFace) {
		for (size_t i = 0; i < 4; i++)
			if (m13(wHand[i]) == m13(wHand[i + 1]) && trisFace != m13(wHand[i]))
				return FULL;
	}
	return ZERO;
}


unsigned int poker(unsigned int *wHand) {
	unsigned int count = 0;
	for (size_t i = 0; i < 4; i++) {
		if (m13(wHand[i]) == m13(wHand[i + 1])) {
			count++;
			if (count == 3) break;
		} else
			count = 0;
	}
	return count == 3 ? POKER : ZERO;
}

unsigned int scalaReale(unsigned int *wHand) {
	return scala(wHand) && colore(wHand) ? SCALA_REALE : ZERO;
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
	unsigned int count = 4;
	unsigned int a = point(wHand1, arrayFun, POINTS);
	unsigned int b = point(wHand2, arrayFun, POINTS);
	unsigned int full1[3] = {0};
	unsigned int full2[3] = {0};
	wHand1 += 4;
	wHand2 += 4;
	if (a == b) {
		switch (a) {
			case COPPIA:
			case DOPPIA_COPPIA:
			case TRIS:
			case POKER:
				while (m13(*wHand1) != m13(*(wHand1 - 1))) wHand1--;
				while (m13(*wHand2) != m13(*(wHand2 - 1))) wHand2--;

				if (m13(*wHand1) == m13(*wHand2))
					return (*wHand1 < *(wHand1 - 1) ? *wHand1 : *(wHand1 - 1)) < (*wHand2 < *(wHand2 - 1) ? *wHand2 : *(wHand2 - 1)) ? 1 : 2;
				break;
			case FULL:
				while (m13(*wHand1) != m13(*(wHand1 - 1)) || m13(*(wHand1 - 1)) != m13(*(wHand1 - 2))) wHand1--;
				while (m13(*wHand2) != m13(*(wHand2 - 1)) || m13(*(wHand2 - 1)) != m13(*(wHand2 - 2))) wHand2--;
				break;
			case SCALA:
			case COLORE:
			case SCALA_REALE:
				while (m13(*wHand1) == m13(*wHand2) && count ) {
					wHand1--;
					wHand2--;
					count--;
				}
				if (count == 0)
					return *(wHand1 + 4) < *(wHand2 + 4) ? 1 : 2;
		}
		return m13((*wHand1 - 1)) > m13((*wHand2 - 1)) ? 1 : 2;
	}
	return a > b ? 1 : 2;
}
