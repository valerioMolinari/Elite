#include <stdio.h>

void print1DArray(size_t size, int array[size]);
void print2DArray(int riga, int col, int array[riga][col]);

int main(void) {
  printf("%s", "Inserisci dimensione del array unidimensionale:\n");
  int arraySize;
  scanf("%d", &arraySize);

  int array[arraySize]; //array unidimensionale di lunghezza variabile

  printf("%s", "Inserisci il numero di righe e colonne per l'array1 bidimensionale:\n");
  int riga1, col1; //lunghezza righe e colonna per array1
  scanf("%d%d", &riga1, &col1);

  int array2D1[riga1][col1]; //array bidimensionale di lunghezza variabile

  printf("%s", "Inserisci il numero di righe e colonne per l'array2 bidimensionale:\n");
  int riga2, col2; //lunghezza righe e colonne per array2
  scanf("%d%d", &riga2, &col2);

  int array2D2[riga2][col2]; //array bidimensionale di lunghezza variabile

  printf("\nLa dimensione dell'array è: %lu bytes\n", sizeof(array));

  for(size_t i = 0; i < arraySize; ++i){
    array[i] = i * i;
  }
  for(size_t i = 0; i < riga1; ++i){
    for(size_t j = 0; j < col1; ++j){
      array2D1[i][j] = i + j;
    }
    for(size_t i = 0; i < riga2; ++i){
      for(size_t j = 0; j < col2; ++j){
        array2D2[i][j] = i + j;
    }
  }
  puts("\nArray unidimensionale:");
  print1DArray(arraySize, array);
  puts("\nArray1 bidimensionale:");
  print2DArray(riga1, col1, array2D1);
  puts("\nArray2 bidimensionale:");
  print2DArray(riga2, col2, array2D2);
  }
}

void print1DArray(size_t size, int array[size]){
  for(size_t i = 0; i < size; i++){
    printf("array[%zu] = %d\n", i, array[i]);
  }
}

void print2DArray(int riga, int col, int array[riga][col]){
  for(size_t i = 0; i < riga; ++i){
    for(size_t j = 0; j < col; ++j){
      printf("%5d", array[i][j]);
    }
    puts("");
  }
}
