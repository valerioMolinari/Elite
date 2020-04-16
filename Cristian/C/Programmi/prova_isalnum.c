#include <stdio.h>
#include <ctype.h>

int main () {
   char testo[20];
   printf("Inserisci del testo\n");
   fgets (testo,sizeof(testo), stdin);

   for (int i=0; testo[i] != '\0'; i++)
    {
      if( isalnum(testo[i]))
        printf("E' un numero o una lettera\n");
      else
        printf("NON e' un numero o una lettera\n");
    }
}
