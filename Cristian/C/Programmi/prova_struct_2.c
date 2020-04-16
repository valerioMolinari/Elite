#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cittadinanza
  {
    char stato[15];
    char codice_postale[7];
  };

struct Residenti
  {
    char nome[15];
    char cognome[15];
    struct Cittadinanza Perugia_1;
    struct Cittadinanza *pPerugia_1;
  };

void print_residenti (struct Residenti comune)
  {
    printf ("Nome: %s\n", comune.nome);
    printf ("Cognome: %s\n", comune.cognome);
  }


void print_cittadinanza (struct Cittadinanza stato)
  {
    printf ("Stato: %s\n", stato.stato);
    printf ("codice_postale: %s\n", stato.codice_postale);
  }

void red ()
  {
  printf("\033[1;31m");
  }

void yellow ()
  {
    printf("\033[1;33m");
  }

void reset ()
  {
    printf("\033[0m");
  }

int main() {

  struct Residenti Perugia;
  struct Cittadinanza Perugia_1;
  struct Cittadinanza *pPerugia_1;


  strcpy (Perugia.nome,"Cristian");
  strcpy (Perugia.cognome, "Cerami");

  strcpy (Perugia_1.stato, "Italia");
  //Perugia_1.codice_postale=06125;
  pPerugia_1 = &Perugia_1;
  strcpy (pPerugia_1 -> codice_postale, "06125");

  red();
  print_residenti(Perugia);
  yellow();
  print_cittadinanza(Perugia_1);
  reset();
}
