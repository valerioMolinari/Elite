#include <stdio.h>

//Programma per calcolo delle tasse in base al reddito

int main(void) {

  double reddito;
  printf("Immetti il tuo reddito: \n");
  scanf("%lf", &reddito);

  system("clear");

  double totale1, totale2, totale3;
  double alloggio, abbigliamento, trasporti, generi_alimentari;
  if(reddito >= 0 && reddito <= 15000){
    printf("La tua tassa è del 23 percento\n");
    printf("Immetti le tue spese per ogni categoria\n");
    printf("Alloggio: \n");
    scanf("%lf", &alloggio);
    printf("Abbigliamento: \n");
    scanf("%lf", &abbigliamento);
    printf("Trasporti: \n");
    scanf("%lf", &trasporti);
    printf("Generi alimentari: \n");
    scanf("%lf", &generi_alimentari);
    totale1 = (alloggio + abbigliamento + trasporti + generi_alimentari);
    totale2 = (totale1 * 23) / 100;
    totale3 = totale1 + totale2;
  }else if(reddito >= 15001 && reddito <= 28000){
    printf("La tua tassa è del 27 percento\n");
    printf("Immetti le tue spese per ogni categoria\n");
    printf("Alloggio: \n");
    scanf("%lf", &alloggio);
    printf("Abbigliamento: \n");
    scanf("%lf", &abbigliamento);
    printf("Trasporti: \n");
    scanf("%lf", &trasporti);
    printf("Generi alimentari: \n");
    scanf("%lf", &generi_alimentari);
    totale1 = (alloggio + abbigliamento + trasporti + generi_alimentari);
    totale2 = (totale1 * 27) / 100;
    totale3 = totale1 + totale2;
  }else if(reddito >= 28001 && reddito <= 55000){
    printf("La tua tassa è del 38 percento\n");
    printf("Immetti le tue spese per ogni categoria\n");
    printf("Alloggio: \n");
    scanf("%lf", &alloggio);
    printf("Abbigliamento: \n");
    scanf("%lf", &abbigliamento);
    printf("Trasporti: \n");
    scanf("%lf", &trasporti);
    printf("Generi alimentari: \n");
    scanf("%lf", &generi_alimentari);
    totale1 = (alloggio + abbigliamento + trasporti + generi_alimentari);
    totale2 = (totale1 * 38) / 100;
    totale3 = totale1 + totale2;
  }else if(reddito >= 55001 && reddito <= 75000){
    printf("La tua tassa è del 41 percento\n");
    printf("Immetti le tue spese per ogni categoria\n");
    printf("Alloggio: \n");
    scanf("%lf", &alloggio);
    printf("Abbigliamento: \n");
    scanf("%lf", &abbigliamento);
    printf("Trasporti: \n");
    scanf("%lf", &trasporti);
    printf("Generi alimentari: \n");
    scanf("%lf", &generi_alimentari);
    totale1 = (alloggio + abbigliamento + trasporti + generi_alimentari);
    totale2 = (totale1 * 41) / 100;
    totale3 = totale1 + totale2;
  }else if(reddito <= 75001){
    printf("La tua tassa è del 43 percento\n");
    printf("Immetti le tue spese per ogni categoria\n");
    printf("Alloggio: \n");
    scanf("%lf", &alloggio);
    printf("Abbigliamento: \n");
    scanf("%lf", &abbigliamento);
    printf("Trasporti: \n");
    scanf("%lf", &trasporti);
    printf("Generi alimentari: \n");
    scanf("%lf", &generi_alimentari);
    totale1 = (alloggio + abbigliamento + trasporti + generi_alimentari);
    totale2 = (totale1 * 43) / 100;
    totale3 = totale1 + totale2;
  }
  printf("Il totale non tassato è: %.2lf\n", totale1);
  printf("La tassa aggiuntiva è: %.2lf\n", totale2);
  printf("Il totale delle tue spese tassato é: %.2lf\n", totale3);
}
