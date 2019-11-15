#include <stdio.h>

int main(void){

  int personaggio;
  printf("Inizio Gioco\n Scegli un personaggio\n 1:Ninja\n Salute: 50\n Danno: 70\n 2:Militare\n Salute: 70\n Danno: 60\n 3:Troll\n Salute: 90\n Danno: 50\n");
  scanf("%d", &personaggio);
  if(personaggio == 1){
    printf("Hai scelto Ninja\n");
  }else if(personaggio == 2){
    printf("Hai scelto Militare\n");
  }else if(personaggio == 3){
    printf("Hai scelto Troll\n");
  }
  if(personaggio == 1){
    printf("Il tuo bonus è:\n Scatto del Drago\n (Usandolo una volta ogni 3 turni puoi muoverti due volte)\n");
  }else if(personaggio == 2){
    printf("Il tuo bonus è:\n Torretta Robot\n (Lo puoi usare quando trovi le munizioni)\n");
  }else if(personaggio == 3){
    printf("Il tuo bonus è:\n Potere dell'Oscurità\n (Una volta per turno la probabilità per trovare più bonus sale di +1.5)\n");
  }


  int menu, armi, medicine;
  printf("Menu\n 1:Armi\n 2:Medicine\n");
  scanf("%d", &menu);
  switch(menu){
    case 1:
    printf("Seleziona Armi\n 1:Glock\n 2:Ak-47\n 3:Katana\n");
    scanf("%d", &armi);
    switch(armi){
      case 1:
      printf("Danno +15\n");
      break;
      case 2:
      printf("Danno +30\n");
      break;
      case 3:
      printf("Danno +20\n");
      break;
    }
    break;
    case 2:
    printf("\nSeleziona Medicine\n 1:Fialette\n 2:Bende\n 3:Pozione\n");
    scanf("%d", &medicine);
    switch(medicine){
      case 1:
      printf("Salute +50\n");
      break;
      case 2:
      printf("Salute +25\n");
      break;
      case 3:
      printf("Salute +15\n");
    }
    break;
  }
  }
