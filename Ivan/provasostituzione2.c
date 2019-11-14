#include <stdio.h>
#include <string.h>

char parola[50];     //parola chiave
char alfabeto[26]={"abcdefghijklmnopqrstuvwxyz"};
char frase[256];
int i, j, k;


void sostituzione () {
  printf("Inserire una parola di sole minuscole e senza ripetizioni di lettere:\n");
  scanf("%s", parola);

  strncat(parola, alfabeto, 50);
  for (i=0; i<strlen(parola); i++) {
    for (j=i+1; j<strlen(parola); j++) {
       if (parola[i] == parola [j])
         for (k=j; k<strlen(parola); k++) {
           parola[k]=parola[k+1];}
         }
    }

  printf("%s\n", parola);
}

  int main () {
    //printf("Inserire una frase:\n");
    //fgets(frase, sizeof(frase), stdin);

  sostituzione ();

  //printf("%s", frase);
    return 0;
  }
