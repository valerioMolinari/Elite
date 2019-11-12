/* considerare i valori numerici interi da 1 a 10,
fissare una variabile;
assegnare a tale variabile il numero più piccolo tra 1 e 10;
calcolare quadrato e cubo del valore;
incrementare la variabile fino ad arrivare al valore 10;
per ogni valore calcolare quadrati e cubi;
stampare una tavola di valori che contenga in ordine crescente i numeri dell'intervallo
e i loro corrispettivi quadrati e cubi;
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
system ("clear");
int a = 0;
  if (a <= 10){
    int quadrato0 = a * a;
    int cubo0 = a * a * a;
    printf("Numero   Quadrato   Cubo\n");
    printf("%4d\t", a);
    printf("%5d", quadrato0);
    printf("%10d\n", cubo0);
  }
  if (a <= 10){
    int quadrato1 = (a + 1) * (a + 1);
    int cubo1 = (a + 1) * (a + 1) * (a + 1);
    printf("%4d\t", a + 1);
    printf("%5d", quadrato1);
    printf("%10d\n", cubo1);
  }
  if (a <= 10){
    int quadrato2 = (a + 2) * (a + 2);
    int cubo2 = (a + 2) * (a + 2) * (a + 2);
    printf("%4d\t", a + 2);
    printf("%5d", quadrato2);
    printf("%10d\n", cubo2);
  }
  if (a <= 10){
    int quadrato3 = (a + 3) * (a + 3);
    int cubo3 = (a + 3) * (a + 3) * (a + 3);
    printf("%4d\t", a + 3);
    printf("%5d", quadrato3);
    printf("%10d\n", cubo3);
  }
  if (a <= 10){
    int quadrato4 = (a + 4) * (a + 4);
    int cubo4 = (a + 4) * (a + 4) * (a + 4);
    printf("%4d\t", a + 4);
    printf("%5d", quadrato4);
    printf("%10d\n", cubo4);
  }
  if (a <= 10){
    int quadrato5 = (a + 5) * (a + 5);
    int cubo5 = (a + 5) * (a + 5) * (a + 5);
    printf("%4d\t", a + 5);
    printf("%5d", quadrato5);
    printf("%10d\n", cubo5);
  }
  if (a <= 10){
    int quadrato6 = (a + 6) * (a + 6);
    int cubo6 = (a + 6) * (a + 6) * (a + 6);
    printf("%4d\t", a + 6);
    printf("%5d", quadrato6);
    printf("%10d\n", cubo6);
  }
  if (a <= 10){
    int quadrato7 = (a + 7) * (a + 7);
    int cubo7 = (a + 7) * (a + 7) * (a + 7);
    printf("%4d\t", a + 7);
    printf("%5d", quadrato7);
    printf("%10d\n", cubo7);
  }
  if (a <= 10){
    int quadrato8 = (a + 8) * (a + 8);
    int cubo8 = (a + 8) * (a + 8) * (a + 8);
    printf("%4d\t", a + 8);
    printf("%5d", quadrato8);
    printf("%10d\n", cubo8);
  }
  if (a <= 10){
    int quadrato9 = (a + 9) * (a + 9);
    int cubo9 = (a + 9) * (a + 9) * (a + 9);
    printf("%4d\t", a + 9);
    printf("%5d", quadrato9);
    printf("%10d\n", cubo9);
  }
  if (a <= 10){
    int quadrato10 = (a + 10) * (a + 10);
    int cubo10 = (a + 10) * (a + 10) * (a + 10);
    printf("%4d\t", a + 10);
    printf("%5d", quadrato10);
    printf("%10d\n", cubo10);
  }

}
