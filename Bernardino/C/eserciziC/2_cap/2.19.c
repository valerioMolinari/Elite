/*
  fissare tre variabili;
  chiedere all'utente di inserire tre numeri;
  inserire i tre numeri all'interno delle variabili;
  per ogni operazione (somma, media, prodotto) creare una nuova variabile;
  stampare la somma dei tre numeri;
  stampare la media dei tre numeri;
  stampare il prodotto dei tre numeri;
  se il primo numero è minore del secondo e del terzo:
    stampare il primo numero;
  se il secondo numero è minore del primo e del terzo:
    stampare il secondo numero;
  se il terzo numero è minore del primo e del secondo:
    stampare il terzo numero;
  se il primo numero è maggiore del secondo e del terzo:
    stampare il primo numero;
  se il secondo numero è maggiore del primo e del terzo:
    stampare il secondo numero;
  se il terzo numero è maggiore del primo e del secondo:
    stampare il terzo numero;
  */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  system("clear");
  int a, b, c;
  printf("Inserisci tre numeri interi:");
  scanf("%d%d%d", &a, &b, &c );

  int somma = a + b + c;
  float media = (float) ((a + b + c) / 3);
  int prodotto = a * b * c;

  printf("La somma è: %d\n", somma );
  printf("La media è: %f\n", media );
  printf("Il prodotto è: %d\n", prodotto );

  if (a > b && a > c) {
    printf("Il maggiore tra i numeri è: %d\n", a);
  }
  if (b > a && b > c) {
    printf("Il maggiore tra i numeri è: %d\n", b);
  }
  if (c > a && c > b) {
    printf("Il maggiore tra i numeri è: %d\n", c);
  }
  if (a < b && a < c) {
    printf("Il minore tra i numeri è: %d\n", a);
  }
  if (b < a && b < c) {
    printf("Il minore tra i numeri è: %d\n", b);
  }
  if (c < a && c < b) {
    printf("Il minore tra i numeri è: %d\n", c);
  }
}
