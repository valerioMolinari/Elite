#include <stdio.h>
#include <stdlib.h>

void printCharacters(const char *sPtr) {
	while (*sPtr != '\0')
		printf("%c", *sPtr++);
}

int main(void){
	system("clear");
	char string[] = "print characters of a string";

	puts("\nThe string is:");
	printCharacters(string);
	puts("\n");
}
