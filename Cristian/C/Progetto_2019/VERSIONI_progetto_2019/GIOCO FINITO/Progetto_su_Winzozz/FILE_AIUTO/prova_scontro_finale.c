#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

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


int main()
  {
    time_t t ;
    srand ((unsigned) time(&t));
    short int scelta_testa_croce = 0;


    for (int i = 0; i < 20; i++)
      {
        short int rand_testa_croce = rand()%100;
        if (i%2 == 0)
          printf("ARVAIS, VUOI ESSERE TESTA O CROCE?\n  1) TESTA\n  2) CROCE\n");
        else printf("HARTORNEN, VUOI ESSERE TESTA O CROCE?\n  1) TESTA\n  2) CROCE\n");

        while (scanf("%hd",&scelta_testa_croce) != 1 || scelta_testa_croce > 2 || scelta_testa_croce < 1)
          {
            printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
            while (getchar() != '\n');
          }
        //Se minore 50% vince TESTA senno' CROCE
        /* Arvais puo' vincere solo se:
           1) Arvais sceglie TESTA ed esce TESTA
           2) Arvais sceglie CROCE ed esce CROCE
           3) Hartornen sceglie TESTA ma esce CROCE
           4) Hartornen sceglie CROCE ma esce TESTA
        */
        printf("rand_testa_croce: %d\n", rand_testa_croce);

        for (int a = 0; a<10; a++)
          {
            static char nome_file [40] = "Moneta[.].txt";
            nome_file[7] = a%2 + 49;
            printf("%s\n", nome_file);
            printfile(nome_file);
          }

        if ((rand_testa_croce <= 49 && ((i%2 == 0 && scelta_testa_croce == 1) || (i%2 == 1 && scelta_testa_croce == 2))) || (rand_testa_croce > 49 && ((i%2 == 0 && scelta_testa_croce == 2) || (i%2 == 1 && scelta_testa_croce == 1))))
          {
            printf("Vince_Arvais.txt\n\n");
            sleep(3);
          }
        else
          {
            printf("Vince_Hartornen.txt\n\n");
            sleep(3);
          }
      }
  }
