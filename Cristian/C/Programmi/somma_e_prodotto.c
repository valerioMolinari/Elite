#include <stdio.h>

int main () {
  int a, b;
  int somma;
  int prodotto;
  printf ("inserire i valori per fare la somma e prodotto\n");
  scanf("%d %d", &a, &b );

  somma = a+b;
  prodotto = a*b;
  printf ("La somma dei valori e': %d\n",somma);
  printf ("Il prodotto dei valori e': %d\n",prodotto);
}
