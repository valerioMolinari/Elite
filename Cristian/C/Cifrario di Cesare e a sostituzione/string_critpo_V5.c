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
* - NON FUNZIONA QUANDO INSERISCO DEL TESTO CHE HA UN RITORNO A CAPO (\n) <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
* - NON FUNZIONA QUANDO INSERISCO PIU' DI 256 CARATTERI <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
* - NON FUNZIONA QUANDO INSERISCO UNA LETTERA AL POSTO DEL METODO (RIGA 57) <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
* Inizio a creare la funzione di criptazione per SOSTITUZIONE (RIGA 88)
* - Non mi prende la funzione fgets (RIGA 105)
***************************************************************************************************************************
* 09/11/2019 ----> string_critpo_V3.c
* Ho fatto funzionare UNA PARTE della funzione di criptazione CESARE:
* - Ho aggiunto la funzione di lettura fino max 256 caratteri
* - Ho risolto il problema del metodo usando gli if al posto dello switch (metodo)
* - NON FUNZIONA QUANDO INSERISCO DEL TESTO CHE HA UN RITORNO A CAPO (\n) <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
* - NON FUNZIONA QUANDO INSERISCO UNA LETTERA AL POSTO DELLA CHIAVE (RIGA 84)<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
* Inizio a creare la funzione di criptazione per SOSTITUZIONE (RIGA 88)
* - Risolto problema lettura funzione fgets (RIGA 116)
***************************************************************************************************************************
* 11/11/2019 ----> string_critpo_V4.c
* SUL CIFRARIO DI CESARE:
* - Se scrivo un alfabeto di sostituzione troppo lungo, le lettere in piu' mi costituiscono dei tentativi di immissione alfabeto andati male
* - Se l'alfabeto_sostituzione è shiftato me lo da per buono, se ha lettere scambiate no
* SUL CIFRARIO A SOSTITUZIONE:
* - Ho inserito la funzione che controlla se l'alfabeto_sostituzione ha il numero di caratteri giusti
* - Ho inserito la funzione che controlla se l'alfabeto_sostituzione ha solo caratteri che appartengono all'alfabeto inglese
* - DEVO INSERIRE LA PARTE CHE CONTROLLA CHE NON VI SIANO RIPETIZIONI DI PIU' CARATTERI UGUALI ------> MANCA <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
***************************************************************************************************************************
* 12/11/2019 ----> string_critpo_V5.c
* SUL CIFRARIO A SOSTITUZIONE:
* - Ho riscritto meglio le due funzioni già funzionanti perchè mi andavano in conflitto con una parte di programma
* - Devo trovare il metodo di unire la parte che ho riscritto con la seconda parte del cifrario <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
* - DEVO INSERIRE LA PARTE CHE CONTROLLA CHE NON VI SIANO RIPETIZIONI DI PIU' CARATTERI UGUALI ------> MANCA <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
***************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

  int  chiave, metodo, caratteri_diversi_1 = 0, caratteri_diversi_2 = 0, b = 0;
  char alfabeto [27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
  char stringa_sicurezza [512]; //ho messo la stringa maggiore di 256 per avere una tolleranza di errore nella scrittura del testo
  char stringa [256];
  char alfabeto_sostituzione [27];

  printf ("Inserisci frase da criptare (max 256 caratteri): \n");
  fgets  (stringa_sicurezza, sizeof(stringa_sicurezza), stdin);
  strncpy(stringa, stringa_sicurezza, sizeof(stringa)-1); // sintassi strncpy(stringa_destinazione, stringa_partenza, primi_n_caratteri_da_copiare);
  //ho messo -1 cosi' che l'ultimo carattere risultasse completato da '\0'

  metodo_sbagliato:
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
            printf ("Inserisci l'alfabeto di criptazione (inglese):\n");
            fgets  (alfabeto_sostituzione, sizeof(alfabeto_sostituzione), stdin);
              if (strlen(alfabeto_sostituzione)==26) //se la lunghezza dell'alfabeto sostitutivo è giusta
                {
                  printf("I due alfabeti sono lunghi uguale\n");//<<<<<<<<<<<<<<<<<<<<<<<<TOGLILO DOPO<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
                  for (int c=0; alfabeto_sostituzione[c] != '\0'; c++)
                  {
                    if (alfabeto_sostituzione[c] >= 65 && alfabeto_sostituzione[c] <= 90) //se compaiono lettere MAIUSCOLE le riporto in MINUSCOLE
                      {
                        alfabeto_sostituzione[c] = alfabeto_sostituzione[c] +32;
                        printf("%s\n",alfabeto_sostituzione);
                        continue;
                      }
                    else if (alfabeto_sostituzione[c] >= 97 && alfabeto_sostituzione[c] <= 122) //se è una lettera minuscola
                      continue;
                    else  //se non appartiene all'alfabeto
                      {
                        printf("L'alfabeto inserito NON contiene solo caratteri dell'alfabeto\n");
                        break;
                      }
                  }//DEVO AGGIUNGERE IL CODICE SOTTO DENTRO QUESTI CICLI SOPRA COSI CHE L'ALFABETO E' SBAGLIATO ESCO DA TUTTI I FOR E REINSERISCO L'ALFABETO

                  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

                  for (int i=0; alfabeto_sostituzione[i] != '\0'; i++) //cerco se nell'alfabeto di sostituzione vi sono caratteri diversi da quelli dell'alfabeto
                    {
                      for(int a=0; alfabeto[a] != alfabeto_sostituzione[i]; a++)
                        {
                            caratteri_diversi_1++;
                            printf("%d\n",caratteri_diversi_1);
                            if (caratteri_diversi_1 == 26)
                              {
                                printf("L'alfabeto di criptazione inserito e' diverso da quello inglese. (RIGA 138)\n\n");
                                break;
                              }
                        }
                        if (caratteri_diversi_1 == 26)//devo arrivare a reinserire l'alfabeto/////////////////////////////////////
                          break;
                        printf("----------------------------------------------------------");/////////////////////////////////////
                        caratteri_diversi_1 = 0;//////////////////////////////////////////////////////////////////////////////////
                    }

                  if(caratteri_diversi_1 != 26)
                    {
                      printf("\nI caratteri_diversi_1 sono diversi da 26.\n",caratteri_diversi_1);//<<<<<<<<<<RIMUOVI DOPO>>>>>>>>>>>>>>>>>>
                      for (int i=0; alfabeto_sostituzione[i] != '\0'; i++) //cerco se nell'alfabeto di sostituzione vi sono caratteri uguali fra loro
                        {
                          for(b=0; alfabeto_sostituzione[i] != alfabeto_sostituzione[b] || b==i; b++)
                            {
                              if (b==i)//se "b" e "i" sono uguali, sicuramente i due caratteri sono uguali
                                continue;
                              caratteri_diversi_2++;
                              if (b==25 && caratteri_diversi_2 < 25)
                                {
                                  printf("L'alfabeto di criptazione inserito contiene dei caratteri uguali fra loro.\n");
                                  printf("I caratteri devono esseri tutti diversi fra loro.\n\n");
                                  break;
                                }
                            }
                            if (b==25 && caratteri_diversi_2 < 25)//devo arrivare a reinserire l'alfabeto//////////////////////////////////////
                              break;
                          caratteri_diversi_2 = 0;/////////////////////////////////////////////////////////////////////////////////////////////
                        }
                    }

                  /*
                  * PER ESSERE GIUSTO L'ALFABETO DEVE ESSERE:
                  * - DI 26 CARATTERI   ------------------------------------------> FATTO <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
                  * - CHE APPARTENGANO SOLAMENTE ALL'ALFABETO INGLESE ------------> FATTO <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
                  * - CHE NON VI SIANO RIPETIZIONI DI PIU' CARATTERI UGUALI ------> MANCA <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
                  */

                printf("L'alfabeto inserito è corretto\n");//se va qui per il momento non è corretto
                break;//termina il programma
                }
            else
                {
                  printf("L'alfabeto di criptazione inserito e' diverso da quello inglese. (RIGA 186)\n\n");
                  caratteri_diversi_1 = 26;//se i due alfabeti hanno lunghezza diversa richiedo di inserire nuovamente l'alfabeto
                }

              //printf ("\nOperazione conclusa.\n"); //forse va inserito nella parentesi sopra else
          } while(caratteri_diversi_1 == 26 || (b==25 && caratteri_diversi_2 < 25) || (strlen(alfabeto_sostituzione)!=26));
        }

      else //METODO SOSTITUZIONE NON RICONOSCIUTO
        {
          printf ("Operazione non riconosciuta.\n\n");
          goto metodo_sbagliato;
        }

}
