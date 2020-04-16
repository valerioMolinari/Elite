//CERAMI CRISTIAN
//MATRICOLA: 324075

/**********************************************************************************************************************
* RICORDATI DI REINSERIRE N° MINIMO GROTTE = 10  e numero_caverne_Arvais >= 10 e numero_caverne_Hartornen >= 10 e
* ricordati di rimettere if (numero_caverne_Arvais < 2) circa riga 754 a 10
*
* NON MI PRENDE IL FLAG CREAZIONE MAPPA
*
* NON MI FUNZIONA QUESTO printf ("NON SONO PRESENTI CAVERNE DA ELIMINARE PER HARTORNEN!");...NON ME LO MOSTRA NONOSTANTE
* CI ABBIA MESSO UNO SLEEP(3);
*
* NON SONO RIUSCITO A METTERE LE STRUCT COME STATIC;
**********************************************************************************************************************/




/**********************************************************************************************************************
* Ho messo che ad ogni turno, anche se non si avanza, la probabilità di incontro fra le due trivelle aumenta del 2%
* e non del 3% senno' il gioco durava troppo poco.
*
* Ho deciso che, se i due giocatori si dovessero incontrare, lanciano una moneta e la probablitita' decide il vincitore
*
* Nella prima grotta che creo ho impostato in automatico tutte le variabili a "normali" quindi sembrera', durante la
* creazione dei cunicoli, saltare questa prima grotta.
*
*
**********************************************************************************************************************/

#include "gamelib.h"

/***********************************************  VARIABILI  *********************************************************/

static time_t t;
struct Caverna *primo_cunicolo_Arvais = NULL;
struct Caverna *primo_cunicolo_Hartornen = NULL;
struct Caverna *pPrimo_Arvais;
struct Caverna *pPrimo_Hartornen;
struct Scavatrice arvais;
struct Scavatrice hartornen;

//VARIABILI IN CREA CUNICOLI
static short int scelta_personaggio = 0;
static short int flag_mappa_cunicoli_Arvais = 0;
static short int flag_mappa_cunicoli_Hartornen = 0;
static short int flag_chiudi_cunicolo = 0;
static short int numero_caverne_Arvais = 0;
static short int numero_caverne_Hartornen = 0;

/***********************************************  PROGRAMMA  *********************************************************/

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

void print_list(struct Caverna *pPrimo)
  {
    if (pPrimo == NULL) //Se non sono state create grotte
      {
        blu();
        printf("NESSUNA GROTTA TROVATA!");
        green();
      }
    else
      {
        struct Caverna *pScan = pPrimo; //Inizializzo il puntatore che mi cerca le grotte
        int a = 1;
        do
          {
            //PER NUMERO GROTTA MAGARI SFRUTTA COUNT E IL VALORE TROVATO FAI -- COSI' FINCHE NON ARRIVI ALLA GROTTA DI PARTENZA = 1
            blu(); printf("\nNUMERO GROTTA: "); green();
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
                printf("CAVERNA DI PARTENZA\n");
              }
            pPrimo = pScan;
            a++;
            //SE VUOI INSERISCI FUNZIONE CHE NON FA STAMPARE LA FRECCIA PER LA GROTTA DI PARTENZA, BASTA NON STAMPARLA PER COUNT = 0 o 1;
            printf("          ^\n"
                   "          |\n"
                   "          |\n");
            //pScan = pScan -> pSuccessivo; //Aggiorno il puntatore per passare alla lista successiva
          } while(pScan != NULL); //Se trova NULL è arrivato all'ultima grotta
      }
    return;
  }

int count (struct Caverna *pPrimo)
  {
    struct Caverna *pScan = pPrimo;
    short int cnt = 0;
    while (pScan != NULL)
      {
        cnt++;
        if (pScan -> sinistra != NULL)
          pScan = pScan -> sinistra;
        else if (pScan -> destra != NULL)
          pScan = pScan -> destra;
        else if (pScan -> avanti != NULL)
          pScan = pScan -> avanti;
        else pScan = NULL;
      }
      return cnt;
  }


/******************************************************* INSERISCI CAVERNA **********************************************************************/
int  inserisci_caverna(void)
  {
    short int numero_caverne = 0;
    short int direzione = 0;
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
        while (scanf("%hd",&scelta_personaggio) != 1 || scelta_personaggio >2 || scelta_personaggio <1)
          {
            blu();
            printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
            while (getchar() != '\n');
            green();
          }
        if (scelta_personaggio == 1 && flag_mappa_cunicoli_Arvais == 1) //Se ho gia costruito le caverne minime per Arvais
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
        if (scelta_personaggio == 2 && flag_mappa_cunicoli_Hartornen == 1) //Se ho gia costruito le caverne minime per Arvais
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
            numero_caverne_Arvais = count (pPrimo_Arvais);

            if (numero_caverne_Arvais == 0)
              {
                printfile("Inserisci_cunicoli_Arvais.txt");
                blu();
                printf("DEVI INSERIRE ALMENO 10 CAVERNE (E MENO DI 100)!\n");
                printf("QUANTE CAVERNE VUOI INSERIRE?\nNUMERO CAVERNE DA INSERIRE: ");
                green();
                while (scanf("%hd",&numero_caverne) != 1 || numero_caverne < 2 || numero_caverne > 100) /////////////// rimetti  numero_caverne < 10
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
                printf("QUANTE CAVERNE VUOI INSERIRE?\nNUMERO CAVERNE DA INSERIRE: ");
                green();
                while (scanf("%hd",&numero_caverne) != 1 || numero_caverne < 1 || numero_caverne > 100) /////////////// rimetti  numero_caverne < 10
                  {
                    blu();
                    printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
                    while (getchar() != '\n');
                    green();
                  }
              }

            for (int i = 0; i < numero_caverne; i++) //Creo il numero di caverne richiesto
              {
                direzione = 0, scelta_quantita_melassa = 0, scelta_tipo_imprevisto = 0, scelta_tipo_caverna = 0;
                struct Caverna *primo_cunicolo_Arvais = (struct Caverna*) malloc(sizeof(struct Caverna)); //Fornisco l'indirizzo di partenza
                printf("RIGA 186. PRIMA CELLA primo_cunicolo_Arvais: %p\n", primo_cunicolo_Arvais);
                //sleep(5);

                primo_cunicolo_Arvais -> sinistra      = NULL;
                primo_cunicolo_Arvais -> avanti        = NULL;
                primo_cunicolo_Arvais -> destra        = NULL;

                printfile("Inserisci_cunicoli_Arvais.txt");
                blu();
                printf("IN QUALE DIREZIONE VUOI ANDARE?\n");
                green();

                while (scanf("%hd",&direzione) != 1 || direzione < 1 || direzione > 3)
                  {
                    blu();
                    printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
                    while (getchar() != '\n');
                    green();
                  }

                if (i == 0 && numero_caverne_Arvais == 0) //La prima grotta deve essere "normale" in tutto
                  {
                    primo_cunicolo_Arvais -> melassa     = nessuna;
                    primo_cunicolo_Arvais -> imprevisto  = nessun_imprevisto;
                    primo_cunicolo_Arvais -> caverna     = normale;
                  }
                else
                  {
                    //FORNISCE LA QUANTITA' DI MELASSA CHE POSSO TROVARE NELLA CAVERNA
                    scelta_quantita_melassa = (rand() %100);
                    printf ("Scelta quantita melassa: %d\n",scelta_quantita_melassa);
                    sleep(5);
                    if (scelta_quantita_melassa <= 49)
                        primo_cunicolo_Arvais -> melassa = nessuna;
                    else if (scelta_quantita_melassa > 49 && scelta_quantita_melassa <= 79)
                        primo_cunicolo_Arvais -> melassa = poca;
                    else if (scelta_quantita_melassa > 79 && scelta_quantita_melassa <= 99)
                        primo_cunicolo_Arvais -> melassa = molta;
                    printf ("primo_cunicolo_Arvais -> melassa: %d\n",primo_cunicolo_Arvais -> melassa);
                    sleep(5);

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
                if (pPrimo_Arvais == NULL) //Se non ci stavano nodi precedenti
                  {
                    pPrimo_Arvais = primo_cunicolo_Arvais; //Ho appena creato il primo nodo
                    printf("RIGA 346. CELLA primo_cunicolo_Arvais: %p\n", primo_cunicolo_Arvais);
                    printf("RIGA 347. CELLA pPrimo_Arvais: %p\n",pPrimo_Arvais);
                    //sleep(5);
                  }
                else //Se gia era presente un nodo
                  {
                    printf("RIGA 350. CELLA primo_cunicolo_Arvais -> sinistra: %p\n", primo_cunicolo_Arvais -> sinistra);
                    printf("RIGA 351. CELLA primo_cunicolo_Arvais -> avanti: %p\n", primo_cunicolo_Arvais -> avanti);
                    printf("RIGA 352. CELLA primo_cunicolo_Arvais -> destra: %p\n", primo_cunicolo_Arvais -> destra);
                    if (direzione == 1) //Se ho scelto sinistra
                      {
                        primo_cunicolo_Arvais -> sinistra = pPrimo_Arvais; //Il primo nodo diventa il secondo
                        printf("RIGA 356. CELLA primo_cunicolo_Arvais -> sinistra: %p\n", primo_cunicolo_Arvais -> sinistra);
                      }
                    else if (direzione == 2) //Se ho scelto avanti
                      {
                        primo_cunicolo_Arvais -> avanti = pPrimo_Arvais; //Il primo nodo diventa il secondo
                        printf("RIGA 358. CELLA primo_cunicolo_Arvais -> avanti: %p\n", primo_cunicolo_Arvais -> avanti);
                      }
                    else if (direzione == 3) //Se ho scelto destra
                      {
                        primo_cunicolo_Arvais -> destra = pPrimo_Arvais; //Il primo nodo diventa il secondo
                        printf("RIGA 360. CELLA primo_cunicolo_Arvais -> destra: %p\n", primo_cunicolo_Arvais -> destra);
                      }

                    pPrimo_Arvais = primo_cunicolo_Arvais; //Aggiorno l'indirizzo di pPrimo_Arvais cosi' che punti nuovamente al primo elemnto della lista

                    printf("RIGA 368. CELLA primo_cunicolo_Arvais: %p\n", primo_cunicolo_Arvais);
                    printf("RIGA 369. CELLA pPrimo_Arvais: %p\n", pPrimo_Arvais);
                    //sleep(5);
                  }
              } //FINE for
              flag_mappa_cunicoli_Arvais = 1;
              printf("flag_mappa_cunicoli_Arvais: %d\n", flag_mappa_cunicoli_Arvais);
              //sleep(5);

    /********************STAMPA IL N° DI ELEMENTI INSERITI*******************************************/
    /*
            printf("RIGA 380. CELLA pPrimo: %p\n", pPrimo);
            struct Caverna *pScan = pPrimo;
            printf("RIGA 382. ATTUALE CELLA pScan: %p\n", pScan);
            printf("RIGA 383. ATTUALE CELLA pPrimo: %p\n", pPrimo);
            printf("RIGA 384. CELLA pScan -> avanti: %p\n", pScan -> avanti);
            printf("RIGA 385. CELLA pScan -> sinistra: %p\n", pScan -> sinistra);
            printf("RIGA 386. CELLA pScan -> destra: %p\n", pScan -> destra);
            sleep(5);
            short int cnt = 0;
            while (pScan != NULL)
              {
                cnt++;
                if (pScan -> sinistra != NULL)
                  pScan = pScan -> sinistra;
                else if (pScan -> destra != NULL)
                  pScan = pScan -> destra;
                else if (pScan -> avanti != NULL)
                  pScan = pScan -> avanti;
                else pScan = NULL;
              }
            printf("N° caverne: %d\n", cnt);
    */

          }

        else //Ho scelto Hartornen
          {
            numero_caverne_Hartornen = count (pPrimo_Hartornen);

            if (numero_caverne_Hartornen == 0)
              {
                printfile("Inserisci_cunicoli_Hartornen.txt");
                blu();
                printf("DEVI INSERIRE ALMENO 10 CAVERNE (E MENO DI 100)!\n");
                printf("QUANTE CAVERNE VUOI INSERIRE?\nNUMERO CAVERNE DA INSERIRE: ");
                green();
                while (scanf("%hd",&numero_caverne) != 1 || numero_caverne < 2 || numero_caverne > 100) /////////////// rimetti  numero_caverne < 10
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
                printf("QUANTE CAVERNE VUOI INSERIRE?\nNUMERO CAVERNE DA INSERIRE: ");
                green();
                while (scanf("%hd",&numero_caverne) != 1 || numero_caverne < 1 || numero_caverne > 100) /////////////// rimetti  numero_caverne < 10
                  {
                    blu();
                    printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
                    while (getchar() != '\n');
                    green();
                  }
              }

            for (int i = 0; i < numero_caverne; i++) //Creo il numero di caverne richiesto
              {
                direzione = 0, scelta_quantita_melassa = 0, scelta_tipo_imprevisto = 0, scelta_tipo_caverna = 0;
                struct Caverna *primo_cunicolo_Hartornen = (struct Caverna*) malloc(sizeof(struct Caverna)); //Fornisco l'indirizzo di partenza
                printf("RIGA 186. PRIMA CELLA primo_cunicolo_Hartornen: %p\n", primo_cunicolo_Hartornen);
                //sleep(5);

                primo_cunicolo_Hartornen -> sinistra      = NULL;
                primo_cunicolo_Hartornen -> avanti        = NULL;
                primo_cunicolo_Hartornen -> destra        = NULL;

                printfile("Inserisci_cunicoli_Hartornen.txt");
                blu();
                printf("IN QUALE DIREZIONE VUOI ANDARE?\n");
                green();

                while (scanf("%hd",&direzione) != 1 || direzione < 1 || direzione > 3)
                  {
                    blu();
                    printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
                    while (getchar() != '\n');
                    green();
                  }

                if (i == 0 && numero_caverne_Hartornen == 0) //La prima grotta deve essere "normale" in tutto
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
                if (pPrimo_Hartornen == NULL) //Se non ci stavano nodi precedenti
                  {
                    pPrimo_Hartornen = primo_cunicolo_Hartornen; //Ho appena creato il primo nodo
                    printf("RIGA 346. CELLA primo_cunicolo_Hartornen: %p\n", primo_cunicolo_Hartornen);
                    printf("RIGA 347. CELLA pPrimo_Hartornen: %p\n",pPrimo_Hartornen);
                    //sleep(5);
                  }
                else //Se gia era presente un nodo
                  {
                    printf("RIGA 350. CELLA primo_cunicolo_Hartornen -> sinistra: %p\n", primo_cunicolo_Hartornen -> sinistra);
                    printf("RIGA 351. CELLA primo_cunicolo_Hartornen -> avanti: %p\n", primo_cunicolo_Hartornen -> avanti);
                    printf("RIGA 352. CELLA primo_cunicolo_Hartornen -> destra: %p\n", primo_cunicolo_Hartornen -> destra);
                    if (direzione == 1) //Se ho scelto sinistra
                      {
                        primo_cunicolo_Hartornen -> sinistra = pPrimo_Hartornen; //Il primo nodo diventa il secondo
                        printf("RIGA 356. CELLA primo_cunicolo_Hartornen -> sinistra: %p\n", primo_cunicolo_Hartornen -> sinistra);
                      }
                    else if (direzione == 2) //Se ho scelto avanti
                      {
                        primo_cunicolo_Hartornen -> avanti = pPrimo_Hartornen; //Il primo nodo diventa il secondo
                        printf("RIGA 358. CELLA primo_cunicolo_Hartornen -> avanti: %p\n", primo_cunicolo_Hartornen -> avanti);
                      }
                    else if (direzione == 3) //Se ho scelto destra
                      {
                        primo_cunicolo_Hartornen -> destra = pPrimo_Hartornen; //Il primo nodo diventa il secondo
                        printf("RIGA 360. CELLA primo_cunicolo_Hartornen -> destra: %p\n", primo_cunicolo_Hartornen -> destra);
                      }

                    pPrimo_Hartornen = primo_cunicolo_Hartornen; //Aggiorno l'indirizzo di pPrimo_Hartornen cosi' che punti nuovamente al primo elemnto della lista

                    printf("RIGA 368. CELLA primo_cunicolo_Hartornen: %p\n", primo_cunicolo_Hartornen);
                    printf("RIGA 369. CELLA pPrimo_Hartornen: %p\n", pPrimo_Hartornen);
                    //sleep(5);
                  }
              } //FINE for
            flag_mappa_cunicoli_Hartornen = 1;
            printf("flag_mappa_cunicoli_Hartornen: %d\n", flag_mappa_cunicoli_Hartornen);
            //sleep(5);
          }
      } while(flag_mappa_cunicoli_Arvais == 0 || flag_mappa_cunicoli_Hartornen == 0);
    return 0;
  }

  /************************************************ FINE INSERISCI CAVERNA **********************************************************************/

  /************************************************ INIZIO CANCELLA CAVERNA **********************************************************************/


int  cancella_caverna(void)
  {
    short int scelta_personaggio = 0;
    short int numero_caverne_da_eliminare = 0;

    numero_caverne_Arvais = count (pPrimo_Arvais);
    numero_caverne_Hartornen = count (pPrimo_Hartornen);

    printfile ("Cancella_cunicoli.txt");
    if (numero_caverne_Arvais < 2 && numero_caverne_Hartornen < 2)
      {
        blu();
        printf ("SIA ARVAIS CHE HARTORNEN NON HANNO CAVERNE ELIMINABILI!\n");
        sleep(3);
        green();
        return 0;
      }
    blu();
    printf ("DI CHI VUOI CANCELLARE LE CAVERNE?\n");
    green();

    while (scanf("%hd",&scelta_personaggio) != 1 || scelta_personaggio > 2 || scelta_personaggio < 1)
      {
        blu();
        printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
        while (getchar() != '\n');
        green();
      }

    if (scelta_personaggio == 1 && numero_caverne_Arvais >= 2) //Ho scelto Arvais
      {
        printfile("Cancella_cunicoli_Arvais.txt");
        blu(); printf ("PUOI ELIMINARE AL MASSIMO "); green();
        printf ("%d ",numero_caverne_Arvais - 1);
        blu();
        printf ("CAVERNE PER ARVAIS\n\n");
        printf ("QUANTE CAVERNE VUOI ELIMINARE?\n");
        green();

        while (scanf("%hd",&numero_caverne_da_eliminare) != 1 || numero_caverne_da_eliminare < 1 || numero_caverne_da_eliminare >= numero_caverne_Arvais)
          {
            blu();
            printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
            while (getchar() != '\n');
            green();
          }

        for (int i = 0; i < numero_caverne_da_eliminare; i++)
          {
            if(pPrimo_Arvais == NULL) //Non sono presenti nodi
              {
                blu();
                printf("NON SONO PRESENTI CAVERNE DA ELIMINARE!\n");
                green();
              }
            else
              {
                //SE E' PRESENTE ALMENO UNA CAVERNA
                struct Caverna *temp;

                if (pPrimo_Arvais -> sinistra != NULL)
                    temp = pPrimo_Arvais -> sinistra;
                else if (pPrimo_Arvais -> avanti != NULL)
                    temp = pPrimo_Arvais -> avanti;
                else if (pPrimo_Arvais -> destra != NULL)
                    temp = pPrimo_Arvais -> destra;

                free (pPrimo_Arvais); //Elimino l'ultima caverna creata
                pPrimo_Arvais = temp; //Aggiorno il puntatore di testa alla caverna successiva
              }
          }
      }
    else if (scelta_personaggio == 1 && numero_caverne_Arvais < 2) //Ho scelto Arvais ma non ho caverne eliminabili
      {
        printfile("Cancella_cunicoli_Arvais.txt");
        blu(); printf ("NON SONO PRESENTI CAVERNE DA ELIMINARE PER ARVAIS!"); green();
        sleep(3);
      }
    else if (scelta_personaggio == 2 && numero_caverne_Hartornen >= 2) //Ho scelto Hartornen
      {
        printfile("Cancella_cunicoli_Hartornen.txt");
        blu(); printf ("PUOI ELIMINARE AL MASSIMO "); green();
        printf ("%d ",numero_caverne_Hartornen - 1);
        blu();
        printf ("CAVERNE PER HARTORNEN\n\n");
        printf ("QUANTE CAVERNE VUOI ELIMINARE?\n");
        green();

        while (scanf("%hd",&numero_caverne_da_eliminare) != 1 || numero_caverne_da_eliminare < 1 || numero_caverne_da_eliminare >= numero_caverne_Hartornen)
          {
            blu();
            printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
            while (getchar() != '\n');
            green();
          }

        for (int i = 0; i < numero_caverne_da_eliminare; i++)
          {
            if(pPrimo_Hartornen == NULL) //Non sono presenti nodi
              {
                blu();
                printf("NON SONO PRESENTI CAVERNE DA ELIMINARE!\n");
                green();
              }
            else
              {
                //SE E' PRESENTE ALMENO UNA CAVERNA
                struct Caverna *temp;

                if (pPrimo_Hartornen -> sinistra != NULL)
                    temp = pPrimo_Hartornen -> sinistra;
                else if (pPrimo_Hartornen -> avanti != NULL)
                    temp = pPrimo_Hartornen -> avanti;
                else if (pPrimo_Hartornen -> destra != NULL)
                    temp = pPrimo_Hartornen -> destra;

                free (pPrimo_Hartornen); //Elimino l'ultima caverna creata
                pPrimo_Hartornen = temp; //Aggiorno il puntatore di testa alla caverna successiva
              }
          }
      }
    else if (scelta_personaggio == 2 && numero_caverne_Hartornen < 2) //Ho scelto Hartornen ma non ho caverne eliminabili
      {
        printfile("Cancella_cunicoli_Hartornen.txt");
        blu();
        printf ("NON SONO PRESENTI CAVERNE DA ELIMINARE PER HARTORNEN!");
        sleep(3);
        green();
      }

    numero_caverne_Arvais = count (pPrimo_Arvais);
    numero_caverne_Hartornen = count (pPrimo_Hartornen);

    if (numero_caverne_Arvais < 2)
      flag_mappa_cunicoli_Arvais = 0;
    if (numero_caverne_Hartornen < 2)
      flag_mappa_cunicoli_Hartornen = 0;
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

    while (scanf("%hd",&scelta_personaggio) != 1 || scelta_personaggio > 2 || scelta_personaggio < 1)
      {
        blu();
        printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
        while (getchar() != '\n');
        green();
      }

    if (scelta_personaggio == 1)
      {
        printfile("Stampa_cunicoli_Arvais.txt");
        print_list (pPrimo_Arvais);
        blu();
        printf ("LA MAPPA SI CHIUDERA' FRA 15 SECONDI\n");
        sleep(15);
        green();
      }
    else
      {
        printfile("Stampa_cunicoli_Hartornen.txt");
        print_list (pPrimo_Hartornen);
        blu();
        printf ("LA MAPPA SI CHIUDERA' FRA 15 SECONDI\n");
        sleep(15);
        green();
      }
    return;
  }

  /************************************************ FINE STAMPA CAVERNA **********************************************************************/



/****************************************************************************************************************************/
/*****************************************************INIZIO CREA CUNICOLI ****************************************************/

int crea_cunicoli (void)
  {
    short int flag_mappa_cunicoli = 0; //Mettila a 1 quando la mappa viene creata
    short int scelta_opzioni_cunicoli = 0;

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
              numero_caverne_Arvais = count (pPrimo_Arvais);
              numero_caverne_Hartornen = count (pPrimo_Hartornen);

              if (numero_caverne_Arvais >= 1 && numero_caverne_Hartornen >= 1)
                stampa_cunicolo();
              else
                {
                  blu();
                  printf ("NON PUOI STAMPARE I CUNICOLI SE PRIMA NON NE HAI CREATO ALMENO UNO PER ENTRAMBI!\n");
                  sleep(3);
                  green();
                }
              break;
            case 4: //Chiudi cunicolo
              flag_chiudi_cunicolo = 1;
              break;
          }
        printf("\n\n\nRIGA 671. SONO ARRIVATO QUI\n");
        numero_caverne_Arvais = count (pPrimo_Arvais);
        numero_caverne_Hartornen = count (pPrimo_Hartornen);
        printf("RIGA 674. numero_caverne_Arvais: %d\n", numero_caverne_Arvais);
        printf("RIGA 675. numero_caverne_Hartornen: %d\n", numero_caverne_Hartornen);
        if (numero_caverne_Arvais >= 2 && numero_caverne_Hartornen >= 2)
          flag_mappa_cunicoli = 1;
        else (flag_mappa_cunicoli = 0);
        printf("RIGA 678. flag_mappa_cunicoli: %d\n", flag_mappa_cunicoli);
        //sleep(5);
     } while(flag_chiudi_cunicolo == 0); /////////////////////////////////////////////////////////////////////////////////
   return (flag_mappa_cunicoli);
  }

  /****************************************************** FINE CREA CUNICOLI ****************************************************/

  /****************************************************** INIZIO GIOCA ****************************************************/

int gioca (void)
  {
    short int flag_morte_Arvais = 0; //Mettila a 1 quando muore Arvais
    short int flag_morte_Hartornen = 0; //Mettila a 1 quando muore Hartornen
    short int esci = 0; //Mettila a 1 qualcuno vuole uscire
    short int probabilita_incontro = 0; //Probabilita' che le due trivelle si incontrino
    short int rand_1 = 0;

    srand ((unsigned) time(&t));

    for (int i = 1; flag_morte_Arvais == 0 && flag_morte_Hartornen == 0 && esci == 0; i++)
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
            if (rand()%100 <= 49)
              {
                system("clear");
                blu();
                printfile("Vince_Arvais.txt");
                green();
                sleep(3);
                break;
              }
            else
              {
                system("clear");
                blu();
                printfile("Vince_Hartornen.txt");
                green();
                sleep(3);
                break;
              }
          }
        if (i%2 == 0) //Se pari gioco con Arvais, senno' con l'altro
          {
            printfile("Gioca_Arvais.txt");
            blu();
            printf("STAI GIOCANDO CON ARVAIS!\n");
            green();
            printf("Inserisci 1 per dire che sei morto: ");
            scanf("%hd",&flag_morte_Arvais);
          }
        else //Turno Hartornen
          {
            printfile("Gioca_Hartornen.txt");
            blu();
            printf("STAI GIOCANDO CON HARTORNEN!\n");
            green();
            printf("Inserisci 1 per dire che sei morto: ");
            scanf("%hd",&flag_morte_Hartornen);
          }
        if (flag_morte_Arvais == 0)
          {
            system("clear");
            print_lampeggio_gameover();
            printfile("Vince_Arvais.txt");
            sleep(3);
            green();
          }
        else if (flag_morte_Hartornen == 0)
          {
            system("clear");
            print_lampeggio_gameover();
            printfile("Vince_Hartornen.txt");
            green();
          }
      }
    return (0);
  }

  /****************************************************** FINE GIOCA ****************************************************/

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
