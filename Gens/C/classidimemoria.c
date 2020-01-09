#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void useGlobal(void); //per le variabili globali
void useLocal(void); //per le variabili locali
void useStaticLocal(void); //per le variabili statiche globali

int x = 1; //variabile globale

int main(){

    int x = 5; //variabile locale (per il main)
    printf("La variabile locale nel main é: %d\n", x);

    {
      int x = 7; //varibile locale in un nuovo blocco
      printf("La variabile locale nel nuovo blocco è: %d\n", x);
    }

    printf("La variabile locale nel main é: %d\n", x);

    useLocal();
    useStaticLocal();
    useGlobal();
    useLocal();
    useStaticLocal();
    useGlobal();

    printf("La variabile nel main é: %d\n", x);
}

void useLocal(void){
  int x = 25;
  printf("La variabile nella funzione useLocal é: %d\n", x);
  ++x;
  printf("La stessa variabile però incrementata è: %d\n", x);
}

void useStaticLocal(void){
  static int x = 50;
  printf("La variabile nella funzione useStaticLocal é: %d\n", x);
  ++x;
  printf("La stessa variabile però incrementata è: %d\n", x);
}

void useGlobal(void){
  printf("La variabile nella funzione useGlobal é: %d\n", x);
  x *= 10;
  printf("La stessa variabile però incrementata è: %d\n", x);
}
