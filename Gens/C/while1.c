#include<stdio.h>
//Determina la media della classe in riferimento al quiz
int main(void){
  unsigned int prossimoVoto;
  int voto;
  int totale;
  int media;

  totale = 0;
  prossimoVoto = 1;

  while(prossimoVoto <= 10) {
    printf("%s", "Immetti voto: ");
    scanf("%d", &voto);
    totale = totale + voto;
    prossimoVoto = prossimoVoto + 1;
  }
  media = totale / 10;
  printf("La media della classe è: %d\n", media);
}
