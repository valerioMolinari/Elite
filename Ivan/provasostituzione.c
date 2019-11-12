#include <stdio.h>
#include <string.h>

char frase[256];
char parola[100];     //parola chiave
char alfabeto[26] = {"abcdefghijklmnopqrstuvwxyz"};



void sostituzione () {
  printf("Inserire l'alfabeto chiave per la sostituzione con tutte e sole le lettere dalla A alla Z: ");
  scanf("%s", parola);

  // trasforma tutto in minuscolo
  for (size_t i = 0; i < strlen(parola); i++) {
    parola[i] = tolower(parola[i]);
  }

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
