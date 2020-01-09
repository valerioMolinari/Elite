#include <stdio.h>
#include <stdlib.h>

int main(void) {

  system("clear");

  int classe = 0; //per la scelta della classe
  int capacità1[4]; //per la disponibilità dei posti in first class
  int capacità2[4]; //per la disponibilità dei posti in economy class
  int i = 0; //serve per l'array capacità1
  int y = 0; //serve per l'array capacità2
  int z = 0; //per il ciclo totale
  int a = 0; //per il ciclo della first class
  printf("Benvenuti nel sito di compagnia aerea AirGenz\n");

  do {
    printf("\nScegli la classe dove vuoi viaggiare\nPremi 1 per la First Class (Max 5 posti)\nPremi 2 per l'Economy Class (Max 5 posti)\nPremi 3 per chiudere la scelta delle classi\n");
    scanf("%d", &classe);
    if(classe == 1){
        capacità1[i] = 1;
        ++i;
        printf("\nCarta d'Imbarco AirGenz\nLei si trova in First Class\nIl suo posto è il numero %d\n", i);
    }else if(classe == 2){
      capacità2[y] = 1;
      ++y;
      printf("\nCarta d'Imbarco AirGenz\nLei si trova in Economy Class\nIl suo posto è il numero %d\n", y);
    }else if(classe == 3){
      break;
    }
    ++z;
  } while(z < 10);

  system("clear");

  printf("I posti occupati in First Class sono:\n");
  for(int b = 0; b < i; ++b){
    printf("Posto %d\n", capacità1[b] + b);
  }
  printf("I posti occupati in Economy Class sono:\n");
  for(int q = 0; q < y; ++q){
    printf("Posto %d\n", capacità2[q] + q);
  }
}
