#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

  int mynumber = 0;
  int numbrand = 0;
  double soldi = 0;
  int scelta = 0;
  srand(time(NULL));

system("clear");

  printf("Inizio Gioco\nIndovina il numero\n");
  printf("Il gioco consiste nell'indovinare qual'è il numero scelto dal pc\n");
  printf("Raddoppi la tua vincita solo se prendi il numero alla prima scelta\nPuoi riprovare solo se indivini alla prima scelta\nQuanto vuoi scommettere: $");
  scanf("%lf", &soldi);
  printf("\nInserisci il numero scelto in un intervallo tra 1 e 10:\n");
  scanf("%d", &mynumber);

  numbrand = 1 + (rand() % 10);

  if(mynumber == numbrand){
    soldi = soldi * 2;
    printf("Hai vinto\nLe tue vincite sono: %.2lf", soldi);
    puts("Per riprovare premi 1\nPer uscire premi 2\n");
    scanf("%d", &scelta);
    if(scelta == 1){
      while(scelta == 1){
        printf("\nInserisci il numero scelto in un intervallo tra 1 e 10:\n");
        scanf("%d", &mynumber);
        numbrand = 1 + (rand() % 10);
        if(mynumber == numbrand){
          printf("Hai vinto\nLe tue vincite sono: %.2lf", soldi);
          puts("Per riprovare premi 1\nPer uscire premi 2\n");
          scanf("%d", &scelta);
        }else{
          puts("Arrivederci torna quando sarai più fortunato e con qualche soldo\n");
          break;
        }
      }
    }
  }if(mynumber < numbrand){
    puts("Il numero è un pò più grande\n");
    puts("Reinserisci il numero\n");
    scanf("%d", &mynumber);
    while(mynumber != numbrand){
      puts("Riprova\n");
      puts("Reinserisci il numero\n");
      scanf("%d", &mynumber);
  }
  printf("Hai vinto\nLe tue vincite sono: %.2lf", soldi);
}if(mynumber > numbrand){
  puts("Il numero è un pò più piccolo\n");
  puts("Reinserisci il numero\n");
  scanf("%d", &mynumber);
  while(mynumber != numbrand){
    puts("Riprova\n");
    puts("Reinserisci il numero\n");
    scanf("%d", &mynumber);
    }
  printf("Hai vinto\nLe tue vincite sono: %.2lf", soldi);
  }
}
