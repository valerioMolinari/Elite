#include "gamelib.h"

//Variabili globali
static CavernaPtr primo_cunicolo_arvais = NULL;
static CavernaPtr primo_cunicolo_hartornen = NULL;
static Scavatrice arvais;
static Scavatrice hartornen;
static ScavatricePtr giocatoreAttuale;
static ScavatricePtr altroGiocatore;
static enumVittoria motivoVittoria;
static int x_max, y_max; //dimensioni massime dello schermo
static unsigned short turno;
static unsigned short lunghezzaPercorso;

//PROTOTIPI SULLE MAPPE
static void crea_cunicoli(bool *mappa); //Gestisce il menu di creazione della mappa
                                        //Funzione crea cunicoli moddata per la funzione load_mappa(bool *mappa)
static void crea_cunicoli_load(enumFamiglia famiglia, int melassa, int imprevisto, int stato, char nextDir);
static void ins_caverna(bool *mappa);                      //Gestisce il menu di creazione manuale delle caverne
static void ins_caverna_automatica(bool *mappa);           //Creazione automatica di una mappa di 10 caverne per famiglia
static void cattura_dati_creazione(enumFamiglia famiglia); //Chiede all'utente con che dati creare il cunicolo
                                                           //Crea effettivamente la caverna e la aggiunge alla lista
static void crea_caverna(enumFamiglia famiglia, int sceltaDirezione, int sceltaStato, bool abbatti);
static void inizializza_cuniccoli();                           //Inizializza i cunicoli iniziali delle famiglie ai valori di start
static void stampa_cunicolo(enumFamiglia famiglia, bool dati); //Stampa la mappa con o senza dati sensibili
static void canc_cavera();                                     //Funzione per cancellare una sola caverna (famiglia scelta dall'utente)
static void chiudi_cunicoli(bool *mappa);                      //Controlla se ci sono almeno 10 caverne per famiglia e setta la mappa a TRUE
static void salva_mappa(bool *mappa);                          //Salva la mappa in due file di testo (uno per famiglia)
static void load_mappa(bool *mappa);                           //Carica la mappa dai file di testo salvati
static void freeMappa(bool *mappa);                            //Cancella tutta la mappa e la setta a FALSE
static void freeAbbatti();                                     //Libera la memoria delle caverne non toccate dal player prima di un abbatti
                                                               //Gestisce le probabilità per le caverne
static unsigned short probabilita_caverna(enumProbabilita tipo, bool abbatti);

//PROTOTIPI DI GIOCO
static bool hack_game();                         //Minigame di hacking
static void minigame_menu();                     //Menu dei minigiochi
static void store();                             //Gestisce il comportamento del negozio dove si possono acquistare i buff di attacco e difesa tramite la melassa di raccolta
static void menu_scontro();                      //Gestice il menu di scontro per il player
static void attacca();                           //Gestisce il comportamento di attacca tenendo in conto il comportamento dei buff
static void difendi();                           //Gestisce il comportamento di difendi per il player
static void check_endgame(bool *end);            //Controlla se la salute di uno dei due giocatori è scesa sotto zero e dichiara il vincitore nello scontro finale
static void gioca(bool *mappa);                  //Funzione principale per la gestione del gameplay
static void inizializza_scavatrici();            //Inizializza le scavatrici ai valori di default
static void switchPlayer();                      //Gestisce il cambio di giocatore e incrementa le probabilità principali
static void controllo_caverna();                 //Funzione che si occupa di stampare a schermo i dati principali del gameplay
static void stampa_dati_caverna(bool *boolBaco); //stampa i dati sensibili sugli avvenimenti nella caverna
                                                 //Si occupa di aggiungere o sottrarre melassa ad uno dei serbatoi e di non farla andare oltre il suo massimo
static void gestione_melassa(short quantita, enumSerbatoio serbatoio);
static void menu_gameplay(bool *baco);      //Gestisce le pricipali richieste da fare all'utente nel gameplay, (Anche all'AI)
static void esci();                         //Fa uscire il giocatore se la caverna ha stato uscita
static bool baco_sabbie();                  //Gestisce il comportamento del baco (il return non è strettamente necessario)
static void avanza(bool boolAggira);        //Gestisce il comanndo avanza del player
static void aggira();                       //Gestisce il comando aggira del player
static void abbatti();                      //Gestisce il comando abbatti del player
static void scontro_finale();               //Gestisce il comportamento dello scontro finale
static void check_gameover(bool *gameover); //Controlla per vedere se uno dei due giocatori ha perso nel gioco normale e gestisce la probabilità di scontro
static void stampa_win();                   //Stampa a schermo il nome della famiglia che vince (Oppure il pareggio ma è estremamente raro)
static short scelta_AI(short lun);          //Simula il comportamento di una scelta da parte del giocatore
static void termina_gioco(bool *mappa);     //Dealloca la memoria e azzera le scavatrici alla fine della partita
static void azzera_scavatrici();            //Azzera tutti i parametri delle scavatrici
static void stampa_famiglia();              //Stampa a schermo il nome della famiglia del giocatore attuale
////PROTOTIPI ESTERNI
static int isEmpty(CavernaPtr caverna);                     //Controlla se una caverna sia vuota
static int stampa_menu_ncurse(char *arr[], int n, int lun); //Stampa un menu esteticamente carino tramite ncurses
static void printfile(char *str, short n);                  //Stampa su schermo i caratteri da un file di testo
void game_over();

//Funzione del menu principale
void menu(bool *play)
{
  int scelta = 0;
  bool mappa = false;
  getmaxyx(stdscr, y_max, x_max); //prende le dimensioni massime della finestra
  keypad(stdscr, TRUE);           //apre l'input alle freccie della tastiera

  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_BLUE, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_RED, COLOR_BLACK); //setta colore di stampa ncurses
  time_t t;
  srand((unsigned)time(&t));
  do
  {
    clear();
    printfile("dune.txt", 1);
    refresh();

    //menu e higlight
    char *arrMenuIniziale[] = {"Gioca", "Crea Cunicoli", "MiniGames", "Istruzioni", "Esci dal Gioco"};
    scelta = stampa_menu_ncurse(arrMenuIniziale, 14, 5);
    switch (scelta)
    {
    case 0:
      gioca(&mappa);
      break;
    case 1:
      crea_cunicoli(&mappa);
      break;
    case 2: //MINIGAMES
      minigame_menu();
      break;
    case 3:
      clear();
      printfile("istruzioni.txt", 1);
      getch();
      break;
    case 4:
      *play = FALSE;
      break;
    }
  } while (scelta != 4);
}

//Menu dei minigiochi
static void minigame_menu()
{
  unsigned short scelta;
  char *arr[] = {"Hacked", "Scontro Finale"};
  clear();
  printfile("mini.txt", 1);
  scelta = stampa_menu_ncurse(arr, 10, 2);
  switch (scelta)
  {

  case 0: //Hacking game(Volevo implementarlo nel gameplay)
    do
    {
      hack_game();
      clear();
      printw("Vuoi giocare di nuovo? Y o N\n");
    } while (getch() != 'n');
    break;

  case 1: //Per poter giocare allo scontro finale in maniera diretta
    do
    {
      inizializza_scavatrici();
      giocatoreAttuale = rand() % 2 ? &arvais : &hartornen;
      altroGiocatore = altroGiocatore == &arvais ? &hartornen : &arvais;
      giocatoreAttuale->raccolta = rand() % 11;
      altroGiocatore->raccolta = rand() % 11;
      scontro_finale();
      clear();
      printw("Vuoi giocare di nuovo? Y o N\n");
    } while (getch() != 'n');
    break;

  default:
    break;
  }
}

/////////////////////////////////////////////////////////////////////|
///////////////////////FUNZIONI SULLA MAPPA//////////////////////////|
/////////////////////////////////////////////////////////////////////|

//Inizializza i cunicoli iniziali delle famiglie ai valori di start
static void inizializza_cuniccoli()
{
  primo_cunicolo_arvais = (CavernaPtr)malloc(sizeof(Caverna));
  primo_cunicolo_hartornen = (CavernaPtr)malloc(sizeof(Caverna));
  CavernaPtr cunicolo[] = {primo_cunicolo_arvais, primo_cunicolo_hartornen};

  for (size_t i = 0; i < 2; i++)
  {
    cunicolo[i]->imprevisto = nessun_imprevisto;
    cunicolo[i]->melassa = nessuna;
    cunicolo[i]->stato = normale;
    cunicolo[i]->destra = NULL;
    cunicolo[i]->sinistra = NULL;
    cunicolo[i]->avanti = NULL;
    cunicolo[i]->indietro = NULL;
    cunicolo[i]->nextDirection = 'n';
  }
}

//Gestisce il menu di creazione della mappa
static void crea_cunicoli(bool *mappa)
{
  unsigned short scelta;
  do
  {
    clear();
    printfile("MenuCunicoli.txt", 1);

    char *arrMenuCunicoli[] = {"Inserisci caverne", "Creazione automatica", "Cancella Caverna",
                               "Stampa Mappa", "Salva Mappa", "Carica Mappa", "Chiudi Cunicoli", "Torna al menu"};

    scelta = stampa_menu_ncurse(arrMenuCunicoli, 10, 8);

    switch (scelta)
    {
    case 0:
      ins_caverna(mappa);
      break;
    case 1:
      ins_caverna_automatica(mappa);
      break;
    case 2:
      canc_cavera();
      break;
    case 3: //stampa i cunicoli compresi i dati nascosti
      stampa_cunicolo(fArvais, TRUE);
      stampa_cunicolo(fHartornen, TRUE);
      break;
    case 4:
      salva_mappa(mappa);
      getch();
      break;
    case 5:
      load_mappa(mappa);
      getch();
      break;
    case 6:
      chiudi_cunicoli(mappa);
      getch();
      break;
    default:
      break;
    }
  } while (scelta != 7);
}

//Chiede all'utente con che dati creare il cunicolo
static void cattura_dati_creazione(enumFamiglia famiglia)
{

  unsigned short counterPosizione = 0;
  int sceltaDirezione;
  int sceltaStato;
  char risposta = 'n';
  char *arrMenuDirezione[] = {"Avanti", "Destra", "Sinistra"};
  char *arrMenuStato[] = {"Normale", "Speciale", "Accidentata"};
  const char *posizione[] = {"prima", "seconda", "terza", "quarta", "quinta", "sesta", "settima", "ottava", "nona", "decima", "undicesima"}; //da allungare semmai

  do
  {
    if (risposta == 'y')
    {
      clear();
      printfile("InserimentoCaverne.txt", 1);
      move(10, 1);
      printw("In quale direzione vuoi che la caverna sia posizionata?");
      sceltaDirezione = stampa_menu_ncurse(arrMenuDirezione, 12, 3);

      sceltaDirezione = sceltaDirezione + 1;

      clear();
      printfile("InserimentoCaverne.txt", 1);
      move(10, 1);
      printw("Che Tipo di Caverna Deve Essere?");
      sceltaStato = stampa_menu_ncurse(arrMenuStato, 12, 3);

      sceltaStato = sceltaStato + 1;

      crea_caverna(famiglia, sceltaDirezione, sceltaStato, FALSE);
    }
    clear();
    printfile("InserimentoCaverne.txt", 1);
    move(10, 1);
    if (famiglia == fArvais)
    {
      printw("Vuoi inserire la %s caverna per la famiglia Arvais?\n Y o N\n>", posizione[counterPosizione]);
    }
    else
    {
      printw("Vuoi inserire la %s caverna per la famiglia hartornen?\n Y o N\n>", posizione[counterPosizione]);
    }

    refresh();
    risposta = getch();
    getch();
    counterPosizione++;
  } while (risposta == 'y');
}

//Crea effettivamente la caverna e la aggiunge alla lista
static void crea_caverna(enumFamiglia famiglia, int sceltaDirezione, int sceltaStato, bool abbatti)
{

  CavernaPtr newCunicolo = (CavernaPtr)malloc(sizeof(Caverna));
  newCunicolo->nextDirection = 'n';
  if (newCunicolo != NULL)
  {
    if (abbatti)
    {
      newCunicolo->stato = probabilita_caverna(pStato, abbatti);
    }
    else
    {
      switch (sceltaStato)
      {
      case 1:
        newCunicolo->stato = normale;
        break;
      case 2:
        newCunicolo->stato = speciale;
        break;
      case 3:
        newCunicolo->stato = accidentata;
        break;
      }
    }
    newCunicolo->melassa = probabilita_caverna(melassa, abbatti);
    newCunicolo->imprevisto = probabilita_caverna(imprevisto, abbatti);
    newCunicolo->destra = NULL;
    newCunicolo->sinistra = NULL;
    newCunicolo->avanti = NULL;

    CavernaPtr currentCunicolo = NULL;
    if (famiglia == fArvais)
    {
      currentCunicolo = primo_cunicolo_arvais;
    }
    else if (famiglia == fHartornen)
    {
      currentCunicolo = primo_cunicolo_hartornen;
    }

    while (currentCunicolo->nextDirection != 'n')
    {

      if (currentCunicolo->avanti != NULL)
      {
        currentCunicolo = currentCunicolo->avanti;
      }
      else if (currentCunicolo->destra != NULL)
      {
        currentCunicolo = currentCunicolo->destra;
      }
      else
      {
        currentCunicolo = currentCunicolo->sinistra;
      }
    }

    newCunicolo->indietro = currentCunicolo;

    if (sceltaDirezione == 1)
    {
      currentCunicolo->nextDirection = 'a';
      currentCunicolo->avanti = newCunicolo;
    }
    else if (sceltaDirezione == 2)
    {
      currentCunicolo->nextDirection = 'd';
      currentCunicolo->destra = newCunicolo;
    }
    else
    {
      currentCunicolo->nextDirection = 's';
      currentCunicolo->sinistra = newCunicolo;
    }
  }
  stampa_cunicolo(famiglia, FALSE);
}

//Gestisce il menu di creazione manuale delle caverne
static void ins_caverna(bool *mappa)
{

  if (*mappa)
  {
    clear();
    printw("La mappa gia esiste vuoi cancellarla?\nY o N");
    refresh();
    if (getch() == 'n')
      return;
    freeMappa(mappa);
  }
  clear();
  printfile("InserimentoCaverne.txt", 1);

  inizializza_cuniccoli();

  do
  {

    cattura_dati_creazione(fArvais);
    cattura_dati_creazione(fHartornen);

    clear();
    printfile("InserimentoCaverne.txt", 1);
    move(10, 1);
    printw("Vuoi Inserire Altre Caverne?\nY o N\n>");

  } while (getch() != 'n');
  getch();
}

//Creazione automatica di una mappa di 10 caverne per famiglia
static void ins_caverna_automatica(bool *mappa)
{
  if (*mappa)
  {
    clear();
    printw("La mappa gia esiste vuoi cancellarla?\nY o N");
    refresh();
    if (getch() == 'n')
      return;
    freeMappa(mappa);
  }

  int sceltaDirezione, sceltaStato;
  inizializza_cuniccoli();

  for (size_t i = 0; i < 2; i++)
  {
    for (size_t j = 1; j < 10; j++)
    {
      sceltaDirezione = (rand() % 3) + 1;
      sceltaStato = (rand() % 3) + 1;
      if (i == 0)
      {
        crea_caverna(fArvais, sceltaDirezione, sceltaStato, FALSE);
      }
      else
      {
        crea_caverna(fHartornen, sceltaDirezione, sceltaStato, FALSE);
      }
    }
  }
  chiudi_cunicoli(mappa);
}

//stampa la mappa con o senza dati sensibili
static void stampa_cunicolo(enumFamiglia famiglia, bool dati)
{
  clear();
  CavernaPtr scanCunicolo;
  if (famiglia == fArvais)
  {
    scanCunicolo = primo_cunicolo_arvais;
    printfile("Arvais.txt", 1);
  }
  else
  {
    scanCunicolo = primo_cunicolo_hartornen;
    printfile("hartornen.txt", 1);
  }

  if (isEmpty(scanCunicolo))
  {
    move(10, 1);
    printw("La Lista è Vuota!!!");
  }
  else
  {
    int n = 0;
    int y = 10, x;
    x = (x_max / 2) - 3; //per stamparla al centro dello schermo

    while (scanCunicolo != NULL)
    {
      if (scanCunicolo->stato == speciale)
      {
        attron(COLOR_PAIR(3));
        n = 3;
      }
      else if (scanCunicolo->stato == accidentata)
      {
        attron(COLOR_PAIR(4));
        n = 4;
      }
      move(y, x);
      if (scanCunicolo->nextDirection == 'n')
      {
        printw(" / \\");
        if (dati)
        {
          move(y + 2, x + 4);
          printw("Melassa: %d Imprevisto: %d", scanCunicolo->melassa, scanCunicolo->imprevisto);
        }

        move(y + 1, x);
        printw("|   |");
        move(y + 2, x);
        printw(" \\ /");
        move(y + 3, x);
        printw(" --");
      }
      else if (scanCunicolo->nextDirection == 'a')
      {
        printw(" / \\");

        if (dati)
        {
          move(y + 2, x + 4);
          printw("Melassa: %d Imprevisto: %d", scanCunicolo->melassa, scanCunicolo->imprevisto);
        }

        move(y + 1, x);
        printw("|   |");
        move(y + 2, x);
        printw(" | |");
        move(y + 3, x);
        printw(" | |");
      }
      else if (scanCunicolo->nextDirection == 'd')
      {
        printw(" / \\");

        if (dati)
        {
          move(y + 2, x + 4);
          printw("Melassa: %d Imprevisto: %d", scanCunicolo->melassa, scanCunicolo->imprevisto);
        }

        move(y + 1, x);
        printw("|   |");
        move(y + 2, x);
        printw(" \\ \\");
        move(y + 3, x);
        printw("  \\ \\");
        x = x + 3;
      }
      else
      {
        printw(" / \\");

        if (dati)
        {
          move(y + 2, x + 4);
          printw("Melassa: %d Imprevisto: %d", scanCunicolo->melassa, scanCunicolo->imprevisto);
        }

        move(y + 1, x);
        printw("|   |");
        move(y + 2, x);
        printw(" / /");
        move(y + 3, x);
        printw("/ /");
        x = x - 3;
      }
      y = y + 4;
      attroff(COLOR_PAIR(n));

      switch (scanCunicolo->nextDirection)
      {
      case 'a':
        scanCunicolo = scanCunicolo->avanti;
        break;
      case 'd':
        scanCunicolo = scanCunicolo->destra;
        break;
      case 's':
        scanCunicolo = scanCunicolo->sinistra;
        break;
      default:
        scanCunicolo = scanCunicolo->avanti;
        break;
      }
    }
    refresh();
  }
  getch();
}

//Funzione per cancellare una sola caverna (famiglia scelta dall'utente)
static void canc_cavera()
{
  int scelta;

  clear();
  printfile("MenuCancella.txt", 1);
  move(10, 1);
  printw("Di Quale famiglia vuoi cancellare la caverna?");
  char *arrMenuFamiglia[] = {"ARVAIS", "hartornen"};

  scelta = stampa_menu_ncurse(arrMenuFamiglia, 12, 2) + 1;

  CavernaPtr scanCunicolo;
  CavernaPtr temp;
  if (scelta == 1)
  {
    scanCunicolo = primo_cunicolo_arvais;
  }
  else
  {
    scanCunicolo = primo_cunicolo_hartornen;
  }
  if (scanCunicolo->nextDirection == 'n')
  {
    clear();
    printw("Non ci sono cunicoli di questa famiglia da cancellare...\nDeve essercene alemno uno!!!");
    getch();
  }
  else
  {
    while (scanCunicolo->nextDirection != 'n')
    {
      temp = scanCunicolo;
      switch (scanCunicolo->nextDirection)
      {
      case 'a':
        scanCunicolo = scanCunicolo->avanti;
        break;
      case 'd':
        scanCunicolo = scanCunicolo->destra;
        break;
      case 's':
        scanCunicolo = scanCunicolo->sinistra;
        break;
      default:
        break;
      }
    }

    free(scanCunicolo);
    temp->avanti = NULL;
    temp->destra = NULL;
    temp->sinistra = NULL;
    temp->nextDirection = 'n';

    if (scelta == 1)
    {
      stampa_cunicolo(fArvais, FALSE);
    }
    else
    {
      stampa_cunicolo(fHartornen, FALSE);
    }
  }
}

//Controlla se ci sono almeno 10 caverne per famiglia e setta la mappa a TRUE
static void chiudi_cunicoli(bool *mappa)
{
  int counterARV = 1, counterHAR = 1;
  int *ptrCount;
  CavernaPtr scanCunicolo;
  for (int i = 0; i < 2; i++)
  {
    if (i == 0)
    {
      scanCunicolo = primo_cunicolo_arvais;
      ptrCount = &counterARV;
    }
    else
    {
      scanCunicolo = primo_cunicolo_hartornen;
      ptrCount = &counterHAR;
    }

    while (scanCunicolo->nextDirection != 'n')
    {

      if (scanCunicolo->avanti != NULL)
      {
        scanCunicolo = scanCunicolo->avanti;
      }
      else if (scanCunicolo->destra != NULL)
      {
        scanCunicolo = scanCunicolo->destra;
      }
      else
      {
        scanCunicolo = scanCunicolo->sinistra;
      }
      *ptrCount += 1;
    }
  }

  lunghezzaPercorso = counterARV;
  if (counterARV >= 10 && counterHAR >= 10)
  {
    *mappa = true;
    clear();
    printw("Mappa Chiusa!!!");
    refresh();
    getch();
  }
  else
  {
    clear();
    printw("Non ci sono abbastanza caverne!!!");
    refresh();
    getch();
  }
}

//Cancella tutta la mappa e la setta a FALSE
static void freeMappa(bool *mappa)
{
  CavernaPtr cunicolo[] = {primo_cunicolo_arvais, primo_cunicolo_hartornen};
  CavernaPtr temp;

  for (size_t i = 0; i < 2; i++)
  {
    //va in fondo alla lista
    while (cunicolo[i]->nextDirection != 'n')
    {

      if (cunicolo[i]->avanti != NULL)
      {
        cunicolo[i] = cunicolo[i]->avanti;
      }
      else if (cunicolo[i]->destra != NULL)
      {
        cunicolo[i] = cunicolo[i]->destra;
      }
      else
      {
        cunicolo[i] = cunicolo[i]->sinistra;
      }
    }

    //Cancella gli elementi della lista
    while (cunicolo[i]->indietro != NULL)
    {
      temp = cunicolo[i];
      cunicolo[i] = cunicolo[i]->indietro;
      free(temp);
    }
  }

  *mappa = false;
}

//Salva la mappa in due file di testo (uno per famiglia)
static void salva_mappa(bool *mappa)
{
  clear();
  if (!*mappa)
  {
    printw("La mappa non è salvabile perchè non è stata chiusa!!!");
    refresh();
  }
  else
  {
    printw("salvataggio in corso...");
    refresh();
    sleep(1);
    move(2, 0);
    printw("Enter per andare avanti");
    refresh();
    CavernaPtr scanCunicolo;
    char dir[50] = "./Save/Arvais.txt";
    char dir2[50] = "./Save/hartornen.txt";
    for (int i = 0; i < 2; i++)
    {
      FILE *fors = fopen(i ? dir2 : dir, "w");

      if (i == 0)
      {
        fprintf(fors, "%c", primo_cunicolo_arvais->nextDirection);
        //salta il primo cunicolo
        switch (primo_cunicolo_arvais->nextDirection)
        {
        case 'a':
          scanCunicolo = primo_cunicolo_arvais->avanti;
          break;
        case 'd':
          scanCunicolo = primo_cunicolo_arvais->destra;
          break;
        case 's':
          scanCunicolo = primo_cunicolo_arvais->sinistra;
        default:
          break;
        }
      }
      else
      {
        fprintf(fors, "%c", primo_cunicolo_hartornen->nextDirection);
        //salta il primo cunicolo
        switch (primo_cunicolo_hartornen->nextDirection)
        {
        case 'a':
          scanCunicolo = primo_cunicolo_hartornen->avanti;
          break;
        case 'd':
          scanCunicolo = primo_cunicolo_hartornen->destra;
          break;
        case 's':
          scanCunicolo = primo_cunicolo_hartornen->sinistra;
        default:
          break;
        }
      }

      while (scanCunicolo != NULL)
      {
        //controllo melassa
        switch (scanCunicolo->melassa)
        {
        case nessuna:
          fprintf(fors, "0");
          break;
        case poca:
          fprintf(fors, "1");
          break;
        case molta:
          fprintf(fors, "2");
          break;
        default:
          break;
        }

        //controllo imprevisto
        switch (scanCunicolo->imprevisto)
        {
        case nessun_imprevisto:
          fprintf(fors, "0");
          break;
        case crollo:
          fprintf(fors, "1");
          break;
        case baco:
          fprintf(fors, "2");
          break;
        default:
          break;
        }

        //controllo stato
        switch (scanCunicolo->stato)
        {
        case normale:
          fprintf(fors, "0");
          break;
        case speciale:
          fprintf(fors, "1");
          break;
        case accidentata:
          fprintf(fors, "2");
          break;
        default:
          break;
        }

        //controllo next direction
        fprintf(fors, "%c", scanCunicolo->nextDirection);

        switch (scanCunicolo->nextDirection)
        {
        case 'a':
          scanCunicolo = scanCunicolo->avanti;
          break;
        case 'd':
          scanCunicolo = scanCunicolo->destra;
          break;
        case 's':
          scanCunicolo = scanCunicolo->sinistra;
          break;
        default:
          scanCunicolo = scanCunicolo->avanti;
          break;
        }
      }
      fclose(fors);
    }
  }
}

//Carica la mappa dai file di testo salvati
static void load_mappa(bool *mappa)
{
  clear();
  if (*mappa)
  {
    printw("La mappa già esiste e sta venendo cancellata!!!");
    refresh();
    freeMappa(mappa);
    return;
  }
  else
  {
    printw("Caricamento in corso...");
    refresh();
    sleep(1);
    move(2, 0);
    printw("Enter per andare avanti");
    refresh();
    char dir[50] = "./Save/";
    char dir2[50] = "./Save/";
    char nextDir;
    int melassa, imprevisto, stato;
    inizializza_cuniccoli();

    for (int i = 0; i < 2; i++)
    {
      if (i == 0)
      {
        strcat(dir, "Arvais.txt");
      }
      else
      {
        strcat(dir2, "hartornen.txt");
      }
      FILE *fors = fopen(i ? dir2 : dir, "r");

      while (1)
      {
        //controllo prossima mossa
        fscanf(fors, "%1c", &nextDir);
        if (nextDir == 'n')
          break;
        //controllo melassa
        fscanf(fors, "%1d", &melassa);

        //controllo imprevisto
        fscanf(fors, "%1d", &imprevisto);

        //controllo stato
        fscanf(fors, "%1d", &stato);

        if (i == 0)
        {
          crea_cunicoli_load(fArvais, melassa, imprevisto, stato, nextDir);
        }
        else
        {
          crea_cunicoli_load(fHartornen, melassa, imprevisto, stato, nextDir);
        }
      }
      fclose(fors);
    }
  }
  stampa_cunicolo(fArvais, FALSE);
  getch();
  stampa_cunicolo(fHartornen, FALSE);
  getch();
  chiudi_cunicoli(mappa);
}

//Funzione crea cunicoli moddata per la funzione load_mappa(bool *mappa)
static void crea_cunicoli_load(enumFamiglia famiglia, int melassa, int imprevisto, int stato, char nextDir)
{
  CavernaPtr newCunicolo = (CavernaPtr)malloc(sizeof(Caverna));
  newCunicolo->nextDirection = 'n';
  if (newCunicolo != NULL)
  {

    //controllo melassa
    switch (melassa)
    {
    case 0:
      newCunicolo->melassa = nessuna;
      break;
    case 1:
      newCunicolo->melassa = poca;
      break;
    case 2:
      newCunicolo->melassa = molta;
      break;
    default:
      break;
    }

    //controllo imprevisto
    switch (imprevisto)
    {
    case 0:
      newCunicolo->imprevisto = nessun_imprevisto;
      break;
    case 1:
      newCunicolo->imprevisto = crollo;
      break;
    case 2:
      newCunicolo->imprevisto = baco;
      break;
    default:
      break;
    }

    //controllo stato
    switch (stato)
    {
    case 0:
      newCunicolo->stato = normale;
      break;
    case 1:
      newCunicolo->stato = speciale;
      break;
    case 2:
      newCunicolo->stato = accidentata;
      break;
    default:
      break;
    }

    newCunicolo->destra = NULL;
    newCunicolo->sinistra = NULL;
    newCunicolo->avanti = NULL;

    CavernaPtr currentCunicolo = NULL;
    if (famiglia == fArvais)
    {
      currentCunicolo = primo_cunicolo_arvais;
    }
    else if (famiglia == fHartornen)
    {
      currentCunicolo = primo_cunicolo_hartornen;
    }

    while (currentCunicolo->nextDirection != 'n')
    {

      if (currentCunicolo->avanti != NULL)
      {
        currentCunicolo = currentCunicolo->avanti;
      }
      else if (currentCunicolo->destra != NULL)
      {
        currentCunicolo = currentCunicolo->destra;
      }
      else
      {
        currentCunicolo = currentCunicolo->sinistra;
      }
    }

    newCunicolo->indietro = currentCunicolo;

    if (nextDir == 'a')
    {
      currentCunicolo->nextDirection = 'a';
      currentCunicolo->avanti = newCunicolo;
    }
    else if (nextDir == 'd')
    {
      currentCunicolo->nextDirection = 'd';
      currentCunicolo->destra = newCunicolo;
    }
    else
    {
      currentCunicolo->nextDirection = 's';
      currentCunicolo->sinistra = newCunicolo;
    }
  }
}

//Gestisce le probabilità per le caverne
static unsigned short probabilita_caverna(enumProbabilita tipo, bool abbatti)
{
  unsigned short random = rand() % 101;
  switch (tipo)
  {
  case melassa:
    if (random > 80)
      return molta;
    else if (random > (abbatti ? 40 : 50))
      return poca;
    else
      return nessuna;
    break;
  case imprevisto:
    if (random > (abbatti ? 80 : 85))
      return baco;
    else if (random > (abbatti ? 40 : 50))
      return crollo;
    else
      return nessun_imprevisto;
    break;

  case pStato:
    if (random > (100 - giocatoreAttuale->probabilitaUscita))
      return uscita;
    else if (random > (80 - giocatoreAttuale->probabilitaUscita))
      return accidentata;
    else if (random > (80 - giocatoreAttuale->probabilitaUscita) / 2)
      return speciale;
    else
      return normale;
    break;
  }
}

/////////////////////////////////////////////////////////////////////|
/////////////////////////FUNZIONI DI GIOCO///////////////////////////|
/////////////////////////////////////////////////////////////////////|

//Funzione principale per la gestione del gameplay
static void gioca(bool *mappa)
{

  if (*mappa == FALSE)
  {
    clear();
    printw("Devi creare la mappa di gioco prima di poter giocare!!!");
    refresh();
    getch();
    return;
  }
  char *arrMenuGioco[] = {"1 VS 1", "1 VS AI"};
  clear();
  printfile("dune.txt", 1);

  turno = 0;
  bool gameOver = FALSE;
  giocatoreAttuale = rand() % 2 ? &arvais : &hartornen;
  altroGiocatore = altroGiocatore == &arvais ? &hartornen : &arvais;
  inizializza_scavatrici();

  switch (stampa_menu_ncurse(arrMenuGioco, 14, 2))
  {
  case 0:
    break;
  case 1:
    giocatoreAttuale->AI = TRUE;
  }

  do
  {
    switchPlayer();

    stampa_cunicolo(giocatoreAttuale->eFamiglia, FALSE); //semmai da implementare un indicatore di posizione (Non molto facile con NCurses)
    controllo_caverna();

    check_gameover(&gameOver);

  } while (!gameOver);
  stampa_win();
  termina_gioco(mappa);
}

//Inizializza le scavatrici ai valori di default
static void inizializza_scavatrici()
{
  ScavatricePtr scavatrice[] = {&arvais, &hartornen};
  for (size_t i = 0; i < 2; i++)
  {
    scavatrice[i]->energia = 4;
    scavatrice[i]->raccolta = 0;
    scavatrice[i]->eFamiglia = i ? fHartornen : fArvais;
    scavatrice[i]->ultimaMossaScontro = 'n';
    scavatrice[i]->AI = FALSE;
    scavatrice[i]->abbatti = FALSE;
    scavatrice[i]->uscito = FALSE;
    scavatrice[i]->win = FALSE;
    scavatrice[i]->aggira = FALSE;
    scavatrice[i]->attaccoBuff = FALSE;
    scavatrice[i]->difesaBuff = FALSE;
    scavatrice[i]->posizione = i ? primo_cunicolo_hartornen : primo_cunicolo_arvais;
    scavatrice[i]->salute = 100;
  }
}

//gestisce il cambio di giocatore e incrementa le probabilità principali
static void switchPlayer()
{
  turno++;
  if (!altroGiocatore->uscito) // blocca il cambio di giocatore nel momento in cui uno dei due è uscito
  {
    altroGiocatore = giocatoreAttuale;
    giocatoreAttuale = giocatoreAttuale == &arvais ? &hartornen : &arvais;
  }

  giocatoreAttuale->probabilitaScontro += 3;

  if (turno < 10)
  {
    giocatoreAttuale->probabilitaUscita += 5;
  }
  else
  {
    giocatoreAttuale->probabilitaUscita += 50;
  }
  if (giocatoreAttuale->probabilitaUscita > 100)
  {
    giocatoreAttuale->probabilitaUscita = 100;
  }
}

//Funzione che si occupa di stampare a schermo i dati principali del gameplay
static void controllo_caverna()
{
  clear();
  bool boolBaco = FALSE;

  stampa_famiglia();
  move(10, 0);
  printw("...................................................................\n\n");
  printw("Turno: %d\n", turno);
  printw("...................................................................\n\n");
  printw("Serbatoio Energia: %d\n", giocatoreAttuale->energia);
  printw("Serbatoio Raccolta: %d\n", giocatoreAttuale->raccolta);
  printw("...................................................................\n\n");
  printw("AVVENIMENTI\n\n");
  printw(";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n\n");

  if (turno < 3) //utile dato che il primo cunicolo per ogni famiglia è neutrale
  {
    printw("Benvenuto al campo base capitano...Buona raccolta!!!\n");
  }
  else
  {
    stampa_dati_caverna(&boolBaco);
  }
  getch();
  menu_gameplay(&boolBaco);

  getch();
}

//stampa i dati sensibili sugli avvenimenti nella caverna
static void stampa_dati_caverna(bool *boolBaco)
{
  short somma = 0;

  if (giocatoreAttuale->posizione->imprevisto == baco)
  {

    *boolBaco = baco_sabbie();
  }
  else
  {

    switch (giocatoreAttuale->posizione->melassa)
    {
    case nessuna:
      printw("Non c'è mellassa\n");
      break;
    case poca:
      printw("La Caverna irradia melassa: ");
      attron(COLOR_PAIR(1));
      printw("+1\n");
      attroff(COLOR_PAIR(1));
      somma += 1;
      break;
    case molta:
      printw("La Caverna irradia molta melassa: ");
      attron(COLOR_PAIR(1));
      printw("+3\n");
      attroff(COLOR_PAIR(1));
      somma += 3;
      break;
    }

    switch (giocatoreAttuale->posizione->stato)
    {
    case normale:
      break;
    case speciale:
      gestione_melassa(1, energia);
      printw("La caverna è speciale: ");
      attron(COLOR_PAIR(3));
      printw("+1\n");
      attroff(COLOR_PAIR(3));
      break;
    case accidentata:
      gestione_melassa(-1, energia);
      printw("La Caverna è accidentata");
      attron(COLOR_PAIR(4));
      printw("-1\n");
      attroff(COLOR_PAIR(4));
      break;
    case uscita:
      esci();
      return;
      break;
    }

    if (giocatoreAttuale->posizione->imprevisto == crollo)
    {
      gestione_melassa(-1, energia);
      printw("C'è stato un crollo: ");
      attron(COLOR_PAIR(4));
      printw("-1\n");
      attroff(COLOR_PAIR(4));
    }

    printw("...................................................................\n\n");
    attron(COLOR_PAIR(1));
    printw("Totale melassa da poter aggiungere ad un serbatoio: %d\n", somma);
    attroff(COLOR_PAIR(1));

    printw(";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n\n");

    if (somma > 0 && !giocatoreAttuale->uscito)
    {
      int scelta = 0;
      printw("In quale serbatoio vuoi mettere la melassa?\n");
      char *arrMelassa[] = {"Energia", "Raccolta"};

      if (giocatoreAttuale->AI) //QUESTA SCRITTURA è PER IL CONTROLLO DELL'AI, (SIMILE IN TUTTO IL PROGRAMMA)
      {
        scelta = scelta_AI(2);
      }
      else
      {
        scelta = stampa_menu_ncurse(arrMelassa, 33, 2);
      }

      if (scelta == 0)
      {
        gestione_melassa(somma, energia);
      }
      else
      {
        gestione_melassa(somma, raccolta);
      }
    }
  }
}

//Si occupa di aggiungere o sottrarre melassa ad uno dei serbatoi e di non farla andare oltre il suo massimo
static void gestione_melassa(short quantita, enumSerbatoio serbatoio)
{
  if (serbatoio == energia)
  {
    giocatoreAttuale->energia += quantita;
  }
  else
  {
    giocatoreAttuale->raccolta += quantita;
  }
  if (giocatoreAttuale->energia > 4)
  {
    giocatoreAttuale->energia = 4;
  }
  if (giocatoreAttuale->raccolta > 10)
  {
    giocatoreAttuale->raccolta = 10;
  }
}

//Gestisce le pricipali richieste da fare all'utente nel gameplay, (Anche all'AI)
static void menu_gameplay(bool *baco)
{
  unsigned short scelta = 0;
  clear();
  stampa_famiglia();
  if (!giocatoreAttuale->AI)
  {

    printw("Scegli la prossima mossa:\n");
  }
  if (*baco) //se il baco è stato riscontrato
  {
    if (giocatoreAttuale->abbatti)
    {
      char *arrBaco[] = {"Abbatti"};

      if (giocatoreAttuale->AI)
      {
      }
      else
      {
        stampa_menu_ncurse(arrBaco, 15, 1);
      }

      abbatti();
    }
    else
    {
      char *arrBaco[] = {"Avanza"};

      if (giocatoreAttuale->AI)
      {
      }
      else
      {
        stampa_menu_ncurse(arrBaco, 15, 1);
      }

      avanza(TRUE);
    }
    *baco = FALSE;
  }

  else if (giocatoreAttuale->abbatti) //continua la streak di abbatti
  {
    char *arrAbbatti[] = {"Abbatti"};
    if (giocatoreAttuale->AI)
    {
    }
    else
    {
      stampa_menu_ncurse(arrAbbatti, 15, 1);
    }

    abbatti();
  }
  else //comportamento normale del menu
  {
    char *arr[] = {"Avanza", "Abbatti"};

    if (giocatoreAttuale->AI)
    {
      scelta = scelta_AI(2);
    }
    else
    {
      scelta = stampa_menu_ncurse(arr, 15, 2);
    }

    if (scelta == 0)
    {
      avanza(TRUE);
    }
    else
    {
      abbatti();
    }
  }
}

//Fa uscire il giocatore se la caverna ha stato uscita
static void esci()
{
  clear();
  stampa_famiglia();
  printfile("uscita.txt", 1);
  printw("Congratulazioni sei uscito!!!");
  giocatoreAttuale->uscito = TRUE;
}

//Gestisce il comportamento del baco (il return non è strettamente necessario)
static bool baco_sabbie()
{
  clear();
  printfile("baco.txt", 1);
  printw("Il baco ha divorato tutta la melassa nei tuoi serbatoi!!!\n");
  giocatoreAttuale->energia = 0;
  giocatoreAttuale->raccolta = 0;
  return TRUE;
}

//Gestisce il comanndo avanza del player
static void avanza(bool boolAggira)
{
  if (boolAggira) //evita che si crei più di un aggira() di seguito
  {
    if (rand() % 101 > 75)
    {
      clear();
      stampa_famiglia();
      char *arr[] = {"Aggira"};

      printw("C'è stato un crollo impovviso\n");

      if (giocatoreAttuale->AI)
      {
      }
      else
      {
        stampa_menu_ncurse(arr, 15, 1);
      }

      aggira();
      return;
    }
  }

  switch (giocatoreAttuale->posizione->nextDirection)
  {
  case 'a':
    giocatoreAttuale->posizione = giocatoreAttuale->posizione->avanti;
    break;
  case 'd':
    giocatoreAttuale->posizione = giocatoreAttuale->posizione->destra;
    break;
  case 's':
    giocatoreAttuale->posizione = giocatoreAttuale->posizione->sinistra;
    break;
  default:
    break;
  }
}

//gestisce il comando aggira del player
static void aggira()
{
  clear();
  stampa_famiglia();
  printw("In quale direzione vuoi andare? \n");
  char direzione;
  unsigned short scelta = 0;

  char *arrADS[] = {"Avanti", "Destra", "Sinistra"};

  if (giocatoreAttuale->AI)
  {
    scelta = scelta_AI(3);
  }
  else
  {
    scelta = stampa_menu_ncurse(arrADS, 16, 3);
  }

  switch (scelta)
  {
  case 0:
    direzione = 'a';
    break;
  case 1:
    direzione = 'd';
    break;
  case 2:
    direzione = 's';
    break;
  default:
    direzione = 'n';
    break;
  }

  CavernaPtr arrivo;
  arrivo = giocatoreAttuale->posizione;
  //prendo i dati del cunicolo di arrivo
  switch (arrivo->nextDirection)
  {
  case 'a':
    arrivo = arrivo->avanti;
    break;
  case 'd':
    arrivo = arrivo->destra;
    break;
  case 's':
    arrivo = arrivo->sinistra;
    break;

  default:
    break;
  }
  //parametri azzerati per far funzionare il crea_caverna()
  giocatoreAttuale->posizione->avanti = NULL;
  giocatoreAttuale->posizione->destra = NULL;
  giocatoreAttuale->posizione->sinistra = NULL;
  giocatoreAttuale->posizione->nextDirection = 'n';

  crea_caverna(giocatoreAttuale->eFamiglia, scelta + 1, 0, TRUE);

  CavernaPtr temp;
  switch (direzione)
  {
  case 'a':
    temp = giocatoreAttuale->posizione->avanti;
    break;
  case 'd':
    temp = giocatoreAttuale->posizione->destra;
    break;
  case 's':
    temp = giocatoreAttuale->posizione->sinistra;
    break;
  }

  //collega la caverna appena creata
  arrivo->indietro = temp;
  temp->nextDirection = 'a';
  temp->avanti = arrivo;
  giocatoreAttuale->posizione = temp;
  stampa_cunicolo(giocatoreAttuale->eFamiglia, FALSE);
  avanza(FALSE);
}

//Gestisce il comando abbatti del player
static void abbatti()
{
  clear();
  stampa_famiglia();
  giocatoreAttuale->energia--;
  char direzione;
  unsigned short scelta = 0;
  char *arrDA[] = {"Avanti", "Destra"};
  char *arrDS[] = {"Destra", "Sinistra"};
  char *arrAS[] = {"Avanti", "Sinistra"};
  char *arrADS[] = {"Avanti", "Destra",
                    "Sinistra"};

  printw("In quale direzione vuoi abbattere?\n");

  //prende la scelta stampando al giocatore solo le direzioni possibili
  switch (giocatoreAttuale->posizione->nextDirection)
  {
  case 'a':
    if (giocatoreAttuale->AI)
    {
      scelta = scelta_AI(2);
    }
    else
    {
      scelta = stampa_menu_ncurse(arrDS, 15, 2);
    }

    if (scelta == 0)
    {
      direzione = 'd';
      scelta = 2;
    }
    else
    {
      direzione = 's';
      scelta = 3;
    }
    break;
  case 'd':

    if (giocatoreAttuale->AI)
    {
      scelta = scelta_AI(2);
    }
    else
    {
      scelta = stampa_menu_ncurse(arrAS, 15, 2);
    }

    if (scelta == 0)
    {
      direzione = 'a';
      scelta = 1;
    }
    else
    {
      direzione = 's';
      scelta = 3;
    }
    break;
  case 's':

    if (giocatoreAttuale->AI)
    {
      scelta = scelta_AI(2);
    }
    else
    {
      scelta = stampa_menu_ncurse(arrDA, 15, 2);
    }

    if (scelta == 0)
    {
      direzione = 'a';
      scelta = 1;
    }
    else
    {
      direzione = 'd';
      scelta = 2;
    }
    break;

  default:
    if (giocatoreAttuale->AI)
    {
      scelta = scelta_AI(3);
    }
    else
    {
      scelta = stampa_menu_ncurse(arrADS, 15, 3);
    }

    if (scelta == 0)
    {
      direzione = 'a';
      scelta = 1;
    }
    else if (scelta == 1)
    {
      direzione = 'd';
      scelta = 2;
    }
    else
    {
      direzione = 's';
      scelta = 3;
    }

    break;
  }

  //se è il primo abbatti dealloca la memoria dinamica per tutte le caverne che non verranno utilizzate
  if (!giocatoreAttuale->abbatti)
  {
    freeAbbatti();
    giocatoreAttuale->abbatti = TRUE;
    giocatoreAttuale->posizione->avanti = NULL;
    giocatoreAttuale->posizione->sinistra = NULL;
    giocatoreAttuale->posizione->destra = NULL;
    giocatoreAttuale->posizione->nextDirection = 'n';
  }

  crea_caverna(giocatoreAttuale->eFamiglia, scelta, 0, TRUE);
  avanza(TRUE);
}

//Simula il comportamento di una scelta da parte del giocatore
static short scelta_AI(short lun)
{
  return rand() % lun;
}

//Libera la memoria delle caverne non toccate dal player prima di un abbatti
static void freeAbbatti()
{
  unsigned short i;
  if (giocatoreAttuale->eFamiglia == fArvais)
  {
    i = 0;
  }
  else
  {
    i = 1;
  }
  CavernaPtr cunicolo[] = {primo_cunicolo_arvais, primo_cunicolo_hartornen};
  CavernaPtr temp;

  //va in fondo alla lista
  while (cunicolo[i]->nextDirection != 'n')
  {

    if (cunicolo[i]->avanti != NULL)
    {
      cunicolo[i] = cunicolo[i]->avanti;
    }
    else if (cunicolo[i]->destra != NULL)
    {
      cunicolo[i] = cunicolo[i]->destra;
    }
    else
    {
      cunicolo[i] = cunicolo[i]->sinistra;
    }
  }

  //Cancella gli elementi della lista fino alla caverna in cui ci si trova
  while (cunicolo[i] != giocatoreAttuale->posizione)
  {
    temp = cunicolo[i];
    cunicolo[i] = cunicolo[i]->indietro;
    free(temp);
  }
}

//gestisce il comportamento dello scontro finale
static void scontro_finale()
{
  bool end = FALSE;
  clear();
  printfile("scontro_finale.txt", 1);
  printw("Benvenuto nella sfida finale!!!");
  getch();
  gestione_melassa(4, raccolta);
  store();
  switchPlayer();
  gestione_melassa(4, raccolta);
  store();
  do
  {
    switchPlayer();
    menu_scontro();
    check_endgame(&end);

  } while (!end);
  stampa_win();
}

//Gestice il menu di scontro per il player
static void menu_scontro()
{
  char *arrMenu[] = {"Attacca", "Difendi"};
  unsigned short scelta;
  clear();
  stampa_famiglia();
  printw("Vita: ");
  attron(COLOR_PAIR(3));
  printw("%d\n\n", giocatoreAttuale->salute);
  attroff(COLOR_PAIR(3));
  if (giocatoreAttuale->attaccoBuff)
  {
    attron(COLOR_PAIR(4));
    printw("Buff Attacco Attivo (+10 attacco)\t");
    attroff(COLOR_PAIR(4));
  }
  if (giocatoreAttuale->difesaBuff)
  {
    attron(COLOR_PAIR(2));
    printw("Buff Difesa Attivo (+10 difesa)");
    attroff(COLOR_PAIR(2));
  }
  printw("\nSceglia la tua mossa!!!");

  if (giocatoreAttuale->AI)
  {
    scelta = scelta_AI(2);
  }
  else
  {
    scelta = stampa_menu_ncurse(arrMenu, 30, 2);
  }

  if (scelta == 0)
  {
    attacca();
  }
  else
  {
    difendi();
  }
}

//Gestisce il comportamento di attacca tenendo in conto il comportamento dei buff
static void attacca()
{
  clear();
  giocatoreAttuale->ultimaMossaScontro = 'a';
  stampa_famiglia();
  printw("Hai deciso di attaccare la vita del tuo nemico va:\n");
  attron(COLOR_PAIR(4));
  printw("%d", altroGiocatore->salute);
  attroff(COLOR_PAIR(4));
  printw(" ---------> ");

  if (altroGiocatore->ultimaMossaScontro == 'd')
  {
    if (!altroGiocatore->difesaBuff)
    {
      if (giocatoreAttuale->attaccoBuff)
      {
        altroGiocatore->salute -= 10;
      }
    }
  }
  else
  {
    if (giocatoreAttuale->attaccoBuff)
    {
      altroGiocatore->salute -= 20;
    }
    else
    {
      altroGiocatore->salute -= 10;
    }
  }
  attron(COLOR_PAIR(4));
  printw("%d", altroGiocatore->salute);
  attroff(COLOR_PAIR(4));
  getch();
}

//Gestisce il comportamento di difendi per il player
static void difendi()
{
  giocatoreAttuale->ultimaMossaScontro = 'd';
  clear();
  stampa_famiglia();
  printw("Hai deciso di difenderti, buona fortuna!!!");
  getch();
}

//Controlla se la salute di uno dei due giocatori è scesa sotto zero e dichiara il vincitore nello scontro finale
static void check_endgame(bool *end)
{
  if (giocatoreAttuale->salute <= 0)
  {
    altroGiocatore->win = TRUE;
    *end = TRUE;
  }
  else if (altroGiocatore->salute <= 0)
  {
    giocatoreAttuale->win = TRUE;
    *end = TRUE;
  }
  motivoVittoria = scontro;
}

//Gestisce il comportamento del negozio dove si possono acquistare i buff di attacco e difesa tramite la melassa di raccolta
static void store()
{
  unsigned short scelta;
  char *arr[] = {"Attacco {melassa: 5}", "difesa {melassa: 4}", "Fine"};
  while (1)
  {
    clear();
    stampa_famiglia();
    printfile("Store.txt", 1);
    printw("Melassa disponibile: ");
    attron(COLOR_PAIR(3)),
        printw("%d\n", giocatoreAttuale->raccolta);
    attroff(COLOR_PAIR(3));
    printw("Aquista i tuoi buff:\n");

    if (giocatoreAttuale->AI)
    {
      scelta = scelta_AI(3);
    }
    else
    {
      scelta = stampa_menu_ncurse(arr, 45, 3);
    }
    switch (scelta)
    {
    case 0:
      if (giocatoreAttuale->raccolta < 5)
      {
        clear();
        printw("Non hai abbastanza melassa!!!");
        getch();
      }
      else
      {
        giocatoreAttuale->attaccoBuff = TRUE;
        giocatoreAttuale->raccolta -= 5;
        clear();
        printw("Hai acquistato attacco!!!");
        getch();
      }
      break;
    case 1:
      if (giocatoreAttuale->raccolta < 4)
      {
        clear();
        printw("Non hai abbastanza melassa!!!");
        getch();
      }
      else
      {
        giocatoreAttuale->difesaBuff = TRUE;
        giocatoreAttuale->raccolta -= 4;
        clear();
        printw("Hai acquistato difesa!!!");
        getch();
      }
      break;
    case 2:
      return;
      break;

    default:
      break;
    }
  }
}

//Controlla per vedere se uno dei due giocatori ha perso nel gioco normale e gestisce la probabilità di scontro
static void check_gameover(bool *gameover)
{

  if (rand() % 101 < giocatoreAttuale->probabilitaScontro)
  {
    scontro_finale();
    motivoVittoria = scontro;
    *gameover = TRUE;
  }
  else if (giocatoreAttuale->energia < 0)
  {
    *gameover = TRUE;
    motivoVittoria = distruzione;
    altroGiocatore->win = TRUE;
  }
  else if ((giocatoreAttuale->uscito && altroGiocatore->uscito) || (turno >= lunghezzaPercorso * 2))
  {
    *gameover = TRUE;
    motivoVittoria = punteggio;
    if (giocatoreAttuale->raccolta > altroGiocatore->raccolta)
    {
      giocatoreAttuale->win = TRUE;
    }
    else if (giocatoreAttuale->raccolta < altroGiocatore->raccolta)
    {
      altroGiocatore->win = TRUE;
    }
  }
}

//Stampa a schermo il nome della famiglia del giocatore attuale
static void stampa_famiglia()
{
  if (giocatoreAttuale->eFamiglia == fArvais)
  {
    if (giocatoreAttuale->AI)
    {
      printfile("Arvais_AI.txt", 1);
    }
    else
    {
      printfile("Arvais.txt", 1);
    }
  }
  else
  {
    if (giocatoreAttuale->AI)
    {
      printfile("Hartornen_AI.txt", 1);
    }
    else
    {
      printfile("Hartornen.txt", 1);
    }
  }
}

//Stampa a schermo il nome della famiglia che vince (Oppure il pareggio ma è estremamente raro)
static void stampa_win()
{
  clear();
  ScavatricePtr temp;
  if (giocatoreAttuale->win)
  {
    temp = giocatoreAttuale;
  }
  else if (altroGiocatore->win)
  {
    temp = altroGiocatore;
  }
  else
  {
    printfile("win_pareggio.txt", 1);
    return;
  }

  if (temp->eFamiglia == fArvais)
  {
    printfile("win_arvais.txt", 1);
  }
  else
  {
    printfile("win_hartornen.txt", 1);
  }

  printw("Motivo della vittoria: ");
  attron(COLOR_PAIR(3));
  switch (motivoVittoria)
  {
  case punteggio:
    printw("Maggiore punteggio.");
    break;
  case distruzione:
    printw("Una scavatrice è andata distrutta.");
    break;
  case scontro:
    printw("Scontro finale.");
    break;
  case pareggio:
    printw("....");
    break;
  default:
    break;
  }
  attroff(COLOR_PAIR(3));

  getch();
  clear();
  printfile("Game_Over.txt", 1);
  refresh();
  sleep(1);
}

//Dealloca la memoria e azzera le scavatrici alla fine della partita
static void termina_gioco(bool *mappa)
{
  freeMappa(mappa);
  azzera_scavatrici();
  giocatoreAttuale = NULL;
  altroGiocatore = NULL;
}

//Azzera tutti i parametri delle scavatrici
static void azzera_scavatrici()
{
  ScavatricePtr scavatrice[] = {&arvais, &hartornen};
  for (size_t i = 0; i < 2; i++)
  {
    scavatrice[i]->energia = 0;
    scavatrice[i]->raccolta = 0;
    scavatrice[i]->salute = 0;
    scavatrice[i]->probabilitaUscita = 0;
    scavatrice[i]->probabilitaScontro = 0;
    scavatrice[i]->posizione = NULL;
    scavatrice[i]->uscito = FALSE;
    scavatrice[i]->abbatti = FALSE;
    scavatrice[i]->aggira = FALSE;
    scavatrice[i]->AI = FALSE;
    scavatrice[i]->uscito = FALSE;
    scavatrice[i]->win = FALSE;
    scavatrice[i]->attaccoBuff = FALSE;
    scavatrice[i]->difesaBuff = FALSE;
  }
}

//Minigame di hacking
static bool hack_game()
{

  char *arrParole[] = {"SHOT", "HURT", "SELL", "GIVE", "SURE", "GEAR", "SENT", "FIRE", "GLOW", "WEEK", "ONES", "SICK"};
  //utilizzo un puntatore a char ed una matrice perchè risulta più facile far funzionare il minigame,è comunque possibile alleggerire il peso di codice in memoria
  char matriceParole[13][5] = {{"SHOT"}, {"HURT"}, {"SELL"}, {"GIVE"}, {"SURE"}, {"GEAR"}, {"SENT"}, {"FIRE"}, {"GLOW"}, {"WEEK"}, {"ONES"}, {"SICK"}};
  char *arrMemoria[] = {"0000", "0100", "0200", "0300", "0400", "0500", "0600", "0700", "0800", "0900", "1000", "1100"};
  short tentativi = 5, similarita;
  int indiceParolaDaTrovare = rand() % 12;
  while (tentativi != 0)

  {
    clear();
    attron(COLOR_PAIR(1));

    printw("___________________________________________________________\n");
    printw("||       Benvenuto al DUNE industries (TM) TermLink      ||\n");
    printw("||               Sei Sotto Attacco!!!                    ||\n"
           "||         Inserisci la Password per Salvarti            ||\n"
           "||                                                       ||\n");
    if (tentativi == 1)
    {
      attron(COLOR_PAIR(4));
      printw("||               Tentativi Rimasti: %d                    ||\n", tentativi);
      attron(COLOR_PAIR(1));
    }
    else
    {
      printw("||               Tentativi Rimasti: %d                    ||\n", tentativi);
    }
    if (tentativi != 5)
    {
      printw("||                  Similarità: %d                       ||\n", similarita);
      printw("___________________________________________________________");
    }
    else
    {
      printw("___________________________________________________________");
    }
    attroff(COLOR_PAIR(1));
    int highlight = 0;
    int scelta;
    //stampa menu moddato
    while (1)
    {
      for (int i = 0; i < 12; i++)
      {
        attron(COLOR_PAIR(2));
        mvprintw(i + 9, 19, "$0x");
        attroff(COLOR_PAIR(2));

        attron(COLOR_PAIR(3));
        mvprintw(i + 9, 22, arrMemoria[i]);
        attroff(COLOR_PAIR(3));

        if (i == highlight)
          attron(A_REVERSE);
        mvprintw(i + 9, 28, arrParole[i]);
        attroff(A_REVERSE);
      }
      refresh();
      scelta = getch();

      switch (scelta)
      {
      case KEY_UP:
        highlight--;
        if (highlight == -1)
          highlight = 11;
        break;
      case KEY_DOWN:
        highlight++;
        if (highlight == 12)
          highlight = 0;
        break;
      default:
        break;
      }
      if (scelta == 10)
        break;
    }

    //controllo se la risposta sia corretta
    similarita = 0;
    for (int i = 0; i < 4; i++)
    {
      if (matriceParole[highlight][i] == matriceParole[indiceParolaDaTrovare][i])
        similarita++;
    }

    //se la parola scelta è giusta
    if (similarita == 4)
    {
      clear();
      printfile("Hacker!.txt", 1);
      refresh();
      sleep(1);
      clear();
      printfile("Hacker!!.txt", 1);
      refresh();
      sleep(1);
      clear();
      printfile("Hacker!!!.txt", 1);
      refresh();

      getch();
      return TRUE;
    }

    tentativi--;

    if (tentativi == 0)
    {
      clear();
      printfile("TooBad.txt", 1);
      refresh();
      getch();
      return FALSE;
    }
  }
  return FALSE;
}

//////////////////////////////////////////////////|
//////////////FUNZIONI ESTERNE////////////////////|
//////////////////////////////////////////////////|

//Controlla se una caverna sia vuota
static int isEmpty(CavernaPtr caverna)
{
  return caverna == NULL;
}

//Stampa un menu esteticamente carino tramite ncurses
static int stampa_menu_ncurse(char *arr[], int n, int lun)
{
  int highlight = 0;
  int scelta;
  while (1)
  {
    for (int i = 0; i < lun; i++)
    {
      if (i == highlight)
        attron(A_REVERSE);
      mvprintw(i + n, 1, arr[i]);
      attroff(A_REVERSE);
    }
    refresh();
    scelta = getch();

    switch (scelta)
    {
    case KEY_UP:
      highlight--;
      if (highlight == -1)
        highlight = lun - 1;
      break;
    case KEY_DOWN:
      highlight++;
      if (highlight == lun)
        highlight = 0;
      break;
    default:
      break;
    }
    if (scelta == 10)
      break;
  }

  return highlight;
}

//Stampa su schermo i caratteri da un file di testo
static void printfile(char *str, short n)
{
  char dir[50] = "./ASCII/";
  char c;
  strcat(dir, str);
  FILE *fors = fopen(dir, "r");
  attron(COLOR_PAIR(n));
  while ((c = getc(fors)) != EOF)
  {
    printw("%c", c);
  }
  fclose(fors);
  attroff(COLOR_PAIR(n));
}

void game_over()
{
  clear();
  printfile("Grazie.txt", 1);
  refresh();
  sleep(2);
}