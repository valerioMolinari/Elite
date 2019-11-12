/* Il personale addetto alle vendite riceve 200 dollari alla settimana più
il 9% delle vendite lorde per quella settimana.

Fissare una variabile;
chiedere all'utente di inserire il valore delle vendite lorde per quella settimana;
assegnare il valore inserito da tastiera alla variabile corrispondente;
se il valore inserito corrisponde a -1:
terminare il programma;
se il valore inserito è diverso da -1:
fissare la variabile riguardante i guadagni dell'addetto;
calcolare i guadagni settimanali;
stampare il valore corrispondente;
elaborare i dati di ogni addetto alla volta;
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
system("clear");

float vendite; //vendite lorde per quella settimana

printf("Inserire il valore delle vendite lorde della settimana: \n");
scanf("%f", &vendite);

while (vendite != -1) {
      float gv = ((vendite) * (9) / (100)); // guadagni che variano in base alle vendite settimanali
      float salario = gv + 200; //200$ è il salario minimo settimanale di ogni addetto

      printf("Il salario settimanale corrisponde a $ %f\n", salario);

      printf("Inserire il valore delle vendite lorde della settimana: \n");
      scanf("%f", &vendite);
   }
  if(vendite == -1){
    return 0;
  }

}
