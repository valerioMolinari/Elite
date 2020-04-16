#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main () {

  int  chiave, metodo, caratteri_diversi_1 = 0, caratteri_diversi_2 = 0, b = 0, tutti_alpha = 0, alpha_minuscoli = 0, alpha_maiuscoli = 0;
  char alfabeto [27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
  char stringa_sicurezza [512]; //ho messo la stringa maggiore di 256 per avere una tolleranza di errore nella scrittura del testo
  char stringa [256];
  char alfabeto_sostituzione [27];

  printf ("Inserisci frase da criptare (max 256 caratteri): \n");
  fgets  (stringa_sicurezza, sizeof(stringa_sicurezza), stdin);
  strncpy(stringa, stringa_sicurezza, sizeof(stringa)-1); // sintassi strncpy(stringa_destinazione, stringa_partenza, primi_n_caratteri_da_copiare);
  //ho messo -1 cosi' che l'ultimo carattere risultasse completato da '\0'

  printf ("Inserisci l'alfabeto di criptazione (inglese):\n");
  fgets  (alfabeto_sostituzione, sizeof(alfabeto_sostituzione), stdin);
    if (strlen(alfabeto_sostituzione)==26) //se la lunghezza dell'alfabeto sostitutivo è giusta
      {
        printf("I due alfabeti sono lunghi uguale\n");//<<<<<<<<<<<<<<<<<<<<<<<<TOGLILO DOPO<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        for (int c=0; alfabeto_sostituzione[c] != '\0'; c++)
          {
            if (isalpha(alfabeto_sostituzione[c])==1)
              alpha_minuscoli++;
            else if (isalpha(alfabeto_sostituzione[c])==2)
              alpha_maiuscoli++;
          }
        tutti_alpha = alpha_minuscoli + alpha_maiuscoli/2;
        printf("tutti_alpha: %d\n",tutti_alpha);
        if (tutti_alpha < 26 )
          printf("L'alfabeto inserito NON contiene solo caratteri dell'alfabeto\n");
      }
