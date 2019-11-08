/*
  Scrivere un'istruzione in C per eseguire ognuno dei seguenti compiti:
  a) Definire le variabili sum e x come tipo int
  b) Porre la variabile x a 1
  c) Porre la variabile sum a 0
  4) Sommare la variabile x alla variabile sum e assegnare il risultato
     alla variabile sum
  5) Stampare "The sum is: " seguito dal valore della variabile sum
*/
#include <stdio.h>

int main(void) {
  int sum, x;
  x = 1;
  sum = 0;
  sum += x;
  printf("The sum is: %d\n", sum);
}
