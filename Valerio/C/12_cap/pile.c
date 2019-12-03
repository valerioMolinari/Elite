#include <stdio.h>
#include <stdlib.h>

struct stackNode {
	int data;
	struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push(StackNodePtr *topPtr, int info);
int pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);
void instructions(void);

int main(void) {
	system("clear");

	StackNodePtr stackPtr = NULL;
	unsigned int choice;
	int value;

	instructions();
	printf("> ");
	scanf("%u", &choice);

	while (choice != 3) {
		switch (choice) {
			case 1:
				printf("\nEnter an integer: ");
				scanf("\n%d", &value);
				push(&stackPtr, value);
				printStack(stackPtr);
				break;
			case 2:
				if (isEmpty(stackPtr))
				puts("\nThe stack is empty\n");
				else {
					printf("\nThe popped value is: %d\n", pop(&stackPtr));
					printStack(stackPtr);
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

int isEmpty(StackNodePtr topPtr) {
	return topPtr == NULL;
}

void printStack(StackNodePtr currentPtr) {
	if (isEmpty(currentPtr))
		puts("\nThe stack is empty.\n\n");
	else {
		puts("\nThe stack is:");
		while (!isEmpty(currentPtr)) {
			printf("%d --> ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}
		puts("NULL\n");
	}
}

void instructions(void) {
	puts("Enter choice:\n"
			 "\t1. Push a value on the stack\n"
			 "\t2. Pop a value off the stack\n"
			 "\t3. Exit\n"
	);
}

void push(StackNodePtr *topPtr, int info) {
	StackNodePtr newPtr = malloc(sizeof(StackNode));
	if (!isEmpty(newPtr)) {
		newPtr->data = info;
		newPtr->nextPtr = *topPtr;
		*topPtr = newPtr;
	} else
		printf("%d not inserted due to no memory available\n", info);
}

int pop(StackNodePtr *topPtr) {
	StackNodePtr tempPtr = *topPtr;
	int info = tempPtr->data;
	*topPtr = (*topPtr)->nextPtr;
	free(tempPtr);
	return info;
}
