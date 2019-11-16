#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 256


void cesare(char stringa[]);
void sostituzione (char stringa[]);
void cypherPrint (char stringa[], char cypher[]);
int controlloChiave(int k);


int main(int argc, char const *argv[]) {

  system("clear");

  int scelta;
  char stringa [MAX];


  printf("Questo programma cripta una stringa inserita da utente tramite \nil cifrario di Cesare oppure il cifrario a sostituzione\n\n");
  printf("Inserisci una stringa da criptare:\n" );
  fgets (stringa, sizeof (stringa), stdin);

  system("clear");

  printf("Scegli il cifrario da utilizzare inserendo il numero corrispondente:\n1. Cifrario di Cesare\n2. Cifrario a sostituzione\n" );
  scanf("%d",&scelta );

  switch (scelta) {
    case 1: cesare(stringa);
      break;

    case 2: sostituzione(stringa);
      break;
  }

  return 0;
}


//funzione che cripta un stringa tramite cifrario di cesare
void cesare(char stringa[]){

  int k, kModulata;
  int lunghezza = strlen(stringa);
  char cypher [lunghezza];

  system("clear");

  printf("Inserire una chiave per il cifrario di Cesare:\n" );
  scanf("%d", &k );

//richiamo alla funzione che modula la chiave fornita dall'utente
  kModulata = controlloChiave(k);

//algoritmo per cifrare con il cifrario di Cesare
  for(int i=0; i < lunghezza; i++){
    stringa[i] = tolower(stringa[i]);
    if(stringa[i] >= 'a' && stringa [i] <= 'z'){
      if (kModulata + stringa[i] > 'z'){
        cypher [i]= 'a' + kModulata - ('z' - stringa[i]) - 1;
      }else{
        cypher[i] = stringa[i] + kModulata;
      }
    }else{
      cypher[i] = stringa[i];
    }
  }

  cypher[lunghezza] = '\0';

  system("clear");


  if(k>26||k<0){
    printf("Chiave di cifratura modulata: %d ------> %d\n\n", k, kModulata );
  }else{
    printf("Chiave di cifratura: %d\n\n", kModulata );
  }

  cypherPrint( stringa, cypher);
}


//funzione che cripta una stringa tramite cifrario a sostituzione
void sostituzione (char stringa[]){

  int indice, l, lunghezza;
  char alfaMescolato[26];
  char alfa[27]=("abcdefghijklmnopqrstuvwxyz");

  system("clear");
  printf("Inserire un alfabeto mescolato:\n" );

//cattura dell'alfabeto mescolato in maniera ordinata e controllata
  for (int i=0; i<26; i++){

    if (i<9)
      printf("%d.  %c: ", i+1, alfa[i] );
    else
      printf("%d. %c: ", i+1, alfa[i] );

    scanf(" %c", &alfaMescolato[i] );
    getchar();
    alfaMescolato[i] = tolower(alfaMescolato[i]);

//controllo dei caratteri esterni ai possibili 26 dell'alfabeto
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
        alfaMescolato[i] = tolower(alfaMescolato[i]);
      } else{
        l=1;
      }
    }

//controllo dei caratteri ripetuti
    if(i>0){
      l=0;
      while(l==0){
        for (int k=0; k<i; k++){
          if (alfaMescolato[i]==alfaMescolato[k]){
            printf("\nHai gia inserito questo carattere.\n" );
            printf("Inserisci un carattere diverso\n" );

            if (i<9)
              printf("%d.  %c: ", i+1, alfa[i] );
            else
              printf("%d. %c: ", i+1, alfa[i] );

            scanf(" %c", &alfaMescolato[i] );
            getchar();
            alfaMescolato[i] = tolower(alfaMescolato[i]);
          }
        }
        l=1;
      }
    }

  }


  lunghezza = strlen(stringa);
  char cypher[lunghezza];

//algoritmo per cifrare con cifrario a sostituzione
  for (int i=0; i<lunghezza; i++){
    stringa[i]=tolower(stringa[i]);

    indice=((int)stringa[i])-97;
    if (stringa[i] >= 'a' && stringa [i] <= 'z'){
      cypher[i]=alfaMescolato[indice];
    }else{
      cypher[i]=stringa[i];
    }
  }

  cypher[lunghezza]='\0';

  system("clear");

  alfa[26] = '\0';
  printf("Alfabeto:           %s\n",alfa );
  printf("Alfabeto mescolato: %s\n\n",alfaMescolato );
  cypherPrint( stringa, cypher);

}


//stampa in maniera ordinata l'output del programma
void cypherPrint (char stringa[], char cypher[]){
  printf("Stringa originale ------> %s ",stringa );
  printf("Stringa criptata ------> %s\n", cypher);
}

//modula il valore della chiave in un valore contenuto in 26
int controlloChiave(int k){

  if (k>26)
    k=k-((k%26)*26);
  if (k<0&&k>-27)
    k=k+26;
  if (k<-26)
    k=26+(k%26);

  return k;
}
