#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Calcolo dell'MCD

int main(void) {

  int a = 0, b = 0;
  int resto = 0;

  printf("Immetti due numeri per il calcolo dell'MCD:\n");
  scanf("%d%d", &a, &b);

  if(a > 0 && b > 0){
    printf("Inizio dell'MCD\n");
  }
  if(b == 0){
    printf("L'MCD è: %d\n", a);
    return 0;
  }else if(b > 0){
    while(b != 0){
      resto = a % b;
      a = b;
      b = resto;
    }
  }
  printf("L'MCD è: %d\n", a);
}
