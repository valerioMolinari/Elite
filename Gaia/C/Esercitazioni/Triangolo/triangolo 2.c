#include <stdio.h>

int main(){

  int a = 0, b = 0, c = 0;

  printf("Inserisci il primo lato(a): \n");
  scanf("%d", &a);
  while (a < 0){
    printf("Inserisci il primo lato(a): \n");
    scanf("%d", &a);
  }

  printf("Inserisci il secondo lato(b): \n");
  scanf("%d", &b);
  while (b < 0){
    printf("Inserisci il secondo lato(b): \n");
    scanf("%d", &b);
  }

  printf("Inserisci il terzo lato(c): d\n");
  scanf("%d", &c);
  while (c < 0){
    printf("Inserisci il terzo lato(c): \n");
    scanf("%d", &c);
  }

  if (a == b == c)
    printf("Il triangolo e' equilatero\n");

  if (a != b != c)
    printf("Il triangolo e' scaleno\n");

  if ((a == b != c) || (a == c != b) || (c == b != a))
    printf("Il triangolo e' isoscele\n");

}
