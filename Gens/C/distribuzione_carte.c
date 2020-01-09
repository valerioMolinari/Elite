#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define FACES 13

typedef struct card{
	const char *face; //definisci il puntatore face
	const char *suit; //definisci il puntatore suit
} Card;

void fillDeck(Card *const wDeck, const char *wFace[], const char *wSuit[]);
void shuffle(Card *const wDeck);
void deal(const Card *const wDeck);

int main(void) {
	system("clear");

Card deck[CARDS]; //definisci l'array di Card

//inizializza un array di puntatori
const char *face[] = {"Uno", "Due", "Tre", "Quattro", "Cinque", "Sei", "Sette", "Otto", "Nove", "Dieci", "Jack", "Regina", "Re"};

//inizializza un array di puntatori
const char *suit[] = {"Cuori", "Picche", "Quadri", "Fiori"};

srand(time(NULL)); //randomizza

fillDeck(deck, face, suit); //carica il mazzo con le carte
shuffle(deck); //metti le carte in ordine casuale
deal(deck); //distribuisci tutte le 52 carte
}

//metti le stringhe nelle strutture Card
void fillDeck(Card *const wDeck, const char *wFace[], const char *wSuit[]){

	//effettua un'iterazione attraverso wDeck
	for(size_t i = 0; i < CARDS; ++i){
		wDeck[i].face = wFace[i % FACES];
		wDeck[i].suit = wSuit[i / FACES];
	}
}

//mescola le carte
void shuffle(Card *const wDeck){

	//effettua un'iterazione attraverso wDeck scambiando a caso le carte
	for(size_t i = 0; i < CARDS; i++){
		size_t j = rand() % CARDS;
		Card temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	}
}

//distribuisci le carte
void deal(const Card *const wDeck){

	//effettua un'iterazione attraverso wDeck
	for(size_t i = 0; i < CARDS; ++i){
		printf("%5s di %-8s%s", wDeck[i].face, wDeck[i].suit, (i + 1) % 4 ? "  " : "\n");
	}
}
