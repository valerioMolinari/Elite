#include <stdio.h>

int main(void) {
  int numeroConto;
  float saldoMese;
  float totaleVoci;
  float totaleCrediti;
  int limiteCredito = 5000;
  float nuovoSaldo;

  printf("%s", "Numero conto:\n");
  scanf("%d", &numeroConto);
  printf("%s", "Saldo mese:\n");
  scanf("%f", &saldoMese);
  printf("%s", "Voci addebitate:\n");
  scanf("%f", &totaleVoci);
  printf("%s", "Totale crediti: \n");
  scanf("%f", &totaleCrediti);

  nuovoSaldo = saldoMese + totaleVoci - totaleCrediti;

  if(nuovoSaldo > limiteCredito){
    printf("Numero conto:\n");
    printf("Limite credito:\n");
    printf("Nuovo saldo:\n");
    printf("Limite di credito superato.");
  }


}
