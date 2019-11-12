#include <stdio.h>
#include <string.h>

char frase[256];
char parola[100];     //parola chiave
char alfabeto[26] = {"abcdefghijklmnopqrstuvwxyz"};



void sostituzione () {
  // printf("Inserire una parola di sole minuscole e senza ripetizioni di lettere:\n");
  // scanf("%s", parola);

  //potresti fare semplicemente
  printf("Inserisci una stringa di testo: ");
  fgets(text, SIZE, stdin);
  //così non devi porre condizioni

  for (int i = 0; i < strlen(parola); i++) {
    alfabeto[i] = parola[i];
  }

  for (int j = 0; i <= strlen(alfabeto); i++)

  printf("%s\n", alfabeto);
}

int main () {
  printf("Inserire una frase: \n");
  fgets(frase, sizeof(frase), stdin);

  sostituzione ();

  printf("%s", frase);

  return 0;
}
