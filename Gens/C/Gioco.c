#include <stdio.h>
#include <stdlib.h>

//Gioco da pc Zacca vs Agrid vs Antonio

int main(void){

  system("clear");

  //Scelta Personaggio
  int personaggio; // per la scelta del personaggio

  printf("Inizio Gioco\n Scegli un personaggio\n \n1:Zacca The Immortal\n Salute: 50\n Danno: 50\n \n2:Agrid dell'Est\n Salute: 50\n Danno: 50\n \n3:Antonio Sbriccolaus\n Salute: 50\n Danno: 50\n");
  scanf("%d", &personaggio);
  if(personaggio == 1){
    printf("\nHai scelto Zacca The Immortal\n");
    printf("Il tuo zaino è composto da:\nBottiglia di Gin (per curarti)\nQuad meccanico (per attaccare)\n");
  }else if(personaggio == 2){
    printf("\nHai scelto Agrid dell'Est\n");
    printf("Il tuo zaino è composto da:\nBecchime (per curarti)\nPlaystatio 4 (per attaccare)\n");
  }else if(personaggio == 3){
    printf("\nHai scelto Antonio Sbriccolaus\n");
    printf("Il tuo zaino è composto da:\nPsicofarmaci (per curarti)\nSigaro Cubano (per attacare)\n");
  }

  //Scelta inventario
  int contatore = 0; // per la scelta di armi o medicine
  int menu; // per la scelta tra armi o medicine
  int x; // per lo slot di armi e medicine
  int salute = 50, danno = 50;

  while(contatore < 2){

    printf("\nHai fino a 2 scelte per l'inventario\n");
    printf("\nScegli tra\n 1: Armi\n 2: Medicine\n");
    scanf("%d", &menu);

    if(personaggio == 1){
      switch(menu){
        case 1:
        printf("Seleziona Armi\n 1: Glock\n 2: Ak-47\n");
        scanf("%d", &x);
        switch(x){
          case 1:
          printf("Danno +10\n");
          danno += 10;
          break;
          case 2:
          printf("Danno +20\n");
          danno += 20;
          break;
        }
        break;
        case 2:
        printf("Seleziona Medicine\n 1: Scudo\n 2: Bende\n");
        scanf("%d", &x);
        switch(x){
          case 1:
          printf("Salute +30\n");
          salute += 30;
          break;
          case 2:
          printf("Salute +20\n");
          salute += 20;
          break;
        }
      }
      ++contatore;
    }else if(personaggio == 2){
      switch(menu){
        case 1:
        printf("Seleziona Armi\n 1: Glock\n 2: Ak-47\n");
        scanf("%d", &x);
        switch(x){
          case 1:
          printf("Danno +20\n");
          danno += 20;
          break;
          case 2:
          printf("Danno +10\n");
          danno += 10;
          break;
        }
        break;
        case 2:
        printf("Seleziona Medicine\n 1: Scudo\n 2: Bende\n");
        scanf("%d", &x);
        switch(x){
          case 1:
          printf("Salute +20\n");
          salute += 20;
          break;
          case 2:
          printf("Salute +30\n");
          salute += 30;
          break;
        }
      }
      ++contatore;
    }else if(personaggio == 3){
      switch(menu){
        case 1:
        printf("Seleziona Armi\n 1: Glock\n 2: Ak-47\n");
        scanf("%d", &x);
        switch(x){
          case 1:
          printf("Danno +20\n");
          danno += 20;
          case 2:
          printf("Danno +10\n");
          danno += 10;
          break;
        }
        break;
        case 2:
        printf("Seleziona Medicine\n 1: Scudo\n 2: Bende\n");
        scanf("%d", &x);
        switch(x){
          case 1:
          printf("Salute +20\n");
          salute += 30;
          break;
          case 2:
          printf("Salute +30\n");
          salute += 30;
        }
      }
      ++contatore;
    }
  }
  printf("Il tuo Danno è: %d\nLa tua Salute è: %d\n", danno, salute);

  //Scelta Mappe
  int mappe;// per la scelta delle mappe

    printf("\nScegli dove combattere\n");
    printf("1: Mignone\n2: Grotta Porcina\n3: Villa Comunale\n");
    scanf("%d", &mappe);
    switch (mappe){
      case 1:
      printf("Hai scelto la palude mistica del Mignone\n(Si consiglia se scelto Zacca The Immortal)\n");
      break;
      case 2:
      printf("Hai scelto le tombe infernali di Grotta Porcina\n(Si consiglia se scelto Agrid dell'Est)\n");
      break;
      case 3:
      printf("Hai scelto la natura selvaggia della Villa Comunale\n(Si consiglia se scelto Antonio Sbriccolaus)\n");
    }
    system ("clear");

    //Scelta Movimenti
    int movimento[4] = {1,2,3,4}; //dove si vuole muovere il tuo personaggio
    int i; //per dove decidere di muoversi il personaggio
    int op1 = 0, op2 = 28, op3 = 100; // operazioni
    int dannoA = 25, saluteA = 150; //danno e salute Agrid per personaggio 1 e mappa 1

    printf("Zacca The Immortal ti sfiderai contro Agrid dell'Est (Danno = 25 / Salute = 150 )\n");
    while(saluteA > 0 || salute > 0){
      if(personaggio == 1 && mappe == 1){
        printf("\nScegli dove muoverti\n1: Nord\n2: Sud\n3: Est\n4: Ovest\n");
        scanf("%d", &i);
        if(i == movimento[0]){
          printf("\nSe indovini il risultato dell'operazione sei tu ad attaccare sennò verrai attaccato\n");
          printf("((3x (-2)) +6) x ((2+2+2) -2) = \n");
          scanf("%d", &op1);
          if(op1 == 0){
            printf("\nHai indovinato\n");
            saluteA = saluteA - danno;
            printf("\nLa salute di Agrid è: %d\n", saluteA);
          }else{
            printf("\nNon Hai indovinato\n");
            salute = salute - dannoA;
          }
        }
        printf("\nZacca\nSalute = %d\nAgrid\nSalute = %d", salute, saluteA);
        if(i == movimento[1]){
          printf("\nSe indovini il risultato dell'operazione sei tu ad attaccare sennò verrai attaccato\n");
          printf("[4x (3+4)] x [(3+2) /5] = \n");
          scanf("%d", &op2);
          if(op2 == 28){
            printf("\nHai indovinato\n");
            saluteA = saluteA - danno;
            printf("\nLa salute di Agrid è: %d\n", saluteA);
          }else{
            printf("\nNon Hai indovinato\n");
            salute = salute - dannoA;
          }
        }
        if(i == movimento[2]){
          printf("\nSe indovini il risultato dell'operazione sei tu ad attaccare sennò verrai attaccato\n");
          printf("{[5x (5x5) - (3x4)]- 13}");
          scanf("%d", &op3);
          if(op3 == 100){
            printf("\nHai indovinato\n");
            saluteA = salute A - danno;
            printf("\nLa salute di Agrid è: %d\n", saluteA);
          }else{
            printf("\nNon Hai indovinato\n");
            salute = salute - dannoA;
          }
        }
      }
    }
    if(saluteA < 0){
      printf("\nHai vinto!!!!!!!!!!!\n");
    }else if(salute < 0){
      printf("\nHai perso!!!!!!!!!!!\n");
    }
  }
