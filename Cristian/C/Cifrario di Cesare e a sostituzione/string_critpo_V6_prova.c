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
* - Ho inserito la parte che mi controlla che sull'alfabeto inserito non vi sia la ripetizione di più caratteri uguali ma da problemi

RIGA 177: Quando l'alfabeto inserito è diverso da quello inglese, mi richiede SEMPRE 2 VOLTE di reinserire l'alfabeto
MI DA PROBLEMI DOPO LA RIGA 201
***************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

  int  chiave, metodo, b = 0, caratteri_diversi = 0, ripetuto = 0, alfabeto_sbagliato=0, alfabeto_giusto=0;
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
            do
             {
                //alfabeto_giusto=0;
                //alfabeto_sbagliato=0;
                printf ("Inserisci l'alfabeto di criptazione (inglese):\n");
                fgets  (alfabeto_sostituzione, sizeof(alfabeto_sostituzione), stdin);
                getchar();

                if (strlen(alfabeto_sostituzione)==26) //se la lunghezza dell'alfabeto sostitutivo è giusta
                  {
                    printf("I due alfabeti sono lunghi uguale\n");//<<<<<<<<<<<<<<<<<<<<<<<<TOGLILO DOPO<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
                    for (int i=0; alfabeto_sostituzione[i] != '\0'; i++)
                      {
                        if (alfabeto_sostituzione[i] >= 65 && alfabeto_sostituzione[i] <= 90) //se compaiono lettere MAIUSCOLE le riporto in MINUSCOLE
                          {
                            alfabeto_sostituzione[i] = alfabeto_sostituzione[i] +32;
                            //printf("RIGA 170. alfabeto_sostituzione[%d]: %c\n",i,alfabeto_sostituzione[i]);//<<<<<<<<<<<<<<<<<<<<<<<<TOGLILO DOPO<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
                            i--;//l'ho messo così che, dopo averla trasformata in minuscola, possa arrivare al codice di verifica dei caratteri doppi;
                            continue;
                          }
                        else if (alfabeto_sostituzione[i] >= 97 && alfabeto_sostituzione[i] <= 122) //se è una lettera minuscola
                          {
                            alfabeto_giusto++;
                            alfabeto_sbagliato=0;
                            //printf("RIGA 177. alfabeto_giusto: %d\n",alfabeto_giusto);//<<<<<<<<<<<<<<<<<<<<<<<<TOGLILO DOPO<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
                            continue;
                          }
                        else //se non appartiene all'alfabeto
                          {
                            printf("RIGA 181. alfabeto_sostituzione[%d]: %c\n",i,alfabeto_sostituzione[i]);//<<<<<<<<<<<<<<<<<<<<<<<<TOGLILO DOPO<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
                            printf("L'alfabeto inserito contiene caratteri diversi da quelli dell'alfabeto inglese\n");
                            alfabeto_sbagliato=1;
                            alfabeto_giusto=0;//guarda se inserito nel giusto posto
                            break;
                          }
                      }
                  }
            } while(alfabeto_sbagliato==1);

            printf("RIGA 192. alfabeto_giusto: %d\n",alfabeto_giusto);//<<<<<<<<<<<<<<<<<<<<<<<<TOGLILO DOPO<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
            printf("alfabeto_sostituzione: %s\n",alfabeto_sostituzione);
            if (alfabeto_giusto==26)
              {
                printf("Sono entrato nella seconda parte\n");//<<<<<<<<<<<<<<<<<<<<<<<<<<<<< ELIMINA DOPO >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                for (int i=0; alfabeto_sostituzione[i] != '\0'; i++)//verifico se vi sono caratteri ripetuti
                  {
                    for(b=0; ((alfabeto_sostituzione[i] != alfabeto_sostituzione[b]) &&  alfabeto_sostituzione[b] != '\0' ) || b==i; b++)
                      {
                        if (b==i)//se "b" e "i" sono uguali, sicuramente i due caratteri sono uguali
                          {
                            ripetuto++;
                            printf("ripetuto: %d\n",ripetuto);
                            continue;
                          }
                        caratteri_diversi++;
                        if (ripetuto==1 && caratteri_diversi < 25)
                          {
                            printf("L'alfabeto di criptazione inserito contiene dei caratteri uguali fra loro.\n");
                            printf("I caratteri devono esseri tutti diversi fra loro.\n\n");
                            break;
                          }
                      }
                      if (ripetuto==1 && caratteri_diversi < 25)//devo arrivare a reinserire l'alfabeto
                        break;
                    b = 0;
                    caratteri_diversi = 0;
                  }//CI ARRIVO DALLA RIGA 214(SE L'ALFABETO CONTIENE CARATTERI RIPETUTI), O SE E' TUTTO GIUSTO
                if((ripetuto==1 && caratteri_diversi < 25) != 1)
                  {
                    printf("Forse l'alfabeto inserito è giusto\n");
                    //SCRIVI QUA IL CODICE DI SOSTITUZIONE CON BREAK FINALE;
                  }
              }
            printf("Sono arrivato QUI\n");
          }while(ripetuto==1 && caratteri_diversi < 25);
        }

      else //METODO SOSTITUZIONE NON RICONOSCIUTO
        {
          printf ("Operazione non riconosciuta.\n\n");
          goto metodo_sbagliato;
        }

}
