#include <stdio.h>

int main(void) {
  int a;
  int b;
  printf("Inserisci un numero: ");
  scanf("%d",&a);
  printf("Inserisci un secondo numero: ");
  scanf("%d",&b);
  int somma = a+b;

  printf("\nSomma = %d\n", somma);
}
