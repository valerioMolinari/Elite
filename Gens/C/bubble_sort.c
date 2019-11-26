#include <stdio.h>

// Bubblesort = algoritmo per ordinare valori dal più piccolo al più grande

int main(void) {

  // L'utente immette il numero di elementi da inserire
  int n;
  printf("Inserisci il numero di elementi\n");
  scanf("%d", &n);

  // Poi immette tanti numeri quanti ne ha decisi sopra
  printf("Inserisci %d numeri interi\n", n);
  int array[n];

  // Riordina dal più piccolo al più grande
  int c, d, inverti;
  for(c = 0; c < n; ++c){
    scanf("%d", &array[c]);
  }for(c = 0; c < n+1; c++){
    for(d = 0; d < n-c-1; d++){
      if(array[d] > array[d+1]){
        inverti = array[d];
        array[d] = array[d+1];
        array[d+1] = inverti;
      }
    }
  }
    // Stampa i valori in ordine
    printf("I valori riordinati sono\n");
    for(int x = 0; x < n; ++x) {
      printf("%d\n", array[x]);
    }
}
