#include<stdio.h>

int main(void){
  unsigned int prossimoVoto;
  int totale;
  int voto;
  float media;

  totale = 0;
  prossimoVoto = 0;

  printf("%s", "Immetti voto, -1 per finire:\n");
  scanf("%d", &voto);

  while(voto != -1){
    totale = totale + voto;
    prossimoVoto = prossimoVoto + 1;
    printf("%s","Immetti voto, -1 per finire\n");
    scanf("%d", &voto);
  } if(prossimoVoto != 0){
    media = (float)totale / prossimoVoto;
    printf("La media della classe è: %.2f\n", media);
  }else{
    printf("Non sono stati inseriti voti");
  }
}
