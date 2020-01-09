#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void staticArrayInit(void);
void automaticArrayInit(void);

int main(void) {
  puts("Prima chiamata delle funzioni: ");
  staticArrayInit();
  automaticArrayInit();

  puts("\n\nSeconda chiamata delle funzioni: ");
  staticArrayInit();
  automaticArrayInit();

  puts("");
}

void staticArrayInit(void){
  static int array1[3];
  puts("\nI valori della funzione staticArrayInit prima dell'incremento: ");

  for(size_t i = 0; i <= 2; ++i){
    printf("array1[%zu] = %d ", i, array1[i]);
  }
  puts("\nI valori della funzione staticArrayInit dopo l'incremento: ");

  for(size_t i = 0; i <= 2; ++i){
    printf("array1[%zu] = %d ", i, array1[i] += 5);
  }
}

void automaticArrayInit(void){
  int array2[3] = {1,2,3};
  puts("\nI valori della funzione automaticArrayInit prima dell'incremento: ");

  for(size_t i = 0; i <= 2; i++){
    printf("array2[%zu] = %d ", i, array2[i]);
  }
  puts("\nI valori della funzione automaticArrayInit dopo l'incremento: ");

  for(size_t i = 0; i <= 2; i++){
    printf("array[%zu] = %d ", i, array2[i] += 5);
  }
}
