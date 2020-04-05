#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>

typedef enum Tipo_imprevisto
{
  nessun_imprevisto,
  crollo,
  baco
} enumImprevisto;

typedef enum Quantita_melassa
{
  nessuna,
  poca,
  molta = 3
} enumMelassa;

typedef enum Tipo_caverna
{
  normale,
  speciale,
  accidentata,
  uscita
} enumStato;

typedef enum Tipo_famiglia
{
  fArvais,
  fHartornen
} enumFamiglia;

typedef enum Mossa
{
  nessuna_mossa,
  avanza,
  abbatti,
  aggira,
  esci
} enumMossa;

typedef enum Tipo_probabilita
{
  melassa,
  imprevisto
} enumProbabilita;
///////////////////////////////////////////////////
//CAVERNE
//////////////////////////////////////////////////

typedef struct Caverna
{
  struct Caverna *avanti;
  struct Caverna *sinistra;
  struct Caverna *destra;
  char nextDirection;
  enumMelassa melassa;
  enumImprevisto imprevisto;
  enumStato stato;
} Caverna;

typedef struct Scavatrcie
{
  struct Caverna *posizione;
  short energia;
  short raccolta;
  short salute;
  unsigned short probabilitaScontro;
  unsigned short probabilitaUscita;
  enumFamiglia eFamiglia;
  enumMossa mossa;
} Scavatrice;

typedef Caverna *CavernaPtr;
typedef Scavatrice *ScavatricePtr;

void menu(bool *play);
