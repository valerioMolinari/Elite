#include <stdio.h>

int main(void) {
  int a;
  printf("Immetti un numero:");
  scanf("%d", &a);

  switch (a) {
    case 0:
    printf("A\n");
    break;

    case 1:
    printf("B\n");
    break;

    case 2:
    printf("C\n");
    break;

    default:
    printf("Z\n");
  }


}
