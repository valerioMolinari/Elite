#include <stdio.h>
#include <stdlib.h>

void reverse(const char * const sPtr);

int main(void) {
	system("clear");
	char string[] = "Ciao";
	reverse(string);
	puts("");
}

void reverse(const char * const sPtr) {
	if (*sPtr == '\0')
		return;
	reverse(sPtr + 1);
	putchar(*sPtr);
}
