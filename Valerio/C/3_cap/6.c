/*
  Scrivere singole istruzioni in C per:
  a) Leggere il valore della variabile intera senza sengo x con scanf.
     Usare lo specificatore di conversione %u.
  b) Leggere il valore della variabile intera senza segno y con scanf.
  c) Impostare la variabile senza segno i a 1.
  d) Impostare la variabile senza segno power a 1.
  e) Moltiplicare la variabile intera senza segno power per x e assegnare il
     risultato a power.
  f) Incrementare la variabile i di 1.
  g) Testare i per vedere se è minore o uguale a y nella condizione di
     un'istruzione while.
  h) Stampare la variabile intera senza segno power con printf.
*/
#include <stdio.h>

int main(void) {
  unsigned int x, y;
  scanf("%u", &x);
  scanf("%u", &y);
  unsigned int i = 1;
  unsigned int power = 1;
  power *= x;
  i++;
  while (++i <= y);
  printf("power: %u\n", power);
}
