/*
Scrivere un programma che chieda all'utente di inserire 2 numeri,
che li legga e ne stampa la somma, il prodotto la differenza,
il quoziente e il resto.

*chiedere all'utente di inserire 2 numeri;
creare 2 variabili;
leggere gli input inseriti dall'utente e salvarli nelle variabili;
per ogni operazione creare una variablie;
stampare ciascuna variabile;*

*/

#include <stdio.h>

int main(void){
  int a, b;
  printf("Inserisci due numeri:");
  scanf("%d %d", &a, &b );
  int somma =(a+b);
  int differenza = (a-b);
  int prodotto = (a*b);
  int resto = (a%b);
  int quoziente = (a/b);
  printf("%d %d %d %d %d\n", somma, differenza, prodotto, resto, quoziente);







}
