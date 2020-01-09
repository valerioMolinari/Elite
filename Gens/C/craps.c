#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(void);
enum Status {CONTINUE, WON, LOST};

int main(void) {

  double soldi = 0;

  printf("Benvenuti nel gioco del Craps!\n");
  printf("Quanto vuoi giocare: $");
  scanf("%lf", &soldi);

  srand(time(NULL));

  int mypoint;
  enum Status gameStatus;
  int sum = rollDice();

  //Al primo lancio
  switch(sum){
    case 7:
    case 11:
    gameStatus = WON;
    break;

    case 2:
    case 3:
    case 12:
    gameStatus = LOST;
    break;

    default:
    gameStatus = CONTINUE;
    mypoint = sum;
    printf("\nPunteggio è: %d\n", mypoint);
    break;
  }
  while(CONTINUE == gameStatus){
    sum = rollDice();
    if(sum == mypoint){
      gameStatus = WON;
    }else if(7 == sum){
      gameStatus = LOST;
    }
  }
  if(WON == gameStatus){
    puts("\nHai vinto e raddoppiato la tua vincita\n");
  }else{
    puts("\nHai perso tutto\n");
  }
}

int rollDice(void){
  int caso1 = 1 + (rand() %6);
  int caso2 = 1 + (rand() %6);
  printf("La somma tra %d + %d = %d\n", caso1, caso2, caso1 + caso2);
  return caso1 + caso2;
}
