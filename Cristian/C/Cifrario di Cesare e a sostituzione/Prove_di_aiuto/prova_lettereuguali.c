#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main () {

  int  b=0, caratteri_uguali=0;
  char alfabeto_sostituzione [27];

  printf ("Inserisci l'alfabeto di criptazione (inglese):\n");
  fgets  (alfabeto_sostituzione, sizeof(alfabeto_sostituzione), stdin);
    if (strlen(alfabeto_sostituzione)==26) //se la lunghezza dell'alfabeto sostitutivo è giusta
      {
        printf("I due alfabeti sono lunghi uguale\n");//<<<<<<<<<<<<<<<<<<<<<<<<TOGLILO DOPO<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        for (int i=0; alfabeto_sostituzione[i] != '\0'; i++)//verifico se vi sono caratteri ripetuti
          {
            printf("RIGA 18. alfabeto_sostituzione i[%d]: %c\n",i,alfabeto_sostituzione[i]);
            for(b=0; alfabeto_sostituzione[b] != '\0'; b++)
              {
                if (alfabeto_sostituzione[i] == alfabeto_sostituzione[b])
                  {
                    printf("RIGA 23. alfabeto_sostituzione b[%d]: %c\n",b,alfabeto_sostituzione[b]);
                    caratteri_uguali++;
                    printf("RIGA 25. alfabeto_sostituzione[%d]: %d\n",i,b);
                    printf("caratteri_uguali: %d\n", caratteri_uguali);
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

          printf("Sono arrivato QUI\n");
      }
    }
