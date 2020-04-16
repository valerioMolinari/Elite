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
* 2) Usare stringhe con solo lettere MINUSCOLE ---> Usa una funzione che trasforma le MAIUSCOLE in MINUSCOLE
* 3) Tutti i caratteri strani devono essere lasciati uguali. ES: ! ? @ ecc...
* 4) Controllare che l’alfabeto mescolato immesso (secondo caso) contenga tutte e sole le 26 lettere dell’alfabeto. ---> funzione che elimina caratteri speciali
****************************************************************************************************************************
* DATA DI SCADENZA:  Domenica 17/11/2019 (23:59)
* DA INVIARE SU:     https://classroom.github.com/a/0WhgfLv-
*
* 07/11/2019 ----> string_critpo_V1.c
* Creato il file.
* Fatta funzionare la scelta del metodo di cifratura
* Fatta funzionare la scelta della chiave di cifratura di Cesare
* Fatta funzionare la lettura del messaggio da criptare
* Creata funzione di criptazione CESARE:
*   - Funziona ma non bene. aggiungi funzione che se arrivo a Z devo ritornare ad A (RIGA 72)
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

  int  chiave, metodo;
  char alfabeto [26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  char stringa [256];

  printf ("Inserisci frase da criptare: \n");
  fgets  (stringa, sizeof(stringa), stdin);

  here:
  printf ("%s\n%s\n%s\n",
  "Con che metodo vuoi criptare?",
  "Cifrario di Cesare (PREMERE 1)",
  "Cifrario a sostituzione (PREMERE 2)");
  scanf ("%d",&metodo);

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
            if (stringa[i] <97 || stringa[i] > 122) //se minore dell'alfabeto in ascii riscrivo il carattere speciale
            {
              printf ("%c",stringa[i]);
              continue;
            }

            if ((stringa[i] + chiave) > 122)
              {
                -------------------------------------
              }
            //aggiungi funzione che se arrivo a Z devo ritornare ad A
            printf ("%c",stringa[i] + chiave);
          }

        printf ("\n");

      break;

      case 2: //SE HO SCELTO CIFRARIO A SOSTITUZIONE---------------------------------
        printf ("Inserisci l'alfabeto di criptazione (inglese): \n");


      break;

      default: //METODO SOSTITUZIONE NON RICONOSCIUTO
      printf ("Operazione non riconosciuta.");
      goto here;
      /*
         METODO SOSTITUZIONE NON RICONOSCIUTO
         printf ("%s\n%s\n%s\n%s\n","Operazione non riconosciuta.",
         "La modalita' di decriptazione puo' essere scelta fra:",
         "Cifrario di Cesare (PREMERE 1)",
         "Cifrario a sostituzione (PREMERE 2)");
         scanf  ("%d",&metodo);
      */
    }
}
