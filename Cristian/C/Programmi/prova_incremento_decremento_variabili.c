#include <stdio.h>

int main ()
  {
    int a = 1, b = 2, c = 3, d = 4; //10
    int risultato = 0;

    a-- , risultato = ++a + b + c + d;
    printf("%d\n", risultato);
  }
