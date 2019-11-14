/* "Stipendio lordo di ciascuno dei diversi impiegati"
Paga prevista all'ora per l'orario lavorativo normale per le prime
40 ore di lavoro e paga "una volta e mezza" per tutte le ore di lavoro oltre le 40 ore.
Vengono dati una lista degli impiegati dell'azienda, il numero di ore
in cui l'impiegato ha lavorato l'ultima settimana e la paga oraria di ogni impiegato.

fissare due variabili;
chiedere all'utente di inserire il valore del numero di ore di lavoro settimanale e la paga oraria;
leggere i dati inseriti da tastiera;
assegnare ogni valore alla variabile corrispondente;
calcolare lo stipendio lordo;
stampare il valore dello stipendio lordo;
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

system("clear");

  float ore; //numero di ore di lavoro settimanale
  float paga; //paga oraria di ogni impiegato

   printf("Inserire il numero di ore lavorate durante l'ultima settimana: \n");
   scanf("%f", &ore);

   while(ore != -1){
     if (ore <= 40){
       printf("Inserire la paga oraria: \n");
       scanf("%f", &paga);

       float stipendio = (ore) * (paga); //stipendio lordo fino alle prime 40 ore di lavoro
       printf("Lo stipendio lordo settimanale corrisponde a $ %f\n", stipendio);

       printf("Inserire il numero di ore lavorate durante l'ultima settimana: \n");
       scanf("%f", &ore);

       if(ore == -1){
         return 0;
          }
        }
     else {
       printf("Inserire la paga oraria: \n");
       scanf("%f", &paga);

       float extra = ore - 40; //ore extra lavorate oltre le 40
       float sl = ((40) * (paga) + (extra) * (1.5 * paga)); //stipendio lordo


       printf("Lo stipendio lordo settimanale corrisponde a $ %f\n", sl);

       printf("Inserire il numero di ore lavorate durante l'ultima settimana: \n");
       scanf("%f", &ore);

       if(ore == -1){
         return 0;
       }
      }

    }

    if(ore == -1){
      return 0;
    }
}
