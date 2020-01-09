#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double calculateCharges(double x, double y);

int main(void) {

  double pagamento = 0;
  double sosta = 0;
  printf("Benvenuti nel parcheggio ParkAlex\n");
  printf("Tariffa Minima = 2.00$ per massimo 3 ore\nOgni prossima ora (o parte di essa) = 0.50$\nGiornata intera (24 ore) = 10$\n");
  printf("Orario max per ogni autovettura = 24 ore\n");
  printf("Quanto hai lasciato la macchina in sosta?\n");
  scanf("%lf", &sosta);

  if(sosta > 24){
    printf("Penalità di 5$ in aggiunta per superamento orario giornaliero\n");
    pagamento += 5;
    printf("Costo parcheggio = 15.00£\n");
  }else{
    printf("Non hai superato l'orario giornaliero\nNon ci sono penalità\n");
    if(sosta <= 3){
      printf("Costo parcheggio = 2.00$\n");
    }else if(sosta > 3 && sosta < 24){
      pagamento = calculateCharges(sosta, pagamento);
      printf("Costo parcheggio = %.2lf\n", pagamento);
    }
  }
}

double calculateCharges(double x, double y){
  x = ceil(x);
  y = ((x - 3) * 0.5) + 2;
  return y;
}
