#include <stdio.h>

//Gioco da pc Zacca vs Agrid vs Enfisema


int main(void){

  system("clear");

  // per la scelta del personaggio
  int personaggio;
  printf("Inizio Gioco\n Scegli un personaggio\n 1: Zacca\n Salute: 50\n Danno: 70\n 2: Agrid\n Salute: 70\n Danno: 60\n 3: Enfisema\n Salute: 90\n Danno: 50\n");
  scanf("%d", &personaggio);
  if(personaggio == 1){
    printf("Hai scelto Zacca\n");
  }else if(personaggio == 2){
    printf("Hai scelto Agrid\n");
  }else if(personaggio == 3){
    printf("Hai scelto Enfisema\n");
  }
  system("clear");

  if(personaggio == 1){
    printf("Il tuo bonus è:\n Scatto del Drago\n (Usandolo una volta ogni 3 turni puoi muoverti due volte)\n");
  }else if(personaggio == 2){
    printf("Il tuo bonus è:\n Torretta Robot\n (Lo puoi usare quando trovi le munizioni)\n");
  }else if(personaggio == 3){
    printf("Il tuo bonus è:\n Potere dell'Oscurità\n (Una volta per turno la probabilità per trovare più bonus sale di +1.5)\n");
  }

  system("clear");

  printf("Hai fino a 3 scelte per l'inventario\n");

  system("clear");
  // per la scelta di armi o medicine
  int contatore = 1;

  while(contatore <= 3){

    int menu;
    char inventario[3] = {0};

    system("clear");

    printf("Menu\n 1: Armi\n 2: Medicine\n");
    scanf("%d", &menu);

    system("clear");

    switch(menu){
      case 1:
      printf("Seleziona Armi\n 1: Glock\n 2: Ak-47\n 3: Katana\n");
      scanf("%d", &inventario[3]);
      switch(inventario[3]){
        case 0:
        printf("Danno +15\n");
        break;
        case 1:
        printf("Danno +30\n");
        break;
        case 2:
        printf("Danno +20\n");
        break;
      }
      break;
      case 2:
      printf("Seleziona Medicine\n 4: Scudo\n 5: Bende\n 6: Pozione\n");
      scanf("%d", &inventario[3]);
      switch(inventario[3]){
        case 4:
        printf("Salute +50\n");
        break;
        case 5:
        printf("Salute +25\n");
        break;
        case 6:
        printf("Salute +15\n");
      }
      break;
    }
    ++contatore;
    printf("%c",inventario[3]);
  }


  system("clear");

  // per la scelta delle mappe
  int mappe;
    printf("Scegli dove combattere\n");
    printf(" 1: Mignone\n 2: Grotta Porcina\n 3: Villa Comunale\n");
    scanf("%d", &mappe);
    switch (mappe){
      case 1:
      printf("Hai scelto la palude mistica del Mignone");
      break;
      case 2:
      printf("Hai scelto le tombe infernali di Grotta Porcina");
      break;
      case 3:
      printf("Hai scelto la natura selvaggia della Villa Comunale");
    }

    system("clear");

  /*  while(personaggio == 1){

  }*/
  }
