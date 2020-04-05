#include "gamelib.h"

//Variabili globali
static CavernaPtr primo_cunicolo_arvais = NULL;
static CavernaPtr primo_cunicolo_hartonen = NULL;
static Scavatrice arvais;
static Scavatrice hartonen;
static ScavatricePtr giocatoreAttuale;
static ScavatricePtr altroGiocatore;
static int x_max, y_max;

//Prototipi
static void crea_cunicoli(bool *mappa);
static void crea_cunicoli_load(enumFamiglia famiglia, int melassa, int imprevisto, int stato, char nextDir);
static void ins_caverna(bool *mappa);
static void crea_caverna(enumFamiglia famiglia);
static void inizializza_cuniccoli();
static void stampa_cunicolo(enumFamiglia famiglia);
static void canc_cavera();
static void chiudi_cunicoli(bool *mappa);
static void salva_mappa(bool *mappa);
static void load_mappa(bool *mappa);
static void probabilita_caverna(CavernaPtr caverna);
static int isEmpty(CavernaPtr caverna);
static int stampa_menu_ncurse(char *arr[], int n, int lun);
static void printfile(char *str, short n);

//definizione funzioni
void menu(bool *play)
{
  int scelta = 0;
  bool mappa = false;
  getmaxyx(stdscr, y_max, x_max); //prende le dimensioni massime della finestra
  keypad(stdscr, TRUE);           //apre l'input alle freccie della tastiera

  init_pair(1, COLOR_GREEN, COLOR_BLACK); //setta colore di stampa ncurses
  do
  {
    srand(time(NULL));
    printfile("dune.txt", 1);
    refresh();
    /*sleep(2);
    printw("\nBenvenuto in Dune, un piccolo gioco programmato da Edoardo Tavassi");
    refresh();
    sleep(2);*/
    clear();
    printfile("dune.txt", 1);
    refresh();

    //menu e higlight
    char *arrMenuIniziale[] = {"Gioca", "Crea Cunicoli", "Istruzioni", "Esci dal Gioco"};

    scelta = stampa_menu_ncurse(arrMenuIniziale, 14, 4);
    switch (scelta)
    {
    case 0:;
      break;
    case 1:
      crea_cunicoli(&mappa);
      break;
    case 2:;
      break;
    case 3:;
      break;
    }

  } while (scelta != 4);
}

static void inizializza_cuniccoli()
{
  primo_cunicolo_arvais = (CavernaPtr)malloc(sizeof(Caverna));
  primo_cunicolo_hartonen = (CavernaPtr)malloc(sizeof(Caverna));

  primo_cunicolo_arvais->imprevisto = nessun_imprevisto;
  primo_cunicolo_arvais->melassa = nessuna;
  primo_cunicolo_arvais->stato = normale;
  primo_cunicolo_arvais->destra = NULL;
  primo_cunicolo_arvais->sinistra = NULL;
  primo_cunicolo_arvais->avanti = NULL;
  primo_cunicolo_arvais->nextDirection = 'n';

  primo_cunicolo_hartonen->imprevisto = nessun_imprevisto;
  primo_cunicolo_hartonen->melassa = nessuna;
  primo_cunicolo_hartonen->stato = normale;
  primo_cunicolo_hartonen->destra = NULL;
  primo_cunicolo_hartonen->sinistra = NULL;
  primo_cunicolo_hartonen->avanti = NULL;
  primo_cunicolo_hartonen->nextDirection = 'n';
}

static void crea_cunicoli(bool *mappa)
{
  int scelta;
  do
  {
    clear();
    printfile("MenuCunicoli.txt", 1);

    char *arrMenuCunicoli[] = {"Inserisci caverne", "Cancella Caverna",
                               "Stampa Mappa", "Salva Mappa", "Carica Mappa", "Chiudi Cunicoli"};

    scelta = stampa_menu_ncurse(arrMenuCunicoli, 10, 6);

    switch (scelta)
    {
    case 0:
      ins_caverna(mappa);
      break;
    case 1:
      canc_cavera();
      break;
    case 2:
      stampa_cunicolo(fArvais);
      stampa_cunicolo(fHartornen);
      break;
    case 3:
      salva_mappa(mappa);
      getch();
      break;
    case 4:
      load_mappa(mappa);
      getch();
      break;
    case 5:
      chiudi_cunicoli(mappa);
      getch();
      break;
    }
  } while (!*mappa);
}

static void crea_caverna(enumFamiglia famiglia)
{
  clear();
  printfile("InserimentoCaverne.txt", 1);

  CavernaPtr newCunicolo = (CavernaPtr)malloc(sizeof(Caverna));
  newCunicolo->nextDirection = 'n';
  int rispostaStato;
  if (newCunicolo != NULL)
  {
    int sceltaDirezione;
    int sceltaStato;
    char *arrMenuDirezione[] = {"Avanti", "Destra", "Sinistra"};
    char *arrMenuStato[] = {"Normale", "Speciale", "Accidentata"};

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
    probabilita_caverna(newCunicolo);
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
      currentCunicolo = primo_cunicolo_hartonen;
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

    if (sceltaDirezione == 1)
    {
      currentCunicolo->nextDirection = 'a';
      currentCunicolo->avanti = newCunicolo;
      currentCunicolo = currentCunicolo->sinistra;
    }
    else if (sceltaDirezione == 2)
    {
      currentCunicolo->nextDirection = 'd';
      currentCunicolo->destra = newCunicolo;
      currentCunicolo = currentCunicolo->destra;
    }
    else
    {
      currentCunicolo->nextDirection = 's';
      currentCunicolo->sinistra = newCunicolo;
      currentCunicolo = currentCunicolo->sinistra;
    }
  }
  stampa_cunicolo(famiglia);
}

static void ins_caverna(bool *mappa)
{
  char risposta;
  clear();
  printfile("InserimentoCaverne.txt", 1);

  if (*mappa)
  {
    puts("la mappa già esiste vuoi cancellarla?\nY o N\n\t>");
    //freeMap(bool *mappa); da implementare
  }
  else if (!*mappa)
  {

    unsigned short counterPosizioneARV = 0;
    unsigned short counterPosizioneHART = 0;
    const char *posizione[] = {"prima", "seconda", "terza", "quarta", "quinta", "sesta", "settima", "ottava", "nona", "decima", "undicesima"}; //da allungare semmai

    inizializza_cuniccoli();

    do
    {
      risposta = 'n';
      do
      {
        if (risposta == 'y')
        {
          crea_caverna(fArvais);
        }
        clear();
        printfile("InserimentoCaverne.txt", 1);
        move(10, 1);
        printw("Vuoi inserire la %s caverna per la famiglia Arvais?\n Y o N\n>", posizione[counterPosizioneARV]);
        refresh();
        risposta = getch();
        getch();
        counterPosizioneARV++;
      } while (risposta == 'y');

      do
      {
        if (risposta == 'y')
        {
          crea_caverna(fHartornen);
        }
        clear();
        printfile("InserimentoCaverne.txt", 1);
        move(10, 1);
        printw("Vuoi inserire la %s caverna per la famiglia Hartonen?\n Y o N\n>", posizione[counterPosizioneHART]);
        refresh();
        risposta = getch();
        getch();
        counterPosizioneHART++;
      } while (risposta == 'y');

      clear();
      printfile("InserimentoCaverne.txt", 1);
      move(10, 1);
      printw("Vuoi Inserire Altre Caverne?\nY o N\n>");
      risposta = getch();
      getch();

    } while (risposta != 'n');
  }
}

static void stampa_cunicolo(enumFamiglia famiglia)
{
  clear();
  CavernaPtr scanCunicolo = (CavernaPtr)malloc(sizeof(Caverna));
  if (famiglia == fArvais)
  {
    scanCunicolo = primo_cunicolo_arvais;
    printfile("Arvais.txt", 1);
  }
  else
  {
    scanCunicolo = primo_cunicolo_hartonen;
    printfile("Hartonen.txt", 1);
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
    x = (x_max / 2) - 3;
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);

    while (scanCunicolo != NULL)
    {
      if (scanCunicolo->stato == speciale)
      {
        attron(COLOR_PAIR(3));
        n = 3;
      }
      else if (scanCunicolo->stato == accidentata)
      {
        attron(COLOR_PAIR(2));
        n = 2;
      }
      move(y, x);
      if (scanCunicolo->nextDirection == 'n')
      {
        printw(" / \\");
        move(y + 1, x);
        printw("|   |");
        move(y + 2, x);
        printw(" \\ /");
      }
      else if (scanCunicolo->nextDirection == 'a')
      {
        printw(" / \\");
        move(y + 1, x);
        printw("|   |");
        move(y + 2, x);
        printw(" | |");
      }
      else if (scanCunicolo->nextDirection == 'd')
      {
        printw(" / \\");
        move(y + 1, x);
        printw("|   |");
        move(y + 2, x);
        printw(" \\ \\");
        x = x + 3;
      }
      else
      {
        printw(" / \\");
        move(y + 1, x);
        printw("|   |");
        move(y + 2, x);
        printw(" / /");
        x = x - 3;
      }
      y = y + 3;
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

static void canc_cavera()
{
  int scelta;

  clear();
  printfile("MenuCancella.txt", 1);
  move(10, 1);
  printw("Di Quale famiglia vuoi cancellare la caverna?");
  char *arrMenuFamiglia[] = {"ARVAIS", "HARTONEN"};
  int highlight = 0;

  while (1)
  {
    for (int i = 0; i < 2; i++)
    {
      if (i == highlight)
        attron(A_REVERSE);
      mvprintw(i + 12, 1, arrMenuFamiglia[i]);
      attroff(A_REVERSE);
    }
    refresh();
    scelta = getch();

    switch (scelta)
    {
    case KEY_UP:
      highlight--;
      if (highlight == -1)
        highlight = 0;
      break;
    case KEY_DOWN:
      highlight++;
      if (highlight == 2)
        highlight = 1;
      break;
    default:
      break;
    }
    if (scelta == 10)
      break;
  }

  scelta = highlight + 1;

  CavernaPtr scanCunicolo = (CavernaPtr)malloc(sizeof(Caverna));
  if (scelta == 1)
  {
    scanCunicolo = primo_cunicolo_arvais;
  }
  else
  {
    scanCunicolo = primo_cunicolo_hartonen;
  }
  while (scanCunicolo->nextDirection != 'n')
  {
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

    free(scanCunicolo);

    if (scelta == 1)
    {
      stampa_cunicolo(fArvais);
    }
    else
    {
      stampa_cunicolo(fHartornen);
    }
  }
}

static void chiudi_cunicoli(bool *mappa)
{
  *mappa = true;
}

static void salva_mappa(bool *mappa)
{
  clear();
  if (!*mappa)
  {
    printw("La mappa non è salvabile");
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
    CavernaPtr scanCunicolo = (CavernaPtr)malloc(sizeof(Caverna));
    char dir[50] = "./Save/Arvais.txt";
    char dir2[50] = "./Save/Hartonen.txt";
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
        fprintf(fors, "%c", primo_cunicolo_hartonen->nextDirection);
        //salta il primo cunicolo
        switch (primo_cunicolo_hartonen->nextDirection)
        {
        case 'a':
          scanCunicolo = primo_cunicolo_hartonen->avanti;
          break;
        case 'd':
          scanCunicolo = primo_cunicolo_hartonen->destra;
          break;
        case 's':
          scanCunicolo = primo_cunicolo_hartonen->sinistra;
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

static void load_mappa(bool *mappa)
{
  clear();
  if (*mappa)
  {
    printw("La mappa già esiste");
    refresh();
    //freemap
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
        strcat(dir2, "Hartonen.txt");
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
  stampa_cunicolo(fArvais);
  getch();
  stampa_cunicolo(fHartornen);
  getch();
}

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
      currentCunicolo = primo_cunicolo_hartonen;
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

    if (nextDir == 'a')
    {
      currentCunicolo->nextDirection = 'a';
      currentCunicolo->avanti = newCunicolo;
      currentCunicolo = currentCunicolo->sinistra;
    }
    else if (nextDir == 'd')
    {
      currentCunicolo->nextDirection = 'd';
      currentCunicolo->destra = newCunicolo;
      currentCunicolo = currentCunicolo->destra;
    }
    else
    {
      currentCunicolo->nextDirection = 's';
      currentCunicolo->sinistra = newCunicolo;
      currentCunicolo = currentCunicolo->sinistra;
    }
  }
}

static void probabilita_caverna(CavernaPtr caverna)
{
  int random = rand() % 101;

  if (random > 80)
  {
    caverna->melassa = molta;
  }
  else if (random > 70)
  {
    caverna->melassa = poca;
  }
  else
  {
    caverna->melassa = nessuna;
  }

  if (random > 85)
  {
    caverna->imprevisto = baco;
  }
  else if (random > 65)
  {
    caverna->imprevisto = crollo;
  }
  else
  {
    caverna->imprevisto = nessun_imprevisto;
  }
}

static int isEmpty(CavernaPtr caverna)
{
  return caverna == NULL;
}

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
        highlight = 0;
      break;
    case KEY_DOWN:
      highlight++;
      if (highlight == lun)
        highlight = lun - 1;
      break;
    default:
      break;
    }
    if (scelta == 10)
      break;
  }

  return highlight;
}

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
