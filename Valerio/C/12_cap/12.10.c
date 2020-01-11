#include <stdio.h>
#include <stdlib.h>

#define SIZE 256

struct stackNode {
	char data;
	struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void fillStack(StackNodePtr *topPtr, char *string);
void printReverse(StackNodePtr topPtr);
void addNode(StackNodePtr *lPtr, char value);
void firstNode(StackNodePtr *currentPtr, char value);

int main(void) {
	system("clear");

	char string[SIZE];
	printf("Inserisci una stringa di caratteri: ");
	fgets(string, SIZE, stdin);
	puts("");
	StackNodePtr stackPtr = NULL;

	fillStack(&stackPtr, string);
	printReverse(stackPtr);
	puts("\n");
}

void fillStack(StackNodePtr *topPtr, char *string) {
	firstNode(topPtr, *string);

	while (*string++ != '\0')
		addNode(topPtr, *string);
}

void printReverse(StackNodePtr topPtr) {
	while (topPtr != NULL) {
		putchar(topPtr->data);
		topPtr = topPtr->nextPtr;
	}
}

void firstNode(StackNodePtr *currentPtr, char value) {
	*currentPtr = malloc(sizeof(StackNode));
	(*currentPtr)->data = value;
	(*currentPtr)->nextPtr = NULL;
}

void addNode(StackNodePtr *lPtr, char value) {
	StackNodePtr newPtr = NULL;
	firstNode(&newPtr, value);

	newPtr->nextPtr = *lPtr;
	*lPtr = newPtr;
}
