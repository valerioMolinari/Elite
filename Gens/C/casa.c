#include <stdio.h>

int main(void) {

  double km = 0;
  double somma = 0;
  printf("Quanti kilometri hai corso:\n Scrivere 1 per terminare\n");
  scanf("%lf", &km);

  while(km == 1){
    km += km;
    somma = km + km;
  } printf("La somma dei km è: %.2f", somma);

}
