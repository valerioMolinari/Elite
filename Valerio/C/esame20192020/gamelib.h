#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef enum Tipo_imprevisto { nessun_imprevisto, crollo, baco } enumImprevisto;
typedef enum Quantita_melassa { nessuna, poca, molta = 3 } enumMelassa;
typedef enum Tipo_caverna { normale, speciale, accidentata, uscita } enumStato;
typedef enum Tipo_menu { first, cunicoli, tipoCaverna, direzione, play, raccoltaMelassa } enumMenu;
typedef enum Tipo_probabilita { melassa, imprevisto, specialeArvais, specialeHartornen } enumProbabilita;
typedef enum Tipo_provenienzaMelassa { fromTipoCaverna, fromQuantitaMelassa } enumProvenienzaMelassa;
typedef enum Tipo_direzione_get_throw { avanti, indietro } enumDirezione;
typedef enum Tipo_famiglia { fArvais, fHartornen} enumFamiglia;
typedef enum Mossa_possibile { mAvanza, mAbbatti, mAggira, mEsci } enumMossa;
typedef enum Oggetto_speciale {
  nessuno,
  moduloEstraniante,
  cercatoreAssassino,
  denteDiLeto,
  amplificatoreDiDolore,
  anelloDelSigillo,
  acquaDellaVita
} enumSpeciale;

typedef struct caverna {
  struct caverna *avanti;
  struct caverna *sinistra;
  struct caverna *destra;
  struct caverna *indietro;
  char nextDirection;
  enumMelassa melassa;
  enumImprevisto imprevisto;
  enumStato stato;
  enumSpeciale oggettoSpeciale;
} Caverna;

typedef struct scavatrice {
  struct caverna *posizione;
  short energia;
  short raccolta;
  char *famiglia;
  unsigned short caverneAttraversate;
  enumFamiglia eFamiglia;
  enumSpeciale zaino[4];
} Scavatrice;

typedef Caverna *CavernaPtr;
typedef Scavatrice *ScavatricePtr;

void FirstMenu(bool * wannaPlay);
void freeMap(bool * map);

typedef unsigned short US;
