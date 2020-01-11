#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queueNode {
	char data;
	struct queueNode *nextPtr;
};

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

void printQueue(QueueNodePtr currentPtr);
int isEmpty(QueueNodePtr headPtr);
char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value);
void instructions(void);

int main(void) {
	system("clear");

	QueueNodePtr headPtr = NULL;
	QueueNodePtr tailPtr = NULL;

	unsigned int choice;
	char item;

	instructions();
	printf("> ");
	scanf("%u", &choice);

	while (choice != 3) {
		switch (choice) {
			case 1:
				printf("\nEnter a character: ");
				scanf("\n%c", &item);
				enqueue(&headPtr, &tailPtr, item);
				printQueue(headPtr);
				break;
			case 2:
			if (isEmpty(headPtr))
			puts("\nThe queue is empty\n");
			else {
				printf("\n%c has been dequeued.\n", dequeue(&headPtr, &tailPtr));
				printQueue(headPtr);
			}
				break;
			default:
				puts("Invalid choice\n");
				instructions();
		}
		printf("> ");
		scanf("%u", &choice);
	}
}

int isEmpty(QueueNodePtr headPtr) {
	return headPtr == NULL;
}

void printQueue(QueueNodePtr currentPtr) {
	if (isEmpty(currentPtr))
		puts("\nThe stack is empty.\n\n");
	else {
		puts("\nThe stack is:");
		while (!isEmpty(currentPtr)) {
			printf("%c --> ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}
		puts("NULL\n");
	}
}

void instructions(void) {
	puts("Enter a choice:\n"
			 "\t1. Add an item to the queue\n"
			 "\t2. Remove an item from the queue\n"
			 "\t3. Exit\n"
	);
}

void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value) {
	QueueNodePtr newPtr = malloc(sizeof(QueueNode));
	if (!isEmpty(newPtr)) {
		newPtr->data = value;
		newPtr->nextPtr = NULL;
		if (isEmpty(*headPtr))
			*headPtr = newPtr;
		else
			(*tailPtr)->nextPtr = newPtr;
		*tailPtr = newPtr;
	} else
		printf("%c not inserted due to no memory available\n", value);
}

char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr) {
	QueueNodePtr tempPtr = *headPtr;
	char dequeued = tempPtr->data;
	*headPtr = (*headPtr)->nextPtr;

	if (isEmpty(*headPtr))
		*tailPtr = NULL;

	free(tempPtr);
	return dequeued;
}
