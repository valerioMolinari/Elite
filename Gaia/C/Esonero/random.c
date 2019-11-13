#include <stdio.h>
#include <stdlib.h>

void main()
{
  char c;
  char r[26];

  //un solo carattere random
  c = random();

  //array di caratteri random
  for (int i = 0; i < 26; i++){

    r[i] = random();

    if ((r[i] == r[i-1]) && (isdigit(r[i]) == 0) && (isalnum(r[i]) == 0)){
      r[i] = random();
    }

    printf("%c\n", r[i]);
  }

  printf("La lettera generata è: %c\n", c);
}
