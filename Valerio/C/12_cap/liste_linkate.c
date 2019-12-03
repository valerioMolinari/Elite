#include <stdio.h>
#include <stdlib.h>

struct listNode {
	char data;
	struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void insert(ListNodePtr *sPtr, char value);
char delete(ListNodePtr *sPtr, char valu);
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);
void instructions(void);

int main(void) {
	system("clear");
	ListNodePtr startPtr = NULL;
	instructions();
	char item;
	unsigned int choice;
	scanf("%u", &choice);

	while (choice != 3) {
		switch (choice) {
			case 1:
				printf("\nEnter a character: ");
				scanf("\n%c", &item);
				insert(&startPtr, item);
				printList(startPtr);
				break;
			case 2:
				if (!isEmpty(startPtr)) {
					printf("\nEnter a character to be deleted: ");
					scanf("\n%c", &item);
					if (delete(&startPtr, item)) {
						printf("\n%c deleted.\n", item);
						printList(startPtr);
					} else
						printf("\n%c not found.\n\n", item);
				} else
					puts("List is empty");
				break;
			default:
				puts("Invalid choice.\n");
				instructions();
		}

		printf("> ");
		scanf("%u", &choice);
	}

	puts("End of run");
}

void instructions(void) {
	printf("Enter your chioce\n"
			 "\t1. insert an element into the list\n"
			 "\t2. delete an element from the list\n"
			 "\t3. exit\n> "
	);
}

void insert(ListNodePtr *sPtr, char value) {
	// Alloco memoria per un puntatore a struct listNode con la dimensione di
	// un nodo di ListNode
	ListNodePtr newPtr = malloc(sizeof(ListNode));
	// Controllo se il programma è riuscito ad allocare memoria per creare il
	// puntatore, ovvero controllo se c'è ancora memoria disponibile
	if (newPtr != NULL) {
		// Inizializzo i dati del nodo al carattere che ho ricevuto in input
		// e non faccio puntare il puntatore al nodo successivo a nulla
		newPtr->data = value;
		newPtr->nextPtr = NULL;

		// Dichiaro un puntatore a struct listNode nullo e uno che punta a ciò a
		// cui punta sPtr, il motivo per cui ho bisogno di ricevere sPtr come
		// puntatore a puntatore è che per modificare il puntatore stesso ho
		// ho bisogno di accedere al suo indirizzo secondo la logica dei
		// puntatori
		ListNodePtr previousPtr = NULL;
		ListNodePtr currentPtr = *sPtr;

		while (currentPtr != NULL && value > currentPtr->data) {
			// Uso questo ciclo while per scorrere la lista in avanti,
			// ovvero continuo ad assegnare il puntatore corrente
			// al puntatore precedente e assegnare il puntatore corrente
			// al suo puntatore successivo, questo finché, alla prossima
			// iterazione il valore di currentPtr sarà diventato NULL
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}

		if (previousPtr == NULL) {
			// Nel caso in cui la lista fosse vuota la prossima riga sarebbe inutile,
			// semplicemente verrebbe inserito il nodo all'inizio della lista mettendolo
			// come valore del puntatore derefernziato alla lista.
			// Nel caso in cui invece la lista abbia soli n elementi con "data" tutti
			// uguali, questa if sarebbe verificata e il nodo verrebbe inserito immediatamente
			// dopo il primo elemento della lista
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		} else {
			// Se il ciclo while è entrato il nodo viene inserito nel punto in cui
			// nella lista compare un nodo con un carattere minore o ugale a quello
			// inserito dall'utente
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
	} else
		printf("Character %c not inserted due to no memory available\n", value);
}

char delete (ListNodePtr *sPtr, char value) {
	ListNodePtr previousPtr = NULL;
	ListNodePtr currentPtr = *sPtr;

	while (currentPtr != NULL && value != currentPtr->data) {
		previousPtr = currentPtr;
		currentPtr = currentPtr->nextPtr;
	}
	if (isEmpty(currentPtr))
		return 0;
	else {
		if (isEmpty(previousPtr)) {
			*sPtr = currentPtr->nextPtr;
			free(currentPtr);
		} else {
			previousPtr->nextPtr = currentPtr->nextPtr;
			free(currentPtr);
		}
	}
	return value;
}

int isEmpty(ListNodePtr sPtr) {
	return sPtr == NULL;
}

void printList(ListNodePtr currentPtr) {
	if (!isEmpty(currentPtr)) {
		printf("\nList: %c", currentPtr->data);
		currentPtr = currentPtr->nextPtr;

		while (currentPtr != NULL) {
			printf(" --> %c", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}

		puts(" --> NULL\n");
	} else
		puts("List is empty\n");
}
