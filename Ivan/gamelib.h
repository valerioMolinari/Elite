#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct Scavatrice {
  struct Scavatrice *posizione;
  int serbatoio_energia;    //valore massimo 4
  int serbatoio_raccolta;   //valore massimo 10
};

struct caverna {
  int a;
  struct caverna *avanti;
  struct caverna *destra;
  struct caverna *sinistra;
  enum melassa {nessuna, poca, molta = 3} melassa;
  enum imprevisto {nessun_imprevisto, crollo, baco} imprevisto;
  enum tipo_caverna {normale, speciale, accidentata, uscita} tipo_caverna;
};
