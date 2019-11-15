#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 256

void cypherPrint (char stringa[], char cypher[]){
  printf("Stringa originale ------> %s ",stringa );
  printf("Stringa criptata ------> %s\n", cypher);
}

int controlloChiave(int k){

  if (k>26)
    k=k-((k%26)*26);
  if (k<0&&k>-27)
    k=k+26;
  if (k<-26)
    k=26+(k%26);

  return k;
}


void cesare(char stringa[]){

  int k;
  int lunghezza= strlen(stringa);
  char cypher [lunghezza];

  printf("Inserire chiave:\n" );
  scanf("%d",&k );
  k = controlloChiave(k);

  for(int i=0; i<lunghezza; i++){
    stringa[i]= tolower(stringa[i]);
    if(stringa[i]>='a' && stringa [i]<='z'){
      if (k+stringa[i]>'z'){
        cypher [i]= 'a'+k -('z'-stringa[i])-1;
      }else{
        cypher[i]=stringa[i]+k;
      }
    }else{
      cypher[i]=stringa[i];
    }
  }

  cypher[lunghezza]='\0';
  system("clear");
  cypherPrint( stringa, cypher);
}


void sostituzione (char stringa[]){

  int indice, l;
  char alfaMescolato[26];
  char alfa[27]=("abcdefghijklmnopqrstuvwxyz");

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
        for (int k=0; k<i; k++){
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
  system("clear");
  alfa[26] = '\0';
  printf("Alfabeto:           %s\n",alfa );
  printf("Alfabeto mescolato: %s\n\n",alfaMescolato );
  cypherPrint( stringa, cypher);

}


int main(int argc, char const *argv[]) {

  system("clear");
  int scelta;
  char stringa [MAX];


  printf("Questo programma cripta una stringa tramite Cesare o Sostituzione\n");
  printf("Inserisci la stringa da criptare:\n" );
  fgets (stringa, sizeof (stringa), stdin);

  system("clear");

  printf("scegli il sistema:\n1.Cesare\n2.Sostituzione\n" );
  scanf("%d",&scelta );
  if (scelta==1){
    system("clear");
    cesare(stringa);
  }

  if (scelta==2){

    sostituzione(stringa);

  }




  return 0;
}
