#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cittadinanza
  {
    char stato[15];
    unsigned int codice_postale;
  };

struct Residenti
  {
    char nome[15];
    char cognome[15];
    struct Cittadinanza Perugia_1;
  };

void print_residenti (struct Residenti comune)
  {
    printf ("Nome: %s\n", comune.nome);
    printf ("Cognome: %s\n", comune.cognome);
  }


void print_cittadinanza (struct Cittadinanza stato)
  {
    printf ("Stato: %s\n", stato.stato);
    printf ("codice_postale: %d\n", stato.codice_postale);
  }

int main() {

  struct Residenti Perugia =
    {
      "Cristian",
      "Cerami",
        {
          "Italia",
          06125
        }
    };

  print_residenti(Perugia);
  print_cittadinanza(Perugia.Perugia_1);

}
