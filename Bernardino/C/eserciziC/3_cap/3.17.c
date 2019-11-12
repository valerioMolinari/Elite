/* Determinare se un cliente di un grande magazzino ha superato il limite di credito sul suo conto di addebito;
per ogni cliente sono a disposizione i seguenti dati:
a) Numero del conto;
b) Saldo all'inizio del mese;
c) Totale delle voci addebitate sul conto del cliente nel mese;
d) Totale dei crediti applicati nel mese al conto del cliente;
e) Limite di credito concesso;

determinare 5 variabili;
chiedere all'utente di inserire il valore di a,b,c,d,e;
leggere gli input da tastiera ed inserirli all'interno delle variabili corrispondenti;
se il numero del conto equivale a -1 terminare il programma;
fissare una nuova variabile del nuovo saldo;
calcolare il nuovo saldo (= saldo iniziale + addebiti - crediti);
determinare se il nuovo saldo supera il limite di credito del cliente;
se il nuovo saldo supera il limite di credito del cliente
stampare il numero del conto del cliente, il limite di credito, il nuovo saldo;
stampare il messaggio "Limite di credito superato";
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    system("clear");
    int conto; //numero del conto
    float saldo; //saldo all'inizio del mese
    float addebiti; //totale delle voci addebitate sul conto del cliente nel mese
    float crediti; //totale dei crediti applicati nel mese al conto del cliente
    float limite; //limite di credito concesso

    printf("Inserire il numero di conto\n");
    scanf("%d", &conto);
      while (conto != -1) {
        printf("Inserire il saldo all'inizio del mese\n");
        scanf("%f", &saldo);
        printf("Inserire il totale delle voci addebitate sul vostro conto nel mese\n");
        scanf("%f", &addebiti);
        printf("Inserire il totale dei crediti applicati nel mese al vostro conto\n");
        scanf("%f", &crediti);
        printf("Inserire il limite del vostro credito\n");
        scanf("%f", &limite);

        float ns; //valore nuovo saldo
        ns = ns + saldo + addebiti - crediti;
          if (ns > limite){
            printf("Il numero del vostro conto: %d\n", conto);
            printf("Il limite di credito: %f\n", limite);
            printf("Il nuovo saldo: %f\n", ns);
            printf("\nLimite di credito superato \n");

            return 0;
            }

      }

      return 0;

  }
