/*
  fissare due variabili;
  chiedere all'utente di inserire 2 interi;
  leggere i due input da tastiera;
  se il primo è maggiore del secondo:
    stampare "il primo numero (%d) è maggiore"
  se il secondo è maggiore del primo:
    stampare "il secondo numero (%d)è maggiore"
  se il primo numero è uguale al secondo:
    stampare "questi numeri sono uguali"
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
  system("clear");

  int a, b;
  printf("Inserisci due numeri:");
  scanf("%d %d", &a, &b );

  if (a > b) {
    printf("il primo numero %d è maggiore \n", a);
  }
  if (a < b) {
    printf("il secondo numero %d è maggiore \n", b);
  }
  if (a == b) {
    printf("questi numeri sono uguali\n" );
  }

}
