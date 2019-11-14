/* fissare una variabile;
chiedere all'utente di inserire un numero di 5 cifre;
leggere l'input da tastiera ed inserirlo all'interno della variabile;
separare il numero in ogni sua cifra individuale;
stampare ogni cifra del numero separata dalla seguente da tre spazi;
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  system("clear");
  int a;

  printf("Inserisci un numero intero di 5 cifre: \n");
  scanf("%d", &a);

  int resto0 = a % 10000;
  int resto1 = resto0 % 1000;
  int resto2 = resto1 % 100;
  int resto3 = resto2 % 10;
  int resto4 = resto3 % 1;

  int primacifra = a / 10000;
  int secondacifra = resto0 / 1000;
  int terzacifra = resto1 / 100;
  int quartacifra = resto2 / 10;
  int quintacifra = resto3 / 1;

  printf("%d", primacifra);
  printf("%4d", secondacifra);
  printf("%4d", terzacifra);
  printf("%4d", quartacifra);
  printf("%4d\n", quintacifra);

}
