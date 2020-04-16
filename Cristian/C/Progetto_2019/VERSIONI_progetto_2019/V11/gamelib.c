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
*
* GUARDA SE METTENDO flag_mappa_cunicoli DI QUESTO FILE A EXTERN LIVELLO GLOBALE POSSO ELIMINARE flag_mappa_cunicoli DAL
* FILE main.c;
**********************************************************************************************************************/

//RICORDATI CHE LA PRIMA VOLTA CHE ABBATTI DEVI ELIMINARE ANCHE LE ALTRE CELLE DEL PERCORSO CHE RIMARREBBERO E NON SOLO QUELLA PRECEDENTE
//HO INSERITO QUESTA FUNZIONE MA MI STA CREANDO PROBLEMI:   elimina_tutte_caverne
//RICORDATI DI RIMETTERE IL SERBATOIO DI ENENERGIA, ALLA PARTENZA, A 4 E NO 2

/**********************************************************************************************************************
* Ho messo che ad ogni turno, anche se non si avanza, la probabilità di incontro fra le due trivelle aumenta del 2%
* e non del 3% senno' il gioco durava troppo poco.
*
* Ho deciso che, se i due giocatori si dovessero incontrare, lanciano una moneta e la probablitita' decide il vincitore
*
* Nella prima grotta che creo ho impostato in automatico tutte le variabili a "normali" quindi sembrera', durante la
* creazione dei cunicoli, saltare questa prima grotta.
*
* Ho messo un imprevisto crollo random del 25%. Se capita deve usare aggira. Se imvece capita una caverna con
* imprevisto == crollo allora toglie semplicemente una unita' di melassa e al turno seguente puo' proseguire con avanza
*
* Ho deciso che se trovo l'uscita abbattendo il muro posso, solo nel turno successivo, usare la funzione uscita.
*
* Ho deciso che al massimo si possono creare 20 caverne iniziali
**********************************************************************************************************************/

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
struct Scavatrice *pPrimo_Arvais_scavatrice;
struct Scavatrice *pPrimo_Hartornen_scavatrice;
struct Scavatrice *pUltimo_Arvais_scavatrice;
struct Scavatrice *pUltimo_Hartornen_scavatrice;

//VARIABILI IN CREA CUNICOLI
static short int scelta_personaggio = 0;
static short int flag_mappa_cunicoli_Arvais = 0;
static short int flag_mappa_cunicoli_Hartornen = 0;
static short int flag_chiudi_cunicolo = 0;
static short int numero_caverne_Arvais = 0;
static short int numero_caverne_Hartornen = 0;

//VARIABILI IN GIOCA
static short int flag_morte_Arvais = 0;
static short int flag_morte_Hartornen = 0;
static short int flag_uscita_Arvais = 0;
static short int flag_uscita_Hartornen = 0;
static short int flag_possibile_uscita_Arvais = 0;
static short int flag_possibile_uscita_Hartornen = 0;
static short int flag_morte_giocatore = 0; //MI SA CHE PUO' ESSERE ELIMINATA
static short int flag_errore_mossa = 0;
static short int flag_crollo_Arvais = 0;
static short int flag_crollo_Hartornen = 0;
static short int flag_abbatti_Arvais = 0;
static short int flag_abbatti_Hartornen = 0;
static short int serbatoio_energia_Arvais = 4; //Puo andare da 0 a 4
static short int serbatoio_raccolta_Arvais = 0;  //Puo andare da 0 a 10
static short int serbatoio_energia_Hartornen = 4; //Puo andare da 0 a 4
static short int serbatoio_raccolta_Hartornen = 0; //Puo andare da 0 a 10
static short int last_direzione_Arvais = 0;
static short int direzione_Arvais = 0;
static short int last_direzione_Hartornen = 0;
static short int direzione_Hartornen = 0;

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
        printf("RIGA 184 INIZIO PRINT. pPrimo_chiamata: %p\n",pPrimo_chiamata);
        printf("RIGA 184 INIZIO PRINT. pUltimo_Arvais_caverna: %p\n",pUltimo_Arvais_caverna);
        printf("RIGA 184 INIZIO PRINT. pUltimo_Hartornen_caverna: %p\n",pUltimo_Hartornen_caverna);
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

            //DOPO ELIMINA QUESTE RIGHE
            //printf("RIGA 215. pPrimo -> sinistra: %p\n",pPrimo -> sinistra);
            //printf("RIGA 215. pPrimo -> destra: %p\n",pPrimo -> destra);
            //printf("RIGA 215. pPrimo -> avanti: %p\n",pPrimo -> avanti);

            blu(); printf("PASSAGGIO DISPONIBILE A : "); green();
            if (pPrimo -> sinistra != NULL)
              {
                printf("SINISTRA\n");
                pScan = pPrimo -> sinistra;
                printf("RIGA 218. pPrimo -> sinistra: %p\n",pPrimo -> sinistra);
              }
            else if (pPrimo -> destra != NULL)
              {
                pScan = pPrimo -> destra;
                printf("DESTRA\n\n");
                printf("RIGA 224. pPrimo -> destra: %p\n",pPrimo -> destra);
              }
            else if (pPrimo -> avanti != NULL)
              {
                pScan = pPrimo -> avanti;
                printf("AVANTI\n");
                printf("RIGA 230. pPrimo -> avanti: %p\n",pPrimo -> avanti);
              }
            else
              {
                pScan = NULL;
                printf("NESSUNA PARTE...LA CAVERNA E' SENZA USCITA!\n");
                printf("RIGA 242. pPrimo -> sinistra: %p\n",pPrimo -> sinistra);
                printf("RIGA 242. pPrimo -> destra: %p\n",pPrimo -> destra);
                printf("RIGA 242. pPrimo -> avanti: %p\n",pPrimo -> avanti);
              }

            pPrimo = pScan;
            a++;
            //SE VUOI INSERISCI FUNZIONE CHE NON FA STAMPARE LA FRECCIA PER LA GROTTA DI PARTENZA, BASTA NON STAMPARLA PER COUNT = 0 o 1;
            printf("\n          |\n"
                   "          |\n"
                   "          v\n\n");
            //pScan = pScan -> pSuccessivo; //Aggiorno il puntatore per passare alla lista successiva
          } while(pScan != NULL); //Se trova NULL è arrivato all'ultima grotta
        printf("RIGA 256. FINE PRINT. pPrimo_chiamata: %p\n",pPrimo_chiamata);
        printf("RIGA 256. FINE PRINT. pUltimo_Arvais_caverna: %p\n",pUltimo_Arvais_caverna);
        printf("RIGA 256 INIZIO PRINT. pUltimo_Hartornen_caverna: %p\n",pUltimo_Hartornen_caverna);
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

        printf("RIGA 304 pPrimo_Arvais_caverna: %p\n",pPrimo_Arvais_caverna);
        printf("RIGA 304 pPrimo_Hartornen_caverna: %p\n",pPrimo_Hartornen_caverna);
        printf("RIGA 304 pUltimo_Arvais_caverna: %p\n",pUltimo_Arvais_caverna);
        printf("RIGA 304 pUltimo_Hartornen_caverna: %p\n",pUltimo_Hartornen_caverna);
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
        if (scelta_personaggio == 2 && flag_mappa_cunicoli_Hartornen == 1) //Se ho gia costruito le caverne minime per Hartornen
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
            numero_caverne_Arvais = count (pPrimo_Arvais_caverna);

            if (numero_caverne_Arvais == 0)
              {
                printfile("Inserisci_cunicoli_Arvais.txt");
                blu();
                printf("DEVI INSERIRE ALMENO 10 CAVERNE (E MENO DI 20)!\n");
                printf("QUANTE CAVERNE VUOI INSERIRE?\n\nNUMERO CAVERNE DA INSERIRE: ");
                green();
                while (scanf("%hd",&numero_caverne) != 1 || numero_caverne < 2 || numero_caverne > 20) /////////////// rimetti  numero_caverne < 10
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
                last_direzione_Arvais = direzione_Arvais;

                struct Caverna *primo_cunicolo_Arvais = (struct Caverna*) malloc(sizeof(struct Caverna)); //Fornisco l'indirizzo di partenza

                printf("RIGA 356. PRIMA CELLA primo_cunicolo_Arvais: %p\n", primo_cunicolo_Arvais);
                //sleep(5);

                primo_cunicolo_Arvais -> sinistra      = NULL;
                primo_cunicolo_Arvais -> avanti        = NULL;
                primo_cunicolo_Arvais -> destra        = NULL;

                printfile("Inserisci_cunicoli_Arvais.txt");
                blu();
                printf("IN QUALE DIREZIONE VUOI ANDARE?\n");
                green();

                while (scanf("%hd",&direzione_Arvais) != 1 || direzione_Arvais < 1 || direzione_Arvais > 3)
                  {
                    blu();
                    printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
                    while (getchar() != '\n');
                    green();
                  }

                if (i == 0 && numero_caverne_Arvais == 0) //La prima grotta deve essere "normale" in tutto
                  {
                    printf("RIGA 409. SONO ENTRATO QUI\n");
                    primo_cunicolo_Arvais -> melassa     = nessuna;
                    primo_cunicolo_Arvais -> imprevisto  = nessun_imprevisto;
                    primo_cunicolo_Arvais -> caverna     = normale;
                  }
                else
                  {
                    //FORNISCE LA QUANTITA' DI MELASSA CHE POSSO TROVARE NELLA CAVERNA
                    scelta_quantita_melassa = (rand() %100);
                    //printf ("Scelta quantita melassa: %d\n",scelta_quantita_melassa);
                    //sleep(5);
                    if (scelta_quantita_melassa <= 49)
                        primo_cunicolo_Arvais -> melassa = nessuna;
                    else if (scelta_quantita_melassa > 49 && scelta_quantita_melassa <= 79)
                        primo_cunicolo_Arvais -> melassa = poca;
                    else if (scelta_quantita_melassa > 79 && scelta_quantita_melassa <= 99)
                        primo_cunicolo_Arvais -> melassa = molta;
                    //printf ("primo_cunicolo_Arvais -> melassa: %d\n",primo_cunicolo_Arvais -> melassa);
                    //sleep(5);

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
                    printf("RIGA 433. CELLA primo_cunicolo_Arvais: %p\n", primo_cunicolo_Arvais);
                    printf("RIGA 434. CELLA pPrimo_Arvais_caverna: %p\n",pPrimo_Arvais_caverna);
                    printf("RIGA 435. CELLA pUltimo_Arvais_caverna: %p\n",pUltimo_Arvais_caverna);
                    //sleep(5);
                  }
                else //Se gia era presente un nodo
                  {
      /*              if (i == (numero_caverne - 1))
                      {
                        primo_cunicolo_Arvais -> sinistra      = NULL;
                        primo_cunicolo_Arvais -> avanti        = NULL;
                        primo_cunicolo_Arvais -> destra        = NULL;

                        pUltimo_Arvais_caverna -> sinistra = primo_cunicolo_Arvais -> sinistra;
                        pUltimo_Arvais_caverna -> avanti   = primo_cunicolo_Arvais -> avanti;
                        pUltimo_Arvais_caverna -> destra   = primo_cunicolo_Arvais -> destra;

                        pUltimo_Arvais_caverna = primo_cunicolo_Arvais; //Aggiorno l'indirizzo di pUltimo_Arvais_caverna cosi' che punti all'ultimo elemnto della lista

                        printf("RIGA 436. CELLA primo_cunicolo_Arvais -> sinistra: %p\n", primo_cunicolo_Arvais -> sinistra);
                        printf("RIGA 437. CELLA primo_cunicolo_Arvais -> avanti: %p\n", primo_cunicolo_Arvais -> avanti);
                        printf("RIGA 438. CELLA primo_cunicolo_Arvais -> destra: %p\n", primo_cunicolo_Arvais -> destra);
                        printf("RIGA 438 BIS. CELLA pUltimo_Arvais_caverna %p\n", pUltimo_Arvais_caverna);
                      }
                    else
                      { */
                        printf("RIGA 439. CELLA pPrimo_Arvais_caverna: %p\n",pPrimo_Arvais_caverna);
                        printf("RIGA 439. CELLA pUltimo_Arvais_caverna: %p\n",pUltimo_Arvais_caverna);
                        printf("RIGA 439. CELLA primo_cunicolo_Arvais -> sinistra: %p\n", primo_cunicolo_Arvais -> sinistra);
                        printf("RIGA 440. CELLA primo_cunicolo_Arvais -> avanti: %p\n", primo_cunicolo_Arvais -> avanti);
                        printf("RIGA 441. CELLA primo_cunicolo_Arvais -> destra: %p\n", primo_cunicolo_Arvais -> destra);
                        printf("RIGA 441. CELLA pPrimo_Arvais_caverna: %p\n", pPrimo_Arvais_caverna);
                        if (last_direzione_Arvais == 1) //Se ho scelto sinistra
                          {
                            pUltimo_Arvais_caverna -> sinistra = primo_cunicolo_Arvais; //L'ultimo nodo creato viene messo in coda
                            printf("RIGA 445. CELLA pUltimo_Arvais_caverna -> sinistra: %p\n", pUltimo_Arvais_caverna -> sinistra);
                          }
                        else if (last_direzione_Arvais == 2) //Se ho scelto avanti
                          {
                            pUltimo_Arvais_caverna -> avanti = primo_cunicolo_Arvais; //L'ultimo nodo creato viene messo in coda
                            printf("RIGA 450. CELLA pUltimo_Arvais_caverna -> avanti: %p\n", pUltimo_Arvais_caverna -> avanti);
                          }
                        else if (last_direzione_Arvais == 3) //Se ho scelto destra
                          {
                            pUltimo_Arvais_caverna -> destra = primo_cunicolo_Arvais; //L'ultimo nodo creato viene messo in coda
                            printf("RIGA 455. CELLA pUltimo_Arvais_caverna -> destra: %p\n", pUltimo_Arvais_caverna -> destra);
                          }

                        pUltimo_Arvais_caverna = primo_cunicolo_Arvais; //Aggiorno l'indirizzo di pUltimo_Arvais_caverna cosi' che punti all'ultimo elemnto della lista

                        printf("RIGA 460. CELLA primo_cunicolo_Arvais: %p\n", primo_cunicolo_Arvais);
                        printf("RIGA 461. CELLA pUltimo_Arvais_caverna: %p\n", pUltimo_Arvais_caverna);
                        printf("RIGA 461. CELLA pUltimo_Arvais_caverna -> sinistra: %p\n", pUltimo_Arvais_caverna -> sinistra);
                        printf("RIGA 461. CELLA pUltimo_Arvais_caverna -> avanti: %p\n", pUltimo_Arvais_caverna -> avanti);
                        printf("RIGA 461. CELLA pUltimo_Arvais_caverna -> destra: %p\n", pUltimo_Arvais_caverna -> destra);
                   //}

                    //sleep(5);
                  }
              } //FINE for
            last_direzione_Arvais = direzione_Arvais;
            numero_caverne_Arvais = count (pPrimo_Arvais_caverna);
            printf("RIGA 462. numero_caverne_Arvais: %d\n", numero_caverne_Arvais);

            if (numero_caverne_Arvais >= 2) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// RIMETTI A 10 DOPO
              flag_mappa_cunicoli_Arvais = 1;
            printf("flag_mappa_cunicoli_Arvais: %d\n", flag_mappa_cunicoli_Arvais);
            //sleep(5);
          }

        else //Ho scelto Hartornen
          {
            numero_caverne_Hartornen = count (pPrimo_Hartornen_caverna);

            if (numero_caverne_Hartornen == 0)
              {
                printfile("Inserisci_cunicoli_Hartornen.txt");
                blu();
                printf("DEVI INSERIRE ALMENO 10 CAVERNE (E MENO DI 20)!\n");
                printf("QUANTE CAVERNE VUOI INSERIRE?\n\nNUMERO CAVERNE DA INSERIRE: ");
                green();
                while (scanf("%hd",&numero_caverne) != 1 || numero_caverne < 2 || numero_caverne > 20) /////////////// rimetti  numero_caverne < 10
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
                while (scanf("%hd",&numero_caverne) != 1 || numero_caverne < 1 || numero_caverne > 20) /////////////// rimetti  numero_caverne < 10
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
                last_direzione_Hartornen = direzione_Hartornen;
                struct Caverna *primo_cunicolo_Hartornen = (struct Caverna*) malloc(sizeof(struct Caverna)); //Fornisco l'indirizzo di partenza
                printf("RIGA 508. PRIMA CELLA primo_cunicolo_Hartornen: %p\n", primo_cunicolo_Hartornen);
                //sleep(5);

                primo_cunicolo_Hartornen -> sinistra      = NULL;
                primo_cunicolo_Hartornen -> avanti        = NULL;
                primo_cunicolo_Hartornen -> destra        = NULL;

                printfile("Inserisci_cunicoli_Hartornen.txt");
                blu();
                printf("IN QUALE DIREZIONE VUOI ANDARE?\n");
                green();

                while (scanf("%hd",&direzione_Hartornen) != 1 || direzione_Hartornen < 1 || direzione_Hartornen > 3)
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
                if (pPrimo_Hartornen_caverna == NULL) //Se non ci stavano nodi precedenti
                  {
                    pPrimo_Hartornen_caverna = primo_cunicolo_Hartornen; //Ho appena creato il primo nodo
                    pUltimo_Hartornen_caverna = primo_cunicolo_Hartornen; //Ho appena creato il primo nodo
                    printf("RIGA 581. CELLA primo_cunicolo_Hartornen: %p\n", primo_cunicolo_Hartornen);
                    printf("RIGA 582. CELLA pPrimo_Hartornen_caverna: %p\n",pPrimo_Hartornen_caverna);
                    printf("RIGA 582. CELLA pUltimo_Hartornen_caverna: %p\n",pUltimo_Hartornen_caverna);
                    //sleep(5);
                  }
                else //Se gia era presente un nodo
                  {
    /*                if (i == (numero_caverne - 1))
                      {
                        primo_cunicolo_Hartornen -> sinistra      = NULL;
                        primo_cunicolo_Hartornen -> avanti        = NULL;
                        primo_cunicolo_Hartornen -> destra        = NULL;

                        pUltimo_Hartornen_caverna -> sinistra = primo_cunicolo_Hartornen -> sinistra;
                        pUltimo_Hartornen_caverna -> avanti   = primo_cunicolo_Hartornen -> avanti;
                        pUltimo_Hartornen_caverna -> destra   = primo_cunicolo_Hartornen -> destra;

                        pUltimo_Hartornen_caverna = primo_cunicolo_Hartornen; //Aggiorno l'indirizzo di pUltimo_Arvais_caverna cosi' che punti all'ultimo elemnto della lista

                        printf("RIGA 436. CELLA primo_cunicolo_Hartornen -> sinistra: %p\n", primo_cunicolo_Hartornen -> sinistra);
                        printf("RIGA 437. CELLA primo_cunicolo_Hartornen -> avanti: %p\n", primo_cunicolo_Hartornen -> avanti);
                        printf("RIGA 438. CELLA primo_cunicolo_Hartornen -> destra: %p\n", primo_cunicolo_Hartornen -> destra);
                        printf("RIGA 438 BIS. CELLA pUltimo_Hartornen_caverna %p\n", pUltimo_Hartornen_caverna);
                      }
                    else
                      { */
                        printf("RIGA 587. CELLA primo_cunicolo_Hartornen -> sinistra: %p\n", primo_cunicolo_Hartornen -> sinistra);
                        printf("RIGA 588. CELLA primo_cunicolo_Hartornen -> avanti: %p\n", primo_cunicolo_Hartornen -> avanti);
                        printf("RIGA 589. CELLA primo_cunicolo_Hartornen -> destra: %p\n", primo_cunicolo_Hartornen -> destra);
                        printf("RIGA 589. CELLA pPrimo_Hartornen_caverna: %p\n", pPrimo_Hartornen_caverna);
                        if (last_direzione_Hartornen == 1) //Se ho scelto sinistra
                          {
                            pUltimo_Hartornen_caverna -> sinistra = primo_cunicolo_Hartornen; //Il primo nodo diventa il secondo
                            printf("RIGA 593. CELLA pUltimo_Hartornen_caverna -> sinistra: %p\n", pUltimo_Hartornen_caverna -> sinistra);
                          }
                        else if (last_direzione_Hartornen == 2) //Se ho scelto avanti
                          {
                            pUltimo_Hartornen_caverna -> avanti = primo_cunicolo_Hartornen; //Il primo nodo diventa il secondo
                            printf("RIGA 598. CELLA pUltimo_Hartornen_caverna -> avanti: %p\n", pUltimo_Hartornen_caverna -> avanti);
                          }
                        else if (last_direzione_Hartornen == 3) //Se ho scelto destra
                          {
                            pUltimo_Hartornen_caverna -> destra = primo_cunicolo_Hartornen; //Il primo nodo diventa il secondo
                            printf("RIGA 603. CELLA pUltimo_Hartornen_caverna -> destra: %p\n", pUltimo_Hartornen_caverna -> destra);
                          }

                        pUltimo_Hartornen_caverna = primo_cunicolo_Hartornen; //Aggiorno l'indirizzo di pPrimo_Hartornen_caverna cosi' che punti nuovamente al primo elemnto della lista

                        printf("RIGA 608. CELLA primo_cunicolo_Hartornen: %p\n", primo_cunicolo_Hartornen);
                        printf("RIGA 609. CELLA pUltimo_Hartornen_caverna: %p\n", pUltimo_Hartornen_caverna);
                        printf("RIGA 461. CELLA pUltimo_Hartornen_caverna -> sinistra: %p\n", pUltimo_Hartornen_caverna -> sinistra);
                        printf("RIGA 461. CELLA pUltimo_Hartornen_caverna -> avanti: %p\n", pUltimo_Hartornen_caverna -> avanti);
                        printf("RIGA 461. CELLA pUltimo_Hartornen_caverna -> destra: %p\n", pUltimo_Hartornen_caverna -> destra);
                        //sleep(5);
              //     }

                  }
              } //FINE for
            last_direzione_Hartornen = direzione_Hartornen;
            numero_caverne_Hartornen = count (pPrimo_Hartornen_caverna);

            if (numero_caverne_Hartornen >= 2) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// RIMETTI A 10 DOPO
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

    numero_caverne_Arvais = count (pPrimo_Arvais_caverna);
    numero_caverne_Hartornen = count (pPrimo_Hartornen_caverna);

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

        printf("RIGA 783. STO ENTRANDO NEL FOR.\n");
        for (int i = 0; i < numero_caverne_da_eliminare; i++)
          {
            printf("RIGA 786. SONO ENTRATO NEL FOR.\n");
            if(pPrimo_Arvais_caverna == NULL) //Non sono presenti nodi
              {
                blu();
                printf("NON SONO PRESENTI CAVERNE DA ELIMINARE!\n");
                green();
              }
            else
              {
                /*
                //SE E' PRESENTE ALMENO UNA CAVERNA
                struct Caverna *temp;

                if (pPrimo_Arvais_caverna -> sinistra != NULL)
                    temp = pPrimo_Arvais_caverna -> sinistra;
                else if (pPrimo_Arvais_caverna -> avanti != NULL)
                    temp = pPrimo_Arvais_caverna -> avanti;
                else if (pPrimo_Arvais_caverna -> destra != NULL)
                    temp = pPrimo_Arvais_caverna -> destra;

                free (pPrimo_Arvais_caverna); //Elimino l'ultima caverna creata
                pPrimo_Arvais_caverna = temp; //Aggiorno il puntatore di testa alla caverna successiva
                */


                struct Caverna *pPrecedente_Arvais_caverna = NULL;
                struct Caverna *pScan_4 = pPrimo_Arvais_caverna;

                printf("RIGA 814. pScan_4 -> sinistra: %p\n",pScan_4 -> sinistra);
                printf("RIGA 814. pScan_4 -> destra: %p\n",pScan_4 -> destra);
                printf("RIGA 814. pScan_4 -> avanti: %p\n",pScan_4 -> avanti);

                if ((pScan_4 -> sinistra == NULL) && (pScan_4 -> avanti == NULL) && (pScan_4 -> destra == NULL)) // It means we only have one node in the list
                  {
                    //DOPO ELIMINA QUESTA PARTE
                    printf("RIGA 821. SEI GIA' ARRIVATO IN CIMA ALLA LISTA.\n");
                    return 0;
                  }
                else // Otherwise, I need to scan the list until I find the last node (pLast)
                  {
                    do
                      {
                        printf("RIGA 824. SONO DENTRO L'ELSE, ESISTONO ALMENO DUE NODI\n");
                        if (pScan_4 -> sinistra != NULL)
                          {
                            if ((pScan_4 -> sinistra) == pUltimo_Arvais_caverna) // Reached the node before the end
                              {
                                printf("RIGA 826. pScan_4: %p\n",pScan_4);
                                printf("RIGA 826. pScan_4 -> sinistra: %p\n",pScan_4 -> sinistra);
                                printf("RIGA 826. pUltimo_Arvais_caverna: %p\n",pUltimo_Arvais_caverna);
                                pPrecedente_Arvais_caverna = pScan_4;
                                break;
                              }
                            else pScan_4 = pScan_4 -> sinistra; // Otherwise, I need to iterate
                            printf("RIGA 828. pScan_4: %p\n",pScan_4);
                          }
                        else if (pScan_4 -> avanti != NULL)
                          {
                            if ((pScan_4 -> avanti) == pUltimo_Arvais_caverna) // Reached the node before the end
                              {
                                printf("RIGA 838. pScan_4: %p\n",pScan_4);
                                printf("RIGA 838. pScan_4 -> avanti: %p\n",pScan_4 -> avanti);
                                printf("RIGA 838. pUltimo_Arvais_caverna: %p\n",pUltimo_Arvais_caverna);
                                pPrecedente_Arvais_caverna = pScan_4;
                                break;
                              }
                            else pScan_4 = pScan_4 -> avanti; // Otherwise, I need to iterate
                            printf("RIGA 840. pScan_4: %p\n",pScan_4);
                          }
                        else if (pScan_4 -> destra != NULL)
                          {
                            if ((pScan_4 -> destra) == pUltimo_Arvais_caverna) // Reached the node before the end
                              {
                                printf("RIGA 850. pScan_4: %p\n",pScan_4);
                                printf("RIGA 850. pScan_4 -> destra: %p\n",pScan_4 -> destra);
                                printf("RIGA 850. pUltimo_Arvais_caverna: %p\n",pUltimo_Arvais_caverna);
                                pPrecedente_Arvais_caverna = pScan_4;
                                break;
                              }
                            else pScan_4 = pScan_4 -> destra; // Otherwise, I need to iterate
                            printf("RIGA 852. pScan_4: %p\n",pScan_4);
                          }
                        printf("RIGA 855. SONO IN FONDO AL WHILE\n");
                  } while((pScan_4 -> sinistra != NULL) || (pScan_4 -> destra != NULL) || (pScan_4 -> avanti != NULL));

                      printf("RIGA 860. SONO USCITO DAL WHILE\n");
                      if (pScan_4 -> sinistra != NULL)
                        {
                          printf("RIGA 865. SONO ARRIVATO QUI\n");
                          printf("RIGA 865. pPrecedente_Arvais_caverna: %p\n", pPrecedente_Arvais_caverna);
                          printf("RIGA 865. pPrecedente_Arvais_caverna -> sinistra: %p\n", pPrecedente_Arvais_caverna -> sinistra);
                          printf("RIGA 865. pPrecedente_Arvais_caverna -> avanti: %p\n", pPrecedente_Arvais_caverna -> avanti);
                          printf("RIGA 865. pPrecedente_Arvais_caverna -> destra: %p\n", pPrecedente_Arvais_caverna -> destra);
                          free (pPrecedente_Arvais_caverna -> sinistra); // Free memory allocated to the last node
                          pPrecedente_Arvais_caverna -> sinistra = NULL; // pPrev becomes the last node (no node after it)
                          printf("RIGA 865. pPrecedente_Arvais_caverna: %p\n",pPrecedente_Arvais_caverna);
                        }
                      else if (pScan_4 -> avanti != NULL)
                        {
                          printf("RIGA 871. SONO ARRIVATO QUI\n");
                          printf("RIGA 871. pPrecedente_Arvais_caverna: %p\n", pPrecedente_Arvais_caverna);
                          printf("RIGA 871. pPrecedente_Arvais_caverna -> sinistra: %p\n", pPrecedente_Arvais_caverna -> sinistra);
                          printf("RIGA 871. pPrecedente_Arvais_caverna -> avanti: %p\n", pPrecedente_Arvais_caverna -> avanti);
                          printf("RIGA 871. pPrecedente_Arvais_caverna -> destra: %p\n", pPrecedente_Arvais_caverna -> destra);
                          free (pPrecedente_Arvais_caverna -> avanti); // Free memory allocated to the last node
                          pPrecedente_Arvais_caverna -> avanti = NULL; // pPrev becomes the last node (no node after it)
                          printf("RIGA 871. pPrecedente_Arvais_caverna: %p\n",pPrecedente_Arvais_caverna);
                        }
                      else if (pScan_4 -> destra != NULL)
                        {
                          printf("RIGA 877. SONO ARRIVATO QUI\n");
                          printf("RIGA 877. pPrecedente_Arvais_caverna: %p\n", pPrecedente_Arvais_caverna);
                          printf("RIGA 877. pPrecedente_Arvais_caverna -> sinistra: %p\n", pPrecedente_Arvais_caverna -> sinistra);
                          printf("RIGA 877. pPrecedente_Arvais_caverna -> avanti: %p\n", pPrecedente_Arvais_caverna -> avanti);
                          printf("RIGA 877. pPrecedente_Arvais_caverna -> destra: %p\n", pPrecedente_Arvais_caverna -> destra);
                          free (pPrecedente_Arvais_caverna -> destra); // Free memory allocated to the last node
                          pPrecedente_Arvais_caverna -> destra = NULL; // pPrev becomes the last node (no node after it)
                          printf("RIGA 877. pPrecedente_Arvais_caverna: %p\n",pPrecedente_Arvais_caverna);
                        }

                      printf("RIGA 894. SONO ARRIVATO QUI\n");
                      pUltimo_Arvais_caverna = pPrecedente_Arvais_caverna;
                      // pPrev becomes the last node
                      printf("RIGA 882. pUltimo_Arvais_caverna: %p\n",pUltimo_Arvais_caverna);
                  }
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

        printf("RIGA 916. STO PER ENTRARE NEL FOR\n");
        for (int i = 0; i < numero_caverne_da_eliminare; i++)
          {
            printf("RIGA 920. SONO ENTRATO NEL FOR\n");
            if(pPrimo_Hartornen_caverna == NULL) //Non sono presenti nodi
              {
                blu();
                printf("NON SONO PRESENTI CAVERNE DA ELIMINARE!\n");
                green();
              }
            else
              {
                /*
                //SE E' PRESENTE ALMENO UNA CAVERNA
                struct Caverna *temp;

                if (pPrimo_Hartornen_caverna -> sinistra != NULL)
                    temp = pPrimo_Hartornen_caverna -> sinistra;
                else if (pPrimo_Hartornen_caverna -> avanti != NULL)
                    temp = pPrimo_Hartornen_caverna -> avanti;
                else if (pPrimo_Hartornen_caverna -> destra != NULL)
                    temp = pPrimo_Hartornen_caverna -> destra;

                free (pPrimo_Hartornen_caverna); //Elimino l'ultima caverna creata
                pPrimo_Hartornen_caverna = temp; //Aggiorno il puntatore di testa alla caverna successiva
                */

                struct Caverna *pPrecedente_Hartornen_caverna = NULL;
                struct Caverna *pScan_4 = pPrimo_Hartornen_caverna;
                printf("RIGA 944. pScan_4 -> sinistra: %p\n",pScan_4 -> sinistra);
                printf("RIGA 944. pScan_4 -> destra: %p\n",pScan_4 -> destra);
                printf("RIGA 944. pScan_4 -> avanti: %p\n",pScan_4 -> avanti);
                if ((pScan_4 -> sinistra != NULL) && (pScan_4 -> destra != NULL) && (pScan_4 -> avanti != NULL)) // It means we only have one node in the list
                  {
                    //DOPO ELIMINA QUESTA PARTE
                    printf("RIGA 814. SEI GIA' ARRIVATO IN CIMA ALLA LISTA.\n");
                    return 0;
                  }
                else // Otherwise, I need to scan the list until I find the last node (pLast)
                  {
                    do
                      {
                        if (pScan_4 -> sinistra != NULL)
                          {
                            if ((pScan_4 -> sinistra) == pUltimo_Hartornen_caverna) // Reached the node before the end
                              {
                                printf("RIGA 952. pScan_4: %p\n",pScan_4);
                                printf("RIGA 952. pScan_4 -> sinistra: %p\n",pScan_4 -> sinistra);
                                printf("RIGA 952. pUltimo_Hartornen_caverna: %p\n",pUltimo_Hartornen_caverna);
                                pPrecedente_Hartornen_caverna = pScan_4;
                                break;
                              }
                            else pScan_4 = pScan_4 -> sinistra; // Otherwise, I need to iterate
                          }
                        else if (pScan_4 -> avanti != NULL)
                          {
                            if ((pScan_4 -> avanti) == pUltimo_Hartornen_caverna) // Reached the node before the end
                              {
                                printf("RIGA 964. pScan_4: %p\n",pScan_4);
                                printf("RIGA 964. pScan_4 -> avanti: %p\n",pScan_4 -> avanti);
                                printf("RIGA 964. pUltimo_Hartornen_caverna: %p\n",pUltimo_Hartornen_caverna);
                                pPrecedente_Hartornen_caverna = pScan_4;
                                break;
                              }
                            else pScan_4 = pScan_4 -> avanti; // Otherwise, I need to iterate
                          }
                        else if (pScan_4 -> destra != NULL)
                          {
                            if ((pScan_4 -> destra) == pUltimo_Hartornen_caverna) // Reached the node before the end
                              {
                                printf("RIGA 964. pScan_4: %p\n",pScan_4);
                                printf("RIGA 964. pScan_4 -> destra: %p\n",pScan_4 -> destra);
                                printf("RIGA 964. pUltimo_Hartornen_caverna: %p\n",pUltimo_Hartornen_caverna);
                                pPrecedente_Hartornen_caverna = pScan_4;
                                break;
                              }
                            else pScan_4 = pScan_4 -> destra; // Otherwise, I need to iterate
                          }
                      } while(pScan_4 -> sinistra != NULL || pScan_4 -> destra != NULL || pScan_4 -> avanti != NULL);

                      printf("RIGA 986. SONO USCITO DAL WHILE\n");
                      if (pScan_4 -> sinistra != NULL)
                        {
                          free (pPrecedente_Hartornen_caverna -> sinistra); // Free memory allocated to the last node
                          pPrecedente_Hartornen_caverna -> sinistra = NULL; // pPrev becomes the last node (no node after it)
                          printf("RIGA 991. pPrecedente_Hartornen_caverna: %p\n",pPrecedente_Hartornen_caverna);
                        }
                      else if (pScan_4 -> avanti != NULL)
                        {
                          free (pPrecedente_Hartornen_caverna -> avanti); // Free memory allocated to the last node
                          pPrecedente_Hartornen_caverna -> avanti = NULL; // pPrev becomes the last node (no node after it)
                          printf("RIGA 997. pPrecedente_Hartornen_caverna: %p\n",pPrecedente_Hartornen_caverna);
                        }
                      else if (pScan_4 -> destra != NULL)
                        {
                          free (pPrecedente_Hartornen_caverna -> destra); // Free memory allocated to the last node
                          pPrecedente_Hartornen_caverna -> destra = NULL; // pPrev becomes the last node (no node after it)
                          printf("RIGA 1003. pPrecedente_Hartornen_caverna: %p\n",pPrecedente_Hartornen_caverna);
                        }

                    pUltimo_Hartornen_caverna = pPrecedente_Hartornen_caverna;
                    // pPrev becomes the last node
                    printf("RIGA 1008. pUltimo_Hartornen_caverna: %p\n",pUltimo_Hartornen_caverna);
                  }
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

    numero_caverne_Arvais = count (pPrimo_Arvais_caverna);
    numero_caverne_Hartornen = count (pPrimo_Hartornen_caverna);

    if (numero_caverne_Arvais < 2) //////////////////////////////////////////////////////////////////////////////////////////////////// RIMETTI 10 DOPO
      flag_mappa_cunicoli_Arvais = 0;
    if (numero_caverne_Hartornen < 2) //////////////////////////////////////////////////////////////////////////////////////////////////// RIMETTI 10 DOPO
      flag_mappa_cunicoli_Hartornen = 0;

    printf("RIGA 1030. fine cancella caverna\n");
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
        print_list (pPrimo_Arvais_caverna);
        blu();
        printf ("LA MAPPA SI CHIUDERA' FRA 15 SECONDI\n");
        sleep(15);
        green();
      }
    else
      {
        printfile("Stampa_cunicoli_Hartornen.txt");
        print_list (pPrimo_Hartornen_caverna);
        blu();
        printf ("LA MAPPA SI CHIUDERA' FRA 15 SECONDI\n");
        sleep(15);
        green();
      }
    return;
  }

/************************************************ FINE STAMPA CAVERNA **********************************************************************/

/******************************************** INIZIO CONTROLLO SERBATOI ***************************************************************************/

/*
void controllo_serbatoio_energia_raccolta (struct Scavatrice *pPersonaggio)
  {
    if (pPersonaggio -> serbatoio_raccolta > 10 && pPersonaggio -> serbatoio_energia == 4)
      pPersonaggio -> serbatoio_raccolta = 10;
    else if (pPersonaggio -> serbatoio_raccolta > 10 && pPersonaggio -> serbatoio_energia < 4)
      {
        pPersonaggio -> serbatoio_energia = pPersonaggio -> serbatoio_energia + ((pPersonaggio -> serbatoio_raccolta) - 10);
        blu(); printf("E' STATA EFFETTUATA LA RICARICA AUTOMATICA AL SERBATOIO DI ENERGIA\nPERCHE' HAI RIEMPITO IL SERBATOIO DI RACCOLTA MELASSA!\n");
        sleep(3);
      }

    if (pPersonaggio -> serbatoio_energia > 4)
      pPersonaggio -> serbatoio_energia = 4;

    if (pPersonaggio -> serbatoio_energia < 0) //Setto il flag morte personaggio
      flag_morte_giocatore = 1;
    return;
  }
*/
void controllo_serbatoio_energia_raccolta ()
  {
    //Arvais

    if (serbatoio_raccolta_Arvais > 10 && serbatoio_energia_Arvais == 4)
      serbatoio_raccolta_Arvais = 10;
    else if (serbatoio_raccolta_Arvais > 10 && serbatoio_energia_Arvais < 4)
      {
        serbatoio_energia_Arvais = serbatoio_energia_Arvais + serbatoio_raccolta_Arvais - 10;
        blu(); printf("E' STATA EFFETTUATA LA RICARICA AUTOMATICA AL SERBATOIO DI ENERGIA\nPERCHE' HAI RIEMPITO IL SERBATOIO DI RACCOLTA MELASSA!\n"); green();
        sleep(3);
      }

    if (serbatoio_energia_Arvais > 4)
      serbatoio_energia_Arvais = 4;

    if (serbatoio_energia_Arvais < 0)
      flag_morte_Arvais = 1;

    //Hartornen

    if (serbatoio_raccolta_Hartornen > 10 && serbatoio_energia_Hartornen == 4)
      serbatoio_raccolta_Hartornen = 10;
    else if (serbatoio_raccolta_Hartornen > 10 && serbatoio_energia_Hartornen < 4)
      {
        serbatoio_energia_Hartornen = serbatoio_energia_Hartornen + serbatoio_raccolta_Hartornen - 10;
        blu(); printf("E' STATA EFFETTUATA LA RICARICA AUTOMATICA AL SERBATOIO DI ENERGIA\nPERCHE' HAI RIEMPITO IL SERBATOIO DI RACCOLTA MELASSA!\n"); green();
        sleep(3);
      }

    if (serbatoio_energia_Hartornen > 4)
      serbatoio_energia_Hartornen = 4;

    if (serbatoio_energia_Hartornen < 0)
      flag_morte_Hartornen = 1;

    printf("RIGA 901. serbatoio_energia_Arvais: %d\n",serbatoio_energia_Arvais);
    printf("RIGA 902. serbatoio_raccolta_Arvais: %d\n",serbatoio_raccolta_Arvais);
    printf("RIGA 903. serbatoio_energia_Hartornen: %d\n",serbatoio_energia_Hartornen);
    printf("RIGA 904. serbatoio_raccolta_Hartornen: %d\n",serbatoio_raccolta_Hartornen);
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
        sleep(3);
        flag_errore_mossa = 1;
      }
    else
      {
        if (((i%2 == 0 && flag_crollo_Arvais == 0 && flag_abbatti_Arvais == 0) || (i%2 == 1 && flag_crollo_Hartornen == 0 && flag_abbatti_Hartornen == 0)) && (pAvanza -> sinistra != NULL || pAvanza -> avanti != NULL || pAvanza -> destra != NULL))
          {
            //PROBABILITA' CROLLO IMPROVVISO
            rand_probabilita_crollo = rand()%100;
            printf("rand_probabilita_crollo: %d\n", rand_probabilita_crollo);

            //Se vuoi aggiungi (pPrimo_Arvais_caverna != NULL || pPrimo_Hartornen_caverna != NULL) servono ad escludere i casi in cui mi trovo di fronte a pPrimo = NULL e si verifica il crollo. anche se non dovrebbe mai succede
            if (rand_probabilita_crollo < 24 && i != 1 && i != 2) //i!= 1 o 2 perchè non deve accadere durante il primo turno
              {
                blu(); printf("SI E' VERIFICATO UN CROLLO IMPROVVISO\nPROVA A RAGGIRARE L'OSTACOLO!\n\n"); green();
                if (i%2 == 0)
                  flag_crollo_Arvais = 1;
                else flag_crollo_Hartornen = 1;
                flag_errore_mossa = 1;
                sleep(3);
                return 0;
              }
          }

        //SE E' PRESENTE ALMENO UNA CAVERNA DAVANTI
        struct Caverna *temp;

        printf("RIGA 860. pAvanza: %p\n", pAvanza);
        printf("RIGA 860. pAvanza -> sinistra: %p\n", pAvanza -> sinistra);
        printf("RIGA 860. pAvanza -> avanti: %p\n"  , pAvanza -> avanti);
        printf("RIGA 860. pAvanza -> destra: %p\n"  , pAvanza -> destra);

        if (pAvanza -> sinistra != NULL)
          temp = pAvanza -> sinistra;
        else if (pAvanza -> avanti != NULL)
          temp = pAvanza -> avanti;
        else if (pAvanza -> destra != NULL)
          temp = pAvanza -> destra;
        else
          {
            temp = NULL;
            printf("RIGA 864. temp = NULL\n");
          }
        free (pAvanza); //Elimino l'ultima caverna creata
        pAvanza = temp; //Aggiorno il puntatore di testa alla caverna successiva
        printf("RIGA 866. pAvanza: %p\n", pAvanza);
        printf("RIGA 867. SONO ARRIVATO QUI\n");
        printf("RIGA 868. pAvanza: %p\n", pAvanza);
        printf("RIGA 868. pAvanza -> sinistra: %p\n", pAvanza -> sinistra);
        printf("RIGA 868. pAvanza -> avanti: %p\n"  , pAvanza -> avanti);
        printf("RIGA 868. pAvanza -> destra: %p\n"  , pAvanza -> destra);
        sleep(3);
        //pPersonaggio -> pCaverna = pAvanza;
        printf("RIGA 869. SONO ARRIVATO QUI\n");

        //DOPO ELIMINA QUESTO CAMPO/////////////////////////////////////////////////////////////////////////////////////////////////
        //print_list (pAvanza);

        printf("RIGA 870. pAvanza: %p\n", pAvanza);
        printf("RIGA 870. pAvanza -> sinistra: %p\n", pAvanza -> sinistra);
        printf("RIGA 870. pAvanza -> avanti: %p\n"  , pAvanza -> avanti);
        printf("RIGA 870. pAvanza -> destra: %p\n"  , pAvanza -> destra);

        printf("RIGA 870 BIS. pAvanza -> caverna: %d\n", pAvanza -> caverna);

        //STATO CAVERNA
        blu(); printf("SEI ENTRATO IN UNA CAVERNA "); green();
        if (flag_possibile_uscita_Arvais == 0 && i%2 == 0)
          {
            if (pAvanza -> caverna == normale)
              {
                printf("NORMALE");
                blu();
                printf("!\n");
                green();
                sleep(2);
              }
            else if (pAvanza -> caverna == speciale)
              {
                printf("SPECIALE "); blu();
                printf("QUINDI GUADAGNI 1 UNITA' DI ENERGIA!\n"); green();

                if (i%2 == 0)
                  {
                    printf("PRIMA INCREMENTO. serbatoio_energia_Arvais: %d\n", serbatoio_energia_Arvais);
                    serbatoio_energia_Arvais++;
                    printf("DOPO INCREMENTO. serbatoio_energia_Arvais: %d\n", serbatoio_energia_Arvais);
                  }
                else
                  {
                    printf("PRIMA INCREMENTO. serbatoio_energia_Hartornen: %d\n", serbatoio_energia_Hartornen);
                    serbatoio_energia_Hartornen++;
                    printf("DOPO INCREMENTO. serbatoio_energia_Hartornen: %d\n", serbatoio_energia_Hartornen);
                  }

                printf("RIGA 887. SONO ARRIVATO QUI\n");
                sleep(3);
              }
            else if (pAvanza -> caverna == accidentata)
              {
                printf("ACCIDENTATA "); blu();
                printf("QUINDI PERDI 1 UNITA' DI ENERGIA!\n"); green();

                if (i%2 == 0)
                  {
                    printf("PRIMA DECREMENTO. serbatoio_energia_Arvais: %d\n", serbatoio_energia_Arvais);
                    serbatoio_energia_Arvais--;
                    printf("DOPO DECREMENTO. serbatoio_energia_Arvais: %d\n", serbatoio_energia_Arvais);
                  }
                else
                  {
                    printf("PRIMA DECREMENTO. serbatoio_energia_Hartornen: %d\n", serbatoio_energia_Hartornen);
                    serbatoio_energia_Hartornen--;
                    printf("DOPO DECREMENTO. serbatoio_energia_Hartornen: %d\n", serbatoio_energia_Hartornen);
                  }

                sleep(3);
              }

            controllo_serbatoio_energia_raccolta ();
            if (flag_morte_Hartornen == 1 || flag_morte_Arvais == 1)
              {
                blu();
                printf("HAI ESAURITO L'ENERGIA E, NON AVENDO PIU' LUCE, TI PERDI FRA I CUNICOLI E MUORI...\n");
                green();
                sleep(3);
                return 0;
              }
          }
        else if (flag_possibile_uscita_Arvais == 1 && i%2 == 0)
          {
            blu(); printf("DI TIPO "); green(); printf("USCITA"); blu(); printf("!\n"); green();
          }
        else if (flag_possibile_uscita_Hartornen == 0 && i%2 == 1)
          {
            if (pAvanza -> caverna == normale)
              {
                printf("NORMALE");
                blu();
                printf("!\n");
                green();
                sleep(2);
              }
            else if (pAvanza -> caverna == speciale)
              {
                printf("SPECIALE "); blu();
                printf("QUINDI GUADAGNI 1 UNITA' DI ENERGIA!\n"); green();

                //DOPO ELIMINA QUESTO IF PERCHE SEI GIA DENTRO TRAMITE I. LASCIA SOLO UNA DELLE DUE SCELTE
                if (i%2 == 0)
                  {
                    printf("PRIMA INCREMENTO. serbatoio_energia_Arvais: %d\n", serbatoio_energia_Arvais);
                    serbatoio_energia_Arvais++;
                    printf("DOPO INCREMENTO. serbatoio_energia_Arvais: %d\n", serbatoio_energia_Arvais);
                  }
                else
                  {
                    printf("PRIMA INCREMENTO. serbatoio_energia_Hartornen: %d\n", serbatoio_energia_Hartornen);
                    serbatoio_energia_Hartornen++;
                    printf("DOPO INCREMENTO. serbatoio_energia_Hartornen: %d\n", serbatoio_energia_Hartornen);
                  }

                printf("RIGA 916. SONO ARRIVATO QUI\n");
                sleep(3);
              }
            else if (pAvanza -> caverna == accidentata)
              {
                printf("ACCIDENTATA "); blu();
                printf("QUINDI PERDI 1 UNITA' DI ENERGIA!\n"); green();

                //DOPO ELIMINA QUESTO IF PERCHE SEI GIA DENTRO TRAMITE I. LASCIA SOLO UNA DELLE DUE SCELTE
                if (i%2 == 0)
                  {
                    printf("PRIMA DECREMENTO. serbatoio_energia_Arvais: %d\n", serbatoio_energia_Arvais);
                    serbatoio_energia_Arvais--;
                    printf("DOPO DECREMENTO. serbatoio_energia_Arvais: %d\n", serbatoio_energia_Arvais);
                  }
                else
                  {
                    printf("PRIMA DECREMENTO. serbatoio_energia_Hartornen: %d\n", serbatoio_energia_Hartornen);
                    serbatoio_energia_Hartornen--;
                    printf("DOPO DECREMENTO. serbatoio_energia_Hartornen: %d\n", serbatoio_energia_Hartornen);
                  }

                printf("RIGA 924. SONO ARRIVATO QUI\n");
                sleep(3);
              }

            controllo_serbatoio_energia_raccolta ();
            if (flag_morte_Hartornen == 1 || flag_morte_Arvais == 1)
              {
                blu();
                printf("HAI ESAURITO L'ENERGIA E, NON AVENDO PIU' LUCE, TI PERDI FRA I CUNICOLI E MUORI...\n");
                green();
                sleep(3);
                return 0;
              }
          }
        else if (flag_possibile_uscita_Hartornen == 1 && i%2 == 1)
          {
            blu(); printf("DI TIPO "); green(); printf("USCITA"); blu(); printf("!\n"); green();
          }

          //QUANTITA' MELASSA CAVERNA
          if (pAvanza -> melassa == nessuna)
            {
              blu(); printf("\n\nSTAI ESPLORANDO LA CAVERNA MA SEMBRA NON ESSERCI MELASSA\n");
              green();
              sleep(3);
            }
          else if (pAvanza -> melassa == poca || pAvanza -> melassa == molta)
            {
              blu(); printf("\n\nSTAI ESPLORANDO LA CAVERNA QUANDO TROVI "); green(); printf("%d ",pAvanza -> melassa); blu(); printf("UNITA' DI MELASSA!\n");
              green();
              sleep(3);

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

              if (i%2 == 0 && pAvanza -> melassa == poca)
                {
                  if (scelta_serbatoio == 1)
                    {
                      printf("PRIMA INCREMENTO. serbatoio_energia_Arvais: %d\n", serbatoio_energia_Arvais);
                      serbatoio_energia_Arvais++;
                      printf("DOPO INCREMENTO. serbatoio_energia_Arvais: %d\n", serbatoio_energia_Arvais);
                    }
                  else
                    {
                      printf("PRIMA INCREMENTO. serbatoio_raccolta_Arvais: %d\n", serbatoio_raccolta_Arvais);
                      serbatoio_raccolta_Arvais++;
                      printf("DOPO INCREMENTO. serbatoio_raccolta_Arvais: %d\n", serbatoio_raccolta_Arvais);
                    }
                }
              else if (i%2 == 0 && pAvanza -> melassa == molta)
                {
                  if (scelta_serbatoio == 1)
                    {
                      printf("PRIMA INCREMENTO. serbatoio_energia_Arvais: %d\n", serbatoio_energia_Arvais);
                      serbatoio_energia_Arvais = serbatoio_energia_Arvais + 3;
                      printf("DOPO INCREMENTO. serbatoio_energia_Arvais: %d\n", serbatoio_energia_Arvais);
                    }
                  else
                    {
                      printf("PRIMA INCREMENTO. serbatoio_raccolta_Arvais: %d\n", serbatoio_raccolta_Arvais);
                      serbatoio_raccolta_Arvais = serbatoio_raccolta_Arvais + 3;
                      printf("DOPO INCREMENTO. serbatoio_raccolta_Arvais: %d\n", serbatoio_raccolta_Arvais);
                    }
                }
              else if (i%2 == 1 && pAvanza -> melassa == poca)
                {
                  if (scelta_serbatoio == 1)
                    {
                      printf("PRIMA INCREMENTO. serbatoio_energia_Hartornen: %d\n", serbatoio_energia_Hartornen);
                      serbatoio_energia_Hartornen++;
                      printf("DOPO INCREMENTO. serbatoio_energia_Hartornen: %d\n", serbatoio_energia_Hartornen);
                    }
                  else
                    {
                      printf("PRIMA INCREMENTO. serbatoio_raccolta_Hartornen: %d\n", serbatoio_raccolta_Hartornen);
                      serbatoio_raccolta_Hartornen++;
                      printf("DOPO INCREMENTO. serbatoio_raccolta_Hartornen: %d\n", serbatoio_raccolta_Hartornen);
                    }
                }
              else if (i%2 == 1 && pAvanza -> melassa == molta)
                {
                  if (scelta_serbatoio == 1)
                    {
                      printf("PRIMA INCREMENTO. serbatoio_energia_Hartornen: %d\n", serbatoio_energia_Hartornen);
                      serbatoio_energia_Hartornen = serbatoio_energia_Hartornen + 3;
                      printf("DOPO INCREMENTO. serbatoio_energia_Hartornen: %d\n", serbatoio_energia_Hartornen);
                    }
                  else
                    {
                      printf("PRIMA INCREMENTO. serbatoio_raccolta_Hartornen: %d\n", serbatoio_raccolta_Hartornen);
                      serbatoio_raccolta_Hartornen = serbatoio_raccolta_Hartornen + 3;
                      printf("DOPO INCREMENTO. serbatoio_raccolta_Hartornen: %d\n", serbatoio_raccolta_Hartornen);
                    }
                }
            }

          printf("RIGA 948. SONO ARRIVATO QUI\n");
          controllo_serbatoio_energia_raccolta ();
          printf("RIGA 950. SONO ARRIVATO QUI\n");

          if (flag_morte_Hartornen == 1 || flag_morte_Arvais == 1)
            {
              blu();
              printf("HAI ESAURITO L'ENERGIA E, NON AVENDO PIU' LUCE, TI PERDI FRA I CUNICOLI E MUORI...\n");
              green();
              sleep(3);
              return 0;
            }


            //IMPREVISTO CAVERNA
            if (pAvanza -> imprevisto == nessun_imprevisto)
              {
                blu(); printf("\n\nHAI CONTINUATO A ESPLORARE LA CAVERNA SENZA INCORRERE IN IMPREVISTI!\n");
                green();
                sleep(3);
              }
            else if (pAvanza -> imprevisto == crollo)
              {
                blu(); printf("\n\nHAI CONTINUATO A ESPLORARE LA CAVERNA QUANDO SI VERIFICA UN "); green(); printf("CROLLO"); blu(); printf("!\n");
                printf("PER LIBERARTI HAI CONSUMATO 1 UNITA' DI MELASSA!\n");
                green();

                if (i%2 == 0)
                  {
                    printf("PRIMA DECREMENTO. serbatoio_energia_Arvais: %d\n", serbatoio_energia_Arvais);
                    serbatoio_energia_Arvais--;
                    printf("DOPO DECREMENTO. serbatoio_energia_Arvais: %d\n", serbatoio_energia_Arvais);
                  }
                else
                  {
                    printf("PRIMA DECREMENTO. serbatoio_energia_Hartornen: %d\n", serbatoio_energia_Hartornen);
                    serbatoio_energia_Hartornen--;
                    printf("DOPO DECREMENTO. serbatoio_energia_Hartornen: %d\n", serbatoio_energia_Hartornen);
                  }

                sleep(3);

                controllo_serbatoio_energia_raccolta ();
                if (flag_morte_Hartornen == 1 || flag_morte_Arvais == 1)
                  {
                    blu();
                    printf("HAI ESAURITO L'ENERGIA E, NON AVENDO PIU' LUCE, TI PERDI FRA I CUNICOLI E MUORI...\n");
                    green();
                    sleep(3);
                    return 0;
                  }
              }
            else if (pAvanza -> imprevisto == baco)
              {
                blu(); printf("\n\nHAI CONTINUATO A ESPLORARE LA CAVERNA QUANDO UN "); green(); printf("BACO "); blu(); printf("TI VEDE E TI RUBA TUTTA LA MELASSA!!\n");
                green();

                if (i%2 == 0)
                  {
                    serbatoio_energia_Arvais = 0;
                    serbatoio_raccolta_Arvais = 0;
                    printf("serbatoio_energia_Arvais: %d\n", serbatoio_energia_Arvais);
                    printf("serbatoio_raccolta_Arvais: %d\n", serbatoio_raccolta_Arvais);
                  }
                else
                  {
                    serbatoio_energia_Hartornen = 0;
                    serbatoio_raccolta_Hartornen = 0;
                    printf("serbatoio_energia_Hartornen: %d\n", serbatoio_energia_Hartornen);
                    printf("serbatoio_raccolta_Hartornen: %d\n", serbatoio_raccolta_Hartornen);
                  }

                sleep(3);

              }
      }
    if (i%2 == 0 && flag_abbatti_Arvais != 0)
       pUltimo_Arvais_caverna = pAvanza;
    else if (i%2 == 0 && flag_abbatti_Arvais == 0)
       pPrimo_Arvais_caverna = pAvanza;
    else if (i%2 == 1 && flag_abbatti_Hartornen != 0)
       pUltimo_Hartornen_caverna = pAvanza;
    else if (i%2 == 1 && flag_abbatti_Hartornen == 0)
      pPrimo_Hartornen_caverna = pAvanza;

    printf("RIGA 1315. flag_errore_mossa: %d\n", flag_errore_mossa);
    printf("RIGA 1315. pAvanza: %p\n", pAvanza);
    printf("RIGA 1315. pAvanza -> sinistra: %p\n", pAvanza -> sinistra);
    printf("RIGA 1315. pAvanza -> avanti: %p\n"  , pAvanza -> avanti);
    printf("RIGA 1315. pAvanza -> destra: %p\n"  , pAvanza -> destra);
    printf("RIGA 1315. FINE AVANZA\n");
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
    if (i%2 == 0)
      {
        printf("PRIMA DECREMENTO. serbatoio_energia_Arvais: %d\n", serbatoio_energia_Arvais);
        serbatoio_energia_Arvais--;
        printf("DOPO DECREMENTO. serbatoio_energia_Arvais: %d\n", serbatoio_energia_Arvais);
      }
    else
      {
        printf("PRIMA DECREMENTO. serbatoio_energia_Hartornen: %d\n", serbatoio_energia_Hartornen);
        serbatoio_energia_Hartornen--;
        printf("DOPO DECREMENTO. serbatoio_energia_Hartornen: %d\n", serbatoio_energia_Hartornen);
      }

    printf("RIGA 1102. SONO ARRIVATO QUI\n");
    controllo_serbatoio_energia_raccolta ();
    printf("RIGA 1104. SONO ARRIVATO QUI\n");

    if (flag_morte_Hartornen == 1 || flag_morte_Arvais == 1)
      {
        blu();
        printf("HAI ESAURITO L'ENERGIA E, NON AVENDO PIU' LUCE, TI PERDI FRA I CUNICOLI E MUORI...\n");
        green();
        sleep(3);
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



    printf("RIGA 1117. SONO ARRIVATO QUI\n");

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

    printf("RIGA 1133. SONO ARRIVATO QUI\n");

    //FORNISCE CHE IMPREVISTO TROVARE NELLA CAVERNA
    scelta_tipo_imprevisto = (rand() % 100);

    if (scelta_tipo_imprevisto <= 49)
        pAggira -> imprevisto = nessun_imprevisto;
    else if (scelta_tipo_imprevisto > 49 && scelta_tipo_imprevisto <= 84)
        pAggira -> imprevisto = crollo;
    else if (scelta_tipo_imprevisto > 84 && scelta_tipo_imprevisto <= 99)
        pAggira -> imprevisto = baco;

    printf("RIGA 1145. SONO ARRIVATO QUI\n");

    //FORNISCE LA TIPOLOGIA DI CAVERNA
    scelta_tipo_caverna = (rand() % 100);

    if (scelta_tipo_caverna <= 49)
        pAggira -> caverna = normale;
    else if (scelta_tipo_caverna > 49 && scelta_tipo_caverna <= 84)
        pAggira -> caverna = speciale;
    else if (scelta_tipo_caverna > 84 && scelta_tipo_caverna <= 99)
        pAggira -> caverna = accidentata;

    printf("RIGA 1157. SONO ARRIVATO QUI\n");

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

    printf("RIGA 1170. SONO ARRIVATO QUA\n");

    return 0;
  }

/********************************************** FINE AGGIRA **********************************************************************/

/****************************************************** INIZIO ELIMINA TUTTE CAVERNE ****************************************************/

void elimina_tutte_caverne (struct Caverna *pPrimo_Elimina, struct Caverna *pUltimo_Elimina, int i, int flag_abbatti_Arvais, int flag_abbatti_Hartornen)
  {
    if (pPrimo_Elimina == NULL)
      return;

    short int numero_caverne_da_eliminare = 0;

    //struct Caverna *temp_2 = pUltimo_Elimina;

    printf("RIGA 1260. i: %d\n", i);
    printf("RIGA 1260. pPrimo_Elimina: %p\n", pPrimo_Elimina);
    printf("RIGA 1260. pPrimo_Elimina -> sinistra: %p\n", pPrimo_Elimina -> sinistra);
    printf("RIGA 1260. pPrimo_Elimina -> avanti: %p\n"  , pPrimo_Elimina -> avanti);
    printf("RIGA 1260. pPrimo_Elimina -> destra: %p\n"  , pPrimo_Elimina -> destra);
    printf("RIGA 1260. pUltimo_Elimina: %p\n", pUltimo_Elimina);

    numero_caverne_da_eliminare = count (pPrimo_Elimina);
    printf("SONO ARRIVATO QUI P1\n");

    //DOPO ELIMINA QUESTI IF CHE NON SERVONO A NULLA
    if (flag_abbatti_Hartornen == 0)
      {
        printf("SONO ARRIVATO QUI P1 PRIMA\n");
        numero_caverne_Hartornen = count (pPrimo_Hartornen_caverna);
        printf("RIGA 1261. numero_caverne_Hartornen: %hd\n", numero_caverne_Hartornen);
        printf("SONO ARRIVATO QUI P1 DOPO\n");
      }
    if (flag_abbatti_Arvais == 0)
      {
        printf("SONO ARRIVATO QUI P2 PRIMA\n");
        numero_caverne_Arvais = count (pPrimo_Arvais_caverna);
        printf("RIGA 1261. numero_caverne_Arvais: %hd\n", numero_caverne_Arvais);
        printf("SONO ARRIVATO QUI P2 DOPO\n");
      }

    printf("RIGA 1261. PRIMA FREE. numero_caverne_da_eliminare: %hd\n", numero_caverne_da_eliminare);

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

            printf("RIGA 1262. pPrimo_Elimina: %p\n", pPrimo_Elimina);
            //printf("RIGA . pPrimo_Elimina -> sinistra: %p\n", pPrimo_Elimina -> sinistra);
            //printf("RIGA . pPrimo_Elimina -> avanti: %p\n"  , pPrimo_Elimina -> avanti);
            //printf("RIGA . pPrimo_Elimina -> destra: %p\n"  , pPrimo_Elimina -> destra);
          }
      }

    numero_caverne_da_eliminare = count (pPrimo_Elimina);
    printf("RIGA 1262 DOPO FREE. numero_caverne_da_eliminare: %hd\n", numero_caverne_da_eliminare);
    pPrimo_Elimina = NULL;

    if(pUltimo_Elimina != NULL)
      free(pUltimo_Elimina);
    pUltimo_Elimina = NULL;

    printf("RIGA 1263 DOPO FREE. pUltimo_Elimina: %p\n", pUltimo_Elimina);

    if (i%2 == 0)
      {
        pPrimo_Arvais_caverna = pPrimo_Elimina;
        pUltimo_Arvais_caverna = pUltimo_Elimina;
        printf("RIGA 1264. SONO ARRIVATO QUI\n");

        if (flag_abbatti_Arvais == 0)
          {
            printf("RIGA 1265 PRIMA MALLOC. pUltimo_Arvais_caverna: %p\n", pUltimo_Arvais_caverna);
            pUltimo_Arvais_caverna = (struct Caverna*) malloc(sizeof(struct Caverna)); //Fornisco l'indirizzo base dal quale ripartire per abbattere dato che ho eliminato tutte le grotte prima.
            pUltimo_Arvais_caverna -> sinistra = NULL;
            pUltimo_Arvais_caverna -> avanti = NULL;
            pUltimo_Arvais_caverna -> destra = NULL;
            printf("RIGA 1265 DOPO MALLOC. pUltimo_Arvais_caverna: %p\n", pUltimo_Arvais_caverna);
            printf("RIGA 1265. SONO ARRIVATO QUI\n");
          }
      }
    else
      {
        pPrimo_Hartornen_caverna =  pPrimo_Elimina;
        pUltimo_Hartornen_caverna = pUltimo_Elimina;
        printf("RIGA 1266. SONO ARRIVATO QUI\n");
        if (i%2 == 1 && flag_abbatti_Hartornen == 0)
          {
            printf("RIGA 1267 PRIMA MALLOC. pUltimo_Hartornen_caverna: %p\n", pUltimo_Hartornen_caverna);
            pUltimo_Hartornen_caverna = (struct Caverna*) malloc(sizeof(struct Caverna)); //Fornisco l'indirizzo base dal quale ripartire per abbattere dato che ho eliminato tutte le grotte prima.;
            pUltimo_Hartornen_caverna -> sinistra = NULL;
            pUltimo_Hartornen_caverna -> avanti = NULL;
            pUltimo_Hartornen_caverna -> destra = NULL;
            printf("RIGA 1267 DOPO MALLOC. pUltimo_Hartornen_caverna: %p\n", pUltimo_Hartornen_caverna);
            printf("RIGA 1267. SONO ARRIVATO QUI\n");
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
    //short int scelta_tipo_caverna_speciale_Arvais = 0;
    short int scelta_tipo_caverna_uscita_Hartornen = 0;
    short int scelta_tipo_caverna_accidentata_Hartornen = 20;
    short int scelta_tipo_caverna_normale_Hartornen = 0;
    //short int scelta_tipo_caverna_speciale_Hartornen = 0;
    short int scelta_tipo_caverna = 0;
    short int direzione = 0;

    printf ("RIGA 1078. ABBATTI -> i: %d\n", i);

    if (i%2 == 0 && flag_abbatti_Arvais == 0)
      {
        printf ("RIGA 1079. PRIMA ELIMINA pUltimo_Arvais_caverna %p\n", pUltimo_Arvais_caverna);
        elimina_tutte_caverne (pPrimo_Arvais_caverna, pUltimo_Arvais_caverna, i, flag_abbatti_Arvais, flag_abbatti_Hartornen);
        printf ("RIGA 1080. DOPO ELIMINA pUltimo_Arvais_caverna: %p\n", pUltimo_Arvais_caverna);
        printf ("RIGA 1080. pAbbatti_caverna: %p\n", pAbbatti_caverna);
      }
    else if (i%2 == 1 && flag_abbatti_Hartornen == 0)
      {
        printf ("RIGA 1081. PRIMA ELIMINA pUltimo_Hartornen_caverna %p\n", pUltimo_Hartornen_caverna);
        elimina_tutte_caverne (pPrimo_Hartornen_caverna, pUltimo_Hartornen_caverna, i, flag_abbatti_Arvais, flag_abbatti_Hartornen);
        printf ("RIGA 1082. DOPO ELIMINA pUltimo_Hartornen_caverna: %p\n", pUltimo_Hartornen_caverna);
        printf ("RIGA 1082. pAbbatti_caverna: %p\n", pAbbatti_caverna);
      }

    sleep(5); //DOPO ELIMINA

    if (i%2 == 0) //Sto giocando con ARVAIS
      scelta_tipo_caverna_uscita_Arvais = scelta_tipo_caverna_uscita_Arvais + 5;
    else scelta_tipo_caverna_uscita_Hartornen = scelta_tipo_caverna_uscita_Hartornen + 5;

    printf ("RIGA 1084. ABBATTI -> SONO ARRIVATO QUI\n");

    //Tolgo l'energia necessaria per abbattere
    if (i%2 == 0)
      {
        printf("PRIMA DECREMENTO. serbatoio_energia_Arvais: %d\n", serbatoio_energia_Arvais);
        serbatoio_energia_Arvais--;
        printf("DOPO DECREMENTO. serbatoio_energia_Arvais: %d\n", serbatoio_energia_Arvais);
      }
    else
      {
        printf("PRIMA DECREMENTO. serbatoio_energia_Hartornen: %d\n", serbatoio_energia_Hartornen);
        serbatoio_energia_Hartornen--;
        printf("DOPO DECREMENTO. serbatoio_energia_Hartornen: %d\n", serbatoio_energia_Hartornen);
      }

    printf ("RIGA 1086. ABBATTI -> serbatoio_energia_Arvais: %d\n", serbatoio_energia_Arvais);
    printf ("RIGA 1087. ABBATTI -> serbatoio_energia_Hartornen: %d\n", serbatoio_energia_Hartornen);

    controllo_serbatoio_energia_raccolta ();
    if (flag_morte_Hartornen == 1 || flag_morte_Arvais == 1)
      {
        blu();
        printf("HAI ESAURITO L'ENERGIA E, NON AVENDO PIU' LUCE, TI PERDI FRA I CUNICOLI E MUORI...\n");
        green();
        sleep(3);

        if (i%2 == 0)
          flag_abbatti_Arvais = 1;
        else flag_abbatti_Hartornen = 1;

        return 0;
      }

    struct Caverna *pAbbatti = (struct Caverna*) malloc(sizeof(struct Caverna)); //Fornisco l'indirizzo di partenza

    pAbbatti -> sinistra = NULL;
    pAbbatti -> avanti   = NULL;
    pAbbatti -> destra   = NULL;

    printf ("RIGA 1104. ABBATTI -> pUltimo_Arvais_caverna: %p\n",pUltimo_Arvais_caverna);
    printf ("RIGA 1104. ABBATTI -> pUltimo_Hartornen_caverna: %p\n", pUltimo_Hartornen_caverna);
    printf ("RIGA 1104. ABBATTI -> pAbbatti: %p\n", pAbbatti);
    printf ("RIGA 1104. ABBATTI -> pAbbatti -> sinistra: %p\n", pAbbatti -> sinistra);
    printf ("RIGA 1105. ABBATTI -> pAbbatti -> avanti: %p\n"  , pAbbatti -> avanti);
    printf ("RIGA 1106. ABBATTI -> pAbbatti -> destra: %p\n"  , pAbbatti -> destra);


    //FORNISCE LA QUANTITA' DI MELASSA CHE POSSO TROVARE NELLA CAVERNA
    scelta_quantita_melassa = (rand() %100);

    if (scelta_quantita_melassa <= 39)
      pAbbatti -> melassa = nessuna;
    else if (scelta_quantita_melassa > 39 && scelta_quantita_melassa <= 79)
      pAbbatti -> melassa = poca;
    else if (scelta_quantita_melassa > 79 && scelta_quantita_melassa <= 99)
      pAbbatti -> melassa = molta;

    printf ("RIGA 1119. ABBATTI -> pAbbatti -> melassa %d\n"  , pAbbatti -> melassa);

    //FORNISCE CHE IMPREVISTO TROVARE NELLA CAVERNA
    scelta_tipo_imprevisto = (rand() % 100);

    if (scelta_tipo_imprevisto <= 39)
      pAbbatti -> imprevisto = nessun_imprevisto;
    else if (scelta_tipo_imprevisto > 39 && scelta_tipo_imprevisto <= 79)
      pAbbatti -> imprevisto = crollo;
    else if (scelta_tipo_imprevisto > 79 && scelta_tipo_imprevisto <= 99)
      pAbbatti -> imprevisto = baco;

    printf ("RIGA 1131. ABBATTI -> pAbbatti -> imprevisto %d\n",  pAbbatti -> imprevisto);

    //FORNISCE LA TIPOLOGIA DI CAVERNA
    scelta_tipo_caverna = (rand() % 100);

    if (i%2 == 0) //Sto giocando con ARVAIS
      {
        scelta_tipo_caverna_normale_Arvais = (100 - scelta_tipo_caverna_uscita_Arvais - scelta_tipo_caverna_accidentata_Arvais)/2;
        //scelta_tipo_caverna_speciale_Arvais = 100 - scelta_tipo_caverna_normale_Arvais - scelta_tipo_caverna_uscita_Arvais - scelta_tipo_caverna_accidentata_Arvais;

        if (scelta_tipo_caverna <= scelta_tipo_caverna_accidentata_Arvais)
          pAbbatti -> caverna = accidentata;
        else if (scelta_tipo_caverna > scelta_tipo_caverna_accidentata_Arvais && scelta_tipo_caverna <= scelta_tipo_caverna_accidentata_Arvais + scelta_tipo_caverna_uscita_Arvais)
          {
            pAbbatti -> caverna = uscita;
            flag_possibile_uscita_Arvais = 1;
          }
        else if (scelta_tipo_caverna > scelta_tipo_caverna_accidentata_Arvais + scelta_tipo_caverna_uscita_Arvais && scelta_tipo_caverna <= scelta_tipo_caverna_accidentata_Arvais + scelta_tipo_caverna_uscita_Arvais + scelta_tipo_caverna_normale_Arvais)
          pAbbatti -> caverna = normale;
        else if (scelta_tipo_caverna > scelta_tipo_caverna_accidentata_Arvais + scelta_tipo_caverna_uscita_Arvais + scelta_tipo_caverna_normale_Arvais)
          pAbbatti -> caverna = speciale;

        printf ("RIGA 1155. ABBATTI -> pAbbatti -> caverna %d\n",  pAbbatti -> caverna);
      }
    else
      {
        scelta_tipo_caverna_normale_Hartornen = (100 - scelta_tipo_caverna_uscita_Hartornen - scelta_tipo_caverna_accidentata_Hartornen)/2;
        //scelta_tipo_caverna_speciale_Hartornen = 100 - scelta_tipo_caverna_normale_Hartornen - scelta_tipo_caverna_uscita_Hartornen - scelta_tipo_caverna_accidentata_Hartornen;

        if (scelta_tipo_caverna <= scelta_tipo_caverna_accidentata_Hartornen)
          pAbbatti -> caverna = accidentata;
        else if (scelta_tipo_caverna > scelta_tipo_caverna_accidentata_Hartornen && scelta_tipo_caverna <= scelta_tipo_caverna_accidentata_Hartornen + scelta_tipo_caverna_uscita_Hartornen)
          {
            pAbbatti -> caverna = uscita;
            flag_possibile_uscita_Hartornen = 1;
          }
        else if (scelta_tipo_caverna > scelta_tipo_caverna_accidentata_Hartornen + scelta_tipo_caverna_uscita_Hartornen && scelta_tipo_caverna <= scelta_tipo_caverna_accidentata_Hartornen + scelta_tipo_caverna_uscita_Hartornen + scelta_tipo_caverna_normale_Hartornen)
          pAbbatti -> caverna = normale;
        else if (scelta_tipo_caverna > scelta_tipo_caverna_accidentata_Hartornen + scelta_tipo_caverna_uscita_Hartornen + scelta_tipo_caverna_normale_Hartornen)
          pAbbatti -> caverna = speciale;

        printf ("RIGA 1176. ABBATTI -> pAbbatti -> caverna %d\n",  pAbbatti -> caverna);
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
              numero_caverne_Arvais = count (pPrimo_Arvais_caverna);
              numero_caverne_Hartornen = count (pPrimo_Hartornen_caverna);

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
        printf("\n\n\nRIGA 1234. SONO ARRIVATO QUI\n");
        numero_caverne_Arvais = count (pPrimo_Arvais_caverna);
        numero_caverne_Hartornen = count (pPrimo_Hartornen_caverna);
        printf("RIGA 1237. numero_caverne_Arvais: %d\n", numero_caverne_Arvais);
        printf("RIGA 1238. numero_caverne_Hartornen: %d\n", numero_caverne_Hartornen);
        if (numero_caverne_Arvais >= 2 && numero_caverne_Hartornen >= 2) ///////////////////////////////////////////////////// RIMETTI A 10 DOPO
          flag_mappa_cunicoli = 1;
        else (flag_mappa_cunicoli = 0);
        printf("RIGA 1242. flag_mappa_cunicoli: %d\n", flag_mappa_cunicoli);
        //sleep(5);
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

    for (int i = 1; flag_morte_Arvais == 0 && flag_morte_Hartornen == 0 && (flag_uscita_Arvais == 0 || flag_uscita_Hartornen == 0); i++)
      {
        probabilita_incontro = probabilita_incontro + 2;
        printf("Probabilita incontro: %hd\n",probabilita_incontro);
        rand_probabilita_incontro = rand()%100;
        printf("rand_probabilita_incontro: %hd\n",rand_probabilita_incontro);

        if ((probabilita_incontro >= 99 || rand_probabilita_incontro <= probabilita_incontro) && i != 1 && i != 2)
          {
            printfile("Scontro_diretto.txt");
            blu();
            printf("%s\n",                     "                                   STAVI PER AVANZARE QUANDO HAI VISTO IL NEMICO PASSARTI DAVANTI!");
            sleep(3);
            printf("%s\n\n",                   "    DECIDETE DI AFFRONTARVI UNA VOLTA PER TUTTE E DI GIOCARVI CON UN TESTA E CROCE LA CONCESSIONE DI ESTRAZIONE IN QUELLE GROTTE.");
            sleep(6);
            printf("%s\n\n",                   "                                           ARVAIS SCEGLIE TESTA E HARTORNEN SCEGLIE CROCE!" );
            sleep(4);
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

        if (i%2 == 0) //Se pari, gioco con Arvais, senno' con l'altro
          {
            if (flag_uscita_Arvais == 0)
              {
                printfile("Gioca_Arvais.txt");
                flag_crollo_Arvais = 0;

                blu();
                printf("STAI GIOCANDO CON ARVAIS!\n\n");
                green();

                if (flag_possibile_uscita_Arvais == 1)
                  {
                    blu();
                    printf("%s\n%s\n", "IN QUESTA CAVERNA HAI TROVATO L'USCITA!",
                                       "SE VUOI USCIRE E PROVARE A VINCERE USA IL COMANDO ESCI ALTRIMENTI CONTINUA A TRIVELLARE.\n");
                    green();
                    sleep(3);
                  }

                do
                 {
                   flag_errore_mossa = 0;
                   blu();
                   printf("\nCOSA VUOI FARE?\n");
                   green();

                   //Controllo dell'input
                   while (scanf("%hd",&scelta_opzioni_gioca) != 1 || scelta_opzioni_gioca > 4 || scelta_opzioni_gioca < 1)
                     {
                       blu();
                       printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
                       while (getchar() != '\n');
                       green();
                     }

                   switch (scelta_opzioni_gioca)
                     {
                       case 1: //Avanza
                         if (flag_crollo_Arvais == 1 || flag_abbatti_Arvais == 1)
                           {
                             blu();
                             printf("NON PUOI USARE QUESTA FUNZIONE SE SI E' VERIFICATO UN CROLLO O SE HAI ABBATTUTO UNA PARETE DELLA CAVERNA!\n");
                             green();
                             sleep(3);
                             flag_errore_mossa = 1;
                           }
                         else
                           {
                             printf ("RIGA 1359. primo_cunicolo_Arvais: %p\n", primo_cunicolo_Arvais);
                             printf ("RIGA 1360. pPrimo_Arvais_caverna: %p\n", pPrimo_Arvais_caverna);
                             sleep(3);
                             avanza (pPrimo_Arvais_caverna, pScavatrice_Arvais, i);
                             //pPrimo_Arvais_caverna = primo_cunicolo_Arvais;

                             printf("RIGA 1361. pPrimo_Arvais_caverna: %p\n", pPrimo_Arvais_caverna);
                             printf("RIGA 1361. pPrimo_Arvais_caverna -> sinistra: %p\n", pPrimo_Arvais_caverna -> sinistra);
                             printf("RIGA 1361. pPrimo_Arvais_caverna -> avanti: %p\n"  , pPrimo_Arvais_caverna -> avanti);
                             printf("RIGA 1361. pPrimo_Arvais_caverna -> destra: %p\n"  , pPrimo_Arvais_caverna -> destra);

                             /*

                             //AGGIORNAMENTO PUNTATORI
                             if (pPrimo_Arvais_caverna -> sinistra != NULL)
                               pPrimo_Arvais_caverna = pPrimo_Arvais_caverna -> sinistra;
                             else if (pPrimo_Arvais_caverna -> avanti != NULL)
                               pPrimo_Arvais_caverna = pPrimo_Arvais_caverna -> avanti;
                             else if (pPrimo_Arvais_caverna -> destra != NULL)
                               pPrimo_Arvais_caverna = pPrimo_Arvais_caverna -> destra;
                             //else pPrimo_Arvais_caverna = NULL;
                             else
                                {
                                  printf ("RIGA 1364. pPrimo E' = NULL\n");
                                  break;
                                }

                            */

                             printf ("RIGA 1364. primo_cunicolo_Arvais: %p\n", primo_cunicolo_Arvais);
                             printf ("RIGA 1365. pPrimo_Arvais_caverna: %p\n", pPrimo_Arvais_caverna);

                             sleep(3);
                           }

                         //MI SA CHE NON SERVE PIU'
                         if (flag_morte_giocatore == 1)
                           flag_morte_Arvais = 1;

                         break;
                       case 2: //Abbatti
                       if (flag_crollo_Arvais == 1)
                         {
                           blu();
                           printf("NON PUOI USARE QUESTA FUNZIONE SE SI E' VERIFICATO UN CROLLO!\n");
                           green();
                           sleep(3);
                           flag_errore_mossa = 1;
                         }
                        else
                         {
                           direzione = abbatti (pUltimo_Arvais_caverna, pScavatrice_Arvais, i);

                           if (flag_morte_Arvais == 1)
                             break;

                           printfile("Gioca_Arvais.txt");

                           //AGGIORNAMENTO PUNTATORI
                           if (direzione == 1)
                             pUltimo_Arvais_caverna -> sinistra = pPrimo_Arvais_caverna; //Ho abbattuto a sinistra
                           else if (direzione == 2)
                             pUltimo_Arvais_caverna  -> avanti = pPrimo_Arvais_caverna; //Ho abbattuto davanti
                           else pUltimo_Arvais_caverna -> destra = pPrimo_Arvais_caverna; //Ho abbattuto a destra

                           flag_abbatti_Arvais = 1;

                           avanza (pUltimo_Arvais_caverna, pScavatrice_Arvais, i);
                         }
                         break;
                       case 3: //Aggira
                         if (flag_crollo_Arvais == 1)
                           {
                             printf("RIGA 1531. pPrimo_Arvais_caverna: %p\n", pPrimo_Arvais_caverna);
                             printf("RIGA 1531. pPrimo_Arvais_caverna -> sinistra: %p\n", pPrimo_Arvais_caverna -> sinistra);
                             printf("RIGA 1531. pPrimo_Arvais_caverna -> avanti: %p\n"  , pPrimo_Arvais_caverna -> avanti);
                             printf("RIGA 1361. pPrimo_Arvais_caverna -> destra: %p\n"  , pPrimo_Arvais_caverna -> destra);

                             aggira (pPrimo_Arvais_caverna, pScavatrice_Arvais, i);

                             printf("RIGA 1532. pPrimo_Arvais_caverna: %p\n", pPrimo_Arvais_caverna);
                             printf("RIGA 1532. pPrimo_Arvais_caverna -> sinistra: %p\n", pPrimo_Arvais_caverna -> sinistra);
                             printf("RIGA 1532. pPrimo_Arvais_caverna -> avanti: %p\n"  , pPrimo_Arvais_caverna -> avanti);
                             printf("RIGA 1532. pPrimo_Arvais_caverna -> destra: %p\n"  , pPrimo_Arvais_caverna -> destra);
                             printf("RIGA 1532. SONO ARRIVATO QUA\n");

                             avanza (pPrimo_Arvais_caverna, pScavatrice_Arvais, i);  //Avanzo fino la caverna dove sarei entrato con avanza ma subendo gli effetti di due caverne
                             //pPrimo_Arvais_caverna = primo_cunicolo_Arvais;

                             /*
                             printf("RIGA 1533. pPrimo_Arvais_caverna: %p\n", pPrimo_Arvais_caverna);
                             printf("RIGA 1533. pPrimo_Arvais_caverna -> sinistra: %p\n", pPrimo_Arvais_caverna -> sinistra);
                             printf("RIGA 1533. pPrimo_Arvais_caverna -> avanti: %p\n"  , pPrimo_Arvais_caverna -> avanti);
                             printf("RIGA 1533. pPrimo_Arvais_caverna -> destra: %p\n"  , pPrimo_Arvais_caverna -> destra);


                             //AGGIORNAMENTO PUNTATORI
                             if (pPrimo_Arvais_caverna -> sinistra != NULL)
                               pPrimo_Arvais_caverna = pPrimo_Arvais_caverna -> sinistra;
                             else if (pPrimo_Arvais_caverna -> avanti != NULL)
                               pPrimo_Arvais_caverna = pPrimo_Arvais_caverna -> avanti;
                             else if (pPrimo_Arvais_caverna -> destra != NULL)
                               pPrimo_Arvais_caverna = pPrimo_Arvais_caverna -> destra;
                             else pPrimo_Arvais_caverna = NULL; //SONO ARRIVATO ALL'ULTIMA CAVERNA

                             */

                             printf("RIGA 1534. pPrimo_Arvais_caverna: %p\n", pPrimo_Arvais_caverna);
                             printf("RIGA 1534. pPrimo_Arvais_caverna -> sinistra: %p\n", pPrimo_Arvais_caverna -> sinistra);
                             printf("RIGA 1534. pPrimo_Arvais_caverna -> avanti: %p\n"  , pPrimo_Arvais_caverna -> avanti);
                             printf("RIGA 1534. pPrimo_Arvais_caverna -> destra: %p\n"  , pPrimo_Arvais_caverna -> destra);

                             printf("RIGA 1535. SONO ARRIVATO QUA\n");

                             avanza (pPrimo_Arvais_caverna, pScavatrice_Arvais, i);  //Avanzo fino la caverna dove sarei entrato con avanza ma subendo gli effetti di due caverne
                             //pPrimo_Arvais_caverna = primo_cunicolo_Arvais;

                             /*
                             printf("RIGA 1536. pPrimo_Arvais_caverna: %p\n", pPrimo_Arvais_caverna);
                             printf("RIGA 1536. pPrimo_Arvais_caverna -> sinistra: %p\n", pPrimo_Arvais_caverna -> sinistra);
                             printf("RIGA 1536. pPrimo_Arvais_caverna -> avanti: %p\n"  , pPrimo_Arvais_caverna -> avanti);
                             printf("RIGA 1536. pPrimo_Arvais_caverna -> destra: %p\n"  , pPrimo_Arvais_caverna -> destra);

                             //AGGIORNAMENTO PUNTATORI
                             if (pPrimo_Arvais_caverna -> sinistra != NULL)
                               pPrimo_Arvais_caverna = pPrimo_Arvais_caverna -> sinistra;
                             else if (pPrimo_Arvais_caverna -> avanti != NULL)
                               pPrimo_Arvais_caverna = pPrimo_Arvais_caverna -> avanti;
                             else if (pPrimo_Arvais_caverna -> destra != NULL)
                               pPrimo_Arvais_caverna = pPrimo_Arvais_caverna -> destra;
                             else pPrimo_Arvais_caverna = NULL;
                             */

                             printf("RIGA 1537. pPrimo_Arvais_caverna: %p\n", pPrimo_Arvais_caverna);
                             printf("RIGA 1537. pPrimo_Arvais_caverna -> sinistra: %p\n", pPrimo_Arvais_caverna -> sinistra);
                             printf("RIGA 1537. pPrimo_Arvais_caverna -> avanti: %p\n"  , pPrimo_Arvais_caverna -> avanti);
                             printf("RIGA 1537. pPrimo_Arvais_caverna -> destra: %p\n"  , pPrimo_Arvais_caverna -> destra);

                             printf("RIGA 1538. SONO ARRIVATO QUA\n");

                           }
                         else
                           {
                             blu();
                             printf("NON PUOI USARE QUESTA FUNZIONE SE NON SI E' VERIFICATO UN CROLLO!\n");
                             green();
                             sleep(3);
                             flag_errore_mossa = 1;
                           }
                         break;
                       case 4: //Esci
                         if (flag_possibile_uscita_Arvais == 1)
                          {
                            //elimina_tutte_caverne (pPrimo_Arvais_caverna, pUltimo_Arvais_caverna, i, flag_abbatti_Arvais, flag_abbatti_Hartornen);
                            flag_uscita_Arvais = 1;
                          }
                        else
                          {
                            blu();
                            printf("NON PUOI USARE QUESTA FUNZIONE SE NON SEI SU UNA GROTTA DI TIPO USCITA!\n");
                            green();
                            sleep(3);
                            flag_errore_mossa = 1;
                          }
                         break;
                     }
                 } while (flag_errore_mossa == 1);

              }
            else continue;
          }

        else //Turno Hartornen
          {
            if (flag_uscita_Hartornen == 0)
              {
                printfile("Gioca_Hartornen.txt");
                flag_crollo_Hartornen = 0;

                blu();
                printf("STAI GIOCANDO CON HARTORNEN!\n\n");
                green();

                if (flag_possibile_uscita_Hartornen == 1)
                  {
                    blu();
                    printf("%s\n%s\n", "IN QUESTA CAVERNA HAI TROVATO L'USCITA!",
                                       "SE VUOI USCIRE E PROVARE A VINCERE USA IL COMANDO ESCI ALTRIMENTI CONTINUA A TRIVELLARE.\n");
                    green();
                    sleep(3);
                  }

                do
                 {
                    flag_errore_mossa = 0;
                    blu();
                    printf("\nCOSA VUOI FARE?\n");
                    green();

                    //Controllo dell'input
                    while (scanf("%hd",&scelta_opzioni_gioca) != 1 || scelta_opzioni_gioca > 4 || scelta_opzioni_gioca < 1)
                      {
                        blu();
                        printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
                        while (getchar() != '\n');
                        green();
                      }

                    switch (scelta_opzioni_gioca)
                      {
                        case 1: //Avanza
                          if (flag_crollo_Hartornen == 1 || flag_abbatti_Hartornen == 1)
                            {
                              blu();
                              printf("NON PUOI USARE QUESTA FUNZIONE SE SI E' VERIFICATO UN CROLLO O SE HAI ABBATTUTO UNA PARETE DELLA CAVERNA!\n");
                              green();
                              sleep(3);
                              flag_errore_mossa = 1;
                            }
                          else
                            {
                              printf ("RIGA 1495. primo_cunicolo_Hartornen: %p\n", primo_cunicolo_Hartornen);
                              printf ("RIGA 1496. pPrimo_Hartornen_caverna: %p\n", pPrimo_Hartornen_caverna);
                              sleep(3);
                              avanza (pPrimo_Hartornen_caverna, pScavatrice_Hartornen, i);
                              //pPrimo_Hartornen_caverna = primo_cunicolo_Hartornen;
                              printf("RIGA 1497. pPrimo_Hartornen_caverna: %p\n", pPrimo_Hartornen_caverna);
                              printf("RIGA 1497. pPrimo_Hartornen_caverna -> sinistra: %p\n", pPrimo_Hartornen_caverna -> sinistra);
                              printf("RIGA 1497. pPrimo_Hartornen_caverna -> avanti: %p\n"  , pPrimo_Hartornen_caverna -> avanti);
                              printf("RIGA 1497. pPrimo_Hartornen_caverna -> destra: %p\n"  , pPrimo_Hartornen_caverna -> destra);

                              /*
                              //AGGIORNAMENTO PUNTATORI
                              if (pPrimo_Hartornen_caverna -> sinistra != NULL)
                                pPrimo_Hartornen_caverna = pPrimo_Hartornen_caverna -> sinistra;
                              else if (pPrimo_Hartornen_caverna -> avanti != NULL)
                                pPrimo_Hartornen_caverna = pPrimo_Hartornen_caverna -> avanti;
                              else if (pPrimo_Hartornen_caverna -> destra != NULL)
                                pPrimo_Hartornen_caverna = pPrimo_Hartornen_caverna -> destra;
                              //else pPrimo_Hartornen_caverna = NULL; //SONO ARRIVATO ALL'ULTIMA CAVERNA
                              else
                                {
                                  printf ("RIGA 1500. pPrimo E' = NULL\n");
                                  //break;
                                }

                              */

                              printf ("RIGA 1500. primo_cunicolo_Hartornen: %p\n", primo_cunicolo_Hartornen);
                              printf ("RIGA 1501. pPrimo_Hartornen_caverna: %p\n", pPrimo_Hartornen_caverna);

                              sleep(3);
                            }

                           //MI SA CHE NON SERVE PIU'
                          if (flag_morte_giocatore == 1)
                            flag_morte_Hartornen = 1;

                          break;
                        case 2: //Abbatti
                          if (flag_crollo_Hartornen == 1)
                            {
                              blu();
                              printf("NON PUOI USARE QUESTA FUNZIONE SE SI E' VERIFICATO UN CROLLO!\n");
                              green();
                              sleep(3);
                              flag_errore_mossa = 1;
                            }
                          else
                            {
                              direzione = abbatti(pUltimo_Hartornen_caverna, pScavatrice_Hartornen, i);
                              if (flag_morte_Hartornen == 1)
                                break;
                              printfile("Gioca_Hartornen.txt");

                              //AGGIORNAMENTO PUNTATORI
                              if (direzione == 1)
                                pUltimo_Hartornen_caverna -> sinistra = pPrimo_Hartornen_caverna; //Ho abbattuto a sinistra
                              else if (direzione == 2)
                                pUltimo_Hartornen_caverna -> avanti = pPrimo_Hartornen_caverna; //Ho abbattuto davanti
                              else pUltimo_Hartornen_caverna -> destra = pPrimo_Hartornen_caverna; //Ho abbattuto a destra

                              flag_abbatti_Hartornen = 1;
                              avanza (pUltimo_Hartornen_caverna, pScavatrice_Hartornen, i);
                            }
                          break;
                        case 3: //Aggira
                          if (flag_crollo_Hartornen == 1)
                            {
                              printf("RIGA 1703. pPrimo_Hartornen_caverna: %p\n", pPrimo_Hartornen_caverna);
                              printf("RIGA 1703. pPrimo_Hartornen_caverna -> sinistra: %p\n", pPrimo_Hartornen_caverna -> sinistra);
                              printf("RIGA 1703. pPrimo_Hartornen_caverna -> avanti: %p\n"  , pPrimo_Hartornen_caverna -> avanti);
                              printf("RIGA 1703. pPrimo_Hartornen_caverna -> destra: %p\n"  , pPrimo_Hartornen_caverna -> destra);

                              aggira (pPrimo_Hartornen_caverna, pScavatrice_Hartornen, i);

                              printf("RIGA 1704. pPrimo_Hartornen_caverna: %p\n", pPrimo_Hartornen_caverna);
                              printf("RIGA 1704. pPrimo_Hartornen_caverna -> sinistra: %p\n", pPrimo_Hartornen_caverna -> sinistra);
                              printf("RIGA 1704. pPrimo_Hartornen_caverna -> avanti: %p\n"  , pPrimo_Hartornen_caverna -> avanti);
                              printf("RIGA 1704. pPrimo_Hartornen_caverna -> destra: %p\n"  , pPrimo_Hartornen_caverna -> destra);

                              printf("RIGA 1705. SONO ARRIVATO QUA\n");

                              /*
                              //AGGIORNAMENTO PUNTATORI
                              if (pPrimo_Hartornen_caverna -> sinistra != NULL)
                                 primo_cunicolo_Hartornen -> sinistra = pPrimo_Hartornen_caverna; //Ho creato una nuova caverna per aggirare l'ostacolo
                              else if (pPrimo_Hartornen_caverna -> avanti != NULL)
                                  primo_cunicolo_Hartornen -> avanti = pPrimo_Hartornen_caverna; //Ho creato una nuova caverna per aggirare l'ostacolo
                              else if (pPrimo_Hartornen_caverna -> destra != NULL)
                                  primo_cunicolo_Hartornen -> destra = pPrimo_Hartornen_caverna; //Ho creato una nuova caverna per aggirare l'ostacolo

                              pPrimo_Hartornen_caverna = primo_cunicolo_Hartornen; //Aggiorno l'indirizzo di pPrimo_Hartornen_caverna cosi' che punti nuovamente al primo elemnto della lista

                              */

                              printf("RIGA 1716. SONO ARRIVATO QUA\n");
                              avanza (pPrimo_Hartornen_caverna, pScavatrice_Hartornen, i);  //Avanzo fino la caverna dove sarei entrato con avanza ma subendo gli effetti di due caverne
                              //pPrimo_Hartornen_caverna = primo_cunicolo_Hartornen;

                              /*
                              printf("RIGA 1717. pPrimo_Hartornen_caverna: %p\n", pPrimo_Hartornen_caverna);
                              printf("RIGA 1717. pPrimo_Hartornen_caverna -> sinistra: %p\n", pPrimo_Hartornen_caverna -> sinistra);
                              printf("RIGA 1717. pPrimo_Hartornen_caverna -> avanti: %p\n"  , pPrimo_Hartornen_caverna -> avanti);
                              printf("RIGA 1717. pPrimo_Hartornen_caverna -> destra: %p\n"  , pPrimo_Hartornen_caverna -> destra);

                              //AGGIORNAMENTO PUNTATORI
                              if (pPrimo_Hartornen_caverna -> sinistra != NULL)
                                pPrimo_Hartornen_caverna = pPrimo_Hartornen_caverna -> sinistra;
                              else if (pPrimo_Hartornen_caverna -> avanti != NULL)
                                pPrimo_Hartornen_caverna = pPrimo_Hartornen_caverna -> avanti;
                              else if (pPrimo_Hartornen_caverna -> destra != NULL)
                                pPrimo_Hartornen_caverna = pPrimo_Hartornen_caverna -> destra;
                              else pPrimo_Hartornen_caverna = NULL; //SONO ARRIVATO ALL'ULTIMA CAVERNA
                              */

                              printf("RIGA 1718. pPrimo_Hartornen_caverna: %p\n", pPrimo_Hartornen_caverna);
                              printf("RIGA 1718. pPrimo_Hartornen_caverna -> sinistra: %p\n", pPrimo_Hartornen_caverna -> sinistra);
                              printf("RIGA 1718. pPrimo_Hartornen_caverna -> avanti: %p\n"  , pPrimo_Hartornen_caverna -> avanti);
                              printf("RIGA 1718. pPrimo_Hartornen_caverna -> destra: %p\n"  , pPrimo_Hartornen_caverna -> destra);

                              avanza (pPrimo_Hartornen_caverna, pScavatrice_Hartornen, i);  //Avanzo fino la caverna dove sarei entrato con avanza ma subendo gli effetti di due caverne
                              //pPrimo_Hartornen_caverna = primo_cunicolo_Hartornen;

                              /*
                              printf("RIGA 1719. pPrimo_Hartornen_caverna: %p\n", pPrimo_Hartornen_caverna);
                              printf("RIGA 1719. pPrimo_Hartornen_caverna -> sinistra: %p\n", pPrimo_Hartornen_caverna -> sinistra);
                              printf("RIGA 1719. pPrimo_Hartornen_caverna -> avanti: %p\n"  , pPrimo_Hartornen_caverna -> avanti);
                              printf("RIGA 1719. pPrimo_Hartornen_caverna -> destra: %p\n"  , pPrimo_Hartornen_caverna -> destra);

                              //AGGIORNAMENTO PUNTATORI
                              if (pPrimo_Hartornen_caverna -> sinistra != NULL)
                                pPrimo_Hartornen_caverna = pPrimo_Hartornen_caverna -> sinistra;
                              else if (pPrimo_Hartornen_caverna -> avanti != NULL)
                                pPrimo_Hartornen_caverna = pPrimo_Hartornen_caverna -> avanti;
                              else if (pPrimo_Hartornen_caverna -> destra != NULL)
                                pPrimo_Hartornen_caverna = pPrimo_Hartornen_caverna -> destra;
                              else pPrimo_Hartornen_caverna = NULL; //SONO ARRIVATO ALL'ULTIMA CAVERNA
                              */

                              printf("RIGA 1720. pPrimo_Hartornen_caverna: %p\n", pPrimo_Hartornen_caverna);
                              printf("RIGA 1720. pPrimo_Hartornen_caverna -> sinistra: %p\n", pPrimo_Hartornen_caverna -> sinistra);
                              printf("RIGA 1720. pPrimo_Hartornen_caverna -> avanti: %p\n"  , pPrimo_Hartornen_caverna -> avanti);
                              printf("RIGA 1720. pPrimo_Hartornen_caverna -> destra: %p\n"  , pPrimo_Hartornen_caverna -> destra);
                            }
                          else
                            {
                              blu();
                              printf("NON PUOI USARE QUESTA FUNZIONE SE NON SI E' VERIFICATO UN CROLLO!\n");
                              green();
                              sleep(3);
                              flag_errore_mossa = 1;
                            }
                          break;
                        case 4: //Esci
                          if (flag_possibile_uscita_Hartornen == 1)
                            {
                              //elimina_tutte_caverne (pPrimo_Hartornen_caverna, pUltimo_Hartornen_caverna, i, flag_abbatti_Arvais, flag_abbatti_Hartornen);
                              flag_uscita_Hartornen = 1;
                            }
                          else
                            {
                              blu();
                              printf("NON PUOI USARE QUESTA FUNZIONE SE NON SEI SU UNA GROTTA DI TIPO USCITA!\n");
                              green();
                              sleep(3);
                              flag_errore_mossa = 1;
                            }
                          break;
                      }
                  } while (flag_errore_mossa == 1);
              }
            else continue;
          }

        //PROCLAMAZIONE VINCITORE PER MORTE AVVERSARIO
        if (flag_morte_Arvais == 1)
          {
            system("clear");
            print_lampeggio_gameover();
            printfile("Vince_Hartornen.txt");
            sleep(3);
            green();
          }
        else if (flag_morte_Hartornen == 1)
          {
            system("clear");
            print_lampeggio_gameover();
            printfile("Vince_Arvais.txt");
            sleep(3);
            green();
          }
      } //FINE FOR

    //system("clear");

    //PROCLAMAZIONE VINCITORE PER MERITO (HA TROVATO PIU' MELASSA)
    if (flag_uscita_Arvais == 1 && flag_uscita_Hartornen == 1)
      {
        if (serbatoio_raccolta_Arvais > serbatoio_raccolta_Hartornen)
          {
            system("clear");
            printfile("Vince_Arvais.txt");
            sleep(3);
            green();
          }
        else
          {
            system("clear");
            printfile("Vince_Hartornen.txt");
            sleep(3);
            green();
          }
      }

    if (flag_abbatti_Arvais != 0)
      {
        if (pPrimo_Arvais_caverna == pUltimo_Arvais_caverna)
          {
            printf("RIGA 2538. SONO ARRIVATO QUI\n");
            free(pPrimo_Arvais_caverna);
            printf("RIGA 2538 BIS. SONO ARRIVATO QUI\n");
            pPrimo_Arvais_caverna = NULL;
            pUltimo_Arvais_caverna = NULL;
          }
        else
          {
            printf("RIGA 2539. SONO ARRIVATO QUI\n");
            if (pPrimo_Arvais_caverna != NULL)
              free(pPrimo_Arvais_caverna);
            pPrimo_Arvais_caverna = NULL;
            printf("RIGA 2539 bis. SONO ARRIVATO QUI\n");
            if (pUltimo_Arvais_caverna != NULL)
              free(pUltimo_Arvais_caverna);
            pUltimo_Arvais_caverna = NULL;
            printf("RIGA 2539 tris. SONO ARRIVATO QUI\n");
          }
      }
    else elimina_tutte_caverne (pPrimo_Arvais_caverna, pUltimo_Arvais_caverna, 2, flag_abbatti_Arvais, flag_abbatti_Hartornen);
    printf("RIGA 2540 P1. SONO ARRIVATO QUI\n");

    if (flag_abbatti_Hartornen != 0)
      {
        printf("RIGA 2540 p1 bis. SONO ARRIVATO QUI\n");
        printf("RIGA 2540 p1 bis PRIMA FREE. pPrimo_Hartornen_caverna: %p\n", pPrimo_Hartornen_caverna);
        if (pPrimo_Hartornen_caverna == pUltimo_Hartornen_caverna)
          {
            printf("RIGA 2538. SONO ARRIVATO QUI\n");
            free(pPrimo_Hartornen_caverna);
            printf("RIGA 2538 BIS. SONO ARRIVATO QUI\n");
            pPrimo_Hartornen_caverna = NULL;
            pUltimo_Hartornen_caverna = NULL;
          }
        else
          {
            printf("RIGA 2540 p1 bis PRIMA FREE. pPrimo_Hartornen_caverna: %p\n", pPrimo_Hartornen_caverna);
            if (pPrimo_Hartornen_caverna != NULL)
              free(pPrimo_Hartornen_caverna);
            printf("RIGA 2540 p1 bis DOPO FREE. pPrimo_Hartornen_caverna: %p\n", pPrimo_Hartornen_caverna);
            pPrimo_Hartornen_caverna = NULL;
            printf("RIGA 2540 p1 tris. SONO ARRIVATO QUI\n");
            printf("RIGA 2540 p1 tris PRIMA FREE. pUltimo_Hartornen_caverna: %p\n", pUltimo_Hartornen_caverna);
            if (pUltimo_Hartornen_caverna != NULL)
              free(pUltimo_Hartornen_caverna);
            printf("RIGA 2540 p1 tris DOPO FREE. pUltimo_Hartornen_caverna: %p\n", pUltimo_Hartornen_caverna);
            pUltimo_Hartornen_caverna = NULL;
            printf("RIGA 2540 p1 quadris. SONO ARRIVATO QUI\n");
          }
      }
    else elimina_tutte_caverne (pPrimo_Hartornen_caverna, pUltimo_Hartornen_caverna, 1, flag_abbatti_Arvais, flag_abbatti_Hartornen);
    printf("RIGA 2540 P2. SONO ARRIVATO QUI\n");

    //AZZERO TUTTE LE VARIABILI PRIMA DI USCIRE
    scelta_personaggio = 0;
    flag_mappa_cunicoli_Arvais = 0;
    flag_mappa_cunicoli_Hartornen = 0;
    flag_chiudi_cunicolo = 0;
    numero_caverne_Arvais = 0;
    numero_caverne_Hartornen = 0;

    flag_morte_Arvais = 0;
    flag_morte_Hartornen = 0;
    flag_uscita_Arvais = 0;
    flag_uscita_Hartornen = 0;
    flag_possibile_uscita_Arvais = 0;
    flag_possibile_uscita_Hartornen = 0;
    flag_morte_giocatore = 0;
    flag_errore_mossa = 0;
    flag_crollo_Arvais = 0;
    flag_crollo_Hartornen = 0;
    flag_abbatti_Arvais = 0;
    flag_abbatti_Hartornen = 0;
    serbatoio_energia_Arvais = 4;
    serbatoio_raccolta_Arvais = 0;
    serbatoio_energia_Hartornen = 4;
    serbatoio_raccolta_Hartornen = 0;
    last_direzione_Arvais = 0;
    direzione_Arvais = 0;
    last_direzione_Hartornen = 0;
    direzione_Hartornen = 0;

    return 0;
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
