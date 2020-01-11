/*
  Scrivere singole istruzioni im C per effettuare ciascuna delle seguenti azioni:
  a) Moltiplicare la variabile product per 2 usando l'operatore *=.
  b) Moltiplicare la variabile product per 2 usansdo gli operatori * e =.
  c) Verificare se il valore della variabile count è maggiore di 10.
     Se lo è, stampare "count is greater then 10"
  d) Calcolare il resto della divisione di q per divisore e assegnare il
     risultato a q. Scrivere questa istruzione in due modi differenti
  e) Stampare il valore 123.4567 con due cifre di precisione. Quale valore
     viene stampato?
  f) Stampare il valore del numero in virgola mobile 3.14159 con tre cifre
     alla destra del numero decimale. Quale valore viene stampato?
*/

#include <stdio.h>

int main(void) {
  int product = 1;
  //#x *= 2 è equivalente a x = x * 2;\n
  printf("Product: %d\n", product);
  product *= 2;
  printf("Product: %d\n", product);
  product = product * 2;
  printf("Product: %d\n", product);
  /*
  # Quando una selezione if contiene una sola istruzione è possibile scriverla
  # senza utilizzare le parentesi graffe e su una sola riga\n
  */
  int count = 12;
  printf("\nCount: %d\n", count);
  if (count > 10) puts("count is greater then 10");
  //# q %= divisore è equivalente a q = q % divisore\n
  int q = 47;
  int divisore = 4;
  printf("\nq: %d, divisore: %d\n", q, divisore);
  q %= divisore;
  printf("q: %d\n", q);
  q = 47;
  q = q % divisore;
  printf("q: %d\n", q);
  //# è possibile indicare la precisione di un numero in virgola mobile
  //# tramite lo specificatore di conversione '%' seguito dalla precisione\n
  //# espressa come .2f : %.2f
  float f = 123.4567;
  printf("\nf: %.2f\n", f);
  f = 3.14159;
  printf("f: %.3f\n", f);
}
