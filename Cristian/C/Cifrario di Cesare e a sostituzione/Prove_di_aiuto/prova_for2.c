#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{

  char alfabeto_sostituzione [27];

  printf ("Inserisci l'alfabeto di criptazione (inglese):\n");
  fgets  (alfabeto_sostituzione, sizeof(alfabeto_sostituzione), stdin);

      for (int i=0; alfabeto_sostituzione[i] != '\0'; i++)
        {
          printf("[I] entrato: %d\n",i);
          if (alfabeto_sostituzione[i] >= 65 && alfabeto_sostituzione[i] <= 90) //se compaiono lettere MAIUSCOLE le riporto in MINUSCOLE
            {
              alfabeto_sostituzione[i] = alfabeto_sostituzione[i] +32;
              printf("%s\n",alfabeto_sostituzione);
              i--;//l'ho messo così che, dopo averla trasformata in minuscola, possa arrivare al codice di verifica dei caratteri doppi;
              continue;
            }
          printf("[I] uscito: %d\n",i);
        }
}
