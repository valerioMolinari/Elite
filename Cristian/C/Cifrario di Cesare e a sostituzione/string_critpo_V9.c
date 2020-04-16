/****************************************************************************************************************************
* COSA DEVE FARE IL PROGRAMMA:
* 1) Deve leggere in input il messaggio da cifrare.
* 2) Deve chiedere con quale metodo cifrare.
* 3) Deve chiedere la chiave con cui cifrare:
*     - Nel caso di CESARE la chiave è un numero fra 1 e 26 (lettere alfabeto inglese)
*     - Nel caso di SOSTITUZIONE deve chiedere l'ALFABETO (inglese) con cui cifrarlo
* 4) In entrambi i casi, deve restituire in uscita il messaggio criptato.
*
* SONO OBBLIGATO A:
* 1) Usare l'alfabeto inglese (26 lettere)
* 2) Usare stringhe con solo lettere MINUSCOLE
* 3) Tutti i caratteri strani devono essere lasciati uguali. ES: ! ? @ ecc...
* 4) Controllare che l’alfabeto mescolato immesso (secondo caso) contenga tutte e sole le 26 lettere dell’alfabeto. ---> funzione che elimina caratteri speciali
****************************************************************************************************************************
* DATA DI SCADENZA:  Domenica 17/11/2019 (23:59)
* DA INVIARE SU:     https://classroom.github.com/a/0WhgfLv-
****************************************************************************************************************************
* 07/11/2019 ----> string_critpo_V1.c
* Creato il file.
* Fatta funzionare la scelta del metodo di cifratura
* Fatta funzionare la scelta della chiave di cifratura di Cesare
* Fatta funzionare la lettura del messaggio da criptare
* Creata funzione di criptazione CESARE:
*   - Funziona ma non bene. Aggiungi funzione che se arrivo a Z devo ritornare ad A (RIGA 72)
****************************************************************************************************************************
* 08/11/2019 ----> string_critpo_V2.c
* Ho fatto funzionare UNA PARTE della funzione di criptazione CESARE:
* - Ho agiunto la funzione di lettura MAIUSCOLE e trasformazione in MINUSCOLE
* - Ho aggiunto le funzioni di ritorno Z ---> A
* - NON FUNZIONA QUANDO INSERISCO DEL TESTO CHE HA UN RITORNO A CAPO (\n)
* - NON FUNZIONA QUANDO INSERISCO PIU' DI 256 CARATTERI
* - NON FUNZIONA QUANDO INSERISCO UNA LETTERA AL POSTO DEL METODO (RIGA 57)
* Inizio a creare la funzione di criptazione per SOSTITUZIONE (RIGA 88)
* - Non mi prende la funzione fgets (RIGA 105)
***************************************************************************************************************************
* 09/11/2019 ----> string_critpo_V3.c
* Ho fatto funzionare UNA PARTE della funzione di criptazione CESARE:
* - Ho aggiunto la funzione di lettura fino max 256 caratteri
* - Ho risolto il problema del metodo usando gli if al posto dello switch (metodo)
* - NON FUNZIONA QUANDO INSERISCO DEL TESTO CHE HA UN RITORNO A CAPO (\n)
* - NON FUNZIONA QUANDO INSERISCO UNA LETTERA AL POSTO DELLA CHIAVE (RIGA 84)
* Inizio a creare la funzione di criptazione per SOSTITUZIONE (RIGA 88)
* - Risolto problema lettura funzione fgets (RIGA 116)
***************************************************************************************************************************
* 11/11/2019 ----> string_critpo_V4.c
* SUL METODO:
* - Se scrivo un metodo di sostituzione (letterale) troppo lungo, le lettere in piu' mi costituiscono dei tentativi di immissione metodo andati male
* SUL CIFRARIO DI CESARE:
* - NON FUNZIONA QUANDO INSERISCO DEL TESTO CHE HA UN RITORNO A CAPO (\n)
* - NON FUNZIONA QUANDO INSERISCO UNA LETTERA AL POSTO DELLA CHIAVE (RIGA 84)
* SUL CIFRARIO A SOSTITUZIONE:
* - Ho inserito la funzione che controlla se l'alfabeto_sostituzione ha il numero di caratteri giusti
* - Ho inserito la funzione che controlla se l'alfabeto_sostituzione ha solo caratteri che appartengono all'alfabeto inglese
* - DEVO INSERIRE LA PARTE CHE CONTROLLA CHE NON VI SIANO RIPETIZIONI DI PIU' CARATTERI UGUALI ------> MANCA <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
***************************************************************************************************************************
* 12/11/2019 ----> string_critpo_V5.c
* SUL METODO:
* - Se scrivo un metodo di sostituzione (letterale) troppo lungo, le lettere in piu' mi costituiscono dei tentativi di immissione metodo andati male
* SUL CIFRARIO DI CESARE:
* - NON FUNZIONA QUANDO INSERISCO DEL TESTO CHE HA UN RITORNO A CAPO (\n)
* - NON FUNZIONA QUANDO INSERISCO UNA LETTERA AL POSTO DELLA CHIAVE (RIGA 84)
* SUL CIFRARIO A SOSTITUZIONE:
* - Ho riscritto meglio le due funzioni già funzionanti perchè mi andavano in conflitto con una parte di programma
* - Devo trovare il metodo di unire la parte che ho riscritto con la seconda parte del cifrario
* - DEVO INSERIRE LA PARTE CHE CONTROLLA CHE NON VI SIANO RIPETIZIONI DI PIU' CARATTERI UGUALI
***************************************************************************************************************************
* 13/11/2019 ----> string_critpo_V6.c
* SUL METODO:
* - Se scrivo un metodo di sostituzione (letterale) troppo lungo, le lettere in piu' mi costituiscono dei tentativi di immissione metodo andati male
* SUL CIFRARIO DI CESARE:
* - NON FUNZIONA QUANDO INSERISCO DEL TESTO CHE HA UN RITORNO A CAPO (\n) <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
* - NON FUNZIONA QUANDO INSERISCO UNA LETTERA AL POSTO DELLA CHIAVE (RIGA 84)<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
* SUL CIFRARIO A SOSTITUZIONE:
* - Ho aggiustato tutto quello che non andava.
* - Bisogna inserire la parte della sostituzione vera e propria.
***************************************************************************************************************************
* 14/11/2019 ----> string_critpo_V7.c
* SUL METODO:
* - Se scrivo un metodo di sostituzione (letterale) troppo lungo, le lettere in piu' mi costituiscono dei tentativi di immissione metodo andati male
* SUL CIFRARIO DI CESARE:
* - NON FUNZIONA QUANDO INSERISCO DEL TESTO CHE HA UN RITORNO A CAPO (\n) <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
* - NON FUNZIONA QUANDO INSERISCO UNA LETTERA AL POSTO DELLA CHIAVE (RIGA 84)<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
* SUL CIFRARIO A SOSTITUZIONE:
* - I messaggi vengono criptati ma insieme a loro vengono aggiunti in fondo 3 caratteri speciali che non dovrebbero esserci
***************************************************************************************************************************
* 14/11/2019 ----> string_critpo_V8.c
* - Gli errori sono gli stessi di V7.
* - Ho eliminato solo i commenti inutilli.
***************************************************************************************************************************
* 14/11/2019 ----> string_critpo_V9.c
* -
***************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

  int  chiave, metodo, metodo_sbagliato=0, b=0, alfabeto_sbagliato=0, alfabeto_giusto=0, caratteri_uguali=0;
  char stringa_sicurezza [512]; //ho messo la stringa maggiore di 256 per avere una tolleranza di errore nella scrittura del testo
  char stringa [256];
  char alfabeto_sostituzione [27];
  char stringa_cifrata [256];

  printf ("Inserisci frase da criptare (max 256 caratteri): \n");
  fgets  (stringa_sicurezza, sizeof(stringa_sicurezza), stdin);
  strncpy(stringa, stringa_sicurezza, sizeof(stringa)-1); // sintassi strncpy(stringa_destinazione, stringa_partenza, primi_n_caratteri_da_copiare);
  //ho messo -1 cosi' che l'ultimo carattere risultasse completato da '\0'

  do {

  printf ("%s\n%s\n%s\n",
  "Con che metodo vuoi criptare?",
  "Cifrario di Cesare (PREMERE 1)",
  "Cifrario a sostituzione (PREMERE 2)");
  scanf ("%d",&metodo);
  getchar(); //lo devo usare senno' non mi funziona il secondo fgets

  if (metodo == 1)  //SE HO SCELTO CIFRARIO DI CESARE
    {
        printf ("Inserisci chiave di criptazione (da 1 a 26): \n");
        scanf  ("%d",&chiave);

        //CONDIZIONE ESISTENZA CHIAVE CRIPTAZIONE
        while (chiave > 26 || chiave < 1)
            {
              printf ("%s\n%s\n","Chiave errata. Deve essere fra 1 e 26","Inserisci nuova chiave di criptazione (da 1 a 26):");
              scanf  ("%d",&chiave);
            }

        //CIFRATURA TESTO
        for (int i=0; stringa[i] != '\0'; i++)
          {
            if (stringa[i] >= 65 && stringa[i] <= 90) //se compaiono lettere MAIUSCOLE le riporto in MINUSCOLE
            {
              if (stringa[i] + chiave > 90) //se il carattere da criptare appartiene all'alfabeto ma, aggiunta la chiave,è maggiore della Z, riparto da A
              {
                stringa[i] = stringa[i] + chiave -26;
                printf ("%c",stringa[i] + 32);
                continue;
              }
              printf ("%c",stringa[i] +32 + chiave);
              continue;
            }
            if (stringa[i] <97 || stringa[i] > 122) //se non appartiene all'alfabeto, in ascii, riscrivo il carattere speciale
            {
              printf ("%c",stringa[i]);
              continue;
            }
            if (stringa[i] >= 97 && stringa[i] <= 122) //se il carattere da criptare appartiene all'alfabeto ma, aggiunta la chiave,è maggiore della Z, riparto da A
            {
              if (stringa[i] + chiave > 122)
              {
                stringa[i] = stringa[i] + chiave -26;
                printf ("%c",stringa[i]);
                continue;
              }
            }
            printf ("%c",stringa[i] + chiave);
          }

        printf ("\nOperazione conclusa.\n");
    }

      else if(metodo == 2) //SE HO SCELTO CIFRARIO A SOSTITUZIONE
        {
          do
          {
            do
             {

                alfabeto_sbagliato=0;
                alfabeto_giusto=0;
                caratteri_uguali=0;
                printf ("Inserisci l'alfabeto di criptazione (inglese):\n");
                fgets  (alfabeto_sostituzione, sizeof(alfabeto_sostituzione), stdin);
                getchar();

                if (strlen(alfabeto_sostituzione)==26) //se la lunghezza dell'alfabeto sostitutivo è giusta
                  {
                    for (int i=0; alfabeto_sostituzione[i] != '\0'; i++)
                      {
                        if (alfabeto_sostituzione[i] >= 65 && alfabeto_sostituzione[i] <= 90) //se compaiono lettere MAIUSCOLE le riporto in MINUSCOLE
                          {
                            alfabeto_sostituzione[i] = alfabeto_sostituzione[i] +32;
                            i--;//l'ho messo così che, dopo averla trasformata in minuscola, possa arrivare al codice di verifica dei caratteri doppi;
                            continue;
                          }
                        else if (alfabeto_sostituzione[i] >= 97 && alfabeto_sostituzione[i] <= 122) //se è una lettera minuscola
                          {
                            alfabeto_giusto++;
                            alfabeto_sbagliato=0;
                            continue;
                          }
                        else //se non appartiene all'alfabeto
                          {
                            printf("L'alfabeto inserito contiene caratteri diversi da quelli dell'alfabeto inglese\n");
                            alfabeto_sbagliato=1;
                            alfabeto_giusto=0;
                            break;
                          }
                      }
                  }
              if (strlen(alfabeto_sostituzione)!=26)
                printf("L'alfabeto inserito è troppo corto\n");
            } while(alfabeto_sbagliato==1 || strlen(alfabeto_sostituzione)!=26);

            if (alfabeto_giusto==26)//se la lunghezza dell'alfabeto inserito è corrette e contiene solo i caratteri giusti
              {
                for (int i=0; alfabeto_sostituzione[i] != '\0'; i++)//verifico se vi sono caratteri ripetuti
                  {
                    for(b=0; alfabeto_sostituzione[b] != '\0'; b++)
                      {
                        if (alfabeto_sostituzione[i] == alfabeto_sostituzione[b])
                          {
                            caratteri_uguali++;
                            if (caratteri_uguali > 1)
                              {
                                printf("L'alfabeto di criptazione inserito contiene dei caratteri uguali fra loro.\n");
                                printf("I caratteri devono esseri tutti diversi fra loro.\n\n");
                                break;
                              }
                          }
                      }
                      if (caratteri_uguali > 1)//devo arrivare a reinserire l'alfabeto
                        break;
                    b = 0;
                    caratteri_uguali = 0;
                  }

                if(caratteri_uguali == 0)
                  {
                    for (int i=0; stringa[i] != '\0'; i++)//sostituisco le lettere della stringa in base all'alfabeto cifrato
                      {
                        if (stringa[i] >= 65 && stringa[i] <= 90) //se compaiono lettere MAIUSCOLE le riporto in MINUSCOLE
                          {
                            stringa[i] = stringa[i] +32;
                            i--;
                            continue;
                          }
                        else if (stringa[i] < 97 || stringa[i] > 122) //se è uncarattere speciale
                          {
                            stringa_cifrata[i] = stringa[i];
                            continue;
                          }

                        switch (stringa[i])
                          {
                            case 'a':
                              stringa_cifrata[i] = alfabeto_sostituzione[0];
                              break;
                            case 'b':
                              stringa_cifrata[i] = alfabeto_sostituzione[1];
                              break;
                            case 'c':
                              stringa_cifrata[i] = alfabeto_sostituzione[2];
                              break;
                            case 'd':
                              stringa_cifrata[i] = alfabeto_sostituzione[3];
                              break;
                            case 'e':
                              stringa_cifrata[i] = alfabeto_sostituzione[4];
                              break;
                            case 'f':
                              stringa_cifrata[i] = alfabeto_sostituzione[5];
                              break;
                            case 'g':
                              stringa_cifrata[i] = alfabeto_sostituzione[6];
                              break;
                            case 'h':
                              stringa_cifrata[i] = alfabeto_sostituzione[7];
                              break;
                            case 'i':
                              stringa_cifrata[i] = alfabeto_sostituzione[8];
                              break;
                            case 'j':
                              stringa_cifrata[i] = alfabeto_sostituzione[9];
                              break;
                            case 'k':
                              stringa_cifrata[i] = alfabeto_sostituzione[10];
                              break;
                            case 'l':
                              stringa_cifrata[i] = alfabeto_sostituzione[11];
                              break;
                            case 'm':
                              stringa_cifrata[i] = alfabeto_sostituzione[12];
                              break;
                            case 'n':
                              stringa_cifrata[i] = alfabeto_sostituzione[13];
                              break;
                            case 'o':
                              stringa_cifrata[i] = alfabeto_sostituzione[14];
                              break;
                            case 'p':
                              stringa_cifrata[i] = alfabeto_sostituzione[15];
                              break;
                            case 'q':
                              stringa_cifrata[i] = alfabeto_sostituzione[16];
                              break;
                            case 'r':
                              stringa_cifrata[i] = alfabeto_sostituzione[17];
                              break;
                            case 's':
                              stringa_cifrata[i] = alfabeto_sostituzione[18];
                              break;
                            case 't':
                              stringa_cifrata[i] = alfabeto_sostituzione[19];
                              break;
                            case 'u':
                              stringa_cifrata[i] = alfabeto_sostituzione[20];
                              break;
                            case 'v':
                              stringa_cifrata[i] = alfabeto_sostituzione[21];
                              break;
                            case 'w':
                              stringa_cifrata[i] = alfabeto_sostituzione[22];
                              break;
                            case 'x':
                              stringa_cifrata[i] = alfabeto_sostituzione[23];
                              break;
                            case 'y':
                              stringa_cifrata[i] = alfabeto_sostituzione[24];
                              break;
                            case 'z':
                              stringa_cifrata[i] = alfabeto_sostituzione[25];
                              break;

                          }
                      }
                    printf("stringa_cifrata: %s\n",stringa_cifrata);
                    printf("\nOperazione terminata\n");
                  }
              }
          }while(caratteri_uguali > 1);
        }

      else //METODO SOSTITUZIONE NON RICONOSCIUTO
        {
          printf ("Operazione non riconosciuta.\n\n");
          metodo_sbagliato = 1;
        }
    } while (metodo_sbagliato == 1);
}
