#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main () {

printf ("Inserisci chiave di criptazione (da 1 a 26): \n");
scanf  ("%d",&chiave);

//CONDIZIONE ESISTENZA CHIAVE CRIPTAZIONE
while (chiave > 26 || chiave < 1 || isalpha(chiave)!=0)
    {
      printf ("%s\n%s\n","Chiave errata. Deve essere fra 1 e 26","Inserisci nuova chiave di criptazione (da 1 a 26):");
      scanf  ("%d",&chiave);
    }
    printf("Chiave solo numerica\n");
  }
