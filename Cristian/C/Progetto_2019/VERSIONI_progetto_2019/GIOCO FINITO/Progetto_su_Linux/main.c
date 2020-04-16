//CERAMI CRISTIAN
//MATRICOLA: 324075

#include "gamelib.h"
#include <stdio.h>
#include <stdlib.h>

int main ()
  {
    short int scelta_menu = 0, flag_termina_gioco = 0, flag_mappa_cunicoli = 0;
    green();

    for (int i = 0; i<19; i++)
      {
        static char nome_file [40] = "Trivella[.].txt";
        nome_file[9] = i + 65;
        printfile(nome_file);
      }

    do {
         printfile("Menu_iniziale.txt");
         blu();
         printf("COSA VUOI FARE?\n");
         green();

         //Controllo dell'input
         while (scanf("%hd",&scelta_menu) != 1 || scelta_menu >3 || scelta_menu <1)
           {
             blu();
             printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
             while (getchar() != '\n');
             green();
           }

        switch (scelta_menu)
           {
             case 1: //se ho scelto crea_cunicoli()
                flag_mappa_cunicoli = crea_cunicoli();
                break;
             case 2: //se ho scelto gioca()
                if (flag_mappa_cunicoli == 0)
                  {
                    blu();
                    printf("DEVI PRIMA CREARE I CUNICOLI!\n");
                    green();
                    sleep(2);
                    break;
                  }
                flag_mappa_cunicoli = gioca();
                break;
             case 3: //se ho scelto termina_gioco()
                flag_termina_gioco = 1;
                system("clear");
                for (int a=1; a<=4; a++)
                  {
                    if (a%2 == 0)
                      red();
                    else
                      yellow();
                    print_nome();
                    sleep(2);
                    print_matricola();
                    sleep(2);
                    if (a == 4)
                      break;
                    system("clear");
                  }
                break;
           }
       } while(flag_termina_gioco != 1);
    return 0;
  }
