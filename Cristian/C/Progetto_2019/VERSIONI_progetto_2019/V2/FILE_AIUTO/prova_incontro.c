#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void printfile(char str[])
  {
    system("clear");
    char dir[50]="./ASCII/";
    char c;
    strcat(dir, str);
    FILE *fors=fopen(dir, "r");
    while((c=getc(fors))!=EOF){
        printf("%c", c);
    }
    fclose(fors);
    sleep(1);
    //system("clear");
    printf("\n\n\n\n");
  }

void blu (void)
  {
    printf("\033[1;34m");
  }



int main ()
{
short int probabilita_incontro = 0, rand_1 = 0, rand_2 = 0;
time_t t;

srand ((unsigned) time(&t));

while (1)
  {
    probabilita_incontro = probabilita_incontro + 2;
    printf("Probabilita incontro: %hd\n",probabilita_incontro);
    rand_1 = rand()%100;
    printf("Rand: %hd\n",rand_1);
    if (probabilita_incontro >= 99 || rand_1 <= probabilita_incontro)
      {
        printfile("Scontro_diretto.txt");
        blu();
        printf("%s\n",                     "                                   STAVI PER AVANZARE QUANDO HAI VISTO IL NEMICO PASSARTI DAVANTI!");
        sleep(3);
        printf("%s\n\n",                   "    DECIDETE DI AFFRONTARVI UNA VOLTA PER TUTTE E DI GIOCARVI CON UN TESTA E CROCE LA CONCESSIONE DI ESTRAZIONE IN QUELLE GROTTE.");
        sleep(6);
        printf("%s\n\n",                   "                                           ARVAIS SCEGLIE TESTA E HARTORNEN SCEGLIE CROCE!" );
        sleep(3);
        rand_2 = rand()%100;
        printf("Rand: %hd\n",rand_2);
        sleep(3);
        if (rand_2 <= 49)
          {
            system("clear");
            printfile("Vince_Arvais.txt");
            sleep(3);
            break;
          }
        else
          {
            system("clear");
            printfile("Vince_Hartornen.txt");
            sleep(3);
            break;
          }
      }
  }
}
