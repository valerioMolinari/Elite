#include "gamelib.h"

// Variabili globali
static CavernaPtr primo_cunicolo_arvais;
static CavernaPtr primo_cunicolo_hartornen;
static Scavatrice arvais;
static Scavatrice hartornen;
static ScavatricePtr currentPlayer;
static ScavatricePtr otherPlayer;

// Dichiarazione Prototipi
static CavernaPtr next(CavernaPtr currentPtr);
static CavernaPtr newCave(enumFamiglia famiglia, bool abbattimento);
static US getThroughTunnel(CavernaPtr *currentPtr, enumDirezione direzione);
static US probabilita(enumProbabilita tipo, bool abbattimento);
static bool can(enumMossa mossa);
static bool conditionsMossaFinale(char mossa);
static bool checkChar(char c);
static bool checkGameOver(enumRagione * ragione, bool print);
static bool findSpecial(enumSpeciale oggetto);
static bool isEmpty(CavernaPtr currentTunnel);
static bool valutaSceltaSerbatoio(US sceltaSerbatoio);
static char * nomeDirezione();
static void abbatti();
static void aggira();
static void attacco(enumMossa mossa);
static void avanza();
static void azzeramento_scavatrici(enumRagione ragione);
static void canc_caverna(bool * map);
static void carica(enumCarica carica);
static void carica_azione(enumMossa azione);
static void caveColors(CavernaPtr currentPtr);
static void chiudi_cunicoli(bool * map);
static void crea_caverne(size_t i, size_t j);
static void crea_cunicoli(bool * map);
static void esci();
static void freeMap(bool * map, enumFree whichFree);
static void gioca(bool * map);
static void inizializzazione_scavatrici();
static void ins_caverna(bool * map);
static void jsPrintAction(enumMossa action, char nextDirection);
static void passa();
static void printMenu(enumMenu menu, bool firstPrint);
static void putMelassa(US turno, short contoMelassa);
static void putSpeciale(bool *eventoSpeciale);
static void risolvi_azione();
static void resoconto_finale(US turno, bool firstPrint);
static void resoconto_scavatrice(US turno, bool inPutMelassa);
static void safeScanf(char * c);
static void scontro_finale(US * turno, enumRagione * ragione, bool * map);
static void separatore(char carattere, US quantita);
static void spaces(unsigned short n, const char * const string);
static void stampaCunicolo(CavernaPtr currentPtr);
static void stampa_cunicoli(bool needEnter);
static void stampa_direzioni();
static void stampa_direzioni();
static void switchFinalMove(bool arrayCanMove[], US * iterator, US mossa);
static void switchPlayer(US * turno, bool advance);
static void termina_gioco(enumRagione ragione, bool * map);
static void waitEnter();
static void warn(char timeToWait);


// Definizione Funzioni

// /   | Menu principale
void FirstMenu(bool * wannaPlay) {
  char choice;
  bool mappa = false;
  do {
    srand(time(NULL));
    clr;
    system("cat titolo.txt; echo ''");
    printMenu(first, true);
    safeScanf(&choice);
    switch (choice) {
      case '1': system("less istruzioni.txt"); break;
      case '2': crea_cunicoli(&mappa); break;
      case '3': gioca(&mappa); break;
      case '4': termina_gioco(ragione_deallocazione, &mappa); break;
      default: warn('1');
    }
  } while(choice != '4');
  char playChoice;
  do {
    clr;
    puts("Tutte le impostazioni di gioco sono state resettate, vuoi continuare a giocare? (y/n)");
    safeScanf(&playChoice);
    if (playChoice != 'y' && playChoice != 'n')
      warn('1');
  } while(playChoice != 'y' && playChoice != 'n');
  *wannaPlay = playChoice == 'y' ? true : false;
}

// ~/  | Controlla se il carattere inserito è valido
static bool checkChar(char c) {
	for (char i = 'a'; i <= 'z'; i++)
		if (c == i) return true;
	for (char i = '0'; i <= '9'; i++)
		if (c == i) return true;
	return false;
}

// ~/  | Continua a leggere un carattere finché non ne viene inserito uno valido
static void safeScanf(char * c) {
	do {
		*c = getchar();
	} while(!checkChar(*c));
}

// ~/   | Stampa i menu
static void printMenu(enumMenu menu, bool firstPrint) {
  US i = 0;
  if (firstPrint)
    puts("Effettua una scelta:");
  switch (menu) {
    case first:
      puts(
        "\t1. Istruzioni\n"
        "\t2. Crea cunicoli\n"
        "\t3. Gioca\n"
        "\t4. Esci dal gioco"
      );
      break;
    case cunicoli:
      puts(
        "\t1. Inserisci caverna\n"
        "\t2. Cancella caverna\n"
        "\t3. Stampa cunicoli\n"
        "\t4. Chiudi cunicoli\n"
        "\t5. Stampa direzioni\n"

      );
      break;
    case caverneRandom:
      puts(
        "\t1. Casuale\n"
        "\t2. Manuale"
      );
      break;
    case tipoCaverna:
      puts(
        "\t\x1b[1m\x1b[33m1. Caverna normale\x1b[0m\n"
        "\t\x1b[1m\x1b[36m2. Caverna Speciale\x1b[0m\n"
        "\t\x1b[1m\x1b[31m3. Caverna accidentata\x1b[0m\n"
        "\t4. Torna al menù principale"
      );
      break;
    case direzione:
      puts(
        "\tCostruisci in avanti (a)\n"
        "\tCostruisci verso destra (d)\n"
        "\tCostruisci verso sinistra (s)"
      );
      break;
    case play:
      if (can(mAvanza)) printf("\t%hu. %s\n", ++i, "Avanza");
      if (can(mAggira)) printf("\t%hu. %s\n", ++i, "Aggira");
      if (can(mAbbatti)) printf("\t%hu. %s\n", ++i, "Abbatti");
      if (can(mEsci)) printf("\t%hu. \x1b[95m%s\x1b[0m\n", ++i, "Esci"); break;
    case raccoltaMelassa:
      if (valutaSceltaSerbatoio(1))
        puts("\t1. Serbatoio di raccolta");
      else if (valutaSceltaSerbatoio(2))
        puts("\t1. Serbatoio di energia");
      else
        puts("\t1. Serbatoio di energia\n\t2. Serbatoio di raccolta");
      break;
    case finale:
      printf("\n\t\x1b[2mMossa\t\t\t  Consumo {Melassa, Turni}\x1b[0m\n\n");
      if (can(pistolaLaser)) printf("\t%2hu. %s\t\t\x1b[37m\x1b[2m%12s\x1b[0m\n", ++i, "Pistola laser", "{1 M, 0 T}");
      if (can(colpoEstraniante)) printf("\t%2hu. %s\t\t\x1b[37m\x1b[2m%12s\x1b[0m\n", ++i, "Modulo Estraniante", "{2 M, 1 T}");
      if (can(colpoAssassino)) printf("\t%2hu. %s\t\t\x1b[37m\x1b[2m%12s\x1b[0m\n", ++i, "Cercatore Assassino", "{2 M, 1 T}");
      if (can(superColpoEstraniante)) printf("\t%2hu. %s\t\x1b[37m\x1b[2m%12s\x1b[0m\n", ++i, "Super Modulo Estraniante", "{3 M, 2 T}");
      if (can(superColpoAssassino)) printf("\t%2hu. %s\t\x1b[37m\x1b[2m%12s\x1b[0m\n", ++i, "Super Cercatore Assassino", "{3 M, 2 T}");
      if (can(risveglioDelDormiente)) printf("\t%2hu. \x1b[96m%s\t\x1b[37m\x1b[2m%12s\x1b[0m\n", ++i, "Risveglio Del Dormiente", "{All M, 3 T}");
      if (can(richiamoDelBaco)) printf("\t%2hu. \x1b[91m%s\t\t\x1b[37m\x1b[2m%12s\x1b[0m\n", ++i, "Richiamo Del Baco", "{0 M, 0 T}");
      if (can(ricaricaEnergia)) printf("\t%2hu. %s\t\t\x1b[37m\x1b[2m%12s\x1b[0m\n", ++i, "Ricarica Energia", "{1 M, 0 T}");
      if (can(cura)) printf("\t%2hu. %s\t\t\t\x1b[37m\x1b[2m%12s\x1b[0m\n", ++i, "Cura", "{1 M, 0 T}");
      printf("\t%2hu. %s\t\t\t\x1b[37m\x1b[2m%12s\x1b[0m\n", ++i, "Passa", "{0 M, 0 T}");
  }
}

// ~/   | Stampa "Scelta sbagliata"
static void warn(char timeToWait) {
  char string[8] = "sleep ";
  string[6] = timeToWait;
  string[7] = '\0';
  puts("\nScelta sbagliata");
  system(string);
  system("clear");
  fflush(stdin);
}

// ~/   | Mette in pausa l'esecuzione !!!
static void waitEnter() {
  char enter;
  fflush(stdin);
  do {
    puts("\nPremi INVIO per continuare");
    enter = getchar();
  } while(enter != '\n');
}

// ~/   | Restituisce puntatore NULL?
static bool isEmpty(CavernaPtr currentTunnel) {
  return currentTunnel == NULL;
}

// ~/   | Restituisce un puntatore a una caverna dislocata
static CavernaPtr newCave(enumFamiglia famiglia, bool abbattimento) {
  CavernaPtr cave = malloc(sizeof(Caverna));
  if (isEmpty(cave))
    fprintf(stderr, "%s\n", "Errore in newCave(): memoria insufficiente");
  else {
    if (abbattimento)
      cave->stato = probabilita(pStato, abbattimento);
    cave->melassa = probabilita(melassa, abbattimento);
    cave->imprevisto = probabilita(imprevisto, abbattimento);
    cave->oggettoSpeciale = probabilita(famiglia ? specialeHartornen : specialeArvais, abbattimento);
    cave->avanti = NULL;
    cave->sinistra = NULL;
    cave->destra = NULL;
    cave->indietro = NULL;
  }
  return cave;
}

// ~/   | Stampa n spazi, una stringa e un \n
static void spaces(unsigned short n, const char * const string) {
	for (size_t i = 0; i < n; i++) printf(" "); printf("%s\n", string);
}

// ~/   | Cancella i cunicoli
static void freeMap(bool * map, enumFree whichFree) {
  CavernaPtr *cunicoli[] = {&primo_cunicolo_arvais, &primo_cunicolo_hartornen};
  CavernaPtr tempPtr = NULL;
  for (size_t i = 0; i < 2; i++) {
    if (whichFree == freeArvais && i)
      break;
    else if (whichFree == freeHartornen && !i)
      continue;
    while (!isEmpty(*cunicoli[i])) {
      tempPtr = *cunicoli[i];
      *cunicoli[i] = (*cunicoli[i])->indietro;
      if (!isEmpty(tempPtr))
        free(tempPtr);
    }
  }
  *map = false;
}

// ~/newCave  | Restituisce la probabilità di melassa o imprevisto
static US probabilita(enumProbabilita tipo, bool abbattimento) {
  US random = rand() % 101;
  switch (tipo) {
    case melassa:
      if (random > 80)
        return molta;
      else if (random > (abbattimento ? 40 : 50))
        return poca;
      else
        return nessuna; break;
    case imprevisto:
      if (random > (abbattimento ? 80 : 85))
        return baco;
      else if (random > (abbattimento ? 40 : 50))
        return crollo;
      else
        return nessun_imprevisto;
      break;
    case specialeArvais:
      if (random > 90)
        return acquaDellaVita;
      else if (random > 80)
        return anelloDelSigillo;
      else if (random > 65)
        return denteDiLeto;
      else if (random > 55)
        return moduloEstraniante;
      else
        return nessuno;
      break;
    case specialeHartornen:
      if (random > 90)
        return acquaDellaVita;
      else if (random > 80)
        return anelloDelSigillo;
      else if (random > 65)
        return amplificatoreDiDolore;
      else if (random > 55)
        return cercatoreAssassino;
      else
        return nessuno;
      break;
    case pStato:
      if (random > (100 - currentPlayer->probabilitaUscita))
        return uscita;
      else if (random > (80 - currentPlayer->probabilitaUscita))
        return accidentata;
      else if (random > (80 - currentPlayer->probabilitaUscita) / 2 )
        return speciale;
      else
        return normale;
      break;
    case cPistolaLaser: return rand() % 11 + 10; break;
    case cColpoEstraniante:
    case cColpoAssassino: return rand() % 26 + 20; break;
    case cSuperColpoEstraniante:
    case cSuperColpoAssassino: return rand() % 41 + 40; break;
  }
}

// ~/FirstMenu/   | Menu crea cunicoli
static void crea_cunicoli(bool * map) {
  char choice;

  do {
    system("clear");
    printMenu(cunicoli, true);
    safeScanf(&choice);
    switch (choice) {
      case '1': ins_caverna(map); break;
      case '2': canc_caverna(map); break;
      case '3': stampa_cunicoli(true); break;
      case '4': chiudi_cunicoli(map); break;
      case '5': stampa_direzioni(); break;
      default: warn('1');
    }
  } while(!*map);
}

// ~/FirstMenu/   | Menu gioca
static void gioca(bool * map) {
  if (*map) {
    currentPlayer = rand() % 2 ? &arvais : &hartornen;
    US turno = 0;
    US usChoice;
    char choice;
    bool gameOver = false;
    enumRagione gameOverReason;
    getThroughTunnel(&primo_cunicolo_arvais, avanti);
    getThroughTunnel(&primo_cunicolo_hartornen, avanti);
    inizializzazione_scavatrici();
    do {
      switchPlayer(&turno, true);
      clr;
      US probabilita_scontro = rand()%101;
      if (probabilita_scontro < currentPlayer->probabilitaScontro && turno > 10 && !(arvais.exit || hartornen.exit) && !(otherPlayer->posizione->stato == uscita)) {
        scontro_finale(&turno, &gameOverReason, map);
        break;
      }
      bool firstPrint = true;
      enumStato statoCaverna = currentPlayer->posizione->stato;
      do {
        resoconto_scavatrice(turno, !firstPrint);
        if (checkGameOver(&gameOverReason, false))
          break;
        printMenu(play, true);
        safeScanf(&choice);
        usChoice = choice - 48;
        if (usChoice > can(mAvanza) + can(mAggira) + can(mAbbatti) + can(mEsci) || usChoice == 0) {
          warn('1');
          firstPrint = true;
        }
      } while(usChoice > can(mAvanza) + can(mAggira) + can(mAbbatti) + can(mEsci) || usChoice == 0);
      // Questo serve perché resoconto_scavatrice dopo la prima stampa annulla lo stato della caverna
      currentPlayer->posizione->stato = statoCaverna;
      if (!checkGameOver(&gameOverReason, false))
        switch (choice) {
          case '1':
            if (can(mAvanza))
              avanza();
            else if (can(mAggira))
              aggira();
            else if (can(mAbbatti))
              abbatti();
            else
              esci();
            break;
          case '2':
            if ((can(mAvanza) || can(mAggira)) && can(mAbbatti))
              abbatti();
            else
              esci();
            break;
          case '3':
            esci();
        }
      gameOver = checkGameOver(&gameOverReason, true);
      fflush(stdin);
    } while(!gameOver);
    termina_gioco(gameOverReason, map);
  } else {
    puts("\nPer poter giocare è prima necessario creare la mappa.\n"
         "Seleziona crea cunicoli e procedi con la creazione");
    waitEnter();
  }
}

// ~/FirstMenu/   | Resoconto finale
static void termina_gioco(enumRagione ragione, bool * map) {
  if (ragione != ragione_deallocazione) {
    clr;
    printf("\t\t\t\t\t%s\t\t\t\t\t\t\t%s\n", "Famiglia Arvais","Famiglia Hartornen");
    printf("\n%s\t\t\t\t%2hu\t\t\t\t\t\t\t\t%2hu\n",
    "Caverne Attraversate", arvais.caverneAttraversate , hartornen.caverneAttraversate);
    printf("\n%s\t\t\t\t\t%2hu\t\t\t\t\t\t\t\t%2hu\n",
    "Aggiramenti", arvais.aggiramenti, hartornen.aggiramenti);
    printf("\n%s\t\t\t\t\t%2hu\t\t\t\t\t\t\t\t%2hu\n",
    "Abbattimenti", arvais.abbattimenti, hartornen.abbattimenti);
    printf("\n%s\t\t\t\t%2hu\t\t\t\t\t\t\t\t%2hu\n",
    "Invasioni subite", arvais.invasioni, hartornen.invasioni);
    printf("\n%s\t\t\t\t%2hu\t\t\t\t\t\t\t\t%2hu\n",
    "Melassa raccolta", arvais.raccolta, hartornen.raccolta);
    switch (ragione) {
      case ragione_esaurimento:
        printf("\n%s\t\t\t\t\t%13s\t\t\t\t\t\t\t%14s\n",
        "Partita", arvais.energia < 0 ? "Sconfitta":"Vittoria",
        hartornen.energia < 0 ? "Sconfitta":"Vittoria");
        puts("\n\nRagione: Esaurimento Melassa\n");
        arvais.energia < 0 ? hartornen.vittorie++ : arvais.vittorie++;
        break;
      case ragione_uscita:
        if (arvais.raccolta == hartornen.raccolta) {
          printf("\n%s\t\t\t\t\t%13s\t\t\t\t\t\t\t%14s\n", "Partita", "Pareggio", "Pareggio");
          hartornen.vittorie++;
          arvais.vittorie++;
        } else {
          printf("\n%s\t\t\t\t\t%13s\t\t\t\t\t\t\t%14s\n",
          "Partita", arvais.raccolta > hartornen.raccolta ? "Vittoria":"Sconfitta",
          arvais.raccolta < hartornen.raccolta ? "Vittoria":"Sconfitta");
          arvais.raccolta < hartornen.raccolta ? hartornen.vittorie++ : arvais.vittorie++;
        }
        puts("\n\nRagione: Uscita dai Cunicoli\n");
        break;
      case ragione_scontroFinale:
        printf("\n%s\t\t\t\t\t\t%2hu\t\t\t\t\t\t\t\t%2hu\n",
        "Spari", arvais.azioni[0], hartornen.azioni[0]);
        printf("\n%s\t\t\t%2hu\t\t\t\t\t\t\t\t%2hu\n",
        "Attacchi con arma secondaria", arvais.azioni[1], hartornen.azioni[1]);
        printf("\n%s\t\t%2hu\t\t\t\t\t\t\t\t%2hu\n",
        "Attacchi potenziati con arma secondaria", arvais.azioni[2], hartornen.azioni[2]);
        printf("\n%s\t\t\t\t%2hu\t\t\t\t\t\t\t\t%2hu\n",
        "Risvegli del dormiente", arvais.azioni[3], hartornen.azioni[3]);
        printf("\n%s\t\t\t\t%2hu\t\t\t\t\t\t\t\t%2hu\n",
        "Richiami del baco", arvais.azioni[4], hartornen.azioni[4]);
        printf("\n%s\t\t\t\t%2hu\t\t\t\t\t\t\t\t%2hu\n",
        "Richariche serbatoio", arvais.azioni[5], hartornen.azioni[5]);
        printf("\n%s\t\t\t\t\t%2hu\t\t\t\t\t\t\t\t%2hu\n",
        "Cure effettuate", arvais.azioni[6], hartornen.azioni[6]);
        printf("\n%s\t\t\t\t\t%2hu\t\t\t\t\t\t\t\t%2hu\n",
        "Turni saltati", arvais.azioni[7], hartornen.azioni[7]);
        printf("\n%s\t\t\t\t\t%13s\t\t\t\t\t\t\t%14s\n",
        "Partita", arvais.salute <= 0 ? "Sconfitta":"Vittoria",
        hartornen.salute <= 0 ? "Sconfitta":"Vittoria");
        arvais.salute <= 0 ? hartornen.vittorie++ : arvais.vittorie++;
        puts("\nRagione: Scontro Finale");
        break;
      case ragione_deallocazione:;
    }
    printf("\n%s\t\t\t\t\t%2hu\t\t\t\t\t\t\t\t%2hu\n", "Vittorie", arvais.vittorie, hartornen.vittorie);
    printf("%s\n\n\n\n\n\n\n\n\n", ragione == ragione_scontroFinale ? "\n" : "\n\n\n\n\n\n\n\n\n\n\n");
    waitEnter();
  }
  freeMap(map, freeEntrambi);
  azzeramento_scavatrici(ragione);
  currentPlayer = NULL;
}

// ~/FirstMenu/crea_cunicoli/   | Menu creazione caverna
static void ins_caverna(bool * map) {
  system("clear");

  if (isEmpty(primo_cunicolo_arvais))
    crea_caverne(0, 0);
  else if (isEmpty(primo_cunicolo_hartornen)) {
    getThroughTunnel(&primo_cunicolo_arvais, avanti);
    crea_caverne(0, getThroughTunnel(&primo_cunicolo_arvais, indietro) + 1);
  } else {
    char deleteChoice;
    CavernaPtr *arvaisPtr = &primo_cunicolo_arvais;
    CavernaPtr *hartornenPtr = &primo_cunicolo_hartornen;
    if (getThroughTunnel(arvaisPtr, avanti) + getThroughTunnel(hartornenPtr, avanti) == 18) {
      do {
        puts(
            "Poiché entrambi i cunicoli sono stati completati per creare una nuova\n"
            "caverna occorre cancellarli entrambi, confermi di voler procedere?\n"
            "(l'operazione è irreversibile) (y/n):"
        );
        safeScanf(&deleteChoice);
        if (deleteChoice != 'y' && deleteChoice != 'n')
          warn('1');
        } while(deleteChoice != 'y' && deleteChoice != 'n');
        if (deleteChoice == 'y') {
          freeMap(map, freeEntrambi);
          puts("\nLa mappa è stata cancellata. Ora è possibile crearne una nuova");
          waitEnter();
          return;
        } else {
          getThroughTunnel(arvaisPtr, indietro);
          getThroughTunnel(hartornenPtr, indietro);
        }
    } else {
      getThroughTunnel(arvaisPtr, indietro);
      getThroughTunnel(hartornenPtr, indietro);
    }
    getThroughTunnel(&primo_cunicolo_hartornen, avanti);
    crea_caverne(1, getThroughTunnel(&primo_cunicolo_hartornen, indietro) + 1);
  }
}

// ~/FirstMenu/crea_cunicoli/   | Cancella l'ultima caverna inserita
static void canc_caverna(bool * map) {
  system("clear");

  if (isEmpty(primo_cunicolo_arvais)) {
    puts("La mappa è vuota");
    waitEnter();
  } else {
    US DoctorWho = isEmpty(primo_cunicolo_hartornen);
    CavernaPtr *tempPtrPtr = DoctorWho ? &primo_cunicolo_arvais : &primo_cunicolo_hartornen;
    getThroughTunnel(tempPtrPtr, indietro);
    CavernaPtr tempPtr = *tempPtrPtr;
    stampaCunicolo(tempPtr);
    *tempPtrPtr = (*tempPtrPtr)->indietro;
    if (!isEmpty(*tempPtrPtr)) {
      (*tempPtrPtr)->avanti = NULL;
      (*tempPtrPtr)->destra = NULL;
      (*tempPtrPtr)->sinistra = NULL;
    }
    free(tempPtr);
    printf("\n    È stata rimossa l'ultima caverna della famiglia %s\n\n", DoctorWho ? "Arvais" : "Hartornen");
    stampaCunicolo(*tempPtrPtr);
    *map = false;
    waitEnter();
  }
}

// ~/FirstMenu/crea_cunicoli/   | Stampa i cunicoli creati
static void stampa_cunicoli(bool needEnter) {
  spaces(19, "Cunicolo della famiglia Arvais\n");
  stampaCunicolo(primo_cunicolo_arvais);
  puts("");
  spaces(19, "Cunicolo della famiglia Hartornen\n");
  stampaCunicolo(primo_cunicolo_hartornen);
  puts("");
  if (needEnter)
    waitEnter();
}

// ~/FirstMenu/crea_cunicoli/   | Verifica le condizioni d'uscita e crea la mappa
static void chiudi_cunicoli(bool * map) {
  CavernaPtr *arvaisPtr = &primo_cunicolo_arvais;
  CavernaPtr *hartornenPtr = &primo_cunicolo_hartornen;

  if (getThroughTunnel(arvaisPtr, avanti) + getThroughTunnel(hartornenPtr, avanti) == 18) {
    char confirm;
    do {
      stampa_cunicoli(false);
      puts("Va bene così? (y/n)\n");
      safeScanf(&confirm);
      if (confirm != 'y' && confirm != 'n')
        warn('1');
    } while(confirm != 'y' && confirm != 'n');
    if (confirm == 'y') {
      *map = true;
      getThroughTunnel(arvaisPtr, indietro);
      getThroughTunnel(hartornenPtr, indietro);
      system("clear");
      puts("Ok, i cunicoli sono stati completati.");
      waitEnter();
    } else
      return;
  } else {
    *map = false;
    getThroughTunnel(arvaisPtr, indietro);
    getThroughTunnel(hartornenPtr, indietro);
    puts(
      "\nNon è possibile chiudere i cunicoli perché ancora non contengono 10 caverne ognuno.\n"
      "Torna all'inserimento caverne per completarli"
    );
    waitEnter();
  }
}

// ~/FirstMenu/crea_cunicoli/   | Stampa un cunicolo
static void stampaCunicolo(CavernaPtr currentPtr) {
  if (isEmpty(currentPtr))
    spaces(32, "Vuoto\n");
  else {
    getThroughTunnel(&currentPtr, avanti);
    const char *top = "/  \\";
    const char *low[4] = {"/ __/", "\\  /", "\\__ \\", "\\__/"};
    const char *aisle[3] = {"/ /", "|  |", "\\ \\"};
    unsigned short space = 32;
    caveColors(currentPtr);
    spaces(space + 1, "__");
    spaces(space, top);
    while (!(isEmpty(currentPtr->sinistra) && isEmpty(currentPtr->destra) && isEmpty(currentPtr->avanti))) {
      switch (currentPtr->nextDirection) {
        case 's':
          spaces(--space, low[0]);
          printf("\x1b[0m\x1b[37m");
          spaces(--space, aisle[0]);
          caveColors(currentPtr->sinistra);
          spaces(--space, top);
          currentPtr = currentPtr->sinistra; break;
        case 'a':
          spaces(space, low[1]);
          printf("\x1b[0m\x1b[37m");
          spaces(space, aisle[1]);
          caveColors(currentPtr->avanti);
          spaces(space, top);
          currentPtr = currentPtr->avanti; break;
        case 'd':
          spaces(space++, low[2]);
          printf("\x1b[0m\x1b[37m");
          spaces(++space + 1, aisle[2]);
          caveColors(currentPtr->destra);
          spaces(++space, top);
          currentPtr = currentPtr->destra; break;
      }
    }
    spaces(space, low[3]);
    printf("\x1b[0m");
  }
}

// ~/FirstMenu/crea_cunicoli   | Fa puntare un puntatore a cunicolo all'inizio o
//                               alla fine del cunicolo e restituisce la lunghezza del cunicolo
static US getThroughTunnel(CavernaPtr *currentPtr, enumDirezione direzione) {
  if (isEmpty(*currentPtr))
    return 0;
  US count = 0;
  switch (direzione) {
    case indietro:
      while (!isEmpty((*currentPtr)->avanti) || !isEmpty((*currentPtr)->destra) || !isEmpty((*currentPtr)->sinistra)) {
        switch ((*currentPtr)->nextDirection) {
          case 's': *currentPtr = (*currentPtr)->sinistra; break;
          case 'd': *currentPtr = (*currentPtr)->destra; break;
          case 'a': *currentPtr = (*currentPtr)->avanti;
        }
        count++;
      } break;
    case avanti:
      while (!isEmpty((*currentPtr)->indietro)) {
        *currentPtr = (*currentPtr)->indietro;
        count++;
      }
  }
  return count;
}

// ~/FirstMenu/crea_cunicoli/stampaCunicolo   | Stampa un carattere di colore
static void caveColors(CavernaPtr currentPtr) {
  printf("\x1b[0m");
  switch (currentPtr->stato) {
    case normale: printf("\x1b[1m\x1b[33m"); break;
    case speciale: printf("\x1b[1m\x1b[36m"); break;
    case accidentata: printf("\x1b[1m\x1b[31m"); break;
    case uscita: printf("\x1b[5m\x1b[1m\x1b[104m"); break;
  }
}

// ~/FirstMenu/crea_cunicoli/ins_caverna   | Crea i cunicoli
static void crea_caverne(size_t i, size_t j) {
  CavernaPtr *cunicoli[] = {&primo_cunicolo_arvais, &primo_cunicolo_hartornen};
  char direction;
  US stato;
  char randomChoice;
  do {
    puts("In che modo vuoi generare le caverne?");
    printMenu(caverneRandom, false);
    safeScanf(&randomChoice);
    if (randomChoice != '1' && randomChoice != '2')
      warn('1');
  } while(randomChoice != '1' && randomChoice != '2');
  bool random = randomChoice == '1';
  char charStato;
  for (; i < 2; i++) {
    for (; j < 10; j++) {
      if (random)
        stato = rand() % 3;
      else {
        do {
          system("clear");
          if (j)
            stampaCunicolo(*cunicoli[i]);
          printMenu(tipoCaverna, true);
          safeScanf(&charStato);
          stato = charStato - 48;
          stato--;
          if (stato != normale && stato != speciale && stato != accidentata && stato != 3)
            warn('1');
        } while(stato != normale && stato != speciale && stato != accidentata && stato != 3);
        if (stato == 3)
          return;
      }
      CavernaPtr cave = newCave(i, false);
      cave->stato = stato;
      cave->numero = j;
      if (j) {
        if (random) {
          char dir[3] = {'a', 's', 'd'};
          direction = dir[rand() % 3];
        } else {
          do {
            system("clear");
            stampaCunicolo(*cunicoli[i]);
            printMenu(tipoCaverna, true);
            printf("> %d\n", stato + 1);
            printMenu(direzione, true);
            safeScanf(&direction);
            if (direction != 's' && direction != 'd' && direction != 'a')
              warn('1');
          } while(direction != 's' && direction != 'd' && direction != 'a');
        }
        (*cunicoli[i])->nextDirection = direction;
        switch (direction) {
          case 's': (*cunicoli[i])->sinistra = cave; break;
          case 'd': (*cunicoli[i])->destra = cave; break;
          case 'a': (*cunicoli[i])->avanti = cave; break;
        }
      }
      cave->indietro = *cunicoli[i];
      *cunicoli[i] = cave;
    }
    j = 0;
  }
}

// ~/FirstMenu/gioca  | Stabilisce si il player può compiere una determinata azione
static bool can(enumMossa mossa) {
  ScavatricePtr cp = currentPlayer;
  switch (mossa) {
    case mAvanza:
      return cp->posizione->sinistra || cp->posizione->avanti || cp->posizione->destra;
      break;
    case mAbbatti:
      return cp->energia > 0;
      break;
    case mAggira:
      return false;
      break;
    case mEsci:
      return cp->posizione->stato == uscita;
      break;
    case pistolaLaser:
      return cp->energia > 0;
      break;
    case colpoEstraniante:
      return findSpecial(moduloEstraniante) && cp->energia > 1 && !cp->azione;
      break;
    case colpoAssassino:
      return findSpecial(cercatoreAssassino) && cp->energia > 1 && !cp->azione;
      break;
    case superColpoEstraniante:
      return findSpecial(moduloEstraniante) && findSpecial(denteDiLeto) && cp->energia > 2 && !cp->azione;
      break;
    case superColpoAssassino:
      return findSpecial(cercatoreAssassino) && findSpecial(amplificatoreDiDolore) && cp->energia > 2 && !cp->azione;
      break;
    case risveglioDelDormiente:
      return findSpecial(anelloDelSigillo) && findSpecial(acquaDellaVita) && !cp->azione;
      break;
    case richiamoDelBaco:
      return findSpecial(risveglio) && cp->energia > 0;
      break;
    case ricaricaEnergia:
      return cp->raccolta > 0 && cp->energia < 4;
      break;
    case cura:
      return cp->energia > 0 && cp->salute < 100;
      break;
    case nessuna_mossa:
      return false;
  }
}

// ~/FirstMenu/gioca  | Abbatte una caverna consumando melassa e dealloca il percorso alternativo se esistente
static void abbatti() {
  currentPlayer->energia--;
  if (currentPlayer->energia < 0)
    return;
  bool fakeMap;
  CavernaPtr *cunicoli[] = { &primo_cunicolo_arvais, &primo_cunicolo_hartornen };
  char nd;
  char pnd = currentPlayer->posizione->nextDirection;
  char *directions[] = {"\tIn avanti (a)\n", "\tVerso destra (d)\n", "\tVerso sinistra (s)\n"};
  do {
    puts("\nIn che direzione vuoi andare?");
    switch (pnd) {
      case 'a': printf("%s%s", directions[1], directions[2]); break;
      case 'd': printf("%s%s", directions[0], directions[2]); break;
      case 's': printf("%s%s", directions[0], directions[1]); break;
      default: printf("%s%s%s", directions[0], directions[1], directions[2]);
    }
    safeScanf(&nd);
    if (pnd ?
      (pnd == 'a' ? nd != 'd' && nd != 's' : (pnd == 'd' ? nd != 'a' && nd != 's' : nd != 'a' && nd != 'd')) :
      (nd != 'a' && nd != 'd' && nd != 's')
    )
      warn('1');
  } while(pnd ?
    (pnd == 'a' ? nd != 'd' && nd != 's' : (pnd == 'd' ? nd != 'a' && nd != 's' : nd != 'a' && nd != 'd'))
    :(nd != 'a' && nd != 'd' && nd != 's')
  );
  clr;
  jsPrintAction(mAbbatti, nd);
  *cunicoli[currentPlayer->eFamiglia] = next(currentPlayer->posizione);
  if (*cunicoli[currentPlayer->eFamiglia])
    (*cunicoli[currentPlayer->eFamiglia])->indietro = NULL;
  CavernaPtr nuovaCaverna = newCave(currentPlayer->eFamiglia, true);
  currentPlayer->posizione->stato = normale;
  currentPlayer->posizione->nextDirection = nd;
  currentPlayer->posizione->avanti = NULL;
  currentPlayer->posizione->sinistra = NULL;
  currentPlayer->posizione->destra = NULL;
  nuovaCaverna->indietro = currentPlayer->posizione;
  currentPlayer->posizione->imprevisto = nessun_imprevisto;
  //printf("\nConsumando \x1b[91m1 unità\x1b[0m di melassa hai abbattuto la parete ");
  switch (currentPlayer->posizione->nextDirection) {
    case 'a':
      currentPlayer->posizione->avanti = nuovaCaverna;
      //printf("\x1b[93mdavanti\x1b[0m a te, ");
      break;
    case 'd':
      currentPlayer->posizione->destra = nuovaCaverna;
      //printf("alla tua \x1b[93mdestra\x1b[0m, ");
      break;
    case 's':
      currentPlayer->posizione->sinistra = nuovaCaverna;
      //printf("alla tua \x1b[93msinistra\x1b[0m, ");
      break;
  }
  //puts("al prossimo turno potrai attraversarla.");
  currentPlayer->abbattimenti++;
  if (*cunicoli[currentPlayer->eFamiglia])
    freeMap(&fakeMap, currentPlayer->eFamiglia + 1);
  *cunicoli[currentPlayer->eFamiglia] = currentPlayer->posizione;
  //system("sleep 1.5");
}

// ~/FirstMenu/gioca  | Sposta il giocatore in una nuova caverna nel mezzo del cunicolo e dealloca la precedente
static void aggira() {
  CavernaPtr deviazione = newCave(currentPlayer->eFamiglia, false);
  CavernaPtr ultimaCaverna = currentPlayer->posizione;
  char prevNd = ultimaCaverna->nextDirection;
  char nd;
  char pnd = currentPlayer->posizione->nextDirection;
  char *directions[] = {"\tIn avanti (a)\n", "\tVerso destra (d)\n", "\tVerso sinistra (s)\n"};
  do {
    puts("In che direzione vuoi andare?");
    switch (pnd) {
      case 'a': printf("%s%s", directions[1], directions[2]); break;
      case 'd': printf("%s%s", directions[0], directions[2]); break;
      case 's': printf("%s%s", directions[0], directions[1]); break;
    }
    safeScanf(&nd);
    if (pnd == 'a' ? nd != 'd' && nd != 's' : (pnd == 'd' ? nd != 'a' && nd != 's' : nd != 'a' && nd != 'd'))
      warn('1');
  } while(pnd == 'a' ? nd != 'd' && nd != 's' : (pnd == 'd' ? nd != 'a' && nd != 's' : nd != 'a' && nd != 'd'));

  CavernaPtr *cunicoli[] = { &primo_cunicolo_arvais, &primo_cunicolo_hartornen };
  deviazione->nextDirection = prevNd;
  switch (prevNd) {
    case 'a':
      deviazione->avanti = next(currentPlayer->posizione);
      deviazione->avanti->indietro = deviazione;
      break;
    case 's':
      deviazione->sinistra = next(currentPlayer->posizione);
      deviazione->sinistra->indietro = deviazione;
      break;
    case 'd':
      deviazione->destra = next(currentPlayer->posizione);
      deviazione->destra->indietro = deviazione;
      break;
  }
  currentPlayer->posizione = deviazione;
  currentPlayer->caverneAttraversate++;
  currentPlayer->aggiramenti++;
  currentPlayer->energia--;
  clr;
  jsPrintAction(mAggira, nd);
  *cunicoli[currentPlayer->eFamiglia] = currentPlayer->posizione;
  free(ultimaCaverna);
  currentPlayer->posizione->indietro = NULL;
}

// ~/FirstMenu/gioca  | Sposta il giocatore nella caverna successiva e dealloca la precedente
static void avanza() {
  US crollo_improvviso = rand()%101;
  if (crollo_improvviso <= 25) {
    char scelta;
    do {
      clr;
      puts("C'è stato un crollo improvviso, non è possibile avanzare!\n");
      if (!currentPlayer->energia) {
        currentPlayer->energia--;
        return;
      }
      puts("Effettua una scelta:\n\t1. Aggira\n\t2. Abbatti");
      safeScanf(&scelta);
      if (scelta != '1' && scelta != '2')
        warn('1');
    } while(scelta != '1' && scelta != '2');
    puts("");
    switch (scelta) {
      case '1': aggira(); break;
      case '2': abbatti(); break;
    }
    return;
  }
  CavernaPtr *cunicoli[] = { &primo_cunicolo_arvais, &primo_cunicolo_hartornen };
  CavernaPtr ultimaCaverna = currentPlayer->posizione;
  char nd = currentPlayer->posizione->nextDirection;
  clr;
  jsPrintAction(mAvanza, nd);
  switch (nd) {
    case 'a':
      currentPlayer->posizione = currentPlayer->posizione->avanti; break;
    case 'd':
      currentPlayer->posizione = currentPlayer->posizione->destra; break;
    case 's':
      currentPlayer->posizione = currentPlayer->posizione->sinistra; break;
  }
  currentPlayer->caverneAttraversate++;
  currentPlayer->posizione->indietro = NULL;
  *cunicoli[currentPlayer->eFamiglia] = currentPlayer->posizione;
  free(ultimaCaverna);
  // char *directions[] = {"\x1b[93mdavanti\x1b[0m a te", "alla tua \x1b[93mdestra\x1b[0m", "alla tua \x1b[93msinistra\x1b[0m"};
  // printf(
  //   "\nTi sei appena spostato nella caverna %s\n",
  //   nd == 'a' ? directions[0] : (nd == 'd' ? directions[1] : directions[2])
  // );
  // system("sleep 1.5");
}

// ~/FirstMenu/gioca  | Controlla se le condizioni per il game over sono soddisfatte quindi interrompe il gioco
static bool checkGameOver(enumRagione * ragione, bool print) {
  char command[50];
  if (arvais.exit && hartornen.exit) {
    if (print)
      system("./effetto.js scontro exit.txt");
      system("sleep 1");
      if (arvais.raccolta != hartornen.raccolta) {
        sprintf(command, "clear; ./effetto.js slideLeft %s.txt", arvais.raccolta < hartornen.raccolta ? "arvais" : "hartornen");
        system(command);
        system("sleep 1");
        system("clear; ./effetto.js death death.txt");
        system("sleep 1");
      } else
        system("clear; ./effetto baco parita.txt");
      system("sleep 1");
      waitEnter();
    *ragione = ragione_uscita;
    return true;
  } else if (arvais.sFinal && hartornen.sFinal) {
      *ragione = ragione_scontroFinale;
      if (currentPlayer->salute <= 0) {
        sprintf(command, "clear; ./effetto.js slideRight %s.txt", currentPlayer->famiglia);
        system(command);
        system("sleep 1");
        system("clear; ./effetto.js death death.txt");
        system("sleep 1");
        waitEnter();
        return false;
      }
      return true;
  } else if (currentPlayer->energia < 0 || (!(can(mAvanza) || can(mAbbatti) || can(mAggira) || can(mEsci)) && !print)) {
    if (print) {
      if (!can(mAbbatti))
        puts("Hai esaurito la melassa e non puoi più avanzare...");
      else
        puts("Hai esaurito la melassa...");
      system("sleep 2");
      sprintf(command, "clear; ./effetto.js slideLeft %s.txt", currentPlayer->famiglia);
      system(command);
      system("sleep 1");
      system("clear; ./effetto.js death death.txt");
      system("sleep 1");
      waitEnter();
    }
    *ragione = ragione_esaurimento;
    return true;
  } else
    return false;
}

// ~/FirstMenu/gioca  | Estrae il giocatore dai cunicoli e smette di farlo giocare
static void esci() {
  CavernaPtr *cunicoli[] = { &primo_cunicolo_arvais, &primo_cunicolo_hartornen };
  *cunicoli[currentPlayer->eFamiglia] = currentPlayer->posizione;
  jsPrintAction(mEsci, 0);
  currentPlayer->exit = true;
}

// ~/FirstMenu/gioca  | Setta i parametri
static void inizializzazione_scavatrici() {
  ScavatricePtr scavatrice[] = {&arvais, &hartornen};
  for (size_t i = 0; i < 2; i++) {
    scavatrice[i]->energia = 4;
    for (size_t j = 0; j < 5; j++)
      scavatrice[i]->zaino[j] = nessuno;
    scavatrice[i]->famiglia = i ? "Hartornen" : "Arvais";
    scavatrice[i]->eFamiglia = i ? fHartornen : fArvais;
    scavatrice[i]->posizione = i ? primo_cunicolo_hartornen : primo_cunicolo_arvais;
    scavatrice[i]->salute = 100;
  }
}

// ~/FirstMenu/gioca  | Restituisce la caverna successiva a quella passata come parametro
static CavernaPtr next(CavernaPtr currentPtr) {
    switch (currentPtr->nextDirection) {
      case 'a': return currentPtr->avanti; break;
      case 'd': return currentPtr->destra; break;
      case 's': return currentPtr->sinistra; break;
      default: return NULL;
    }
}

// ~/FirstMenu/gioca  | Restituisce la prossima direzione della caverna attuale
static char * nomeDirezione() {
  switch (currentPlayer->posizione->nextDirection) {
    case 'a': return "avanti"; break;
    case 's': return "sinistra"; break;
    case 'd': return "destra"; break;
    default: return "nessuna";
  }
}

//~/FirstMenu/gioca  | Stampa informazioni sull'attuale scavatrice
static void resoconto_scavatrice(US turno, bool inPutMelassa) {
  US eventi = 0;
  bool eventoSpeciale = false;
  clr;
  switch (currentPlayer->eFamiglia) {
    case fArvais:
      system("echo '\x1b[1m\x1b[36m'; cat arvais.txt; echo '\x1b[0m'");
      break;
    case fHartornen:
      system("echo '\x1b[1m\x1b[31m'; cat hartornen.txt; echo '\x1b[0m'");
  }
  if (!inPutMelassa)
    system("sleep .5");
  printf("Turno: %hu\n\n", turno);
  if (!inPutMelassa)
	 system("sleep .03");
  separatore('-', 40);
  if (!inPutMelassa)
	 system("sleep .03");
  printf("\nDirezione consentita: \x1b[1m%s\x1b[0m\n\n", nomeDirezione());
  if (!inPutMelassa)
    system("sleep .03");
  separatore('-', 40);
  if (!inPutMelassa)
		system("sleep .03");
  printf("\nSerbatoio energia\t: [ ");
  for (size_t i = 1; i <= 4; i++)
    printf("%s", i <= currentPlayer->energia ? "#" : "·");
  puts(" ]");
  if (!inPutMelassa)
		system("sleep .03");
  printf("Serbatoio raccolta\t: [ ");
  for (size_t i = 1; i <= 10; i++)
    printf("%s", i <= currentPlayer->raccolta ? "#" : "·");
  puts(" ]\n");
  if (!inPutMelassa)
		system("sleep .03");
  separatore('-', 40);
  if (!inPutMelassa)
		system("sleep .03");
  for (size_t i = 0; i < 4; i++) {
    if (currentPlayer->zaino[i]) {
      printf("\nOggetti speciali\t: [ ");
      for (size_t j = 0; j < 4; j++) {
        enumSpeciale oggetto = currentPlayer->zaino[j];
        char *string = NULL;
        switch (oggetto) {
          case moduloEstraniante:
          case cercatoreAssassino:
            string = oggetto == moduloEstraniante ? "Modulo Estraniante" : "Cercatore Assassino";
            break;
          case denteDiLeto:
          case amplificatoreDiDolore:
            string = oggetto == denteDiLeto ? "Dente di Leto" : "Amplificatore di Dolore";
            break;
          case anelloDelSigillo:
            string = "Anello del Sigillo";
            break;
          case acquaDellaVita:
            string = "Acqua della Vita";
            break;
          case risveglio:;
          case nessuno:;
        }
        if (string) {
          printf(" %s", string);
          for (size_t k = j + 1; k < 4; k++)
            if (currentPlayer->zaino[k]) {
              printf(",");
              break;
            }
        }
      }
      puts(" ]\n");
      if (!inPutMelassa)
    		system("sleep .03");
      separatore('-', 40);
      if (!inPutMelassa)
    		system("sleep .03");
      break;
    }
  }
  puts("\nReport avvenimenti:\n");
  if (!inPutMelassa)
		system("sleep .03");
  separatore('>', 112);
  puts("");
  if (!inPutMelassa)
		system("sleep .03");
  if (currentPlayer->posizione->oggettoSpeciale) {
    putSpeciale(&eventoSpeciale);
    if (eventoSpeciale) puts("");
  }
  if (currentPlayer->posizione->imprevisto != baco) {
    short contoMelassa = 0;
    switch (currentPlayer->posizione->stato) {
      case normale:
      case uscita:
        break;
      case speciale:
        if (eventoSpeciale) {
          separatore('-', 112);
          system("sleep .03");
        }
        puts("La caverna in cui ti trovi irradia melassa e l'hai presa con te\t\t\t\t\t\x1b[1m+1 unità\x1b[0m");
        contoMelassa++;
        eventi++;
        if (!inPutMelassa)
    	    system("sleep .03");
        break;
      case accidentata:
        if (eventoSpeciale) {
          separatore('-', 112);
          system("sleep .03");
        }
        puts("La caverna in cui ti trovi è malridotta, è servita più potenza per scavare\t\t\t\t\x1b[91m-1 unità\x1b[0m");
        contoMelassa--;
        eventi++;
        if (!inPutMelassa)
  		    system("sleep .03");
        break;
    }
    if (currentPlayer->posizione->stato != uscita)
      currentPlayer->posizione->stato = normale;
    switch (currentPlayer->posizione->melassa) {
      case nessuna:
        break;
      case poca:
        if (contoMelassa == 0 && eventoSpeciale) {
          separatore('-', 112);
          system("sleep .03");
        }
        puts("Gli scavi hanno portato al ritrovamento di una modesta quantità di melassa\t\t\t\x1b[1m+1 unità\x1b[0m");
        contoMelassa++;
        eventi++;
        if (!inPutMelassa)
  		    system("sleep .03");
        break;
      case molta:
        if (contoMelassa == 0 && eventoSpeciale) {
          separatore('-', 112);
          system("sleep .03");
        }
        puts("Gli scavi hanno portato al ritrovamento di un'ingente quantità di melassa\t\t\t\x1b[1m+3 unità\x1b[0m");
        contoMelassa += 3;
        eventi++;
        if (!inPutMelassa)
  		    system("sleep .03");
        break;
    }
    currentPlayer->posizione->melassa = nessuna;
    if (currentPlayer->posizione->imprevisto == crollo) {
      if (contoMelassa == 0 && eventoSpeciale) {
        separatore('-', 112);
        system("sleep .03");
      }
      puts("Durante gli scavi la caverna ha subito un crollo ed è servita potenza per scrollare le macerie\t\t\x1b[91m-1 unità\x1b[0m");
      contoMelassa--;
      eventi++;
  		system("sleep .03");
      currentPlayer->posizione->imprevisto = nessun_imprevisto;
    }

    if (eventi)
      separatore('-',  112);
    system("sleep .03");
    if (contoMelassa > 0) {
      printf("Totale:\t\t\t\t\t\t\t\t\t\t\t\t\x1b[1m+%d unità\x1b[0m\n\n", contoMelassa);
      system("sleep .03");
      separatore('<', 112);
      if (!inPutMelassa) {
        puts("");
        putMelassa(turno, contoMelassa);
      }
    } else if (contoMelassa < 0) {
      printf("Totale:\t\t\t\t\t\t\t\t\t\t\t\t\t\x1b[91m%d unità\x1b[0m\n\n", contoMelassa);
      system("sleep .03");
      separatore('<', 112);
      printf("\nHai consumato \x1b[91m%u unità\x1b[0m di melassa del serbatoio di energia\n", -contoMelassa);
      currentPlayer->energia += contoMelassa;
    } else {
      if (eventi)
        printf("Totale:\t\t\t\t\t\t\t\t\t\t\t\t    \x1b[93m0 unità\x1b[0m\n\n");
      else if (!eventoSpeciale)
        puts("Niente da segnalare\n");
      system("sleep .03");
      separatore('<', 112);
    }
    puts("");
  } else {
    system("sleep 1; clear; ./effetto.js baco baco.txt; sleep 1");
    puts("Hai subito un'invasione\n");
    system("sleep 1");
    puts("Il baco ha divorato tutta la melassa che avevi\n");
    system("sleep 1.5");
    puts("in entrambi i serbatoi...\n");
    system("sleep 1.5");
    currentPlayer->energia = 0;
    currentPlayer->raccolta = 0;
    currentPlayer->invasioni++;
    if (can(mAvanza)) {
      puts(
        "Non disperare, per fortuna puoi ancora avanzare, con un po di fortuna\n"
        "troverai melassa nella prossima caverna. Tanti auguri!\n"
      );
    } else if (!can(mEsci)) {
      currentPlayer->energia--;
    }
    currentPlayer->posizione->imprevisto = nessun_imprevisto;
  }
}

//~/FirstMenu/gioca  | Stampa più volte un carattere
static void separatore(char carattere, US quantita) {
  for (size_t i = 0; i < quantita; i++)
    printf("%c", carattere);
  puts("");
}

// ~/FirstMenu/gioca  | Cambia giocatore
static void switchPlayer(US * turno, bool advance) {
  if (advance) {
    (*turno)++;
    currentPlayer->probabilitaScontro += 3;
    currentPlayer->probabilitaUscita += 15;
    if (otherPlayer && otherPlayer->azione)
      otherPlayer->caricamento_azione--;
  }
  if (currentPlayer == &arvais ? !hartornen.exit : !arvais.exit) {
    otherPlayer = currentPlayer;
    currentPlayer = currentPlayer == &arvais ? &hartornen : &arvais;
  }
}

// ~/FirstMenu/gioca/resoconto_scavatrice   | Inserisce melassa in un serbatoio
static void putMelassa(US turno, short contoMelassa) {
  if (!(valutaSceltaSerbatoio(1) && valutaSceltaSerbatoio(2))) {
    US sceltaSerbatoio;
    char charSceltaSerbatoio;
    system("sleep 1");
    do {
      printf(
        "Puoi immagazzinare \x1b[1m%u unità\x1b[0m di melassa, scegli il serbatoio in cui metterl%c:\n",
        contoMelassa, contoMelassa > 1 ? 'e':'a'
      );
      printMenu(raccoltaMelassa, false);
      safeScanf(&charSceltaSerbatoio);
      sceltaSerbatoio = charSceltaSerbatoio - 48;
      if (valutaSceltaSerbatoio(1) || valutaSceltaSerbatoio(2) ? sceltaSerbatoio != 1 : sceltaSerbatoio != 1 && sceltaSerbatoio != 2) {
        warn('1');
        resoconto_scavatrice(turno, true);
      }
    } while(valutaSceltaSerbatoio(1) || valutaSceltaSerbatoio(2) ? sceltaSerbatoio != 1 : sceltaSerbatoio != 1 && sceltaSerbatoio != 2);
    sceltaSerbatoio = sceltaSerbatoio != 2 ? (valutaSceltaSerbatoio(1) ? 2 : 1) : 2;
    switch (sceltaSerbatoio) {
      case 1:
        if (contoMelassa <= 4 - currentPlayer->energia)
          currentPlayer->energia += contoMelassa;
        else
          currentPlayer->energia = 4;
        puts("\nHai ricaricato il serbatoio di energia");
        break;
      case 2:
        if (contoMelassa <= 10 - currentPlayer->raccolta)
          currentPlayer->raccolta += contoMelassa;
        else
          currentPlayer->raccolta = 10;
        puts("\nHai ricaricato il serbatoio di raccolta");
        break;
    }
  } else
    puts("\nPoiché entrambi i serbatoi sono pieni la melassa di questa caverna verrà scartata, che spreco...");
  currentPlayer->posizione->melassa = nessuna;
  system("sleep .3");
}

// ~/FirstMenu/gioca/resoconto_scavatrice   | Inserisce oggetto speciale nello zaino
static void putSpeciale(bool *eventoSpeciale) {
  enumSpeciale oggetto = currentPlayer->posizione->oggettoSpeciale;
  bool skip = false;
  char *string = NULL;
  switch (oggetto) {
    case moduloEstraniante:
    case cercatoreAssassino:
      if (currentPlayer->zaino[0])
        skip = true;
      currentPlayer->zaino[0] = oggetto;
      string = oggetto == moduloEstraniante ? "il Modulo Estraniante" : "il Cercatore Assassino";
      break;
    case denteDiLeto:
    case amplificatoreDiDolore:
      if (currentPlayer->zaino[1])
        skip = true;
      currentPlayer->zaino[1] = oggetto;
      string = oggetto == denteDiLeto ? "il Dente di Leto" : "l'Amplificatore di Dolore";
      break;
    case anelloDelSigillo:
      if (currentPlayer->zaino[2])
        skip = true;
      currentPlayer->zaino[2] = oggetto;
      string = "l'Anello del Sigillo";
      break;
    case acquaDellaVita:
      if (currentPlayer->zaino[3])
        skip = true;
      currentPlayer->zaino[3] = oggetto;
      string = "l'Acqua della Vita";
      break;
    case risveglio:;
    case nessuno:;
  }
  currentPlayer->posizione->oggettoSpeciale = nessuno;
  if (!skip) {
    printf("Congratulazioni! Sei riuscito a ottenere %s!\n", string);
    *eventoSpeciale = true;
    system("sleep 1");
  } else {
    *eventoSpeciale = false;
  }
}

// ~/FirstMenu/gioca/resoconto_scavatrice/putMelassa  | Indica se un serbatoio può essere riempito o meno
static bool valutaSceltaSerbatoio(US sceltaSerbatoio) {
  US energia = currentPlayer->energia;
  US raccolta = currentPlayer->raccolta;
  switch (sceltaSerbatoio) {
    case 1: return energia == 4 ? true : false; break;
    case 2: return raccolta == 10 ? true : false; break;
  }
  return true;
}

// ~/FirstMenu/termina_gioco  | Resetta i parametri
static void azzeramento_scavatrici(enumRagione ragione) {
  ScavatricePtr scavatrice[] = {&arvais, &hartornen};
  for (size_t i = 0; i < 2; i++) {
    scavatrice[i]->energia = 0;
    scavatrice[i]->raccolta = 0;
    scavatrice[i]->probabilitaUscita = 0;
    scavatrice[i]->probabilitaScontro = 0;
    scavatrice[i]->posizione = NULL;
    scavatrice[i]->exit = false;
    scavatrice[i]->sFinal = false;
    if (ragione == ragione_deallocazione) {
      scavatrice[i]->salute = 0;
      scavatrice[i]->abbattimenti = 0;
      scavatrice[i]->caricamento_azione = 0;
      scavatrice[i]->caverneAttraversate = 0;
      scavatrice[i]->invasioni = 0;
      scavatrice[i]->vittorie = 0;
    }
  }
}

// ~/FirstMenu/gioca   | Menù dello scontro finale
static void scontro_finale(US * turno, enumRagione * ragione, bool * map) {
  system("./effetto.js scontro scontroFinale.txt; sleep 2");
  arvais.sFinal = true;
  hartornen.sFinal = true;
  char mossa;
  do {
    bool firstPrint = true;
    do {
      resoconto_finale(*turno, firstPrint);
      risolvi_azione();
      printMenu(finale, true);
      safeScanf(&mossa);
      if (conditionsMossaFinale(mossa)) {
        warn('1');
        firstPrint = false;
      }
    } while(conditionsMossaFinale(mossa));
    puts("");
    bool canMove[10] = { false };
    for (size_t i = 0; i < 9; i++)
      canMove[i] = can(i + 5);
    canMove[9] = true;
    US iMove = 0;
    for (size_t i = 0; i < 9; i++)
      if (mossa == 49 + i)
        switchFinalMove(canMove, &iMove, i);
    switchPlayer(turno, true);
    fflush(stdin);
  } while(checkGameOver(ragione, true));
}

// ~/FirstMenu/gioca/scontro_finale  | Comprende la scelta effettuata dal giocatore ed esegue la mossa corrispondente
static void switchFinalMove(bool arrayCanMove[], US * iterator, US mossa) {
  while ((!arrayCanMove[*iterator] || mossa) && *iterator < 10) {
    if (arrayCanMove[*iterator])
      mossa = mossa == 0 ? 0 : mossa - 1;
    (*iterator)++;
  }
  if (*iterator < 10) {
    switch (*iterator) {
      case 0: attacco(pistolaLaser); break;
      case 1: attacco(colpoEstraniante); break;
      case 2: attacco(colpoAssassino); break;
      case 3: attacco(superColpoAssassino); break;
      case 4: attacco(superColpoEstraniante); break;
      case 5: carica(_risveglio); break;
      case 6: attacco(richiamoDelBaco); break;
      case 7: carica(_energia); break;
      case 8: carica(_cura); break;
      case 9: passa(); break;
    }
    arrayCanMove[*iterator] = false;
  }
}

// ~/FirstMenu/gioca/scontro_finale  | Stampa informazioni dell'attuale scavatrice durante lo scontro finale
static void resoconto_finale(US turno, bool firstPrint) {
  clr;
  switch (otherPlayer->eFamiglia) {
    case fArvais:
      system("echo '\x1b[1m\x1b[36m'; cat arvaisEnemy.txt; echo '\x1b[0m'");
      break;
    case fHartornen:
      system("echo '\x1b[1m\x1b[31m'; cat hartornenEnemy.txt; echo '\x1b[0m'");
  }
  printf("\t\t\t\t\t\t\t\t\t\t\t\tSalute: [ ");
  for (size_t i = 1; i < 101; i += 2)
    printf("%s", i < otherPlayer->salute ? "#" : "·");
  puts(" ]");
  puts("\n\n");
  separatore('-', 167);
  puts("");
  switch (currentPlayer->eFamiglia) {
    case fArvais:
      system("echo '\x1b[1m\x1b[36m'; cat arvais.txt; echo '\x1b[0m'");
      break;
    case fHartornen:
      system("echo '\x1b[1m\x1b[31m'; cat hartornen.txt; echo '\x1b[0m'");
  }
  printf("Turno: %hu\n\n", turno);
  separatore('-', 80);
  if (firstPrint) {
    US random = rand() % 101;
    if (random > 75) {
      currentPlayer->raccolta++;
      puts("Hai ottenuto \x1b[1m1 unità\x1b[0m di melassa extra nel tuo serbatoio di raccolta");
      separatore('-', 80);
    } else if (random > 65) {
      currentPlayer->energia++;
      puts("Hai ottenuto \x1b[1m1 unità\x1b[0m di melassa extra nel tuo serbatoio di energia");
      separatore('-', 80);
    }
  }
  printf("\nSalute\t\t\t: [ ");
  for (size_t i = 1; i < 101; i += 2)
    printf("%s", i < currentPlayer->salute ? "#" : "·");
  puts(" ]");
  printf("Serbatoio energia\t: [ ");
  for (size_t i = 1; i <= 4; i++)
    printf("%s", i <= currentPlayer->energia ? "#" : "·");
  puts(" ]");
  printf("Serbatoio raccolta\t: [ ");
  for (size_t i = 1; i <= 10; i++)
    printf("%s", i <= currentPlayer->raccolta ? "#" : "·");
  puts(" ]\n");
  separatore('-', 80);
  for (size_t i = 0; i < 4; i++) {
    if (currentPlayer->zaino[i]) {
      printf("\nOggetti speciali\t: [ ");
      for (size_t j = 0; j < 5; j++) {
        enumSpeciale oggetto = currentPlayer->zaino[j];
        char *string = NULL;
        switch (oggetto) {
          case moduloEstraniante:
          case cercatoreAssassino:
            string = oggetto == moduloEstraniante ? "Modulo Estraniante" : "Cercatore Assassino";
            break;
          case denteDiLeto:
          case amplificatoreDiDolore:
            string = oggetto == denteDiLeto ? "Dente di Leto" : "Amplificatore di Dolore";
            break;
          case anelloDelSigillo:
            string = "Anello del Sigillo";
            break;
          case acquaDellaVita:
            string = "Acqua della Vita";
            break;
          case risveglio:
            string = "Risveglio del Dormiente";
            break;
          case nessuno:;
        }
        if (string) {
          printf(" %s", string);
          for (size_t k = j + 1; k < 4; k++)
            if (currentPlayer->zaino[k]) {
              printf(",");
              break;
            }
        }
      }
      puts(" ]\n");
      separatore('-', 80);
      break;
    }
  }
  puts("");
}

// ~/FirstMenu/gioca/scontro_finale  | Verifica se la scelta effettuata dal giocatore durante lo scontro finale è possibile o meno
static bool conditionsMossaFinale(char mossa) {
  short count = 49;
  for (size_t i = 4; i <= 13; i++)
    if (can(i))
      count++;
  return mossa < 49 || mossa > count;
}

// ~/FirstMenu/gioca  | Verifica se nello zaino del giocatore c'è l'oggetto speciale richiesto
static bool findSpecial(enumSpeciale oggetto) {
  for (size_t i = 0; i < 5; i++)
    if (currentPlayer->zaino[i] == oggetto)
      return true;
  return false;
}

// ~/FirstMenu/gioca/scontro_finale  | Inizia il countdown di turni per il verificarsi dell'azione selezionata
static void carica_azione(enumMossa azione) {
  currentPlayer->azione = azione;
  switch (azione) {
    case colpoEstraniante:
    case colpoAssassino:
      currentPlayer->caricamento_azione = 1;
      currentPlayer->energia -= 2;
      printf("\x1b[1m%s\x1b[0m in caricamento, il colpo verra sferrato fra \x1b[93m1\x1b[0m turno!\n",
        currentPlayer->eFamiglia == fArvais ? "Modulo estraniante" : "Cercatore assassino"
      );
      break;
    case superColpoEstraniante:
    case superColpoAssassino:
      currentPlayer->caricamento_azione = 2;
      currentPlayer->energia -= 3;
      printf("\x1b[1m%s potenziato\x1b[0m in caricamento, il colpo verra sferrato fra \x1b[93m2\x1b[0m turni!\n",
        currentPlayer->eFamiglia == fArvais ? "Modulo estraniante" : "Cercatore assassino"
      );
      break;
    case risveglioDelDormiente:
      currentPlayer->caricamento_azione = 3;
      currentPlayer->raccolta = 0;
      puts("\x1b[1mRisveglio del dormiente\x1b[0m in caricamento, il richiamo del baco sarà disponibile fra \x1b[93m3\x1b[0m turni!");
      break;
    default:;
  }
  system("sleep 1.2");
}

// ~/FirstMenu/gioca/scontro_finale  | Esegue un attacco sull'avversario
static void attacco(enumMossa mossa) {
  US danno;
  switch (mossa) {
  case pistolaLaser:
    currentPlayer->energia--;
    danno = probabilita(cPistolaLaser, false);
    otherPlayer->salute -= danno;
    currentPlayer->azioni[0]++;
    printf("Hai attaccato la famiglia \x1b[1m%s\x1b[0m con la \x1b[93mpistola laser \x1b[0minfliggendo \x1b[91m%d\x1b[0m punti di danno!\n",
      otherPlayer->famiglia, danno
    );
    break;
  case colpoEstraniante: carica_azione(colpoEstraniante); break;
  case colpoAssassino: carica_azione(colpoAssassino); break;
  case superColpoEstraniante: carica_azione(superColpoEstraniante); break;
  case superColpoAssassino: carica_azione(superColpoAssassino); break;
  case richiamoDelBaco:
    otherPlayer->energia = 0;
    otherPlayer->raccolta = 0;
    otherPlayer->salute = 0;
    currentPlayer->azioni[4]++;
    printf("Hai \x1b[91mdisintegrato\x1b[0m la famiglia %s richiamando un "
           "\x1b[93mbaco delle sabbie\x1b[0m che ha divorato la scavatrice\n",
      otherPlayer->famiglia
    );
    break;
  default:;
  }
  system("sleep 1.5");
  puts("");
}

// ~/FirstMenu/gioca/scontro_finale  | Esegue un azione di recupero o carica il risveglio del dormiente
static void carica(enumCarica carica) {
  switch (carica) {
    case _risveglio:
      carica_azione(risveglioDelDormiente);
      break;
    case _energia:
      currentPlayer->energia++;
      currentPlayer->raccolta--;
      currentPlayer->azioni[5]++;
      puts("Hai trasferito \x1b[1m1 unità\x1b[0m di melassa dal serbatoio di raccolta a quello di energia!");
      break;
    case _cura:
      currentPlayer->energia--;
      currentPlayer->salute += 10;
      currentPlayer->azioni[6]++;
      puts("Hai ripristinato \x1b[1m10\x1b[0m punti salute!");
      break;
  }
  if (carica == _risveglio) system("sleep 2");
  else system("sleep 1.5");
}

// ~/FirstMenu/gioca/scontro_finale  | Esegue un attacco che ha finito il caricamento
static void risolvi_azione() {
  if (currentPlayer->azione && !currentPlayer->caricamento_azione) {
    US danno;
    switch (currentPlayer->azione) {
      case colpoEstraniante:
      case colpoAssassino:
        danno = probabilita(cColpoEstraniante, false);
        otherPlayer->salute -= danno;
        printf("\x1b[93m%s \x1b[0m", currentPlayer->eFamiglia == fArvais ? "Modulo estraniante" : "Cercatore assassino");
        currentPlayer->zaino[0] = nessuno;
        currentPlayer->azioni[1]++;
        break;
      case superColpoEstraniante:
      case superColpoAssassino:
        danno = probabilita(cSuperColpoAssassino, false);
        otherPlayer->salute -= danno;
        printf("\x1b[93m%s \x1b[0m", currentPlayer->eFamiglia == fArvais ? "Modulo estraniante potenziato" : "Cercatore assassino potenziato");
        currentPlayer->zaino[0] = nessuno;
        currentPlayer->zaino[1] = nessuno;
        currentPlayer->azioni[2]++;
        break;
      case risveglioDelDormiente:
        currentPlayer->zaino[2] = nessuno;
        currentPlayer->zaino[3] = nessuno;
        currentPlayer->zaino[4] = risveglio;
        currentPlayer->azioni[3]++;
        break;
      default:;
    }
    if (currentPlayer->azione != risveglioDelDormiente) {
      printf("carico. La famiglia %s ha subito \x1b[91m%d\x1b[0m punti di danno!\n",otherPlayer->famiglia, danno);
      puts("");
      separatore('-', 80);
      puts("");
    }
    currentPlayer->azione = nessuna_mossa;
    system("sleep .8");
  }
}

// ~/FirstMenu/gioca/scontro_finale  | Permette di passare il turno
static void passa() {
  puts("Hai passato il turno");
  currentPlayer->azioni[7]++;
  system("sleep 1");
}

// ~/FirstMenu/gioca  | Visualizza le opzioni avanza, aggira, abbatti e esci con un sistema grafico progettato in javascript
static void jsPrintAction(enumMossa action, char nextDirection) {
  CavernaPtr *cunicoli[] = { &primo_cunicolo_arvais, &primo_cunicolo_hartornen};
  enumFamiglia x = currentPlayer->eFamiglia;
  char string[22];
  char command[66];
  getThroughTunnel(cunicoli[x], avanti);
  size_t i = 0;
  while (!(isEmpty((*cunicoli[x])->avanti) && isEmpty((*cunicoli[x])->destra) && isEmpty((*cunicoli[x])->sinistra))) {
    string[i] = (*cunicoli[x])->stato + 49;
    string[i + 1] = (*cunicoli[x])->nextDirection;
    switch ((*cunicoli[x])->nextDirection) {
      case 'a': *cunicoli[x] = (*cunicoli[x])->avanti; break;
      case 's': *cunicoli[x] = (*cunicoli[x])->sinistra; break;
      case 'd': *cunicoli[x] = (*cunicoli[x])->destra; break;
    }
    i += 2;
  }
  string[i] = (*cunicoli[x])->stato + 49;
  string[i + 1] = ':';
  string[i + 2] = action + 48;
  string[i + 3] = nextDirection;
  string[i + 4] = '\0';
  sprintf(command, "clear; echo '%s:%s' | ./printAction.js", currentPlayer->famiglia, string);
  system(command);
  clr;
}

static void stampa_direzioni() {
  clr;
  CavernaPtr *cunicoli[] = {&primo_cunicolo_arvais, &primo_cunicolo_hartornen};
  int limit = 2;
  if (isEmpty(primo_cunicolo_arvais)) {
    printf("Nessun cunicolo è ancora stato creato\n");
    waitEnter();
    return;
  } else if (isEmpty(primo_cunicolo_hartornen))
    limit = 1;
  for (size_t i = 0; i < limit; i++) {
    getThroughTunnel(cunicoli[i], avanti);
    int a=0, d=0, s=0;
    while (!isEmpty((*cunicoli[i])->avanti) || !isEmpty((*cunicoli[i])->destra) || !isEmpty((*cunicoli[i])->sinistra)) {
      switch ((*cunicoli[i])->nextDirection) {
        case 's':
          *cunicoli[i] = (*cunicoli[i])->sinistra;
          s++;
          break;
        case 'd':
          *cunicoli[i] = (*cunicoli[i])->destra;
          d++;
          break;
        case 'a':
          *cunicoli[i] = (*cunicoli[i])->avanti;
          a++;
          break;
      }
    }
    printf("Nel cunicolo %s ci sono:\n\t%d uscite in avanti\n\t%d uscite a sinistra\n\t%d uscite a destra\n\n", i ? "Hartornen" : "Arvais", a, s, d);
    //getThroughTunnel(cunicoli[i], avanti);
  }
  if (limit == 1)
    printf("Il cunicolo della famiglia Hartornen non esiste ancora\n");
  waitEnter();
}
