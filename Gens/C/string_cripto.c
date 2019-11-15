#include<stdio.h>  //libreria input output
#include<stdlib.h> //libreria che dichiara funzioni e costanti di utilità
#include<string.h> //libreria che gestisce le stringhe
#include<ctype.h> //libreria che dichiara funzioni per la classificazione dei caratteri

int main(void){

  system("clear");

  int k; // chiave per decifrare a scelta dall'utente
  int cifrario; // scelta tra cifrario di Cesare e a Sostituzione
  int count = 0; // serve per il ciclo se la k è minore di 0 o maggiore di 26

  char frase[256]; // frase presa da tastiera da codificare
  char cripto[256]; // frase criptata
  char alfabeto_mescolato[26]; // serve per l'alfabeto mescolato a scelta dell'utente

  printf("Immettere la frase da crittografare:\n");
  fgets(frase, sizeof(frase), stdin); // input di una stringa

  for(int i = 0; i < sizeof(frase); i++)
    frase[i] = tolower(frase[i]); // la funzione tolower cambia le lettere maiuscole in minuscole

  system("clear");

  // l'utente sceglie la tipologia di cifratura
  printf("Con quale tipo di cifrario vuoi crittografare la tua frase:\n");
  printf("1: Il Cifrario di Cesare\n");
  printf("2: Il Cifrario a sostituzione\n");
  scanf("%d", &cifrario);

  system("clear");

  // inizio cifrario di cesare: l'utente dovrà scegliere la chiave di cifratura e la frase verrà crittografata in base alla sua scelta
  if(cifrario == 1){
    printf("Hai scelto il Cifrario di Cesare\n");

    do {
      printf("Scegli la chiave per decifrare con valori da 1 a 25: \n");
      scanf("%d", &k);

      if(k < 26 && k > 0){
        for (size_t i = 0; i < strlen(frase) - 1; i++) {
            cripto[i] = 97 + (((frase[i] % 97) +k) %26); // questa formula serve per cifrare la frase inserita dall'utente
          }
        // ho usato la funzione strlen perchè serve per calcolare la lunghezza di una stringa
        cripto[strlen(frase)-1] = '\0';

        printf("La frase criptata è: %s", cripto);
        count = 1;

      }else{
        printf("Chiave non valida\n");
      }

    }while(count == 0);

  // inizio cifrario a sostituzione: l'utente dovrà immettere l'alfabeto a scelta sua poi verrà cifrata la frase in base alla sua scelta
  }else if(cifrario == 2){
     printf("Hai scelto Il Cifrario a sostituzione\n");
     printf("Immettere l'alfabeto mescolato a scelta dell'utente:\n");

     for (size_t i = 0; i < 26; i++) {
       scanf("%c", &alfabeto_mescolato[i]);
     }
      for (size_t i = 0; i < 26; i++) {
        for (size_t j = i + 1; j < 26; j++) {
          if(alfabeto_mescolato[i] == alfabeto_mescolato[j]){
        }
      }
    }
  }
}
