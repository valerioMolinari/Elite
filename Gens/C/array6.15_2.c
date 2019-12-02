#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

void bubbleSort(int * array, size_t size) {
  for (size_t i = 0; i < size - 1; i++) {
    for (size_t j = 0; j < size - (i + 1); j++) {
      if (array[j] > array[j + 1]) {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

int main() {
  system("clear");

  int scelte[SIZE];

  printf("Inserisci 20 numeri tra 10 e 100: ");

  for (size_t i = 0; i < SIZE; i++) {
    do {
      scanf("%d", &scelte[i]);
      if (scelte[i] < 10 || scelte[i] > 100)
        printf("\nIl numero inserito non è compreso tra 10 e 100 inclusi, inseriscilo di nuovo: ");
    } while(scelte[i] < 10 || scelte[i] > 100);
  }

  bubbleSort(scelte, SIZE);

  for (size_t i = 0; i < SIZE; i++) {
    if (scelte[i] == scelte[i - 1])
      continue;
    printf("%d ", scelte[i]);
  }
}
