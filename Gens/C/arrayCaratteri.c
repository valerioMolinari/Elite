#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

int main(void) {

  char string1[SIZE];
  char string2[] = "stringa letterale";

  printf("%s", "Inserisci la frase (non più lunga di 19 caratteri): ");
  scanf("%19s", string1);

  printf("La frase inserita è: %s\nLa frase già inserita è: %s\nLe lettere della frase inserita sono: \n", string1, string2);

  for(size_t i = 0; i < SIZE && string1[i] != '\0'; i++){
    printf("%c\n", string1[i]);
  }
}
