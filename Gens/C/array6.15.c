#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int a = 0, b = 0;
  int sum = 0;
  int k; // variabile per il segno

  printf("Immetti un numero a: \n");
  scanf("%d", &a);
  printf("Immetti un numero b: \n");
  scanf("%d", &b);

  sum = a + b;
  printf("La somma dei numeri é: %d\n", sum);

  if(b < 0){
    b *= -1;
  }else if (a < 0){
    a *= -1;
  }
  sum = a + b;
  printf("La somma dei numeri senza segno è: %d\n", sum);

  if(b < 0){
    printf("B è negativo\n");
  }else{
    printf("B è positivo\n");
  }

  if(a % 2 == 0){
    printf("A è pari\n");
  }else{
    printf("A è dispari\n");
  }
}
