#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX  256


int main(int argc, char const *argv[]) {

  system("clear");
  int scelta, flag =0, indice, l;
  char stringa [MAX];
  char alfaMescolato [26];
  char alfa[26]=("abcdefghijklmnopqrstuvwxyz");


  printf("Questo programma cripta una stringa tramite Cesare o Sostituzione\n");
  printf("Inserisci la stringa da criptare:\n" );
  fgets (stringa, sizeof (stringa), stdin);

  system("clear");
  printf("Inserire un alfabeto mescolato:\n" );
  for (int i=0; i<26; i++){

    if (i<9)
      printf("%d.  %c: ", i+1, alfa[i] );
    else
      printf("%d. %c: ", i+1, alfa[i] );

    scanf(" %c", &alfaMescolato[i] );
    getchar();

    l=0;
    while(l==0){
      if (alfaMescolato[i]<97||alfaMescolato[i]>122){
        printf("\nhai inserito un carattere non corretto.\n" );
        printf("Inserisci un carattere corretto\n" );

        if (i<9)
          printf("%d.  %c: ", i+1, alfa[i] );
        else
          printf("%d. %c: ", i+1, alfa[i] );

        scanf(" %c", &alfaMescolato[i] );
        getchar();
      } else{
        l=1;
      }

    }


    if(i>0){
      l=0;
      while(l==0){
        for (int k=0; k<=i; k++){
          if (alfaMescolato[i]==alfaMescolato[k]){
            printf("\nHai ripetuto un carattere 2 volte.\n" );
            printf("Inserisci un carattere diverso\n" );

            if (i<9)
              printf("%d.  %c: ", i+1, alfa[i] );
            else
              printf("%d. %c: ", i+1, alfa[i] );

            scanf(" %c", &alfaMescolato[i] );
            getchar();
          }
        }
        l=1;
      }

    }

  }
//  printf("%s\n",alfaMescolato );
  //char alfaMescolato [26]=("opqrstabhijklmncdefguvwxyz");


  int lunghezza = strlen(stringa);
  char cypher[lunghezza];

  for (int i=0; i<lunghezza; i++){
    indice=((int)stringa[i])-97;
    if (indice<0){
      cypher[i]= ' ';
    }else{
      cypher[i]=alfaMescolato[indice];
    }
  }

  cypher[lunghezza]='\0';
  printf("%s\n",cypher );


  return 0;
}
//opstujklmnwvdeabcfghqrixyz
