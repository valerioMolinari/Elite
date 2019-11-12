/* "Interesse semplice su un prestito":
interest = principal * rate * days / 365;
rate = tasso di interesse annuale (quindi effettua la divisione per 365 giorni);

determinare 3 variabili;
chiedere all'utente di inserire il valore di principal, rate e days;
assegnare i valori inseriti da tastiera alle corrispondenti variabili;
se il valore di principal = -1
terminare il programma;
se il valore di principal != -1
calcolare l'interesse semplice per ogni prestito;
stampare il valore dell'interesse per ogni prestito;
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
system("clear");
  float principal; //capitale di prestito
  float rate; //tasso d'interesse annuale
  float days; //durata del prestito in giorni

  printf("Inserire il capitale di prestito:\n");
  scanf("%f", &principal);

  while (principal != -1) {
      printf("Inserire il tasso d'interesse annuale:\n");
      scanf("%f", &rate);
      printf("Inserire la durata del prestito (in giorni):\n");
      scanf("%f", &days);

      float interest = principal * rate * days / 365; //cambio di interesse

      printf("Il valore dell'interesse per ogni prestito: $ %.2f\n", interest);

      printf("Inserire il capitale di prestito:\n");
      scanf("%f", &principal);
    }

  if(principal == 1){
     return 0;
  }
}
