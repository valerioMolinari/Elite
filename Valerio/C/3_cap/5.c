/*
  Mettere insieme le istruzioni inserite nell'esercizio 3.4 in un programma
  che somma dei numeri interi da 1 a 10. Usare l'iterazione while per
  iterare i calcoli e le istruzioni di incremento. Il ciclo deve terminare
  quando il valore di x diventa 11.
*/

#include <stdio.h>

int main(void) {
  int sum, x;
  x = 1;
  sum = 0;
  sum += x;
  /*
  # gli incrementi x++ o ++x possono essere utilizzati all'interno della
  # condizione di un ciclo while
  */
  while (++x < 11) sum += x;
  printf("The sum is: %d\n", sum);
}
