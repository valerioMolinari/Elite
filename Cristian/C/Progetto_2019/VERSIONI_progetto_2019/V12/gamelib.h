#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

//VARIABILI GLOBALI
enum   Quantita_melassa {nessuna, poca, molta = 3};
enum   Tipo_imprevisto  {nessun_imprevisto, crollo, baco};
enum   Tipo_caverna     {normale, speciale, accidentata, uscita};

struct Caverna
  {
     struct Caverna *sinistra;
     struct Caverna *avanti;
     struct Caverna *destra;
     enum   Quantita_melassa melassa;
     enum   Tipo_imprevisto  imprevisto;
     enum   Tipo_caverna     caverna;
  };

struct Scavatrice
  {
     struct Caverna *pCaverna;
     short int serbatoio_energia;
     short int serbatoio_raccolta;
  };

//FUNZIONI ASCII ART
void print_gameover(void);
void print_lampeggio_gameover(void);
void print_nome(void);
void print_matricola(void);
void printfile(char str[]);

//FUNZIONI COLORI SHELL
void red (void);
void yellow (void);
void blu (void);
void magenta (void);
void green (void);
void cyan (void);
void reset (void);

//FUNZIONI MENU' PRINCIPALE
int crea_cunicoli (void);
int gioca (void);

//FUNZIONI MENU' CREA CUNICOLI
int  inserisci_caverna(void);
int  cancella_caverna(void);
void stampa_cunicolo(void);
void print_list(struct Caverna *pPrimo_chiamata);
int  richiesta_tipo_caverna (void);
int  count (struct Caverna *pPrimo);

//FUNZIONI MENU' GIOCA
int  avanza (struct Caverna *pAvanza,  struct Scavatrice *pPersonaggio, int i);
int  abbatti(struct Caverna *pAbbatti_caverna, struct Scavatrice *pPersonaggio, int i);
int  aggira (struct Caverna *pAggira_caverna,  struct Scavatrice *pPersonaggio, int i);
void controllo_serbatoio_energia_raccolta (void);
void elimina_tutte_caverne (struct Caverna *pPrimo_Elimina, struct Caverna *pUltimo_Elimina, int i, int flag_abbatti_Arvais, int flag_abbatti_Hartornen);


