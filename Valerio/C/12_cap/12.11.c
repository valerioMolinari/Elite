#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 256

struct stackNode {
	char data;
	struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void addNode(StackNodePtr *lPtr, char value);
void firstNode(StackNodePtr *currentPtr, char value);
void fillStack(StackNodePtr *topPtr, char * string);
char * palindrome(StackNodePtr topPtr, char * string);
void printStack(StackNodePtr currentPtr);
int isEmpty(StackNodePtr topPtr);

int main(void) {
	system("clear");

	char string[SIZE];
	printf("Inserisci una stringa di caratteri: ");
	fgets(string, SIZE, stdin);
	puts("");

	StackNodePtr stackPtr = NULL;

	fillStack(&stackPtr, string);
	printStack(stackPtr);
	printf("La stringa %s%s\n", string, palindrome(stackPtr, string));
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

void fillStack(StackNodePtr *topPtr, char *string) {
	firstNode(topPtr, *string);
	string++;
	while (*string != '\0') {
		if (tolower(*string) >= 97 && tolower(*string) <= 126)
			addNode(topPtr, *string);
		string++;
	}
}

char * palindrome(StackNodePtr topPtr, char * string) {
	int i = 0;
	while (*string != '\0' && topPtr != NULL) {
		if (*string != topPtr->data)
			return "non è palindroma";
		string++;
		topPtr = topPtr->nextPtr;
	}
	return "è palindroma";
}

void printStack(StackNodePtr currentPtr) {
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

int isEmpty(StackNodePtr topPtr) {
	return topPtr == NULL;
}
