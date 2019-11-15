#include <stdio.h>

int main(void) {
  unsigned int migliaPercorse;
  unsigned int galloniPieno;
  float migliaPERgalloni;

  migliaPercorse = 0;
  galloniPieno = 0;
  migliaPERgalloni = 0;

  printf("%s", "Inserisci le miglia percorse: ");
  scanf("%u", &migliaPercorse);
  printf("%s", "Inserisci i galloni a ogni pieno: (-1 per finire)");
  scanf("%u", &galloniPieno);

  while(migliaPercorse != -1){
    migliaPERgalloni = (float)migliaPercorse * (float)galloniPieno;
    printf("Inserisci le miglia percorse: ");
    scanf("%u", &migliaPercorse);
    printf("Inserisci i galloni a ogni pieno: (-1 per finire)");
    scanf("%u", &galloniPieno);
  }
  printf("I miglia per galloni: %f", migliaPERgalloni);
}
