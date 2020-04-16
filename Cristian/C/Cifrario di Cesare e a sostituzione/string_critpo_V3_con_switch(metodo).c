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
* - NON FUNZIONA QUANDO INSERISCO DEL TESTO CHE HA UN RITORNO A CAPO (\n) <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
* - NON FUNZIONA QUANDO INSERISCO UNA LETTERA AL POSTO DEL METODO (RIGA 57) <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
* Inizio a creare la funzione di criptazione per SOSTITUZIONE (RIGA 88)
* - Risolto problema lettura funzione fgets (RIGA 116)
***************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

  int  chiave, metodo;
  char alfabeto [26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  char stringa_sicurezza [512]; //ho messo la stringa maggiore di 256 per avere una tolleranza di errore nella scrittura del testo
  char stringa [256];
  char elimina_caratteri [] = {'\n'};
  char alfabeto_sostituzione [26];

  printf ("Inserisci frase da criptare (max 256 caratteri): \n");
  fgets  (stringa_sicurezza, sizeof(stringa_sicurezza), stdin);
  strncpy(stringa, stringa_sicurezza, sizeof(stringa)-1); // sintassi strncpy(stringa_destinazione, stringa_partenza, primi_n_caratteri_da_copiare);
  //ho messo -1 cosi' che l'ultimo carattere risultasse completato da '\0'
  if(strchr(stringa, '\n'))    //Se la stringa contiene \n (ritorno a capo)
    while(getc(stdin)!= '\n');  //Butto via la parte residua

  here:
  printf ("%s\n%s\n%s\n",
  "Con che metodo vuoi criptare?",
  "Cifrario di Cesare (PREMERE 1)",
  "Cifrario a sostituzione (PREMERE 2)");
  scanf ("%d",&metodo);
  getchar(); //lo devo usare senno' non mi funziona il secondo fgets

  switch (metodo)
    {
      case 1: //SE HO SCELTO CIFRARIO DI CESARE
        printf ("Inserisci chiave di criptazione (da 1 a 26): \n");
        scanf  ("%d",&chiave);

        //CONDIZIONE ESISTENZA CHIAVE CRIPTAZIONE
        while (chiave > 26 || chiave < 1)
            {
              printf ("%s\n%s\n","Chiave errata. Deve essere fra 1 e 26","Inserisci nuova chiave di criptazione (da 1 a 26):");
              scanf  ("%d",&chiave);
            }


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
      break;

      case 2: //SE HO SCELTO CIFRARIO A SOSTITUZIONE
        printf ("Inserisci l'alfabeto di criptazione (inglese):\n");
        fgets  (alfabeto_sostituzione, sizeof(alfabeto_sostituzione), stdin);
        for (int i=0; alfabeto_sostituzione[i] != '\0'; i++)
          {
            printf ("alfabeto sostituzione: %c\n", alfabeto_sostituzione[i]);
          }

        /*
        * PER ESSERE GIUSTO L'ALFABETO DEVE ESSERE:
        * - DI 26 CARATTERI
        * - CHE APPARTENGANO SOLAMENTE ALL'ALFABETO INGLESE
        * - CHE NON VI SIANO RIPETIZIONI DI PIU' CARATTERI UGUALI
        */
        /*
        while  (alfabeto_sostituzione[i] != alfabeto) //se vi sono caratteri diversi da quelli dell'alfabeto
          {
            printf ("%s\n%s\n","L'alfabeto inserito non corrisponde ai criteri di funzionamento.",
            "Inserisci nuovamente l'alfabeto di criptazione (inglese):");
            fgets  (alfabeto_sostituzione, sizeof(alfabeto_sostituzione), stdin);
            continue;
          }
*/
      printf ("Sei tonto\n");

      break;

      default: //METODO SOSTITUZIONE NON RICONOSCIUTO
      printf ("Operazione non riconosciuta.\n\n");
      goto here;
    }
}
