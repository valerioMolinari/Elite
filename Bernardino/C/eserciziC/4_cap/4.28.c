/* I manager ricevono una retribuzione fissa settimanale;
i lavoratori ad ore ricevono una paga fissa all'ora per le prime 40 ore e
una volta e mezza la paga oraria per gli straordinari;
i lavoratori con provvigione ricevono $250 più il 5,7% delle loro vendite;
i lavoratori a cottimo ricevono una quantità fissa di denaro per ogni articolo prodotto;

codice paga manager = 1;
codice paga lavoratori a ore = 2;
codice paga lavoratori a provvigione = 3;
codice paga lavoratori a cottimo = 4;
switch per calcolare la paga di ogni impiegato in base al codice paga
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
system("clear");

int codice; //codice paga
float rf; //retribuzione fissa settimanale dei manager
float ore; //ore lavorate dai lavoratori ad ore
float paga; //paga fissa oraria dei lavoratori ad ore
float extra; //paga oltre le 40 ore dei lavoratori ad ore
float guadagno; //guadagno vendite dei lavoratori a provvigione
float articolo; //guadagno per articolo prodotto
float numero; //numero di articoli prodotti

while (1) {
  printf("Inserisci il codice paga dell'impiegato: \n");
  scanf("%d", &codice);

  while (codice > 0 && codice < 5) {
    switch (codice) {
      case 1: //codice paga manager
      printf("Inserisci il valore della retribuzione fissa: \n");
      scanf("%f", &rf);
      printf("La paga dell'impiegato corrisponde a: %f\n", rf);
      break;

      case 2: //codice paga lavoratori a valore
      printf("Inserisci il numero di ore lavorate \n");
      scanf("%f", &ore);
      printf("Inserisci la paga fissa oraria: \n");
      scanf("%f", &paga);
      if(ore > 40){
        float oreex = ore - 40; //ore di straordinario
        extra = ((paga) * (40) + (oreex) * (1.5 * paga));
        printf("La paga dell'impiegato corrisponde a: %f\n", extra);
      } else {
        double stipendio = paga * ore;
        printf("La paga dell'impiegato corrisponde a: %f\n", stipendio);
      }
      break;

      case 3: //codice paga lavoratori a provvigione
      printf("Inserisci il guadagno delle vendite settimanali: \n");
      scanf("%f", &guadagno);
      float pagaprovvigione = 250 + (guadagno * 5.7 / 100);
      printf("La paga dell'impiegato corrisponde a: %f\n", pagaprovvigione);
      break;

      case 4: //paga lavoratori a cottimo
      printf("Inserisci il guadagno per ogni articolo prodotto: \n");
      scanf("%f", &articolo);
      printf("Inserisci il numero di articoli prodotti: \n");
      scanf("%f", &numero);

      float pagacottimo = articolo * numero;
      printf("La paga dell'impiegato corrisponde a: %f\n", pagacottimo);
      break;
       }
       printf("Inserisci il codice paga dell'impiegato: \n");
       scanf("%d", &codice);
     }
     printf("Inserisci un codice paga valido.\n");
   }
 }
