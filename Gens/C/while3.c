#include<stdio.h>

int main(void){

  unsigned int promozioni = 0;
  unsigned int bocciature = 0;
  unsigned int contatore = 1;
  int result;

  while(contatore <= 10){
    printf("%s", "Immetti voto (1=pass, 2=fail):");
    scanf("%d", &result);
   if(result == 1){
    promozioni = promozioni + 1;
  }else{
    bocciature = bocciature + 1;
  }
    contatore = contatore + 1;
  }
    printf("Promozioni %u\n", promozioni);
    printf("Bocciature %u\n", bocciature);
    if(promozioni >= 8){
    printf("Bonus per il prof");
  }
  }
