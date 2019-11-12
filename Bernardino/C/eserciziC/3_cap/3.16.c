/* fissare due variabile;
chiedere all'utente di inserire le miglia percorse;
chiedere all'utente di inserire i galloni consumati ad ogni pieno;
leggere gli input da tastiera ed inserirli all'interno delle due variabili;
fissare una nuova variabile che calcoli le miglia percorse per ogni pieno;
stampare il valore di tale variabile;
processare tutte le informazioni di input;
se il valore inserito in input riguardo i galloni consumati ad ogni pieno è negativo:
fissare una nuova variabile che calcoli le miglia complessive per gallone percorse per tutti i pieni;
stampare tale valore; */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  system("clear");
  float miglia;
  float galloni;
  int contatore = 0;
  float media;
  float mg;
  float mgtotal;
  float mg1;

  while (galloni != -1) {
    printf("Inserisci galloni consumati ad ogni pieno, -1 per terminare il programma:\n");
    scanf("%f", &galloni);
    if (galloni == -1){
      float media = mgtotal / contatore;
      printf("Le miglia complessive per gallone percorse per tutti i pieni: %f\n", media);
      return 0;
      }

    printf("\nInserisci le miglia percorse:\n");
    scanf("%f", &miglia);
    mg = miglia / galloni;
    contatore = contatore + 1;
    printf("Miglia/galloni: %f\n", mg);
    mgtotal = mgtotal + mg;
    }
}
