#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(void){
  char frase[256]; // frase presa da tastiera da codificare
  char cripto[256]; // frase criptata
  char alfabeto_mescolato[27] = {0};
  const char alfabeto_inglese[27] = "abcdefghijklmnopqrstuvwxyz";

  printf("Hai scelto Il Cifrario a sostituzione\n");
  printf("L'alfabeto inglese è: %s\n", alfabeto_inglese);
  printf("Immettere l'alfabeto mescolato a scelta dell'utente:\n");
  scanf("%s", alfabeto_mescolato);

  int p = 0;

  for(int i = 0; i < 25; i++){
    for (int l = i + 1; l < 25; l++){
      if(alfabeto_mescolato[l] != alfabeto_inglese[i] && p == 0){
        printf("L'alfabeto può essere utilizzato\n");
        p = 1;
      }
    }
  }
}
