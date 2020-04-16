//CERAMI CRISTIAN
//MATRICOLA: 324075

#include "gamelib.h"

/***********************************************  VARIABILI  *********************************************************/

static time_t t;
struct Caverna *primo_cunicolo_Arvais = NULL;
struct Caverna *primo_cunicolo_Hartornen = NULL;
struct Caverna *pPrimo_Arvais_caverna;
struct Caverna *pPrimo_Hartornen_caverna;
struct Caverna *pUltimo_Arvais_caverna;
struct Caverna *pUltimo_Hartornen_caverna;
struct Scavatrice *pScavatrice_Arvais;
struct Scavatrice *pScavatrice_Hartornen;

//VARIABILI IN CREA CUNICOLI
static short int scelta_personaggio = 0;

//VARIABILI IN GIOCA
static short int flag_errore_mossa = 0;

/***********************************************  PROGRAMMA  *********************************************************/

void red (void)
  {
    system ("color C");
  }

void green (void)
  {
    system ("color A");
  }

void blu (void)
  {
    system ("color 9");
  }

 void yellow (void)
  {
    system ("color E");
  }

void magenta (void)
  {
    system ("color D");
  }

void cyan (void)
  {
    system ("color B");
  }

 void reset (void)
  {
    system ("color 0F");
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
        Sleep(500);
        system("cls");
      }
  }

void printfile(char str[])
  {
    system("cls");
    char dir[50]="./ASCII/";
    char c;
    strcat(dir, str);
    FILE *fors=fopen(dir, "r");
    while((c=getc(fors))!=EOF){
        printf("%c", c);
    }
    fclose(fors);
    Sleep(1000);
    //system("cls");
    printf("\n\n\n\n");
  }

/********************************************** INIZIO STAMPA CAVERNA **********************************************************************/

void print_list (struct Caverna *pPrimo_chiamata)
  {
    if (pPrimo_chiamata == NULL) //Se non sono state create grotte
      {
        blu();
        printf("NESSUNA GROTTA TROVATA!");
        green();
      }
    else
      {
        struct Caverna *pScan = pPrimo_chiamata; //Inizializzo il puntatore che mi cerca le grotte
        struct Caverna *pPrimo = pPrimo_chiamata; //Faccio questa operazione affinche' non si modifichi la cella a cui punta pPrimo
        int a = 1;
        do
          {
            //PER NUMERO GROTTA MAGARI SFRUTTA COUNT E IL VALORE TROVATO FAI -- COSI' FINCHE NON ARRIVI ALLA GROTTA DI PARTENZA = 1
            blu(); printf("NUMERO GROTTA: "); green();
            printf("[%d]\n", a);
            blu(); printf("QUANTITA' MELASSA:        "); green();
            if (pPrimo -> melassa == nessuna)
              printf("NESSUNA\n");
            else if (pPrimo -> melassa == poca)
              printf("POCA\n");
            else if (pPrimo -> melassa == molta)
              printf("MOLTA\n");
            blu(); printf("TIPO IMPREVISTO:          "); green();
            if (pPrimo -> imprevisto == nessun_imprevisto)
              printf("NESSUNO\n");
            else if (pPrimo -> imprevisto == crollo)
              printf("CROLLO\n");
            else if (pPrimo -> imprevisto == baco)
              printf("BACO\n");
            blu(); printf("TIPOLOGIA CAVERNA :       "); green();
            if (pPrimo -> caverna == normale)
              printf("NORMALE\n");
            else if (pPrimo -> caverna == speciale)
              printf("SPECIALE\n");
            else if (pPrimo -> caverna == accidentata)
              printf("ACCIDENTATA\n");

            blu(); printf("PASSAGGIO DISPONIBILE A : "); green();
            if (pPrimo -> sinistra != NULL)
              {
                printf("SINISTRA\n");
                pScan = pPrimo -> sinistra;
              }
            else if (pPrimo -> destra != NULL)
              {
                pScan = pPrimo -> destra;
                printf("DESTRA\n\n");
              }
            else if (pPrimo -> avanti != NULL)
              {
                pScan = pPrimo -> avanti;
                printf("AVANTI\n");
              }
            else
              {
                pScan = NULL;
                printf("NESSUNA PARTE...LA CAVERNA E' SENZA USCITA!\n");
              }

            pPrimo = pScan;
            a++;
            printf("\n          |\n"
                   "          |\n"
                   "          v\n\n");
          } while(pScan != NULL); //Se trova NULL è arrivato all'ultima grotta
      }
    return;
  }

  /********************************************** FINE STAMPA CAVERNA **********************************************************************/

  /********************************************** INIZIO CONTA CAVERNA **********************************************************************/


int count (struct Caverna *pPrimo)
  {
    if (pPrimo == NULL)
      return 0;
    struct Caverna *pScan_1 = pPrimo;
    short int cnt = 0;
    while (pScan_1 != NULL)
      {
        cnt++;
        if (pScan_1 -> sinistra != NULL)
          pScan_1 = pScan_1 -> sinistra;
        else if (pScan_1 -> destra != NULL)
          pScan_1 = pScan_1 -> destra;
        else if (pScan_1 -> avanti != NULL)
          pScan_1 = pScan_1 -> avanti;
        else pScan_1 = NULL;
      }
      return cnt;
  }

/********************************************** FINE CONTA CAVERNA **********************************************************************/

/********************************************** INIZIO INSERISCI CAVERNA **********************************************************************/
int inserisci_caverna(void)
  {
    short int numero_caverne = 0;
    short int scelta_quantita_melassa = 0;
    short int scelta_tipo_imprevisto = 0;
    short int scelta_tipo_caverna = 0;
    short int scelta_aggiunta_cunicoli_Arvais = 0;
    short int scelta_aggiunta_cunicoli_Hartornen = 0;

    srand ((unsigned) time (&t));

    do
      {
        printfile("Inserisci_cunicoli.txt");

        blu();
        printf("COSA VUOI FARE?\n");
        green();

        //Controllo dell'input
        while (scanf("%hd",&scelta_personaggio) != 1 || scelta_personaggio >3 || scelta_personaggio <1)
          {
            blu();
            printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
            while (getchar() != '\n');
            green();
          }

        if (scelta_personaggio == 3)
          return 0;

        if (scelta_personaggio == 1 && pScavatrice_Arvais -> flag_mappa_cunicoli == 1) //Se ho gia costruito le caverne minime per Arvais
          {
            printfile ("Aggiungere_cunicoli_Arvais.txt");
            blu();
            printf ("SONO GIA STATE COSTRUITE LE CAVERNE MINIME PER ARVAIS. NE VUOI AGGIUNGERE DELLE ALTRE?\n");
            green();
            while (scanf("%hd",&scelta_aggiunta_cunicoli_Arvais) != 1 || scelta_aggiunta_cunicoli_Arvais >2 || scelta_aggiunta_cunicoli_Arvais <1)
              {
                blu();
                printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
                while (getchar() != '\n');
                green();
              }
            if (scelta_aggiunta_cunicoli_Arvais == 2)
              break;
          }
        if (scelta_personaggio == 2 && pScavatrice_Hartornen -> flag_mappa_cunicoli == 1) //Se ho gia costruito le caverne minime per Hartornen
          {
            printfile ("Aggiungere_cunicoli_Hartornen.txt");
            blu();
            printf ("SONO GIA STATE COSTRUITE LE CAVERNE MINIME PER HARTORNEN. NE VUOI AGGIUNGERE DELLE ALTRE?\n");
            green();
            while (scanf("%hd",&scelta_aggiunta_cunicoli_Hartornen) != 1 || scelta_aggiunta_cunicoli_Hartornen >2 || scelta_aggiunta_cunicoli_Hartornen <1)
              {
                blu();
                printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
                while (getchar() != '\n');
                green();
              }
            if (scelta_aggiunta_cunicoli_Hartornen == 2)
              break;
          }

        if (scelta_personaggio == 1) //Ho scelto Arvais
          {
            pScavatrice_Arvais -> numero_caverne = count (pPrimo_Arvais_caverna);

            if (pScavatrice_Arvais -> numero_caverne == 0)
              {
                printfile("Inserisci_cunicoli_Arvais.txt");
                blu();
                printf("DEVI INSERIRE ALMENO 10 CAVERNE (E MASSIMO 20)!\n");
                printf("QUANTE CAVERNE VUOI INSERIRE?\n\nNUMERO CAVERNE DA INSERIRE: ");
                green();
                while (scanf("%hd",&numero_caverne) != 1 || numero_caverne < 10 || numero_caverne > 20)
                  {
                    blu();
                    printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
                    while (getchar() != '\n');
                    green();
                  }
              }
            else
              {
                printfile("Inserisci_cunicoli_Arvais.txt");
                blu();
                printf("QUANTE CAVERNE VUOI INSERIRE?\n\nNUMERO CAVERNE DA INSERIRE: ");
                green();
                while (scanf("%hd",&numero_caverne) != 1 || numero_caverne < 1 || numero_caverne > 20)
                  {
                    blu();
                    printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
                    while (getchar() != '\n');
                    green();
                  }
              }

            for (int i = 0; i < numero_caverne; i++) //Creo il numero di caverne richiesto
              {
                scelta_quantita_melassa = 0, scelta_tipo_imprevisto = 0, scelta_tipo_caverna = 0;
                pScavatrice_Arvais -> last_direzione = pScavatrice_Arvais -> direzione;

                struct Caverna *primo_cunicolo_Arvais = (struct Caverna*) malloc(sizeof(struct Caverna)); //Fornisco l'indirizzo di partenza

                primo_cunicolo_Arvais -> sinistra      = NULL;
                primo_cunicolo_Arvais -> avanti        = NULL;
                primo_cunicolo_Arvais -> destra        = NULL;

                printfile("Inserisci_cunicoli_Arvais.txt");
                blu();
                printf("IN QUALE DIREZIONE VUOI ANDARE?\n");
                green();

                while (scanf("%hd",&(pScavatrice_Arvais -> direzione)) != 1 || pScavatrice_Arvais -> direzione < 1 || pScavatrice_Arvais -> direzione > 3)
                  {
                    blu();
                    printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
                    while (getchar() != '\n');
                    green();
                  }

                if (i == 0 && pScavatrice_Arvais -> numero_caverne == 0) //La prima grotta deve essere "normale" in tutto
                  {
                    primo_cunicolo_Arvais -> melassa     = nessuna;
                    primo_cunicolo_Arvais -> imprevisto  = nessun_imprevisto;
                    primo_cunicolo_Arvais -> caverna     = normale;
                  }
                else
                  {
                    //FORNISCE LA QUANTITA' DI MELASSA CHE POSSO TROVARE NELLA CAVERNA
                    scelta_quantita_melassa = (rand() %100);
                    if (scelta_quantita_melassa <= 49)
                        primo_cunicolo_Arvais -> melassa = nessuna;
                    else if (scelta_quantita_melassa > 49 && scelta_quantita_melassa <= 79)
                        primo_cunicolo_Arvais -> melassa = poca;
                    else if (scelta_quantita_melassa > 79 && scelta_quantita_melassa <= 99)
                        primo_cunicolo_Arvais -> melassa = molta;

                    //FORNISCE CHE IMPREVISTO TROVARE NELLA CAVERNA
                    scelta_tipo_imprevisto = (rand() % 100);
                    if (scelta_tipo_imprevisto <= 49)
                        primo_cunicolo_Arvais -> imprevisto = nessun_imprevisto;
                    else if (scelta_tipo_imprevisto > 49 && scelta_tipo_imprevisto <= 84)
                        primo_cunicolo_Arvais -> imprevisto = crollo;
                    else if (scelta_tipo_imprevisto > 84 && scelta_tipo_imprevisto <= 99)
                        primo_cunicolo_Arvais -> imprevisto = baco;

                    //CHIEDO QUALE VOGLIO CHE SIA LA TIPOLOGIA DI CAVERNA
                    printfile("Tipo_caverna.txt");
                    blu();
                    printf("QUALE E' LA TIPOLOGIA DELLA CAVERNA?\n");
                    green();

                    while (scanf("%hd",&scelta_tipo_caverna) != 1 || scelta_tipo_caverna < 1 || scelta_tipo_caverna > 3)
                      {
                        blu();
                        printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
                        while (getchar() != '\n');
                        green();
                      }

                    if (scelta_tipo_caverna == 1)
                        primo_cunicolo_Arvais -> caverna = normale;
                    else if (scelta_tipo_caverna == 2)
                        primo_cunicolo_Arvais -> caverna = speciale;
                    else if (scelta_tipo_caverna == 3)
                        primo_cunicolo_Arvais -> caverna = accidentata;

                  } //FINE RICHESTA INFORMAZIONI SULLA CAVERNA

                //AGGIORNAMENTO PUNTATORI PER CREARE NUOVE LISTE
                if (pPrimo_Arvais_caverna == NULL) //Se non ci stavano nodi precedenti
                  {
                    pPrimo_Arvais_caverna = primo_cunicolo_Arvais;  //Ho appena creato il primo nodo
                    pUltimo_Arvais_caverna = primo_cunicolo_Arvais; //Ho appena creato il primo nodo
                  }
                else //Se gia era presente un nodo
                  {
                    if (pScavatrice_Arvais -> last_direzione == 1) //Se ho scelto sinistra
                      pUltimo_Arvais_caverna -> sinistra = primo_cunicolo_Arvais; //L'ultimo nodo creato viene messo in coda
                    else if (pScavatrice_Arvais -> last_direzione == 2) //Se ho scelto avanti
                      pUltimo_Arvais_caverna -> avanti = primo_cunicolo_Arvais; //L'ultimo nodo creato viene messo in coda
                    else if (pScavatrice_Arvais -> last_direzione == 3) //Se ho scelto destra
                      pUltimo_Arvais_caverna -> destra = primo_cunicolo_Arvais; //L'ultimo nodo creato viene messo in coda

                    pUltimo_Arvais_caverna = primo_cunicolo_Arvais; //Aggiorno l'indirizzo di pUltimo_Arvais_caverna cosi' che punti all'ultimo elemnto della lista
                  }
              } //FINE for
            pScavatrice_Arvais -> last_direzione = pScavatrice_Arvais -> direzione;
            pScavatrice_Arvais -> numero_caverne = count (pPrimo_Arvais_caverna);

            if (pScavatrice_Arvais -> numero_caverne >= 10)
              pScavatrice_Arvais -> flag_mappa_cunicoli = 1;
          }

        else //Ho scelto Hartornen
          {
            pScavatrice_Hartornen -> numero_caverne = count (pPrimo_Hartornen_caverna);

            if (pScavatrice_Hartornen -> numero_caverne == 0)
              {
                printfile("Inserisci_cunicoli_Hartornen.txt");
                blu();
                printf("DEVI INSERIRE ALMENO 10 CAVERNE (E MASSIMO 20)!\n");
                printf("QUANTE CAVERNE VUOI INSERIRE?\n\nNUMERO CAVERNE DA INSERIRE: ");
                green();
                while (scanf("%hd",&numero_caverne) != 1 || numero_caverne < 10 || numero_caverne > 20)
                  {
                    blu();
                    printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
                    while (getchar() != '\n');
                    green();
                  }
              }
            else
              {
                printfile("Inserisci_cunicoli_Hartornen.txt");
                blu();
                printf("QUANTE CAVERNE VUOI INSERIRE?\n\nNUMERO CAVERNE DA INSERIRE: ");
                green();
                while (scanf("%hd",&numero_caverne) != 1 || numero_caverne < 1 || numero_caverne > 20)
                  {
                    blu();
                    printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
                    while (getchar() != '\n');
                    green();
                  }
              }

            for (int i = 0; i < numero_caverne; i++) //Creo il numero di caverne richiesto
              {
                scelta_quantita_melassa = 0, scelta_tipo_imprevisto = 0, scelta_tipo_caverna = 0;
                pScavatrice_Hartornen -> last_direzione = pScavatrice_Hartornen -> direzione;
                struct Caverna *primo_cunicolo_Hartornen = (struct Caverna*) malloc(sizeof(struct Caverna)); //Fornisco l'indirizzo di partenza

                primo_cunicolo_Hartornen -> sinistra      = NULL;
                primo_cunicolo_Hartornen -> avanti        = NULL;
                primo_cunicolo_Hartornen -> destra        = NULL;

                printfile("Inserisci_cunicoli_Hartornen.txt");
                blu();
                printf("IN QUALE DIREZIONE VUOI ANDARE?\n");
                green();

                while (scanf("%hd",&(pScavatrice_Hartornen -> direzione)) != 1 || pScavatrice_Hartornen -> direzione < 1 || pScavatrice_Hartornen -> direzione > 3)
                  {
                    blu();
                    printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
                    while (getchar() != '\n');
                    green();
                  }

                if (i == 0 && pScavatrice_Hartornen -> numero_caverne == 0) //La prima grotta deve essere "normale" in tutto
                  {
                    primo_cunicolo_Hartornen -> melassa     = nessuna;
                    primo_cunicolo_Hartornen -> imprevisto  = nessun_imprevisto;
                    primo_cunicolo_Hartornen -> caverna     = normale;
                  }
                else
                  {
                    //FORNISCE LA QUANTITA' DI MELASSA CHE POSSO TROVARE NELLA CAVERNA
                    scelta_quantita_melassa = (rand() %100);
                    if (scelta_quantita_melassa <= 49)
                        primo_cunicolo_Hartornen -> melassa = nessuna;
                    else if (scelta_quantita_melassa > 49 && scelta_quantita_melassa <= 79)
                        primo_cunicolo_Hartornen -> melassa = poca;
                    else if (scelta_quantita_melassa > 79 && scelta_quantita_melassa <= 99)
                        primo_cunicolo_Hartornen -> melassa = molta;

                    //FORNISCE CHE IMPREVISTO TROVARE NELLA CAVERNA
                    scelta_tipo_imprevisto = (rand() % 100);
                    if (scelta_tipo_imprevisto <= 49)
                        primo_cunicolo_Hartornen -> imprevisto = nessun_imprevisto;
                    else if (scelta_tipo_imprevisto > 49 && scelta_tipo_imprevisto <= 84)
                        primo_cunicolo_Hartornen -> imprevisto = crollo;
                    else if (scelta_tipo_imprevisto > 84 && scelta_tipo_imprevisto <= 99)
                        primo_cunicolo_Hartornen -> imprevisto = baco;

                    //CHIEDO QUALE VOGLIO CHE SIA LA TIPOLOGIA DI CAVERNA
                    printfile("Tipo_caverna.txt");
                    blu();
                    printf("QUALE E' LA TIPOLOGIA DELLA CAVERNA?\n");
                    green();

                    while (scanf("%hd",&scelta_tipo_caverna) != 1 || scelta_tipo_caverna < 1 || scelta_tipo_caverna > 3)
                      {
                        blu();
                        printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
                        while (getchar() != '\n');
                        green();
                      }

                    if (scelta_tipo_caverna == 1)
                        primo_cunicolo_Hartornen -> caverna = normale;
                    else if (scelta_tipo_caverna == 2)
                        primo_cunicolo_Hartornen -> caverna = speciale;
                    else if (scelta_tipo_caverna == 3)
                        primo_cunicolo_Hartornen -> caverna = accidentata;

                  } //FINE RICHESTA INFORMAZIONI SULLA CAVERNA

                //AGGIORNAMENTO PUNTATORI PER CREARE NUOVE LISTE
                if (pPrimo_Hartornen_caverna == NULL) //Se non ci stavano nodi precedenti
                  {
                    pPrimo_Hartornen_caverna = primo_cunicolo_Hartornen; //Ho appena creato il primo nodo
                    pUltimo_Hartornen_caverna = primo_cunicolo_Hartornen; //Ho appena creato il primo nodo
                  }
                else //Se gia era presente un nodo
                  {
                    if (pScavatrice_Hartornen -> last_direzione == 1) //Se ho scelto sinistra
                      pUltimo_Hartornen_caverna -> sinistra = primo_cunicolo_Hartornen; //Il primo nodo diventa il secondo
                    else if (pScavatrice_Hartornen -> last_direzione == 2) //Se ho scelto avanti
                      pUltimo_Hartornen_caverna -> avanti = primo_cunicolo_Hartornen; //Il primo nodo diventa il secondo
                    else if (pScavatrice_Hartornen -> last_direzione == 3) //Se ho scelto destra
                      pUltimo_Hartornen_caverna -> destra = primo_cunicolo_Hartornen; //Il primo nodo diventa il secondo

                    pUltimo_Hartornen_caverna = primo_cunicolo_Hartornen; //Aggiorno l'indirizzo di pPrimo_Hartornen_caverna cosi' che punti nuovamente al primo elemnto della lista
                  }
              } //FINE for
            pScavatrice_Hartornen -> last_direzione = pScavatrice_Hartornen -> direzione;
            pScavatrice_Hartornen -> numero_caverne = count (pPrimo_Hartornen_caverna);

            if (pScavatrice_Hartornen -> numero_caverne >= 10)
              pScavatrice_Hartornen -> flag_mappa_cunicoli = 1;
          }
      } while(pScavatrice_Arvais -> flag_mappa_cunicoli == 0 || pScavatrice_Hartornen -> flag_mappa_cunicoli == 0);
    return 0;
  }

  /************************************************ FINE INSERISCI CAVERNA **********************************************************************/

  /************************************************ INIZIO CANCELLA CAVERNA **********************************************************************/


int  cancella_caverna(void)
  {
    short int scelta_personaggio = 0;
    short int numero_caverne_da_eliminare = 0;

    pScavatrice_Arvais -> numero_caverne = count (pPrimo_Arvais_caverna);
    pScavatrice_Hartornen -> numero_caverne = count (pPrimo_Hartornen_caverna);

    printfile ("Cancella_cunicoli.txt");
    if (pScavatrice_Arvais -> numero_caverne < 2 && pScavatrice_Hartornen -> numero_caverne < 2)
      {
        blu();
        printf ("SIA ARVAIS CHE HARTORNEN NON HANNO CAVERNE ELIMINABILI!\n");
        Sleep(3000);
        green();
        return 0;
      }
    blu();
    printf ("DI CHI VUOI CANCELLARE LE CAVERNE?\n");
    green();

    while (scanf("%hd",&scelta_personaggio) != 1 || scelta_personaggio > 3 || scelta_personaggio < 1)
      {
        blu();
        printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
        while (getchar() != '\n');
        green();
      }

    if (scelta_personaggio == 3)
      return 0;

    if (scelta_personaggio == 1 && pScavatrice_Arvais -> numero_caverne >= 2) //Ho scelto Arvais
      {
        printfile("Cancella_cunicoli_Arvais.txt");
        blu(); printf ("PUOI ELIMINARE AL MASSIMO "); green();
        printf ("%d ",pScavatrice_Arvais -> numero_caverne - 1);
        blu();
        printf ("CAVERNE PER ARVAIS\n\n");
        printf ("QUANTE CAVERNE VUOI ELIMINARE?\n");
        green();

        while (scanf("%hd",&numero_caverne_da_eliminare) != 1 || numero_caverne_da_eliminare < 1 || numero_caverne_da_eliminare >= pScavatrice_Arvais -> numero_caverne)
          {
            blu();
            printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
            while (getchar() != '\n');
            green();
          }

        for (int i = 0; i < numero_caverne_da_eliminare; i++)
          {
            if(pPrimo_Arvais_caverna == NULL) //Non sono presenti nodi
              {
                blu();
                printf("NON SONO PRESENTI CAVERNE DA ELIMINARE!\n");
                green();
              }
            else
              {
                struct Caverna *pPrecedente_Arvais_caverna = NULL;
                struct Caverna *pScan_4 = pPrimo_Arvais_caverna;

                if ((pScan_4 -> sinistra == NULL) && (pScan_4 -> avanti == NULL) && (pScan_4 -> destra == NULL)) // Se abbiamo un solo nodo nella lista
                  return 0;
                else //Se ho piu' di nodo devo arrivare fino all'ultimo nodo
                  {
                    do
                      {
                        if (pScan_4 -> sinistra != NULL)
                          {
                            if ((pScan_4 -> sinistra) == pUltimo_Arvais_caverna) //Se ho raggiunto il penultimo nodo
                              {
                                pPrecedente_Arvais_caverna = pScan_4;
                                break;
                              }
                            else pScan_4 = pScan_4 -> sinistra; //Senno' ripeto la procedura finche non ci arrivo
                          }
                        else if (pScan_4 -> avanti != NULL)
                          {
                            if ((pScan_4 -> avanti) == pUltimo_Arvais_caverna) //Se ho raggiunto il penultimo nodo
                              {
                                pPrecedente_Arvais_caverna = pScan_4;
                                break;
                              }
                            else pScan_4 = pScan_4 -> avanti; //Senno' ripeto la procedura finche non ci arrivo
                          }
                        else if (pScan_4 -> destra != NULL)
                          {
                            if ((pScan_4 -> destra) == pUltimo_Arvais_caverna) //Se ho raggiunto il penultimo nodo
                              {
                                pPrecedente_Arvais_caverna = pScan_4;
                                break;
                              }
                            else pScan_4 = pScan_4 -> destra; //Senno' ripeto la procedura finche non ci arrivo
                          }
                  } while((pScan_4 -> sinistra != NULL) || (pScan_4 -> destra != NULL) || (pScan_4 -> avanti != NULL));

                      if (pScan_4 -> sinistra != NULL)
                        {
                          free (pPrecedente_Arvais_caverna -> sinistra); //Dealloco la memoria dell'ultimo blocco
                          pPrecedente_Arvais_caverna -> sinistra = NULL;
                        }
                      else if (pScan_4 -> avanti != NULL)
                        {
                          free (pPrecedente_Arvais_caverna -> avanti); //Dealloco la memoria dell'ultimo blocco
                          pPrecedente_Arvais_caverna -> avanti = NULL;
                        }
                      else if (pScan_4 -> destra != NULL)
                        {
                          free (pPrecedente_Arvais_caverna -> destra); //Dealloco la memoria dell'ultimo blocco
                          pPrecedente_Arvais_caverna -> destra = NULL;
                        }

                      pUltimo_Arvais_caverna = pPrecedente_Arvais_caverna; //Il penultimo nodo diventa l'ultimo
                  }
              }
          }
      }
    else if (scelta_personaggio == 1 && pScavatrice_Arvais -> numero_caverne < 2) //Ho scelto Arvais ma non ho caverne eliminabili
      {
        printfile("Cancella_cunicoli_Arvais.txt");
        blu(); printf ("NON SONO PRESENTI CAVERNE DA ELIMINARE PER ARVAIS!"); green();
        Sleep(3000);
      }
    else if (scelta_personaggio == 2 && pScavatrice_Hartornen -> numero_caverne >= 2) //Ho scelto Hartornen
      {
        printfile("Cancella_cunicoli_Hartornen.txt");
        blu(); printf ("PUOI ELIMINARE AL MASSIMO "); green();
        printf ("%d ",pScavatrice_Hartornen -> numero_caverne - 1);
        blu();
        printf ("CAVERNE PER HARTORNEN\n\n");
        printf ("QUANTE CAVERNE VUOI ELIMINARE?\n");
        green();

        while (scanf("%hd",&numero_caverne_da_eliminare) != 1 || numero_caverne_da_eliminare < 1 || numero_caverne_da_eliminare >= pScavatrice_Hartornen -> numero_caverne)
          {
            blu();
            printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
            while (getchar() != '\n');
            green();
          }

        for (int i = 0; i < numero_caverne_da_eliminare; i++)
          {
            if(pPrimo_Hartornen_caverna == NULL) //Non sono presenti nodi
              {
                blu();
                printf("NON SONO PRESENTI CAVERNE DA ELIMINARE!\n");
                green();
              }
            else
              {
                struct Caverna *pPrecedente_Hartornen_caverna = NULL;
                struct Caverna *pScan_4 = pPrimo_Hartornen_caverna;

                if ((pScan_4 -> sinistra != NULL) && (pScan_4 -> destra != NULL) && (pScan_4 -> avanti != NULL)) // Se abbiamo un solo nodo nella lista
                  return 0;
                else //Se ho piu' di nodo devo arrivare fino all'ultimo nodo
                  {
                    do
                      {
                        if (pScan_4 -> sinistra != NULL)
                          {
                            if ((pScan_4 -> sinistra) == pUltimo_Hartornen_caverna) //Se ho raggiunto il penultimo nodo
                              {
                                pPrecedente_Hartornen_caverna = pScan_4;
                                break;
                              }
                            else pScan_4 = pScan_4 -> sinistra; //Senno' ripeto la procedura finche non ci arrivo
                          }
                        else if (pScan_4 -> avanti != NULL)
                          {
                            if ((pScan_4 -> avanti) == pUltimo_Hartornen_caverna) //Se ho raggiunto il penultimo nodo
                              {
                                pPrecedente_Hartornen_caverna = pScan_4;
                                break;
                              }
                            else pScan_4 = pScan_4 -> avanti; //Senno' ripeto la procedura finche non ci arrivo
                          }
                        else if (pScan_4 -> destra != NULL)
                          {
                            if ((pScan_4 -> destra) == pUltimo_Hartornen_caverna) //Se ho raggiunto il penultimo nodo
                              {
                                pPrecedente_Hartornen_caverna = pScan_4;
                                break;
                              }
                            else pScan_4 = pScan_4 -> destra; //Senno' ripeto la procedura finche non ci arrivo
                          }
                      } while(pScan_4 -> sinistra != NULL || pScan_4 -> destra != NULL || pScan_4 -> avanti != NULL);

                      if (pScan_4 -> sinistra != NULL)
                        {
                          free (pPrecedente_Hartornen_caverna -> sinistra); //Dealloco la memoria dell'ultimo nodo
                          pPrecedente_Hartornen_caverna -> sinistra = NULL;
                        }
                      else if (pScan_4 -> avanti != NULL)
                        {
                          free (pPrecedente_Hartornen_caverna -> avanti); //Dealloco la memoria dell'ultimo nodo
                          pPrecedente_Hartornen_caverna -> avanti = NULL;
                        }
                      else if (pScan_4 -> destra != NULL)
                        {
                          free (pPrecedente_Hartornen_caverna -> destra); //Dealloco la memoria dell'ultimo nodo
                          pPrecedente_Hartornen_caverna -> destra = NULL;
                        }

                    pUltimo_Hartornen_caverna = pPrecedente_Hartornen_caverna; //Il penultimo nodo diventa l'ultimo
                  }
              }
          }
      }
    else if (scelta_personaggio == 2 && pScavatrice_Hartornen -> numero_caverne < 2) //Ho scelto Hartornen ma non ho caverne eliminabili
      {
        printfile("Cancella_cunicoli_Hartornen.txt");
        blu();
        printf ("NON SONO PRESENTI CAVERNE DA ELIMINARE PER HARTORNEN!\n");
        Sleep(3000);
        green();
      }

    pScavatrice_Arvais -> numero_caverne = count (pPrimo_Arvais_caverna);
    pScavatrice_Hartornen -> numero_caverne = count (pPrimo_Hartornen_caverna);

    if (pScavatrice_Arvais -> numero_caverne < 10)
      pScavatrice_Arvais -> flag_mappa_cunicoli = 0;
    if (pScavatrice_Hartornen -> numero_caverne < 10)
      pScavatrice_Hartornen -> flag_mappa_cunicoli = 0;

    return 0;
  }

  /************************************************ FINE CANCELLA CAVERNA **********************************************************************/

  /************************************************ INIZIO STAMPA CAVERNA **********************************************************************/

void stampa_cunicolo(void)
  {
    short int scelta_personaggio = 0;
    printfile ("Stampa_cunicoli.txt");
    blu();
    printf ("DI CHI VUOI STAMPARE LA MAPPA CUNICOLI?\n");
    green();

    while (scanf("%hd",&scelta_personaggio) != 1 || scelta_personaggio > 3 || scelta_personaggio < 1)
      {
        blu();
        printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
        while (getchar() != '\n');
        green();
      }

    if (scelta_personaggio == 3)
      return;

    if (scelta_personaggio == 1)
      {
        printfile("Stampa_cunicoli_Arvais.txt");
        print_list (pPrimo_Arvais_caverna);
        blu();
        printf ("LA MAPPA SI CHIUDERA' FRA 20 SECONDI\n");
        Sleep(20000);
        green();
      }
    else
      {
        printfile("Stampa_cunicoli_Hartornen.txt");
        print_list (pPrimo_Hartornen_caverna);
        blu();
        printf ("LA MAPPA SI CHIUDERA' FRA 20 SECONDI\n");
        Sleep(20000);
        green();
      }
    return;
  }

/************************************************ FINE STAMPA CAVERNA **********************************************************************/

/******************************************** INIZIO CONTROLLO SERBATOI ***************************************************************************/

void controllo_serbatoio_energia_raccolta (struct Scavatrice *pPersonaggio, int i)
  {
    if (pPersonaggio -> serbatoio_raccolta > 10 && pPersonaggio -> serbatoio_energia == 4)
      pPersonaggio -> serbatoio_raccolta = 10;
    else if (pPersonaggio -> serbatoio_raccolta > 10 && pPersonaggio -> serbatoio_energia < 4)
      {
        pPersonaggio -> serbatoio_energia = pPersonaggio -> serbatoio_energia + ((pPersonaggio -> serbatoio_raccolta) - 10);
        blu(); printf("E' STATA EFFETTUATA LA RICARICA AUTOMATICA AL SERBATOIO DI ENERGIA\nPERCHE' HAI RIEMPITO IL SERBATOIO DI RACCOLTA MELASSA!\n");
        Sleep(3000);
      }

    if (pPersonaggio -> serbatoio_energia > 4)
      pPersonaggio -> serbatoio_energia = 4;

    if (pPersonaggio -> serbatoio_energia < 0)
      {
        if (i%2 == 0)
          pScavatrice_Arvais -> flag_morte = 1;
        else pScavatrice_Hartornen -> flag_morte = 1;
      }
    return;
  }

/******************************************** FINE CONTROLLO SERBATOI ***************************************************************************/

/************************************************ INIZIO AVANZA **********************************************************************/

int avanza (struct Caverna *pAvanza, struct Scavatrice *pPersonaggio, int i)
  {
    short int scelta_serbatoio = 0;
    short int rand_probabilita_crollo = 0;

    srand ((unsigned) time(&t));

    if(pAvanza == NULL || (pAvanza -> sinistra == NULL && pAvanza -> avanti == NULL && pAvanza -> destra == NULL)) //Non sono presenti nodi
      {
        blu();
        printf("NON SONO PRESENTI CAVERNE SU CUI AVANZARE!\nABBATTI UNA PARETE!\n");
        green();
        Sleep(3000);
        flag_errore_mossa = 1;
      }
    else
      {
        if (pPersonaggio -> flag_crollo == 0 && pPersonaggio -> flag_abbatti == 0 && (pAvanza -> sinistra != NULL || pAvanza -> avanti != NULL || pAvanza -> destra != NULL))
          {
            //PROBABILITA' CROLLO IMPROVVISO
            rand_probabilita_crollo = rand()%100;

            if (rand_probabilita_crollo < 24 && i != 1 && i != 2) //i!= 1 o 2 perchè non deve accadere durante il primo turno
              {
                blu(); printf("SI E' VERIFICATO UN CROLLO IMPROVVISO\nPROVA A RAGGIRARE L'OSTACOLO!\n\n"); green();
                pPersonaggio -> flag_crollo = 1;
                flag_errore_mossa = 1;
                Sleep(3000);
                return 0;
              }
          }

        //SE E' PRESENTE ALMENO UNA CAVERNA DAVANTI
        struct Caverna *temp;

        if (pAvanza -> sinistra != NULL)
          temp = pAvanza -> sinistra;
        else if (pAvanza -> avanti != NULL)
          temp = pAvanza -> avanti;
        else if (pAvanza -> destra != NULL)
          temp = pAvanza -> destra;
        else
          temp = NULL;
        free (pAvanza); //Elimino l'ultima caverna creata
        pAvanza = temp; //Aggiorno il puntatore di testa alla caverna successiva

        blu(); printf("SEI ENTRATO IN UNA CAVERNA "); green();
        if (pPersonaggio -> flag_possibile_uscita == 0 && i%2 == 0)
          {
            if (pAvanza -> caverna == normale)
              {
                printf("NORMALE");
                blu();
                printf("!\n");
                green();
                Sleep(3000);
              }
            else if (pAvanza -> caverna == speciale)
              {
                printf("SPECIALE "); blu();
                printf("QUINDI GUADAGNI 1 UNITA' DI ENERGIA!\n"); green();

                pPersonaggio -> serbatoio_energia = pPersonaggio -> serbatoio_energia + 1;
                Sleep(3000);
              }
            else if (pAvanza -> caverna == accidentata)
              {
                printf("ACCIDENTATA "); blu();
                printf("QUINDI PERDI 1 UNITA' DI ENERGIA!\n"); green();

                pPersonaggio -> serbatoio_energia = pPersonaggio -> serbatoio_energia - 1;
                Sleep(3000);
              }

            controllo_serbatoio_energia_raccolta (pPersonaggio, i);
            if (pScavatrice_Hartornen -> flag_morte == 1 || pScavatrice_Arvais -> flag_morte == 1)
              {
                blu();
                printf("HAI ESAURITO L'ENERGIA E, NON AVENDO PIU' LUCE, TI PERDI FRA I CUNICOLI E MUORI...\n");
                green();
                Sleep(4000);
                return 0;
              }
          }
        else if (pPersonaggio -> flag_possibile_uscita == 1 && i%2 == 0)
          {
            blu(); printf("DI TIPO "); green(); printf("USCITA"); blu(); printf("!\n"); green();
          }
        else if (pPersonaggio -> flag_possibile_uscita == 0 && i%2 == 1)
          {
            if (pAvanza -> caverna == normale)
              {
                printf("NORMALE");
                blu();
                printf("!\n");
                green();
                Sleep(2000);
              }
            else if (pAvanza -> caverna == speciale)
              {
                printf("SPECIALE "); blu();
                printf("QUINDI GUADAGNI 1 UNITA' DI ENERGIA!\n"); green();

                pPersonaggio -> serbatoio_energia = pPersonaggio -> serbatoio_energia + 1;
                Sleep(3000);
              }
            else if (pAvanza -> caverna == accidentata)
              {
                printf("ACCIDENTATA "); blu();
                printf("QUINDI PERDI 1 UNITA' DI ENERGIA!\n"); green();

                pPersonaggio -> serbatoio_energia = pPersonaggio -> serbatoio_energia - 1;
                Sleep(3000);
              }

            controllo_serbatoio_energia_raccolta (pPersonaggio, i);
            if (pScavatrice_Hartornen -> flag_morte == 1 || pScavatrice_Arvais -> flag_morte == 1)
              {
                blu();
                printf("HAI ESAURITO L'ENERGIA E, NON AVENDO PIU' LUCE, TI PERDI FRA I CUNICOLI E MUORI...\n");
                green();
                Sleep(4000);
                return 0;
              }
          }
        else if (pPersonaggio -> flag_possibile_uscita == 1 && i%2 == 1)
          {
            blu(); printf("DI TIPO "); green(); printf("USCITA"); blu(); printf("!\n"); green();
          }

          //QUANTITA' MELASSA CAVERNA
          if (pAvanza -> melassa == nessuna)
            {
              blu(); printf("\n\nSTAI ESPLORANDO LA CAVERNA MA SEMBRA NON ESSERCI MELASSA\n");
              green();
              Sleep(3000);
            }
          else if (pAvanza -> melassa == poca || pAvanza -> melassa == molta)
            {
              blu(); printf("\n\nSTAI ESPLORANDO LA CAVERNA QUANDO TROVI "); green(); printf("%d ",pAvanza -> melassa); blu(); printf("UNITA' DI MELASSA!\n");
              green();
              Sleep(3000);

              blu();
              printf("DOVE METTO LA MELASSA?\n  1) SERBATOIO ENERGIA\n  2) SERBATOIO DI RACCOLTA\n");
              green();

              while (scanf("%hd",&scelta_serbatoio) != 1 || scelta_serbatoio > 2 || scelta_serbatoio < 1)
                {
                  blu();
                  printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
                  while (getchar() != '\n');
                  green();
                }

              if (pAvanza -> melassa == poca)
                {
                  if (scelta_serbatoio == 1)
                    pPersonaggio -> serbatoio_energia = pPersonaggio -> serbatoio_energia + 1;
                  else
                    pPersonaggio -> serbatoio_raccolta = pPersonaggio -> serbatoio_raccolta + 1;
                }
              else if (pAvanza -> melassa == molta)
                {
                  if (scelta_serbatoio == 1)
                    pPersonaggio -> serbatoio_energia = pPersonaggio -> serbatoio_energia + 3;
                  else pPersonaggio -> serbatoio_raccolta = pPersonaggio -> serbatoio_raccolta + 3;
                }
            }

          controllo_serbatoio_energia_raccolta (pPersonaggio, i);

          if (pScavatrice_Hartornen -> flag_morte == 1 || pScavatrice_Arvais -> flag_morte == 1)
            {
              blu();
              printf("HAI ESAURITO L'ENERGIA E, NON AVENDO PIU' LUCE, TI PERDI FRA I CUNICOLI E MUORI...\n");
              green();
              Sleep(4000);
              return 0;
            }


            //IMPREVISTO CAVERNA
            if (pAvanza -> imprevisto == nessun_imprevisto)
              {
                blu(); printf("\n\nHAI CONTINUATO A ESPLORARE LA CAVERNA SENZA INCORRERE IN IMPREVISTI!\n\n");
                green();
                Sleep(3000);
              }
            else if (pAvanza -> imprevisto == crollo)
              {
                blu(); printf("\n\nHAI CONTINUATO A ESPLORARE LA CAVERNA QUANDO SI VERIFICA UN "); green(); printf("CROLLO"); blu(); printf("!\n");
                printf("PER LIBERARTI HAI CONSUMATO 1 UNITA' DI MELASSA!\n");
                green();

                pPersonaggio -> serbatoio_energia = pPersonaggio -> serbatoio_energia - 1;
                Sleep(3000);

                controllo_serbatoio_energia_raccolta (pPersonaggio, i);

                if (pScavatrice_Hartornen -> flag_morte == 1 || pScavatrice_Arvais -> flag_morte == 1)
                  {
                    blu();
                    printf("HAI ESAURITO L'ENERGIA E, NON AVENDO PIU' LUCE, TI PERDI FRA I CUNICOLI E MUORI...\n");
                    green();
                    Sleep(4000);
                    return 0;
                  }
              }
            else if (pAvanza -> imprevisto == baco)
              {
                blu(); printf("\n\nHAI CONTINUATO A ESPLORARE LA CAVERNA QUANDO UN "); green(); printf("BACO "); blu(); printf("TI VEDE E TI RUBA TUTTA LA MELASSA!!\n");
                green();
                pPersonaggio -> serbatoio_energia = 0;
                pPersonaggio -> serbatoio_raccolta = 0;
                Sleep(3000);

              }
      }
    if (i%2 == 0 && pPersonaggio -> flag_abbatti != 0)
       pUltimo_Arvais_caverna = pAvanza;
    else if (i%2 == 0 && pPersonaggio -> flag_abbatti == 0)
       pPrimo_Arvais_caverna = pAvanza;
    else if (i%2 == 1 && pPersonaggio -> flag_abbatti != 0)
       pUltimo_Hartornen_caverna = pAvanza;
    else if (i%2 == 1 && pPersonaggio -> flag_abbatti == 0)
      pPrimo_Hartornen_caverna = pAvanza;

    return 0;
  }

/************************************************ FINE AVANZA **********************************************************************/

/********************************************** INIZIO AGGIRA **********************************************************************/

int aggira (struct Caverna *pAggira_caverna, struct Scavatrice *pPersonaggio, int i)
  {
    short int scelta_quantita_melassa = 0;
    short int scelta_tipo_imprevisto = 0;
    short int scelta_tipo_caverna = 0;

    //Tolgo l'energia necessaria per aggirare l'ostacolo
    pPersonaggio -> serbatoio_energia = pPersonaggio -> serbatoio_energia - 1;

    controllo_serbatoio_energia_raccolta (pPersonaggio, i);

    if (pScavatrice_Hartornen -> flag_morte == 1 || pScavatrice_Arvais -> flag_morte == 1)
      {
        blu();
        printf("HAI ESAURITO L'ENERGIA E, NON AVENDO PIU' LUCE, TI PERDI FRA I CUNICOLI E MUORI...\n");
        green();
        Sleep(4000);
        return 0;
      }

    struct Caverna *pAggira = (struct Caverna*) malloc(sizeof(struct Caverna)); //Fornisco l'indirizzo di partenza
    struct Caverna *temp_aggira;

    if (pAggira_caverna -> sinistra != NULL)
       temp_aggira = pAggira_caverna -> sinistra;  //Ho salvato l'indirizzo di memoria al quale ricollegarmi dopo l'aggiunta della nuova caverna
    else if (pAggira_caverna -> avanti != NULL)
        temp_aggira = pAggira_caverna -> avanti;   //Ho salvato l'indirizzo di memoria al quale ricollegarmi dopo l'aggiunta della nuova caverna
    else if (pAggira_caverna -> destra != NULL)
        temp_aggira = pAggira_caverna -> destra;   //Ho salvato l'indirizzo di memoria al quale ricollegarmi dopo l'aggiunta della nuova caverna
    else temp_aggira = NULL; //Si puo' verificare quando, prima di chiamare la funzione, pPrimo = NULL perchè ha finito i cunicoli

    pAggira -> sinistra      = NULL;
    pAggira -> avanti        = NULL;
    pAggira -> destra        = NULL;

    //FORNISCE LA QUANTITA' DI MELASSA CHE POSSO TROVARE NELLA CAVERNA
    scelta_quantita_melassa = (rand() %100);

    if (scelta_quantita_melassa <= 49)
        pAggira -> melassa = nessuna;
    else if (scelta_quantita_melassa > 49 && scelta_quantita_melassa <= 79)
        pAggira -> melassa = poca;
    else if (scelta_quantita_melassa > 79 && scelta_quantita_melassa <= 99)
        pAggira -> melassa = molta;

    //FORNISCE CHE IMPREVISTO TROVARE NELLA CAVERNA
    scelta_tipo_imprevisto = (rand() % 100);

    if (scelta_tipo_imprevisto <= 49)
        pAggira -> imprevisto = nessun_imprevisto;
    else if (scelta_tipo_imprevisto > 49 && scelta_tipo_imprevisto <= 84)
        pAggira -> imprevisto = crollo;
    else if (scelta_tipo_imprevisto > 84 && scelta_tipo_imprevisto <= 99)
        pAggira -> imprevisto = baco;

    //FORNISCE LA TIPOLOGIA DI CAVERNA
    scelta_tipo_caverna = (rand() % 100);

    if (scelta_tipo_caverna <= 49)
        pAggira -> caverna = normale;
    else if (scelta_tipo_caverna > 49 && scelta_tipo_caverna <= 84)
        pAggira -> caverna = speciale;
    else if (scelta_tipo_caverna > 84 && scelta_tipo_caverna <= 99)
        pAggira -> caverna = accidentata;

    //AGGIORNAMENTO PUNTATORI
    if (pAggira_caverna -> sinistra != NULL)
      {
        pAggira_caverna -> sinistra = pAggira;
        pAggira -> sinistra = temp_aggira; //Collego la nuova caverna creata con quella da raggiungere
      }
    else if (pAggira_caverna -> avanti != NULL)
      {
        pAggira_caverna -> avanti = pAggira;
        pAggira -> avanti = temp_aggira; //Collego la nuova caverna creata con quella da raggiungere
      }
    else if (pAggira_caverna -> destra != NULL)
      {
        pAggira_caverna -> destra = pAggira;
        pAggira -> destra = temp_aggira; //Collego la nuova caverna creata con quella da raggiungere
      }

    return 0;
  }

/********************************************** FINE AGGIRA **********************************************************************/

/****************************************************** INIZIO ELIMINA TUTTE CAVERNE ****************************************************/

void elimina_tutte_caverne (struct Caverna *pPrimo_Elimina, struct Caverna *pUltimo_Elimina, int i, int flag_abbatti_Arvais, int flag_abbatti_Hartornen)
  {
    if (pPrimo_Elimina == NULL)
      return;

    short int numero_caverne_da_eliminare = 0;

    numero_caverne_da_eliminare = count (pPrimo_Elimina);

    for (int a = 0; a < numero_caverne_da_eliminare; a++)
      {
        if(pPrimo_Elimina == NULL) //Non sono presenti nodi
          break;
        else
          {
            //SE E' PRESENTE ALMENO UNA CAVERNA
            struct Caverna *temp;

            if (pPrimo_Elimina -> sinistra != NULL)
                temp = pPrimo_Elimina -> sinistra;
            else if (pPrimo_Elimina -> avanti != NULL)
                temp = pPrimo_Elimina -> avanti;
            else if (pPrimo_Elimina -> destra != NULL)
                temp = pPrimo_Elimina -> destra;
            else temp = NULL;

            free (pPrimo_Elimina); //Elimino l'ultima caverna creata
            pPrimo_Elimina = temp; //Aggiorno il puntatore di testa alla caverna successiva

            if(pUltimo_Elimina == pPrimo_Elimina)
              pUltimo_Elimina = NULL;
          }
      }

    numero_caverne_da_eliminare = count (pPrimo_Elimina);
    pPrimo_Elimina = NULL;

    if(pUltimo_Elimina != NULL)
      free(pUltimo_Elimina);
    pUltimo_Elimina = NULL;

    if (i%2 == 0)
      {
        pPrimo_Arvais_caverna = pPrimo_Elimina;
        pUltimo_Arvais_caverna = pUltimo_Elimina;

        if (flag_abbatti_Arvais == 0)
          {
            pUltimo_Arvais_caverna = (struct Caverna*) malloc(sizeof(struct Caverna)); //Fornisco l'indirizzo base dal quale ripartire per abbattere dato che ho eliminato tutte le grotte prima.
            pUltimo_Arvais_caverna -> sinistra = NULL;
            pUltimo_Arvais_caverna -> avanti = NULL;
            pUltimo_Arvais_caverna -> destra = NULL;
          }
      }
    else
      {
        pPrimo_Hartornen_caverna =  pPrimo_Elimina;
        pUltimo_Hartornen_caverna = pUltimo_Elimina;
        if (i%2 == 1 && flag_abbatti_Hartornen == 0)
          {
            pUltimo_Hartornen_caverna = (struct Caverna*) malloc(sizeof(struct Caverna)); //Fornisco l'indirizzo base dal quale ripartire per abbattere dato che ho eliminato tutte le grotte prima.;
            pUltimo_Hartornen_caverna -> sinistra = NULL;
            pUltimo_Hartornen_caverna -> avanti = NULL;
            pUltimo_Hartornen_caverna -> destra = NULL;
          }
      }
    return;
  }

/****************************************************** FINE ELIMINA TUTTE CAVERNE ****************************************************/

/********************************************* INIZIO ABBATTI ***********************************************************************/

int abbatti (struct Caverna *pAbbatti_caverna, struct Scavatrice *pPersonaggio, int i)
  {
    short int scelta_quantita_melassa = 0;
    short int scelta_tipo_imprevisto = 0;
    short int scelta_tipo_caverna_uscita_Arvais = 0;
    short int scelta_tipo_caverna_accidentata_Arvais = 20;
    short int scelta_tipo_caverna_normale_Arvais = 0;
    short int scelta_tipo_caverna_uscita_Hartornen = 0;
    short int scelta_tipo_caverna_accidentata_Hartornen = 20;
    short int scelta_tipo_caverna_normale_Hartornen = 0;
    short int scelta_tipo_caverna = 0;
    short int direzione = 0;

    if (i%2 == 0 && pPersonaggio -> flag_abbatti == 0)
      elimina_tutte_caverne (pPrimo_Arvais_caverna, pUltimo_Arvais_caverna, i, pScavatrice_Arvais -> flag_abbatti, pScavatrice_Hartornen -> flag_abbatti);
    else if (i%2 == 1 && pPersonaggio -> flag_abbatti == 0)
      elimina_tutte_caverne (pPrimo_Hartornen_caverna, pUltimo_Hartornen_caverna, i, pScavatrice_Arvais -> flag_abbatti, pScavatrice_Hartornen -> flag_abbatti);

    if (i%2 == 0) //Sto giocando con ARVAIS
      scelta_tipo_caverna_uscita_Arvais = scelta_tipo_caverna_uscita_Arvais + 5;
    else scelta_tipo_caverna_uscita_Hartornen = scelta_tipo_caverna_uscita_Hartornen + 5;

    //TOLGO ENERGIA NECESSARIA AD ABBATTERE
    pPersonaggio -> serbatoio_energia = pPersonaggio -> serbatoio_energia - 1;

    controllo_serbatoio_energia_raccolta (pPersonaggio, i);
    if (pScavatrice_Hartornen -> flag_morte == 1 || pScavatrice_Arvais -> flag_morte == 1)
      {
        blu();
        printf("HAI ESAURITO L'ENERGIA E, NON AVENDO PIU' LUCE, TI PERDI FRA I CUNICOLI E MUORI...\n");
        green();
        Sleep(4000);

        pPersonaggio -> flag_abbatti = 1;

        return 0;
      }

    struct Caverna *pAbbatti = (struct Caverna*) malloc(sizeof(struct Caverna)); //Fornisco l'indirizzo di partenza

    pAbbatti -> sinistra = NULL;
    pAbbatti -> avanti   = NULL;
    pAbbatti -> destra   = NULL;

    //FORNISCE LA QUANTITA' DI MELASSA CHE POSSO TROVARE NELLA CAVERNA
    scelta_quantita_melassa = (rand() %100);

    if (scelta_quantita_melassa <= 39)
      pAbbatti -> melassa = nessuna;
    else if (scelta_quantita_melassa > 39 && scelta_quantita_melassa <= 79)
      pAbbatti -> melassa = poca;
    else if (scelta_quantita_melassa > 79 && scelta_quantita_melassa <= 99)
      pAbbatti -> melassa = molta;

    //FORNISCE CHE IMPREVISTO TROVARE NELLA CAVERNA
    scelta_tipo_imprevisto = (rand() % 100);

    if (scelta_tipo_imprevisto <= 39)
      pAbbatti -> imprevisto = nessun_imprevisto;
    else if (scelta_tipo_imprevisto > 39 && scelta_tipo_imprevisto <= 79)
      pAbbatti -> imprevisto = crollo;
    else if (scelta_tipo_imprevisto > 79 && scelta_tipo_imprevisto <= 99)
      pAbbatti -> imprevisto = baco;

    //FORNISCE LA TIPOLOGIA DI CAVERNA
    scelta_tipo_caverna = (rand() % 100);

    if (i%2 == 0) //Sto giocando con ARVAIS
      {
        scelta_tipo_caverna_normale_Arvais = (100 - scelta_tipo_caverna_uscita_Arvais - scelta_tipo_caverna_accidentata_Arvais)/2;

        if (scelta_tipo_caverna <= scelta_tipo_caverna_accidentata_Arvais)
          pAbbatti -> caverna = accidentata;
        else if (scelta_tipo_caverna > scelta_tipo_caverna_accidentata_Arvais && scelta_tipo_caverna <= scelta_tipo_caverna_accidentata_Arvais + scelta_tipo_caverna_uscita_Arvais)
          {
            pAbbatti -> caverna = uscita;
            pPersonaggio -> flag_possibile_uscita = 1;
          }
        else if (scelta_tipo_caverna > scelta_tipo_caverna_accidentata_Arvais + scelta_tipo_caverna_uscita_Arvais && scelta_tipo_caverna <= scelta_tipo_caverna_accidentata_Arvais + scelta_tipo_caverna_uscita_Arvais + scelta_tipo_caverna_normale_Arvais)
          pAbbatti -> caverna = normale;
        else if (scelta_tipo_caverna > scelta_tipo_caverna_accidentata_Arvais + scelta_tipo_caverna_uscita_Arvais + scelta_tipo_caverna_normale_Arvais)
          pAbbatti -> caverna = speciale;
      }
    else
      {
        scelta_tipo_caverna_normale_Hartornen = (100 - scelta_tipo_caverna_uscita_Hartornen - scelta_tipo_caverna_accidentata_Hartornen)/2;

        if (scelta_tipo_caverna <= scelta_tipo_caverna_accidentata_Hartornen)
          pAbbatti -> caverna = accidentata;
        else if (scelta_tipo_caverna > scelta_tipo_caverna_accidentata_Hartornen && scelta_tipo_caverna <= scelta_tipo_caverna_accidentata_Hartornen + scelta_tipo_caverna_uscita_Hartornen)
          {
            pAbbatti -> caverna = uscita;
            pPersonaggio -> flag_possibile_uscita = 1;
          }
        else if (scelta_tipo_caverna > scelta_tipo_caverna_accidentata_Hartornen + scelta_tipo_caverna_uscita_Hartornen && scelta_tipo_caverna <= scelta_tipo_caverna_accidentata_Hartornen + scelta_tipo_caverna_uscita_Hartornen + scelta_tipo_caverna_normale_Hartornen)
          pAbbatti -> caverna = normale;
        else if (scelta_tipo_caverna > scelta_tipo_caverna_accidentata_Hartornen + scelta_tipo_caverna_uscita_Hartornen + scelta_tipo_caverna_normale_Hartornen)
          pAbbatti -> caverna = speciale;
      }

    printfile ("Abbatti_cuniculo.txt");
    blu();
    printf("IN QUALE DIREZIONE VUOI ABBATTERE?\n");
    green();

    while (scanf("%hd",&direzione) != 1 || direzione < 1 || direzione > 3)
      {
        blu();
        printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
        while (getchar() != '\n');
        green();
      }

    if (i%2 == 0)
      pPrimo_Arvais_caverna = pAbbatti;
    else pPrimo_Hartornen_caverna = pAbbatti;

    if (direzione == 1) //Sinistra
      return 1;
    else if (direzione == 2) //Avanti
      return 2;
    else return 3; //Destra
  }

/********************************************** FINE ABBATTI **********************************************************************/

/****************************************************************************************************************************/
/*****************************************************INIZIO CREA CUNICOLI ****************************************************/

int crea_cunicoli (void)
  {
    short int flag_mappa_cunicoli = 0; //Mettila a 1 quando la mappa viene creata
    short int scelta_opzioni_cunicoli = 0;
    short int flag_chiudi_cunicolo = 0;

    //Creo le struct Scavatrice e le inizializzo
    pScavatrice_Arvais = (struct Scavatrice*) malloc(sizeof(struct Scavatrice));
    pScavatrice_Hartornen = (struct Scavatrice*) malloc(sizeof(struct Scavatrice));

    pScavatrice_Arvais -> serbatoio_energia = 4;
    pScavatrice_Arvais -> serbatoio_raccolta = 0;
    pScavatrice_Arvais -> flag_mappa_cunicoli = 0;
    pScavatrice_Arvais -> numero_caverne = 0;
    pScavatrice_Arvais -> flag_morte = 0;
    pScavatrice_Arvais -> flag_uscita = 0;
    pScavatrice_Arvais -> flag_possibile_uscita = 0;
    pScavatrice_Arvais -> flag_crollo = 0;
    pScavatrice_Arvais -> flag_abbatti = 0;
    pScavatrice_Arvais -> last_direzione = 0;
    pScavatrice_Arvais -> direzione = 0;

    pScavatrice_Hartornen -> serbatoio_energia = 4;
    pScavatrice_Hartornen -> serbatoio_raccolta = 0;
    pScavatrice_Hartornen -> flag_mappa_cunicoli = 0;
    pScavatrice_Hartornen -> numero_caverne = 0;
    pScavatrice_Hartornen -> flag_morte = 0;
    pScavatrice_Hartornen -> flag_uscita = 0;
    pScavatrice_Hartornen -> flag_possibile_uscita = 0;
    pScavatrice_Hartornen -> flag_crollo = 0;
    pScavatrice_Hartornen -> flag_abbatti = 0;
    pScavatrice_Hartornen -> last_direzione = 0;
    pScavatrice_Hartornen -> direzione = 0;

    do
      {
        flag_chiudi_cunicolo = 0;
        printfile("Crea_cunicoli.txt");
        blu();
        printf("COSA VUOI FARE?\n");
        green();

        //Controllo dell'input
        while (scanf("%hd",&scelta_opzioni_cunicoli) != 1 || scelta_opzioni_cunicoli > 4 || scelta_opzioni_cunicoli < 1)
          {
            blu();
            printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
            while (getchar() != '\n');
            green();
          }

        switch (scelta_opzioni_cunicoli)
          {
            case 1: //Inserisci caverna
              inserisci_caverna();
              break;
            case 2: //Cancella caverna
              cancella_caverna();
              break;
            case 3: //Stampa cunicolo
              pScavatrice_Arvais -> numero_caverne = count (pPrimo_Arvais_caverna);
              pScavatrice_Hartornen -> numero_caverne = count (pPrimo_Hartornen_caverna);

              if (pScavatrice_Arvais -> numero_caverne >= 1 && pScavatrice_Hartornen -> numero_caverne >= 1)
                stampa_cunicolo();
              else
                {
                  blu();
                  printf ("NON PUOI STAMPARE I CUNICOLI SE PRIMA NON NE HAI CREATO ALMENO UNO PER ENTRAMBI!\n");
                  Sleep(3000);
                  green();
                }
              break;
            case 4: //Chiudi cunicolo
              flag_chiudi_cunicolo = 1;
              break;
          }
        pScavatrice_Arvais -> numero_caverne = count (pPrimo_Arvais_caverna);
        pScavatrice_Hartornen -> numero_caverne = count (pPrimo_Hartornen_caverna);
        if (pScavatrice_Arvais -> numero_caverne >= 10 && pScavatrice_Hartornen -> numero_caverne >= 10)
          flag_mappa_cunicoli = 1;
        else (flag_mappa_cunicoli = 0);
     } while(flag_chiudi_cunicolo == 0);
   return (flag_mappa_cunicoli);
  }

  /****************************************************** FINE CREA CUNICOLI ****************************************************/


  /****************************************************************************************************************************/
  /****************************************************** INIZIO GIOCA ****************************************************/

int gioca (void)
  {
    short int scelta_opzioni_gioca = 0;
    short int probabilita_incontro = 0; //Probabilita' che le due trivelle si incontrino
    short int rand_probabilita_incontro = 0;
    short int direzione = 0;

    srand ((unsigned) time(&t));

    for (int i = 1; pScavatrice_Arvais -> flag_morte == 0 && pScavatrice_Hartornen -> flag_morte == 0 && (pScavatrice_Arvais -> flag_uscita == 0 || pScavatrice_Hartornen -> flag_uscita == 0); i++)
      {
        probabilita_incontro = probabilita_incontro + 2;
        rand_probabilita_incontro = rand()%100;

        if ((probabilita_incontro >= 99 || rand_probabilita_incontro <= probabilita_incontro) && i != 1 && i != 2)
          {
            printfile("Scontro_diretto.txt");
            blu();
            printf("%s\n",                     "                                   STAVI PER AVANZARE QUANDO HAI VISTO IL NEMICO PASSARTI DAVANTI!");
            Sleep(3000);
            printf("%s\n\n",                   "    DECIDETE DI AFFRONTARVI UNA VOLTA PER TUTTE E DI GIOCARVI CON UN TESTA E CROCE LA CONCESSIONE DI ESTRAZIONE IN QUELLE GROTTE.");
            Sleep(6000);
            blu();

            short int scelta_testa_croce = 0;
            short int rand_testa_croce = rand()%100;

            if (i%2 == 0)
              printf("ARVAIS, VUOI ESSERE TESTA O CROCE?\n  1) TESTA\n  2) CROCE\n");
            else printf("HARTORNEN, VUOI ESSERE TESTA O CROCE?\n  1) TESTA\n  2) CROCE\n");
            green();

            while (scanf("%hd",&scelta_testa_croce) != 1 || scelta_testa_croce > 2 || scelta_testa_croce < 1)
              {
                blu();
                printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
                while (getchar() != '\n');
                green();
              }

            blu();
            for (int a = 0; a < 10; a++)
              {
                static char nome_file [40] = "Moneta[.].txt";
                nome_file[7] = a%2 + 49;
                printfile(nome_file);
              }
            green();
            Sleep(1000);

            /* Se minore 50% vince TESTA senno' CROCE

               Arvais puo' vincere solo se:
               1) Arvais sceglie TESTA ed esce TESTA
               2) Arvais sceglie CROCE ed esce CROCE
               3) Hartornen sceglie TESTA ma esce CROCE
               4) Hartornen sceglie CROCE ma esce TESTA
            */
            if ((rand_testa_croce <= 49 && ((i%2 == 0 && scelta_testa_croce == 1) || (i%2 == 1 && scelta_testa_croce == 2))) || (rand_testa_croce > 49 && ((i%2 == 0 && scelta_testa_croce == 2) || (i%2 == 1 && scelta_testa_croce == 1))))
              {
                system("cls");
                blu();
                printfile("Vince_Arvais.txt");
                green();
                Sleep(3000);
                break;
              }
            else
              {
                system("cls");
                blu();
                printfile("Vince_Hartornen.txt");
                green();
                Sleep(3000);
                break;
              }
          }

        if (i%2 == 0) //Se pari, gioco con Arvais, senno' con l'altro
          {
            if (pScavatrice_Arvais -> flag_uscita == 0)
              {
                printfile("Gioca_Arvais.txt");
                pScavatrice_Arvais -> flag_crollo = 0;

                blu();
                printf("STAI GIOCANDO CON ARVAIS!\n\n");
                green();

                if (pScavatrice_Arvais -> flag_possibile_uscita == 1)
                  {
                    blu();
                    printf("%s\n%s\n", "IN QUESTA CAVERNA HAI TROVATO L'USCITA!",
                                       "SE VUOI USCIRE E PROVARE A VINCERE USA IL COMANDO ESCI ALTRIMENTI CONTINUA A TRIVELLARE.\n");
                    green();
                    Sleep(3000);
                  }

                do
                 {
                   flag_errore_mossa = 0;
                   blu();
                   printf("\nCOSA VUOI FARE?\n");
                   green();

                   //Controllo dell'input
                   while (scanf("%hd",&scelta_opzioni_gioca) != 1 || scelta_opzioni_gioca > 5 || scelta_opzioni_gioca < 1)
                     {
                       blu();
                       printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
                       while (getchar() != '\n');
                       green();
                     }

                   switch (scelta_opzioni_gioca)
                     {
                       case 1: //Avanza
                         if (pScavatrice_Arvais -> flag_crollo == 1 || pScavatrice_Arvais -> flag_abbatti == 1)
                           {
                             blu();
                             printf("NON PUOI USARE QUESTA FUNZIONE SE SI E' VERIFICATO UN CROLLO O SE HAI ABBATTUTO UNA PARETE DELLA CAVERNA!\n");
                             green();
                             Sleep(3000);
                             flag_errore_mossa = 1;
                           }
                         else
                           avanza (pPrimo_Arvais_caverna, pScavatrice_Arvais, i);
                         break;
                       case 2: //Abbatti
                       if (pScavatrice_Arvais -> flag_crollo == 1)
                         {
                           blu();
                           printf("NON PUOI USARE QUESTA FUNZIONE SE SI E' VERIFICATO UN CROLLO!\n");
                           green();
                           Sleep(3000);
                           flag_errore_mossa = 1;
                         }
                        else
                         {
                           direzione = abbatti (pUltimo_Arvais_caverna, pScavatrice_Arvais, i);

                           if (pScavatrice_Arvais -> flag_morte == 1)
                             break;

                           printfile("Gioca_Arvais.txt");

                           //AGGIORNAMENTO PUNTATORI
                           if (direzione == 1)
                             pUltimo_Arvais_caverna -> sinistra = pPrimo_Arvais_caverna; //Ho abbattuto a sinistra
                           else if (direzione == 2)
                             pUltimo_Arvais_caverna  -> avanti = pPrimo_Arvais_caverna; //Ho abbattuto davanti
                           else pUltimo_Arvais_caverna -> destra = pPrimo_Arvais_caverna; //Ho abbattuto a destra

                           pScavatrice_Arvais -> flag_abbatti = 1;

                           avanza (pUltimo_Arvais_caverna, pScavatrice_Arvais, i);
                         }
                         break;
                       case 3: //Aggira
                         if (pScavatrice_Arvais -> flag_crollo == 1)
                           {
                             aggira (pPrimo_Arvais_caverna, pScavatrice_Arvais, i);

                             if (pScavatrice_Arvais -> flag_morte == 1)
                               break;

                             avanza (pPrimo_Arvais_caverna, pScavatrice_Arvais, i);  //Avanzo fino la caverna dove sarei entrato con avanza ma subendo gli effetti di due caverne

                             if (pScavatrice_Arvais -> flag_morte == 1)
                               break;

                             avanza (pPrimo_Arvais_caverna, pScavatrice_Arvais, i);  //Avanzo fino la caverna dove sarei entrato con avanza ma subendo gli effetti di due caverne

                             if (pScavatrice_Arvais -> flag_morte == 1)
                               break;
                           }
                         else
                           {
                             blu();
                             printf("NON PUOI USARE QUESTA FUNZIONE SE NON SI E' VERIFICATO UN CROLLO!\n");
                             green();
                             Sleep(3000);
                             flag_errore_mossa = 1;
                           }
                         break;
                       case 4: //Esci
                         if (pScavatrice_Arvais -> flag_possibile_uscita == 1)
                          pScavatrice_Arvais -> flag_uscita = 1;
                        else
                          {
                            blu();
                            printf("NON PUOI USARE QUESTA FUNZIONE SE NON SEI SU UNA GROTTA DI TIPO USCITA!\n");
                            green();
                            Sleep(3000);
                            flag_errore_mossa = 1;
                          }
                         break;
                        case 5: //Mostra energia
                          blu();
                          printf("\nSERBATOIO ENERGIA:  ");
                          green();
                          printf("%d\n", pScavatrice_Arvais -> serbatoio_energia);
                          blu();
                          printf("SERBATOIO RACCOLTA: ");
                          green();
                          printf("%d\n", pScavatrice_Arvais -> serbatoio_raccolta);
                          flag_errore_mossa = 1;
                          break;
                     }
                 } while (flag_errore_mossa == 1);

              }
            else continue;
          }

        else //Turno Hartornen
          {
            if (pScavatrice_Hartornen -> flag_uscita == 0)
              {
                printfile("Gioca_Hartornen.txt");
                pScavatrice_Hartornen -> flag_crollo = 0;

                blu();
                printf("STAI GIOCANDO CON HARTORNEN!\n\n");
                green();

                if (pScavatrice_Hartornen -> flag_possibile_uscita == 1)
                  {
                    blu();
                    printf("%s\n%s\n", "IN QUESTA CAVERNA HAI TROVATO L'USCITA!",
                                       "SE VUOI USCIRE E PROVARE A VINCERE USA IL COMANDO ESCI ALTRIMENTI CONTINUA A TRIVELLARE.\n");
                    green();
                    Sleep(3000);
                  }

                do
                 {
                    flag_errore_mossa = 0;
                    blu();
                    printf("\nCOSA VUOI FARE?\n");
                    green();

                    //Controllo dell'input
                    while (scanf("%hd",&scelta_opzioni_gioca) != 1 || scelta_opzioni_gioca > 5 || scelta_opzioni_gioca < 1)
                      {
                        blu();
                        printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
                        while (getchar() != '\n');
                        green();
                      }

                    switch (scelta_opzioni_gioca)
                      {
                        case 1: //Avanza
                          if (pScavatrice_Hartornen -> flag_crollo == 1 || pScavatrice_Hartornen -> flag_abbatti == 1)
                            {
                              blu();
                              printf("NON PUOI USARE QUESTA FUNZIONE SE SI E' VERIFICATO UN CROLLO O SE HAI ABBATTUTO UNA PARETE DELLA CAVERNA!\n");
                              green();
                              Sleep(3000);
                              flag_errore_mossa = 1;
                            }
                          else
                              avanza (pPrimo_Hartornen_caverna, pScavatrice_Hartornen, i);
                          break;
                        case 2: //Abbatti
                          if (pScavatrice_Hartornen -> flag_crollo == 1)
                            {
                              blu();
                              printf("NON PUOI USARE QUESTA FUNZIONE SE SI E' VERIFICATO UN CROLLO!\n");
                              green();
                              Sleep(3000);
                              flag_errore_mossa = 1;
                            }
                          else
                            {
                              direzione = abbatti(pUltimo_Hartornen_caverna, pScavatrice_Hartornen, i);
                              if (pScavatrice_Hartornen -> flag_morte == 1)
                                break;
                              printfile("Gioca_Hartornen.txt");

                              //AGGIORNAMENTO PUNTATORI
                              if (direzione == 1)
                                pUltimo_Hartornen_caverna -> sinistra = pPrimo_Hartornen_caverna; //Ho abbattuto a sinistra
                              else if (direzione == 2)
                                pUltimo_Hartornen_caverna -> avanti = pPrimo_Hartornen_caverna; //Ho abbattuto davanti
                              else pUltimo_Hartornen_caverna -> destra = pPrimo_Hartornen_caverna; //Ho abbattuto a destra

                              pScavatrice_Hartornen -> flag_abbatti = 1;
                              avanza (pUltimo_Hartornen_caverna, pScavatrice_Hartornen, i);
                            }
                          break;
                        case 3: //Aggira
                          if (pScavatrice_Hartornen -> flag_crollo == 1)
                            {
                              aggira (pPrimo_Hartornen_caverna, pScavatrice_Hartornen, i);

                              if (pScavatrice_Hartornen -> flag_morte == 1)
                                break;

                              avanza (pPrimo_Hartornen_caverna, pScavatrice_Hartornen, i);  //Avanzo fino la caverna dove sarei entrato con avanza ma subendo gli effetti di due caverne

                              if (pScavatrice_Hartornen -> flag_morte == 1)
                                break;

                              avanza (pPrimo_Hartornen_caverna, pScavatrice_Hartornen, i);  //Avanzo fino la caverna dove sarei entrato con avanza ma subendo gli effetti di due caverne

                              if (pScavatrice_Hartornen -> flag_morte == 1)
                                break;
                            }
                          else
                            {
                              blu();
                              printf("NON PUOI USARE QUESTA FUNZIONE SE NON SI E' VERIFICATO UN CROLLO!\n");
                              green();
                              Sleep(3000);
                              flag_errore_mossa = 1;
                            }
                          break;
                        case 4: //Esci
                          if (pScavatrice_Hartornen -> flag_possibile_uscita == 1)
                            pScavatrice_Hartornen -> flag_uscita = 1;
                          else
                            {
                              blu();
                              printf("NON PUOI USARE QUESTA FUNZIONE SE NON SEI SU UNA GROTTA DI TIPO USCITA!\n");
                              green();
                              Sleep(3000);
                              flag_errore_mossa = 1;
                            }
                          break;
                        case 5: //Mostra energia
                          blu();
                          printf("\nSERBATOIO ENERGIA:  ");
                          green();
                          printf("%d\n",pScavatrice_Hartornen -> serbatoio_energia);
                          blu();
                          printf("SERBATOIO RACCOLTA: ");
                          green();
                          printf("%d\n",pScavatrice_Hartornen -> serbatoio_raccolta);
                          flag_errore_mossa = 1;
                          break;
                      }
                  } while (flag_errore_mossa == 1);
              }
            else continue;
          }

        //PROCLAMAZIONE VINCITORE PER MORTE AVVERSARIO
        if (pScavatrice_Arvais -> flag_morte == 1)
          {
            system("cls");
            print_lampeggio_gameover();
            printfile("Vince_Hartornen.txt");
            Sleep(3000);
            green();
          }
        else if (pScavatrice_Hartornen -> flag_morte == 1)
          {
            system("cls");
            print_lampeggio_gameover();
            printfile("Vince_Arvais.txt");
            Sleep(3000);
            green();
          }
      } //FINE FOR

    //PROCLAMAZIONE VINCITORE PER MERITO (HA TROVATO PIU' MELASSA)
    if (pScavatrice_Arvais -> flag_uscita == 1 && pScavatrice_Hartornen -> flag_uscita == 1)
      {
        if (pScavatrice_Arvais -> serbatoio_raccolta > pScavatrice_Hartornen -> serbatoio_raccolta)
          {
            system("cls");
            printfile("Vince_Arvais.txt");
            Sleep(3000);
            green();
          }
        else
          {
            system("cls");
            printfile("Vince_Hartornen.txt");
            Sleep(3000);
            green();
          }
      }

    if (pScavatrice_Arvais -> flag_abbatti != 0 || pPrimo_Arvais_caverna == pUltimo_Arvais_caverna)
      {
        if (pPrimo_Arvais_caverna == pUltimo_Arvais_caverna)
          {
            free(pPrimo_Arvais_caverna);
            pPrimo_Arvais_caverna = NULL;
            pUltimo_Arvais_caverna = NULL;
          }
        else
          {
            if (pPrimo_Arvais_caverna != NULL)
              free(pPrimo_Arvais_caverna);
            pPrimo_Arvais_caverna = NULL;
            if (pUltimo_Arvais_caverna != NULL)
              free(pUltimo_Arvais_caverna);
            pUltimo_Arvais_caverna = NULL;
          }
      }
    else elimina_tutte_caverne (pPrimo_Arvais_caverna, pUltimo_Arvais_caverna, 2, pScavatrice_Arvais -> flag_abbatti, pScavatrice_Hartornen -> flag_abbatti);

    if (pScavatrice_Hartornen -> flag_abbatti != 0 || pPrimo_Hartornen_caverna == pUltimo_Hartornen_caverna)
      {
        if (pPrimo_Hartornen_caverna == pUltimo_Hartornen_caverna)
          {
            free(pPrimo_Hartornen_caverna);
            pPrimo_Hartornen_caverna = NULL;
            pUltimo_Hartornen_caverna = NULL;
          }
        else
          {
            if (pPrimo_Hartornen_caverna != NULL)
              free(pPrimo_Hartornen_caverna);
            pPrimo_Hartornen_caverna = NULL;
            if (pUltimo_Hartornen_caverna != NULL)
              free(pUltimo_Hartornen_caverna);
            pUltimo_Hartornen_caverna = NULL;
          }
      }
    else elimina_tutte_caverne (pPrimo_Hartornen_caverna, pUltimo_Hartornen_caverna, 1, pScavatrice_Arvais -> flag_abbatti, pScavatrice_Hartornen -> flag_abbatti);

    free(pScavatrice_Arvais);
    free(pScavatrice_Hartornen);

    //AZZERO TUTTE LE VARIABILI PRIMA DI USCIRE
    scelta_personaggio = 0;
    flag_errore_mossa = 0;
    return 0;
  }

  /****************************************************** FINE GIOCA ****************************************************/
