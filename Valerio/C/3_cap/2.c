// Scrivete quattro differenti istruzioni in C
// che sommino 1 alla variabile intera x

#include <stdio.h>

int main(void) {
  int x = 0;
  /*
  # In un espressione utilizzando x++ si utilizza
  #  l'attuale valore di x, quindi se ne incrementa il valore di 1
  */
  x++;
  /*# In un espressione utilizzando ++x si incrementa il valore di x
  # di 1, quindi si utilizza il valore incrementato di x
  */
  ++x;
  /*# L'espressione x += 1 è equivalente all'espressione x = x + 1,
  #ovvero si sta incrementando il valore di x di un'unità
  */
  x += 1;
  x = x + 1;
}
