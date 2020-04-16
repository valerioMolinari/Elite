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
     short int serbatoio_energia;
     short int serbatoio_raccolta;
     short int flag_mappa_cunicoli;
     short int numero_caverne;
     short int flag_morte;
     short int flag_uscita;
     short int flag_possibile_uscita;
     short int flag_crollo;
     short int flag_abbatti;
     short int last_direzione;
     short int direzione;
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
void controllo_serbatoio_energia_raccolta (struct Scavatrice *pPersonaggio, int i);
void elimina_tutte_caverne (struct Caverna *pPrimo_Elimina, struct Caverna *pUltimo_Elimina, int i, int flag_abbatti_Arvais, int flag_abbatti_Hartornen);


