#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 256
#define ALPHA 26
#define A 97
#define Z 122

int main(void) {
  // Variabili predefinite
  char text[SIZE];
  const char alpha[ALPHA] = "abcdefghijklmnopqrstuvwxyz";
  char verifyAlpha[ALPHA];
  char subCypher[ALPHA];
  short cryptChoice = -1;
  short rightAlpha = 1;
  int key = 0;

  system("clear");
  printf("Inserisci una stringa di testo: ");
  fgets(text, SIZE, stdin);

  // Trasposizione del testo in minuscolo
  const int stringLength = strlen(text) - 1;
  for (size_t i = 0; i < stringLength; i++)
    text[i] = tolower(text[i]);

  do {
    // Menù di selezione cifratura
    system("clear");
    if (cryptChoice != -1)
      puts("Scelta non corretta!\n");
    printf("Seleziona un sistema per cifrare la stringa:\n\t1. Cifrario di Cesare\n\t2. Cifrario di sostituzione\n> ");
    scanf("%hd", &cryptChoice);
  } while(cryptChoice != 1 && cryptChoice != 2);

  switch (cryptChoice) {
    // Cifrario di cesare
    case 1:
      do {
        // Menù di inserimento chiave
        system("clear");
        if (key < 0) puts("Scelta non corretta!\n");
        printf("Inserisci una chiave (maggiore di 0): ");
        scanf("%d", &key);
      } while(key < 0);
      // Algoritmo di criptatura
      for (size_t i = 0; i < stringLength; i++)
        if (text[i] >= A && text[i] <= Z)
          text[i] = toupper((text[i] - A + key % 25) % 25 + A);

      system("clear");
      printf("La stringa inserita è stata criptata tramite il cifrario di Cesare:\n\n> %s\n", text);
      break;
    // Cifrario di sostituzione
    case 2:
      do {
        // Menù di inserimento alfabeto mescolato
        system("clear");
        if (!rightAlpha)
          puts("L'alfabeto inserito contiene lettere mancanti o ripetute\n");
        printf("Inserisci l'alfabeto di sostituzione: ");
        scanf("%s", subCypher);

        // Algoritmo di verifica alfabeto
        for (size_t i = 0; i < ALPHA; i++)
          verifyAlpha[i] = tolower(subCypher[i]);

        for (size_t i = 1; i < ALPHA; i++)
          for (size_t j = 0; j < 25 ; j++)
            if (verifyAlpha[j] > verifyAlpha[j + 1]) {
              char hold = verifyAlpha[j];
              verifyAlpha[j] = verifyAlpha[j + 1];
              verifyAlpha[j + 1] = hold;
            }

        for (size_t i = 0; i < ALPHA; i++)
          if (verifyAlpha[i] != alpha[i]) {
            rightAlpha = 0;
            break;
          } else
            rightAlpha = 1;
      } while(!rightAlpha);

      // Algoritmo di criptatura
      for (size_t i = 0; i < stringLength; i++)
        if (text[i] >= A && text[i] <= Z)
          text[i] = toupper(subCypher[text[i] - A]);
      system("clear");
      printf("La stringa inserita è stata criptata tramite il cifrario di sostituzione:\n\n> %s\n", text);
  }
}
