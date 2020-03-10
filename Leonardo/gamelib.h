#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

struct Scavatrice{
    struct Caverna* posizione;
    int serbatoio;
    int serbatoio_raccolta;
};

struct Caverna{
    struct Caverna* avanti;
    struct Caverna* destra;
    struct Caverna* sinistra;
    enum {nessuna = 0, poca = 1, molta=3} quantita_melassa;
    enum {normale,speciale,accidentata,uscita} tipo_caverna;
    enum {nessuno, crollo, baco} imprevisto;
};

typedef struct Caverna Caverna;
void creaCunicoli(void);
