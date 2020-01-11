#include <stdio.h>

int main(void) {
  printf("%s:%d\n%s:%d\n%s:%d\n%s:%d\n%s:%d\n",
  "char",sizeof(char), "short", sizeof(short),
  "int", sizeof(int), "long int", sizeof(long int),
  "long long int", sizeof(long long int));
}
