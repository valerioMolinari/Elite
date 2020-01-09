#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct Caverna {
  int a;
  struct Caverna *avanti;
  struct Caverna *destra;
  struct Caverna *sinistra;
  enum melassa {nessuna, poca, molta = 3} melassa;
  enum imprevisto {nessun_imprevisto, crollo, baco} imprevisto;
  enum tipo_caverna {normale, speciale, accidentata, uscita} tipo_caverna;
};

struct Scavatrice {
  struct Caverna *posizione;
  int serbatoio_energia;    //valore massimo 4
  int serbatoio_raccolta;   //valore massimo 10
};

void crea_cunicoli ();
