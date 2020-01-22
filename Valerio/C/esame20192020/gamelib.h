#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef enum Tipo_imprevisto { nessun_imprevisto, crollo, baco } enumImprevisto;
typedef enum Quantita_melassa { nessuna, poca, molta = 3 } enumMelassa;
typedef enum Tipo_caverna { normale, speciale, accidentata, uscita } enumStato;
typedef enum Tipo_menu { first, cunicoli, caverneRandom, tipoCaverna, direzione, play, raccoltaMelassa, finale } enumMenu;
typedef enum Tipo_provenienzaMelassa { fromTipoCaverna, fromQuantitaMelassa, fromBaco } enumProvenienzaMelassa;
typedef enum Tipo_direzione_get_throw { avanti, indietro } enumDirezione;
typedef enum Tipo_famiglia { fArvais, fHartornen } enumFamiglia;
typedef enum Tipo_freeMap { freeEntrambi, freeArvais, freeHartornen } enumFree;
typedef enum Tipo_ragione { ragione_deallocazione, ragione_uscita, ragione_esaurimento, ragione_scontroFinale } enumRagione;
typedef enum Tipo_carica { _energia, _cura, _risveglio } enumCarica;
typedef enum Tipo_probabilita {
  melassa,
  imprevisto,
  specialeArvais,
  specialeHartornen,
  pStato,
  cPistolaLaser,
  cColpoEstraniante,
  cColpoAssassino,
  cSuperColpoEstraniante,
  cSuperColpoAssassino,
} enumProbabilita;
typedef enum Mossa_possibile {
  nessuna_mossa,
  mAvanza,
  mAbbatti,
  mAggira,
  mEsci,
  pistolaLaser,
  colpoEstraniante,
  colpoAssassino,
  superColpoEstraniante,
  superColpoAssassino,
  risveglioDelDormiente,
  richiamoDelBaco,
  ricaricaEnergia,
  cura
 } enumMossa;
typedef enum Oggetto_speciale {
  nessuno,
  moduloEstraniante,
  cercatoreAssassino,
  denteDiLeto,
  amplificatoreDiDolore,
  anelloDelSigillo,
  acquaDellaVita,
  risveglio
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
  unsigned short numero;
} Caverna;

typedef struct scavatrice {
  struct caverna *posizione;
  bool exit;
  bool sFinal;
  short energia;
  short raccolta;
  short salute;
  unsigned short abbattimenti;
  unsigned short aggiramenti;
  unsigned short azioni[8];
  unsigned short caricamento_azione;
  unsigned short caverneAttraversate;
  unsigned short invasioni;
  unsigned short probabilitaScontro;
  unsigned short probabilitaUscita;
  unsigned short vittorie;
  char *famiglia;
  enumFamiglia eFamiglia;
  enumMossa azione;
  enumSpeciale zaino[5];
} Scavatrice;

typedef Caverna *CavernaPtr;
typedef Scavatrice *ScavatricePtr;

void FirstMenu(bool * wannaPlay);

typedef unsigned short US;

#define clr system("clear");
