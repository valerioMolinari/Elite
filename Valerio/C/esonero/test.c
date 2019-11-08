#include <stdio.h>

int main(void) {
  int a[] = {1,2,3};
  int * b = a;
  b[1] = 9;
  for (size_t i = 0; i < 3; i++) {
    printf("%d\n", a[i]);
  }
}
