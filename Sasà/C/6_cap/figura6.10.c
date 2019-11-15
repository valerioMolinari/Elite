#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
int main(void) {
	system("clear");

char string1[SIZE];//siserva 20 caratteri
char string2[] = "stringa letterale"; //riserva 15 caratteri

//memorizza la stringa inserita dall'utente nell'array string1
printf("%s", "Enter a string (non più lunga di 19 caratteri):" );
scanf("%19s\n", string1 );

//stampa le stringhe
printf("string 1 è: %s\nstring2 è: %s\n"
       "string1 con gli spazi insieme ai caratteri sono:\n",
       string1, string2);

//stampa i caratteri finchè non si raggiunge il carattere nullo
for (size_t i = 0; i < SIZE && string1[i] != '\0'; ++i) {
	printf("%c ", string1[i] );
}
puts("");

}
