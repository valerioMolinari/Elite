#include <stdio.h>

int main()
{
  int sum = 0;
  int count;

  for (count = 0; count < 5; count++)
  {
      int a = 0;

      printf("Dammi il numero da sommare %d\n", a);

      sum+= a;
  }

  printf("La somma dei numeri e': %d\n", sum );
}
