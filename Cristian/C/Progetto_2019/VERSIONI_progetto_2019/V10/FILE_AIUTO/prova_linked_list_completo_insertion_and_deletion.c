#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

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

enum   Quantita_melassa {nessuna, poca, molta = 3};
enum   Tipo_imprevisto  {nessun_imprevisto, crollo, baco};
enum   Tipo_caverna     {normale, speciale, accidentata, uscita};


struct Caverna
  {
     struct Caverna *sinistra;
     struct Caverna *avanti;
     struct Caverna *destra;
     enum   Quantita_melassa melassa;
     enum   Tipo_imprevisto  imprevisto;
     enum   Tipo_caverna     caverna;
  };

struct Caverna *primo_cunicolo_Arvais;
struct Caverna *pPrimo;

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


//CONTA IL NUMERO DI STRUTTURE CREATE
//int count (struct Caverna *pPrimo);

int main ()
  {
    short int scelta_personaggio = 0;
    short int numero_caverne = 0;
    short int direzione = 0;
    short int scelta_quantita_melassa = 0;
    short int scelta_tipo_imprevisto = 0;
    short int scelta_tipo_caverna = 0;
    short int conta_caverna = 0;


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

    if (scelta_personaggio == 1) //Ho scelto Arvais
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

        for (int i = 0; i < numero_caverne; i++) //Creo il numero di caverne richiesto
          {
            direzione = 0, scelta_quantita_melassa = 0, scelta_tipo_imprevisto = 0, scelta_tipo_caverna = 0;
            struct Caverna *primo_cunicolo_Arvais = (struct Caverna*) malloc(sizeof(struct Caverna)); //Fornisco l'indirizzo di partenza
            printf("RIGA 186. PRIMA CELLA primo_cunicolo_Arvais: %p\n", primo_cunicolo_Arvais);
            sleep(5);

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

            if (i == 0) //La prima grotta deve essere "normale" in tutto
              {
                primo_cunicolo_Arvais -> melassa     = nessuna;
                primo_cunicolo_Arvais -> imprevisto  = nessun_imprevisto;
                primo_cunicolo_Arvais -> caverna     = normale;
              }
            else
              {
                //CHIEDE LA QUANTITA' DI MELASSA CHE POSSO TROVARE NELLA CAVERNA
                printfile("Quantita_melassa.txt");
                blu();
                printf("QUANTA MELASSA VUOI TROVARE DENTRO LA CAVERNA?\n");
                green();

                while (scanf("%hd",&scelta_quantita_melassa) != 1 || scelta_quantita_melassa < 1 || scelta_quantita_melassa > 3)
                  {
                    blu();
                    printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
                    while (getchar() != '\n');
                    green();
                  }

                if (scelta_quantita_melassa == 1)
                    primo_cunicolo_Arvais -> melassa = nessuna;
                else if (scelta_quantita_melassa == 2)
                    primo_cunicolo_Arvais -> melassa = poca;
                else if (scelta_quantita_melassa == 3)
                    primo_cunicolo_Arvais -> melassa = molta;

                //CHIEDO CHE IMPREVISTO TROVARE NELLA CAVERNA
                printfile("Tipo_imprevisto.txt");
                blu();
                printf("CHE IMPREVISTO VUOI TROVARE DENTRO LA CAVERNA?\n");
                green();

                while (scanf("%hd",&scelta_tipo_imprevisto) != 1 || scelta_tipo_imprevisto < 1 || scelta_tipo_imprevisto > 3)
                  {
                    blu();
                    printf("SCELTA NON CORRETTA! REINSERISCI IL VALORE: ");
                    while (getchar() != '\n');
                    green();
                  }

                if (scelta_tipo_imprevisto == 1)
                    primo_cunicolo_Arvais -> imprevisto = nessun_imprevisto;
                else if (scelta_tipo_imprevisto == 2)
                    primo_cunicolo_Arvais -> imprevisto = crollo;
                else if (scelta_tipo_imprevisto == 3)
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
            if (pPrimo == NULL) //Se non ci stavano nodi precedenti
              {
                pPrimo = primo_cunicolo_Arvais; //Ho appena creato il primo nodo
                printf("RIGA 346. CELLA primo_cunicolo_Arvais: %p\n", primo_cunicolo_Arvais);
                printf("RIGA 347. CELLA pPrimo: %p\n",pPrimo);
                sleep(5);
              }
            else //Se gia era presente un nodo
              {
                printf("RIGA 350. CELLA primo_cunicolo_Arvais -> sinistra: %p\n", primo_cunicolo_Arvais -> sinistra);
                printf("RIGA 351. CELLA primo_cunicolo_Arvais -> avanti: %p\n", primo_cunicolo_Arvais -> avanti);
                printf("RIGA 352. CELLA primo_cunicolo_Arvais -> destra: %p\n", primo_cunicolo_Arvais -> destra);
                if (direzione == 1) //Se ho scelto sinistra
                  {
                    primo_cunicolo_Arvais -> sinistra = pPrimo; //Il primo nodo diventa il secondo
                    printf("RIGA 356. CELLA primo_cunicolo_Arvais -> sinistra: %p\n", primo_cunicolo_Arvais -> sinistra);
                  }
                else if (direzione == 2) //Se ho scelto avanti
                  {
                    primo_cunicolo_Arvais -> avanti = pPrimo; //Il primo nodo diventa il secondo
                    printf("RIGA 358. CELLA primo_cunicolo_Arvais -> avanti: %p\n", primo_cunicolo_Arvais -> avanti);
                  }
                else if (direzione == 3) //Se ho scelto destra
                  {
                    primo_cunicolo_Arvais -> destra = pPrimo; //Il primo nodo diventa il secondo
                    printf("RIGA 360. CELLA primo_cunicolo_Arvais -> destra: %p\n", primo_cunicolo_Arvais -> destra);
                  }

                pPrimo = primo_cunicolo_Arvais; //Aggiorno l'indirizzo di pPrimo cosi' che punti nuovamente al primo elemnto della lista

                printf("RIGA 368. CELLA primo_cunicolo_Arvais: %p\n", primo_cunicolo_Arvais);
                printf("RIGA 369. CELLA pPrimo: %p\n", pPrimo);
                sleep(5);
              }
          } //FINE for

        print_list(pPrimo);
        //conta_caverna = count (primo_cunicolo_Arvais);
        //printf("N° caverne: %d", conta_caverna);

        //STAMPA IL N° DI ELEMENTI INSERITI
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

    } //SCELTA PERSONAGGIO = 1
  } //MAIN



/*CONTA IL NUMERO DI STRUTTURE CREATE
int count (struct Caverna *pPrimo)
  {
    struct Caverna *pScan = pPrimo;
    printf("RIGA 121. ATTUALE CELLA primo_cunicolo_Arvais: %p\n", primo_cunicolo_Arvais);
    printf("RIGA 122. ATTUALE CELLA pPrimo: %p\n", pPrimo);
    sleep(5);
    short int cnt = 0;
    while (pScan != NULL)///////////////////////////////////////////////////CONTINUA DA QUA. NON FUNZIONA NE QUESTO NE PRINT_LIST
      {
        cnt++;
        if (pScan -> sinistra != NULL)
          pScan = pScan -> sinistra;
        else if (pScan -> destra != NULL)
          pScan = pScan -> destra;
        else if (pScan -> avanti != NULL)
          pScan = pScan -> avanti;
      }
    return (cnt);
  }

  /*
          struct Caverna *pScan = primo_cunicolo_Arvais -> pPrimo;
          printf("RIGA 383. ATTUALE CELLA primo_cunicolo_Arvais: %p\n", primo_cunicolo_Arvais);
          printf("RIGA 384. ATTUALE CELLA pPrimo: %p\n",primo_cunicolo_Arvais -> pPrimo);
          sleep(5);

          short int cnt = 0;
          printf("RIGA 391. CELLA pSuccessivo: %p\n",pScan -> pSuccessivo);
          printf("RIGA 392. CELLA pScan: %p\n",pScan);
          sleep(5);
          while (pScan != NULL)///////////////////////////////////////////////////CONTINUA DA QUA. NON FUNZIONA NE QUESTO NE PRINT_LIST
            {
              printf("RIGA 392. DENTRO WHILE PRINT");
              cnt++;
              if (pScan -> sinistra != NULL)
                pScan -> pSuccessivo = pScan -> sinistra;
              else if (pScan -> destra != NULL)
                pScan -> pSuccessivo = pScan -> destra;
              else if (pScan -> avanti != NULL)
                pScan -> pSuccessivo = pScan -> avanti;
              pScan = pScan -> pSuccessivo;
            }


          blu(); printf("Numero caverne: "); green();
          printf("%hd\n", cnt);
*/
