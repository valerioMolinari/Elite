/*
 fissare 3 variabili;
 chiedere all'utente di inserire 3 interi;
 leggere i 3 input da tastiera;
 per ogni operazione (somma, media, prodotto) creare una variabile;
 se il primo intero è minore del secondo e minore del terzo:
    stampare "il minore è il primo intero";
 se il secondo intero è minore del primo e del terzo:
    stampare "il minore  è il secondo intero";
 se il terzo è maggiore del primo e del secondo:
    stampare "il minore è il terzo numero"
 se il primo intero è maggiore del secondo e del terzo:
    stampare "il maggiore é il primo intero"
 se il secondo intero è maggiore del primo e del terzo:
    stampare "il maggiore  è il secondo intero";
 se il terzo è maggiore del primo e del secondo:
    stampare "il maggiore è il terzo numero"
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
  system("clear");

  int a, b, c;
  printf("Inserisci tre numeri:");
  scanf("%d %d %d", &a, &b, &c );

  int somma = a+b+c;
  printf("la somma è %d\n", somma );

  int media = (a+b+c)/3;
  printf("la media è %d\n", media);

  int prodotto = a*b*c;
  printf("il prodotto è %d\n", prodotto );

  if(a < b & a < c){
    printf("il minore è il primo intero %d\n", a );
  }
  if(b < a & b < c){
    printf("il minore è il secondo intero %d\n", b );
  }
  if(c < a & c < b){
    printf("il minore è il terzo intero %d\n", c );
  }
  if(a > b & a > c){
    printf("il maggiore è il primo intero %d\n", a );
  }
  if(b > a & b > c){
    printf("il maggiore è il secondo intero %d\n", b );
  }
  if(c > a & c > b){
    printf("il maggiore è il terzo intero %d\n", c );
  }
}
