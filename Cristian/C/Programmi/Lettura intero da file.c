
//Leggere un intero da file

#include <stdlib.h>
#include <stdio.h>

int main() {
  FILE *file1;
/*
Associo al file da aprire il descrittore fd.
Il descrittore è il valore che viene usato dalle successive funzioni
di accesso al file.
*/
  int x;

// Apro il file, leggo il numero, chiude il file

  file1 = fopen ("intero.txt", "r"); // r = metodo apertura file
  fscanf(file1, "%d", &x);
  fclose(file1);  // chiudo il file

// Stampo il numero

  printf("Il numero letto da file e' %d\n", x);

  return 0;
}
