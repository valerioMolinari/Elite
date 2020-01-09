#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct b_brano {
  char titolo[50];
  char autore[50];
  int durata;
}s_brano;

int main(){

  s_brano brano1, *ptr1;
  s_brano brano2; *ptr2;
  ptr1 = &brano1;
  ptr2 = &brano2;

  printf("Inserisci la durata della canzone in secondi: ");
  scanf("%d", ptr1->durata);
  if(ptr1->durata < 100){
    printf("Hai scelto la prima traccia\n");
  }else{
    printf("Hai scelto la seconda\n");
  }
  puts("");
}
