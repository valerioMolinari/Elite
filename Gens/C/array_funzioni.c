#include <stdio.h>
#include<stdlib.h>

#define SIZE 5
void modifyArray(int b[], size_t size);
void modifyElement(int e);

int main(void) {
  int a[SIZE] = {0,1,2,3,4}; //inizializza l'array a
  puts("Effetti del cambiamento di un array per riferimento:\n\nI valori dell'array originale sono:");

  //stampa l'array originario
  for(size_t i = 0; i < SIZE; i++){
    printf("%3d", a[i]);
  }
  puts("");

  modifyArray(a, SIZE); //passa l'array "a" a modifyArray per riferimento
  puts("I valori dell'array modificato sono:");

  //stampa l'array modificato
  for(size_t i = 0; i < SIZE; ++i){
    printf("%3d", a[i]);
  }
  //stampa il valore di a[3]
  printf("\n\nEffetti del cambiamento di un array per valore:\n\nIl valore di a[3] è: %d\n ", a[3]);

  modifyElement(a[3]); //passa l'elemento a[3] per valore

  //stampa il valore di a[3]
  printf("Il valore di a[3] é: %d\n", a[3]);
}
//nei parametri "b" si riferisce all'array originario "a" in memoria
void modifyArray(int b[], size_t size){
    //moltiplica ogni elemento dell'array per 2
    for(size_t j = 0; j < size; ++j){
      b[j] *= 2; //modifica in realtà l'array originario
    }
}

//nei parametri "e" è una copia locale dell'elemento dell'array a[3] passato da main
void modifyElement(int e){
  //moltiplica il parametro per 2
  printf("Il valore in modifyElement is %d\n", e *=2);
}
