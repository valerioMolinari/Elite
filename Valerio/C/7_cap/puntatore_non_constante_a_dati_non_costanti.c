#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void convertToUppercase(char *sPtr) {
	/*
		Il parametro puntatore di questa funzione viene utilizzato per puntare
		ad una stringa, ovvero a corrispondere all'indirizzo del primo carattere
		dell'array. Nel ciclo viene riassegnata la dereferenziazione
		dell'attuale indirizzo, quindi si passa all'indirizzo successivo finché
		esso non punta indirettamente a \0, ovvero la fine della stringa.
	*/
	while (*sPtr != '\0') {
		*sPtr = toupper(*sPtr);
		++sPtr;
	}
}

int main(void){
	system("clear");

	char string[] = "cHaRaCTers and $32.98";

	printf("\nString before conversion is %s\n\n", string);
	convertToUppercase(string);
	printf("String after conversion is %s\n\n", string);
}
