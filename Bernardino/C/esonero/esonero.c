#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
system("clear");

int k; //chiave k del cifrario di sostituzione
char stringa[256]; // frase inserita da tastiera ancora da criptare
char frasecriptata[256]; //frase criptata mediante il cifrario di Cesare
int scelta; //valore di scelta fra cifrario di Cesare e cifrario a sostituzione

     printf("Per utilizzare il cifrario di Cesare premere il tasto 1\n");
     printf("Per utilizzare il cifrario a sostituzione premere il tasto 2\n");
     scanf("%d", &scelta);

     if(scelta == 1){

        system("clear");
        printf("Inserisci il valore della chiave k:\n");
        scanf("%d", &k);

        printf("Inserisci la frase che vuoi cifrare:\n");
        while('\n'!=getchar());
        fgets (stringa, sizeof(stringa), stdin);

        for (size_t i = 0; i < strlen(stringa) - 1; i++) {
          if(stringa[i] >= 97 && stringa[i] <= 122){

            char frasecriptata = 97 + (((stringa[i]%97)+k)%26);
            printf("La frase inserita criptata con il cifrario di Cesare è: %s", frasecriptata);

          }
        }
      }

     if(scelta == 2){

     }

     if(scelta != 1 && scelta != 2){
       printf("Premere un tasto valido all'esecuzione del programma\n");
     }
}
