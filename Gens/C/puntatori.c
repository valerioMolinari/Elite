#include <stdio.h>

int main(void) {
  int a[3] = {3,7,9};
  int *p = &a[1];
  //printf("%p", &a);
  printf("%d", *p);
}
