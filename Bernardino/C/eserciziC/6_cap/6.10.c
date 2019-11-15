/* Commissioni sulle vendite
Gli agenti di vendita ricevono $200 alla settimana più il 9% delle loro vendite
lorde per quella settimana;
utilizzare un array di contatori e un array unidimensionale
determinare quanti agenti di vendita hanno avuto i loro guadagni in ognuno dei
seguenti intervalli:
a) $200-299
b) $300-399
c) $400-499
d) $500-599
e) $600-699
f) $700-799
g) $800-899
h) $900-999
i) $1000 e oltre
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 9

int main(void) {
  system("clear");

  int array[SIZE] =  {0};

  float vendite; //vendite lorde per quella settimana di ogni agente di vendita

  do {
    printf("Inserisci il valore delle vendite lorde settimanali: \n");
    scanf("%f", &vendite);
    if (vendite < 0) break;
    float guadagno = 200 + (vendite * 9 / 100);

    /* if(guadagno >= 200 && guadagno <= 299){
      counter0++;
      array[0] = counter0;
    } else if(guadagno >= 300 && guadagno <= 399){
      array[1] = counter1++;
    } else if(guadagno >= 400 && guadagno <= 499){
      array[2] = counter2++;
    } else if(guadagno >= 500 && guadagno <= 599){
      array[3] = counter3++;
    } else if(guadagno >= 600 && guadagno <= 699){
      array[4] = counter4++;
    } else if(guadagno >= 700 && guadagno <= 799){
      array[5] = counter5++;
    } else if(guadagno >= 800 && guadagno <= 899){
      array[6] = counter6++;
    } else if(guadagno >= 900 && guadagno <= 999){
      array[7] = counter7++;
    } else if(guadagno >= 1000){
      array[8] = counter8++;
    }*/

    for (size_t i = 0; i < SIZE; i++) {
      if(guadagno > (i * 100 + 200) && guadagno < (i * 100 + 299)){
        array[i]++;
      }
    }

  } while (vendite > 0);

  for(int i = 0; i < SIZE - 1; i++) {
    printf("Le persone presenti nell'intervallo tra %d e %d: %d\n", (i * 100 + 200), (i * 100 + 299), array[i]);
  }
  printf("Le persone presenti con un guadagno maggiore o uguale a 1000: %d\n", array[SIZE - 1]);
}
