#include <stdio.h>
#include <string.h>
#include <ctype.h>


char frase[256];
int scelta;  //scelta del menù
char parola[50];     //parola chiave
char alfabeto[26]={"abcdefghijklmnopqrstuvwxyz"};
int x, j, y;         //variabili di iterazione
int spostamento;      //elemento corrispondente al valore dell'array parola

void cesare () {
  int k;             //chiave di cifratura da inserire
  int i;             //variabile di iterazione
  int n=26;           //riporta a valori normali i char oltre il valore 122

  printf("Inserire una chiave di cifratura: ");
  scanf("%d", &k);
  printf("\n");

  if (k >= 1 && k<= 26) {               //condizione della chiave
    for (i=0; i<strlen(frase)-1; i++)
      if (frase[i] + k > 122)          //superamento del valore di 122
      printf("%c", (frase[i]+ k) - n);
      else if (frase[i] + k >= 32 && frase[i] + k <= 96)  //valori da non modificare
      printf("%c", (frase[i] + k) - k);
      else printf("%c", frase[i] + k);   //valori accettabili
}
  else printf("Inserire una chiave tra i valori 1 e 26\n");

    printf("\n");
    printf("\n");
}

void sostituzione () {
  printf("Inserire una parola di sole minuscole e senza ripetizioni di lettere:\n");
  scanf("%s", parola);
  printf("\n");

  strncat(parola, alfabeto, 50);            //aggiunge l'alfabeto nell'arr parola
  for (x=0; x<strlen(parola); x++) {
    for (j=x+1; j<strlen(parola); j++) {
       if (parola[x] == parola[j])
         for (y=j; y<strlen(parola); y++) { //salta le lettere ripetute
           parola[y]=parola[y+1];}
         }
    }
    for (x=0;x<strlen(frase); x++) {
      if (frase[x]>='a' && frase[x]<='z') {
      spostamento=frase[x] - 97;
      frase[x]=toupper(parola[spostamento]);}
    }

    printf("%s", frase);
    printf("\n");
}

int main () {

  printf("Inserire la frase da criptare in sole lettere minuscole:\n"); //plaintext
  fgets(frase, sizeof(frase), stdin);

  printf("\n");
  //Menù del programma//
  while (scelta != 9) {

  printf("Premere 1 per criptare con il cifrario di Cesare\n");
  printf("Premere 2 per criptare con il cifrario a sostituzione\n");
  printf("Premere 9 per chiudere il programma\n");
  scanf(" %d", &scelta);


   if (scelta == 1)
    cesare ();
    else if (scelta == 2)
    sostituzione ();
    else if (scelta == 9)
    return 0;
    else printf("Errore: comando non valido\n");
}
return 0;
}
