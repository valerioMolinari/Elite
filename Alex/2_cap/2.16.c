/*
  creare due variabili;
  chiedere all'utente di inserire due numeri;
  leggere gli input inseriti dall'utente e salvarli nelle variabili;
  per ogni operazione creare una variabile contenente l'operazione;
  stampare ciascuna variabile;
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  system("clear");
  int a,b;

  printf("Inserire due numeri: ");
  scanf("%d%d", &a, &b);

  int somma = a + b;
  int prodotto = a * b;
  int differenza = a - b;
  float quoziente = (float) a / b;
  int resto = a % b;

  printf("Somma: \t\t%d\n", somma);
  printf("Prdotto: \t%d\n", prodotto);
  printf("Differenza: \t%d\n", differenza);
  printf("Quoziente: \t%.2f\n", quoziente);
  printf("Resto: \t\t%d\n", resto);
}
