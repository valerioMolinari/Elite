#include<stdio.h>

int main(void) {
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
