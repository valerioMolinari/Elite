#include <stdio.h>
#include <stdlib.h>

//#define SIZE 10;

int main(void) {

  int imp; //numero impiegati che hanno lavorato
  int scelta = 0; //scelta per il codice paga
  int y = 0; //serve per l'arrays per ogni impiegato
  int b = 0; //serve per la stampa degli stipendi
  double ore = 0; //ore di lavoro
  double paga1; //paga manager
  double paga2; //paga lavoratore a ore
  double paga3; //paga lavoratori con provvigione
  double paga4; //paga lavoratori a cottimo
  double vendite, percentuale; //per i lavoratori a provvigione
  double articoli; //per i lavoratori a cottimo
  double stipendi[10]; //totale stipendi

  system("clear");

  printf("Inserisci il numero di impiegati che hanno lavorato questa settimana: \n");
  scanf("%d",&imp);

  system("clear");

  for(int x = 0; x < imp; ++x){
    printf("Inserire il codice paga: \n");
    printf("\n1 = Manager \n2 = Lavoratori a ore \n3 = Lavoratori a provvigione \n4 = Lavoratori a cottimo\n");
    scanf("%d", &scelta);

    system("clear");

    switch(scelta){
      case 1:
      printf("Quante ore ha lavorato: \n");
      scanf("%lf", &ore);
      paga1 = ore * 10;
      printf("La sua paga settimanale è: %.2lf $\n", paga1);
      stipendi[y] = paga1;
      ++y;
      break;

      case 2:
      printf("Quante ore ha lavorato: \n");
      scanf("%lf", &ore);
      if (ore < 40){
        paga2 = ore * 8;
      }else{
        paga2 = ore * 8.5;
      }
      printf("La sua paga settimanale è: %.2lf $\n", paga2);
      stipendi[y] = paga2;
      ++y;
      break;

      case 3:
      printf("Quante ore ha lavorato: \n");
      scanf("%lf", &ore);
      printf("A quanto ammontano le loro vendite settimanali: \n");
      scanf("%lf", &vendite);
      percentuale = (vendite * 5.7) / 10;
      paga3 = 250 + percentuale;
      printf("La sua paga settimanale è: %.2lf $\n", paga3);
      stipendi[y] = paga3;
      ++y;
      break;

      case 4:
      printf("Quante ore ha lavorato: \n");
      scanf("%lf", &ore);
      printf("Quanti articoli ha prodotto: \n");
      scanf("%lf", &articoli);
      paga4 = articoli * 5;
      printf("La sua paga settimanale è: %.2lf $\n", paga4);
      stipendi[y] = paga4;
      break;

    }
  }

  system ("clear");

  printf("I stipendi settimanali sono: \n");
  for(int i = 0; i < imp; ++i){
    printf("%.2lf $\n\n", stipendi[b]);
    ++b;
  }
  printf("Grazie per aver usato questo programma.\n");
}
