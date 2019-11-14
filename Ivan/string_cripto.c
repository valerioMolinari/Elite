/*
  Chiedere all'utente l'alfabeto chiave;
  Leggerlo;
  Verificare se contiene tutte e sole le lettere dell'alfabeto,
  ovvero verificare se non ci sono lettere mancanti o ripetute;
  Possibile approccio: riordinare l'alfabeto chiave e confrontarlo
  con quello originale;
  Ripetere tutta la procedura finché l'utente non inserisce un alfabeto corretto;
  Per ogni lettera della parola/frase inserita dall'utente, trovare l'indice
  di quella lettera nell'alfabeto normale e sostituirla con la lettera che
  ha lo stesso indice nell'alfabeto chiave
*/

#include <stdio.h>
#include <string.h>

char frase[256];

void cesare () {
  int k;             //chiave di cifratura da inserire
  int i;
  int n=26;           //riporta a valori normali i char oltre il valore 122

  printf("Inserire una chiave di cifratura: ");
  scanf("%d", &k);

  if (k >= 1 && k<= 26) {               //condizione della chiave
  for (i=0; i<strlen(frase); i++)
    if (frase[i] + k > 122)          //superamento del valore di 122
      printf("%c", (frase[i]+ k) - n);
      else if (frase[i] + k >= 32 && frase[i] + k <= 96)  //valori da non modificare
      printf("%c", (frase[i] + k) - k);
      else printf("%c", frase[i] + k);   //valori accettabili
}
    else printf("Inserire una chiave tra i valori 1 e 26\n");

    printf("\n");
}


int main () {

  printf("Inserire la frase da criptare in sole lettere minuscole:\n"); //plaintext
  fgets(frase, sizeof(frase), stdin);

  cesare ();

  return 0;

}
