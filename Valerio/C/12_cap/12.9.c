#include <stdio.h>
#include <stdlib.h>

struct list {
	char data;
	struct list *nextPtr;
};

typedef struct list List;
typedef List *ListPtr;

void addNode(ListPtr *lPtr, char value);
void firstNode(ListPtr *currentPtr, char value);
void build(ListPtr *lPtr);
void reverse(ListPtr lPtr, ListPtr *rPtr);
void printList(ListPtr currentPtr);

int main(void) {
	system("clear");
	puts("");

	ListPtr startList = NULL;
	ListPtr reversedList = NULL;

	build(&startList);
	printList(startList);
	reverse(startList, &reversedList);
	printList(reversedList);
	puts("");
}

void firstNode(ListPtr *currentPtr, char value) {
	*currentPtr = malloc(sizeof(List));
	(*currentPtr)->data = value;
	(*currentPtr)->nextPtr = NULL;
}

void addNode(ListPtr *lPtr, char value) {
	ListPtr newPtr = NULL;
	firstNode(&newPtr, value);

	ListPtr previousPtr = NULL;
	ListPtr currentPtr = *lPtr;

	while (currentPtr != NULL) {
		previousPtr = currentPtr;
		currentPtr = currentPtr->nextPtr;
	}

	previousPtr->nextPtr = newPtr;
}

void build(ListPtr *lPtr) {
	firstNode(lPtr, 97);

	for (size_t i = 1; i <= 10; i++)
		addNode(lPtr, 97 + i);
}

void printList(ListPtr currentPtr) {
		printf("\nList: %c", currentPtr->data);
		currentPtr = currentPtr->nextPtr;

		while (currentPtr != NULL) {
			printf(" --> %c", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}

		puts(" --> NULL\n");
}

void reverse(ListPtr lPtr, ListPtr *rPtr) {
	// Se il puntatore della lista originale è nullo la funzione ritorna
	if (lPtr == NULL)
		return;
	// Richiamo la funzione ricorsivamente passandole il nodo successivo della lista originale
	reverse(lPtr->nextPtr, rPtr);
	// Se il puntatore della lista rovesciata è nullo alloco memoria per un primo nodo
	// con i dati dell'ultimo nodo della lista normale
	if (*rPtr == NULL)
		firstNode(rPtr, lPtr->data);
	else
		// Tornando all'indietro per ogni nodo della lista normale aggiungo un nodo
		// alla lista rovesciata
		addNode(rPtr, lPtr->data);
}
