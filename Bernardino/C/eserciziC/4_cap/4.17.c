/* Calcolare i limiti di credito:
se un cliente aveva un limite di credito di $2000, questo adesso è di 1000$.
Analizzare lo status di tre clienti dell'azienda; vi sono dati per ogni cliente:
1) il numero di conto del cliente;
2) il limite di credito del cliente prima della recessione;
3) il saldo attuale di credito del cliente (cioè l'ammontare che il cliente deve all'azienda);

fissare 3 variabili;
chiedere all'utente di inserire il numero del conto, il limite di credito prima della
recessione e il saldo attuale di credito;
assegnare alle 3 variabili i corrispettivi valori;
calcolare il nuovo limite di credito per ciascun cliente;
stampare tale valore;
se il saldo attuale di credito supera i nuovi limiti di credito:
stampare il numero del conto del cliente;
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
system("clear");

int numero; //numero di conto del cliente
double lc; //limite di credito del cliente prima della recessione
double saldo; //saldo attuale di credito

double nlc; //nuovo limite di credito dimezzato dall'azienda

for (unsigned int counter = 1; counter <= 3; ++counter){
    printf("Inserire il numero del conto: \n");
    scanf("%d", &numero);
    if(numero < 0){
      return 0;
    }
    printf("Inserire il limite attuale di credito: \n");
    scanf("%lf", &lc);
    printf("Inserire il saldo attuale di credito: \n");
    scanf("%lf", &saldo);

    nlc = lc / 2;
    printf("Il nuovo limite di credito equivale a: %lf\n", nlc);

    if(saldo > nlc){
      printf("Numero conto:");
      printf("%d\n", numero);
      printf("Il tuo saldo attuale di credito supera i nuovi limiti di credito. \n");
    }
  }
}
