#include "gamelib.h"

void red (void)
  {
    printf("\033[1;31m");
  }

void green (void)
  {
    printf("\033[1;32m");
  }

void blu (void)
  {
    printf("\033[1;34m");
  }

 void yellow (void)
  {
    printf("\033[1;33m");
  }

void magenta (void)
  {
  printf("\033[1;35m");
  }

void cyan (void)
  {
    printf("\033[1;36m");
  }

 void reset (void)
  {
    printf("\033[0m");
  }

 void print_nome(void)
  {
    printf("%s\n%s\n%s\n%s\n%s\n\n\n\n",
          "                     #### #####  ###  #### ##### ###   #   #    #     #### ##### #####    #   #     # ###             ",
          "                    #     #    #  #  #       #    #   # #  ##   #    #     #     #    #  # #  ##   ##  #              ",
          "                    #     #####   #   ###    #    #  #   # # #  #    #     ##### #####  #   # # # # #  #              ",
          "                    #     #  #    #      #   #    #  ##### #  # #    #     #     #  #   ##### #  #  #  #              ",
          "                     #### #   #  ### ####    #   ### #   # #   ##     #### ##### #   #  #   # #     # ###            ");
  }

 void print_matricola(void)
  {
    printf("%s\n%s\n%s\n%s\n%s\n",
          "           #     #   #   ##### #####  ###  ####  ###  #       #             ###   ####     ##   ###  ###### #####           ",
          "           ##   ##  # #    #   #    #  #  #     #   # #      # #     ####      #      #   # #  #   #     #  #               ",
          "           # # # # #   #   #   #####   #  #     #   # #     #   #           ####  ####   #  #  #   #    #   #####           ",
          "           #  #  # #####   #   #  #    #  #     #   # #     #####    ####      # #      ###### #   #   #        #           ",
          "           #     # #   #   #   #   #  ###  ####  ###  ##### #   #           ###   ####      #   ###   #     #####           ");
  }

 void print_gameover(void)
  {
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
          "                             ***************************************************************                            ",
          "                             **  ####   #   #     # #####     ###  #       # ##### #####  **                            ",
          "                             ** #      # #  ##   ## #        #   #  #     #  #     #    # **                            ",
          "                             ** #  ## #   # # # # # #####    #   #   #   #   ##### #####  **                            ",
          "                             ** #   # ##### #  #  # #        #   #    # #    #     #  #   **                            ",
          "                             **  #### #   # #     # #####     ###      #     ##### #   #  **                            ",
          "                             ***************************************************************                            ");
  }

void print_lampeggio_gameover(void)
  {
    for (int a=1; a<=10; a++)
      {
        if (a%2 == 0)
          red();
        else
          yellow();
        print_gameover();
        usleep(500000);
        system("clear");
      }
  }

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

int crea_cunicoli (void)
  {
    /* code */
    short int flag_mappa_cunicoli = 0; //Mettila a 1 quando la mappa viene creata
    printfile("Crea_cunicoli.txt");
    blu();
    printf("SEI ENTRATO IN CREA CUNICOLI!\n");
    green();
    printf("Inserisci 1 per dire che hai creato la mappa: ");
    scanf("%hd",&flag_mappa_cunicoli);
    printf("flag_mappa_cunicoli: %d\n",flag_mappa_cunicoli);
    return (flag_mappa_cunicoli);
  }

int gioca (void)
  {
    /* code */
    short int flag_morte_Arvais = 0; //Mettila a 1 quando muore Arvais
    short int flag_morte_Hartornen = 0; //Mettila a 1 quando muore Hartornen
    short int esci = 0; //Mettila a 1 qualcuno vuole uscire
    for (int i = 1; flag_morte_Arvais == 0 && flag_morte_Hartornen == 0 && esci == 0; i++)
      {
        if (i%2 == 0) //Se pari gioco con Arvais, senno' con l'altro
          {
            printfile("Gioca_Arvais.txt");
            blu();
            printf("STAI GIOCANDO CON ARVAIS!\n");
            green();
            printf("Inserisci 1 per dire che sei morto: ");
            scanf("%hd",&flag_morte_Arvais);
            printf("flag_morte: %d",flag_morte_Arvais);
          }
        else
          {
            printfile("Gioca_Hartornen.txt");
            blu();
            printf("STAI GIOCANDO CON HARTORNEN!\n");
            green();
            printf("Inserisci 1 per dire che sei morto: ");
            scanf("%hd",&flag_morte_Hartornen);
            printf("flag_morte: %d",flag_morte_Hartornen);
          }
        if (flag_morte_Arvais == 0)
          {
            system("clear");
            print_lampeggio_gameover();
            printfile("Vince_Arvais.txt");
            sleep(3);
          }
        else if (flag_morte_Hartornen == 0)
          {
            system("clear");
            print_lampeggio_gameover();
            printfile("Vince_Hartornen.txt");
          }
      }
    return (0);
  }

int termina_gioco (void)
  {
    /* code */
    short int flag_termina_gioco = 0; //Mettila a 1 quando il giocatore vuole chiudere il gioco
    blu();
    printf("SEI ENTRATO IN TERMINA GIOCO!\n");
    green();
    printf("Inserisci 1 per dire che hai chiuso il gioco: ");
    scanf("%hd",&flag_termina_gioco);
    return (flag_termina_gioco);
  }
