#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){

  system("clear");

  int k; // chiave per decifrare a scelta dall'utente

  char frase[256]; // frase presa da tastiera da codificare

  char cripto[256]; // frase criptata

  int cifrario; // scelta tra cifrario di Cesare e a Sostituzione

  printf("Immettere la frase da crittografare in minuscolo e solo lettere dell'alfabeto inglese:\n");
  fgets(frase, sizeof(frase), stdin); // input di una stringa
  system("clear");

  // l'utente sceglie la tipologia di cifratura
  printf("Con quale tipo di cifrario vuoi crittografare la tua frase:\n");
  printf("1: Il Cifrario di Cesare\n");
  printf("2: Il Cifrario a sostituzione\n");
  scanf("%d", &cifrario);

  // l'utente dovrà scegliere la chiave di cifratura e la frase verrà crittografata in base alla sua scelta
  if(cifrario == 1){
    printf("Hai scelto il Cifrario di Cesare\n");
    printf("Scegli la chiave per decifrare: ");
    scanf("%d", &k);
    if(k < 26 && k > 0){
      for (size_t i = 0; i < strlen(frase) - 1; i++) {
       cripto[i] = 97 + (((frase[i] % 97) +k) %26); // questa formula serve per cifrare la frase inserita dall'utente
       char tolower(frase[i]);
     }
     printf("La frase criptata è: %s", cripto);
    }
  // ho usato la funzione strlen perchè serve per calcolare la lunghezza di una stringa

  }else if(cifrario == 2){
    printf("Hai scelto Il Cifrario a sostituzione");
  }


}
