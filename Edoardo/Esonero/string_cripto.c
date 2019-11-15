#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 256

void cypherPrint (char stringa[], char cypher[]){
  system("clear");
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
  cypherPrint( stringa, cypher);
}


void sostituzione (char stringa[], char alfaMescolato[]){

  int indice, flag=0;

  for (int i=0; i<26; i++){
    if (alfaMescolato[i]<96||alfaMescolato[i]>122)
      flag=1;
  }

  if (flag==0){
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
    cypherPrint( stringa, cypher);
  }else{
    printf("hai sbagliato caratteri\n");
  }

}


int main(int argc, char const *argv[]) {

  system("clear");
  int scelta;
  char stringa [MAX];
  char alfaMescolato [26];
  char alfa[26]=("abcdefghijklmnopqrstuvwxyz");


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
    system("clear");
    printf("Inserire un alfabeto mescolato:\n" );
    for (int i=0; i<26; i++){
      if (i<9)
        printf("%d.  %c: ", i+1, alfa[i] );
      else
        printf("%d. %c: ", i+1, alfa[i] );
      scanf("%c\n",&alfaMescolato[i] );
    }
    printf("%s\n",alfaMescolato );
    //char alfaMescolato [26]=("opqrstabhijklmncdefguvwxyz");
    sostituzione(stringa, alfaMescolato);

  }




  return 0;
}
