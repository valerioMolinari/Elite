#include <stdio.h>

int main(void) {
  unsigned int x = 1;
  unsigned int total = 0;
  unsigned int y;

  while (x <= 10) {
    y = x * x;
    printf("%d\n", y);
    total += y;
    ++x;
  }

  printf("Total is %d\n", total);
}
