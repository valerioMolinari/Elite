<<<<<<< HEAD
/*
  Chiedere all'utente l'alfabeto chiave;
  Leggerlo;
  Verificare se contiene tutte e sole le lettere dell'alfabeto,
  ovvero verificare se non ci sono lettere mancanti o ripetute;
  Possibile approccio: riordinare l'alfabeto chiave e confrontarlo
  con quello originale;
  Ripetere tutta la procedura finché l'utente non inserisce un alfabeto corretto;
  Per ogni lettera della parola/frase inserita dall'utente, trovare l'indice
  di quella lettera nell'alfabeto normale e sostituirla con la lettera che
  ha lo stesso indice nell'alfabeto chiave
*/


=======
>>>>>>> 26f31478c22fc4eb1402875a8d0d622cc4aefe60
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
