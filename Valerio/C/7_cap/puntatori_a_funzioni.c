#include <stdio.h>
#include <stdlib.h>

void function1(int a) {
	printf("You entered %d so function1 was called\n", a);
}

void function2(int b) {
	printf("You entered %d so function2 was called\n", b);
}

void function3(int c) {
	printf("You entered %d so function3 was called\n", c);
}

int main(void) {
	system("clear");

	void (*f[3])(int) = {function1, function2, function3};

	printf("%s", "Enter a number between 0 and 2, 3 to end: ");
	size_t choice;
	scanf("%zu", &choice);

	while (choice >= 0 && choice < 3) {
		(*f[choice])(choice);
		printf("\n%s", "Enter a number between 0 and 2, 3 to end: ");
		scanf("%zu", &choice);
	}
	puts("Program execution completed\n");
}
