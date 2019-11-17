#include<stdio.h>  // libreria input output
#include<stdlib.h> // libreria che dichiara funzioni e costanti di utilità
#include<string.h> // libreria che gestisce le stringhe
#include<ctype.h> // libreria che dichiara funzioni per la classificazione dei caratteri

int main(void){

  system("clear");

  // variabili usate per il codice
  int k; // chiave per decifrare a scelta dall'utente
  int cifrario; // scelta tra cifrario di Cesare e a Sostituzione
  int count = 0; // serve per il ciclo se la k è minore di 0 o maggiore di 26
  int controllo = 0; // variabile che serve nel controllo delle lettere ripetute nell'alfabeto mescolato
  //int c = 1; // variabile che controlla che non ci sono numeri nella frase

  char frase[256]; // frase presa da tastiera da codificare
  char cripto[256]; // frase criptata
  char alfabeto_mescolato[27] = {0}; // serve per l'alfabeto mescolato a scelta dell'utente
  const char alfabeto_inglese[] = "abcdefghijklmnopqrstuvwxyz"; // alfabeto inglese
  
  printf("Immettere la frase da crittografare:\n");
  fgets(frase, sizeof(frase), stdin); // input di una stringa
  for(int i = 0; i < sizeof(frase); i++)
    frase[i] = tolower(frase[i]); // la funzione tolower cambia le lettere maiuscole in minuscole

  // ho provato a creare un ciclo che serve a controllare se ci sono caratteri numerici
  /*while(c == 1){
    for (size_t i = 0; i < sizeof(frase); i++){
      if(frase[i] >= 97 && frase[i] <= 122){
          c = 0;
      }
    }if(c == 0){
      printf("Ho trovato caratteri numerici\n");
    }
      printf("Immettere la frase da crittografare:\n");
      fgets(frase, sizeof(frase), stdin);
      for(int i = 0; i < sizeof(frase); i++)
        frase[i] = tolower(frase[i]); // la funzione tolower cambia le lettere maiuscole in minuscole
  }*/

  system("clear");

  // l'utente sceglie la tipologia di cifratura
  printf("Con quale tipo di cifrario vuoi crittografare la tua frase:\n");
  printf("1: Il Cifrario di Cesare\n");
  printf("2: Il Cifrario a sostituzione\n");
  scanf("%d", &cifrario);

  system("clear");

  // inizio cifrario di cesare: l'utente dovrà scegliere la chiave di cifratura e la frase verrà cifrata in base alla sua scelta
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

  // inizio cifrario a sostituzione: l'utente dovrà immettere l'alfabeto mescolato poi verrà criptata la frase in base alla sua scelta
  }else if(cifrario == 2){
     printf("Hai scelto Il Cifrario a sostituzione\n");
     printf("Immettere l'alfabeto mescolato a scelta dell'utente:\n");
     scanf("%s", alfabeto_mescolato);

     // ho provato a far controllare che l'alfabeto sia di 26 caratteri
     /*while(c == 1){
       if(sizeof(alfabeto_mescolato) < 26 && sizeof(alfabeto_mescolato) > 26){
         printf("Reinserisci l'alfabeto mescolato");
       }else if(sizeof(alfabeto_mescolato) == 26){
         printf("Alfabeto accettato");
       }
     }*/

     // ciclo per il controllo di ripetizione degli elementi nell'array dell'alfabeto
     for(int i = 0; i < 25; i++){
       for (int l = i + 1; l < 25; l++){
         if(alfabeto_mescolato[l] != alfabeto_inglese[i] && controllo == 0){
           printf("L'alfabeto può essere utilizzato\n");
           controllo = 1;
         }
       }
     }
     for(int i = 0; i < frase[i]; i++ ){
      if(frase[i] >= 97 && frase[i] <= 122 ){
        cripto[i] = alfabeto_mescolato[frase[i] - 97];
      }
     }
    printf("La frase criptata è: %s", cripto);
  }
}
