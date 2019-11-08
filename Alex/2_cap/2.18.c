/*
  fissare due variabili;
  chiedere all'utonto di inserire due numeri;
  se il primo numero è maggiore del secondo:
    stampare il numero seguito da "is larger";
  se i due numeri sono uguali:
    stampare "these numbers are equal"
  se il secondo numero è maggiore:
    stampare il numero seguito da "is larger"
*/

#include <stdio.h>

int main(void) {
  int a, b;

  printf("Inserire due valori: ");
  scanf("%d%d", &a, &b);

  if (a > b) {
    printf(" %d is larger\n", a);
  }
  if (a == b) {
    printf("these numbers are equal\n");
  }
  if (a < b) {
    printf("%d is larger\n", b);

  }
}
