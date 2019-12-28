#include "gamelib.h"

static struct Caverna *Pca = NULL;        //primo cunicolo arvais
static struct Caverna *Pch = NULL;    //primo cunicolo hartornen;
static struct Scavatrice *arvais;
static struct Scavatrice *hartornen;
static void ins_caverna (struct Caverna **Pc);
static void stampa_lista (struct Caverna **Pc);
static void canc_caverna (struct Caverna **Pc);
static int prob ();    //probabilità
static void stato_caverna (struct Caverna **Pc);   //tipo caverna
static void fmelassa (struct Caverna **Pc);  // randomizzazione quantità melassa
static void fimprevisto (struct Caverna **Pc);  // randomizzazione imprevisto
static int probabilita;
static void turnoArvais ();
static void turnoHartornen ();
static void avanza (struct Caverna **Pc, struct Scavatrice **fam);
static void abbatti (struct Caverna **Pc, struct Scavatrice **fam);

static void ins_caverna (struct Caverna **Pc) {
  int scelta;
  //Dichiarazione nuova caverna
  struct Caverna *nc =(struct Caverna*) malloc(sizeof(struct Caverna));  //nuova caverna
  printf("Inserire un valore di a\n");
  scanf("%d", &(nc->a));
  nc->avanti = NULL;
  nc->destra = NULL;
  nc->sinistra = NULL;

  //Menù direzione creazione nuova caverna
  printf("Inserire una direzione\n");
  printf("1 per creare una caverna di fronte\n");
  printf("2 per creare una caverna a destra\n");
  printf("3 per creare una caverna a sinistra\n");
  scanf("%d", &scelta);

  if (*Pc == NULL) {
    *Pc = nc;
    stato_caverna (&Pca);
    fmelassa (&Pca);
    fimprevisto (&Pca);
  } else {
    switch (scelta) {
      //Caverna avanti
      case 1:
        nc->avanti = *Pc;
        nc->destra = NULL;
        nc->sinistra = NULL;
        *Pc = nc;
        stato_caverna (&Pca);
        fmelassa (&Pca);
        fimprevisto (&Pca);
        break;
        //caverna a destra
      case 2:
        nc->avanti = NULL;
        nc->destra = *Pc;
        nc->sinistra = NULL;
        *Pc = nc;
        stato_caverna (&Pca);
        fmelassa (&Pca);
        fimprevisto (&Pca);
        break;
        //caverna a sinistra
      case 3:
        nc->avanti = NULL;
        nc->destra = NULL;
        nc->sinistra = *Pc;
        *Pc = nc;
        stato_caverna (&Pca);
        fmelassa (&Pca);
        fimprevisto (&Pca);
        break;
      //case 4:
        //return;
      default:
        printf("Comando non valido");
        break;
    }
  }
  system("clear");
}

void crea_cunicoli () {
  int scelta = 0;
  int scelta2 = 0;
  printf("Creazione caverne famiglia Arvais\n");
  while (scelta != 4) {
    //menù scelta iniziale
  printf("Effettuare una scelta\n");
  printf("Premere 1 per creare cunicolo\n");
  printf("Premere 2 per cancellare una caverna precedente\n");
  printf("Premere 3 per stampare i cunicoli creati\n");
  printf("Premere 4 per uscire\n");
  scanf("%d", &scelta);

  switch (scelta) {
    case 1:
      ins_caverna (&Pca);
    break;
    case 2:
      canc_caverna (&Pca);
    break;
    case 3:
      stampa_lista (&Pca);
    break;
    case 4:
      continue;
    break;
    default:
      printf("Comando non valido\n");
       }
  }
  system("clear");
  printf("Creazione caverne famiglia Hartornen\n");

  while (scelta2 != 4) {
    //menù scelta iniziale
  printf("Effettuare una scelta\n");
  printf("Premere 1 per creare cunicolo\n");
  printf("Premere 2 per cancellare un cunicolo precedente\n");
  printf("Premere 3 per stampare i cunicoli creati\n");
  printf("Premere 4 per uscire\n");
  scanf("%d", &scelta);

  switch (scelta) {
    case 1:
      ins_caverna (&Pch);
    break;
    case 2:
      canc_caverna (&Pch);
    break;
    case 3:
      stampa_lista (&Pch);
    break;
    case 4:
      return;
    break;
    default:
      printf("Comando non valido\n");
    }
  }
}

static void stampa_lista (struct Caverna **Pc) {
  if(*Pc == NULL) {
      printf("Non ci sono caverne\n"); }
  else {
    struct Caverna* sonda = *Pc;

    do {
      if (sonda->tipo_caverna == 0)
        printf("Valore: %d, Tipo: Normale\n", sonda->a);
      else if (sonda->tipo_caverna == 1)
        printf("Valore: %d, Tipo: Speciale\n", sonda->a);
      else
        printf("Valore: %d, Tipo: Accidentata\n", sonda->a);
          if (sonda->avanti != NULL)
            sonda = sonda ->avanti;
          else if (sonda->destra != NULL)
            sonda = sonda ->destra;
          else
            sonda = sonda ->sinistra;
        //sonda = sonda ->destra;
        //sonda = sonda ->sinistra;
    }while(sonda != NULL);
  }
      return;
}

static void canc_caverna (struct Caverna **Pc) {
  if (*Pc == NULL)
    printf("Non ci sono caverne\n");
  else if ((*Pc)->avanti != NULL) {
      struct Caverna *temp = (*Pc)->avanti;
      free(*Pc);
      *Pc = temp;
    }
  else if ((*Pc)->destra != NULL) {
      struct Caverna *temp = (*Pc)->destra;
      free(*Pc);
      *Pc = temp;
  }
  else {
      struct Caverna *temp = (*Pc)->sinistra;
      free(*Pc);
      *Pc = temp;
  }
    system("clear");
    return;
  }

static void stato_caverna (struct Caverna **Pc) {
  int scelta;
  //Menù stato caverna
  printf("Di che tipo deve essere la caverna?\n");
  printf("Premere 1 per creare una caverna normale\n");
  printf("Premere 2 per creare una caverna speciale\n");
  printf("Premere 3 per creare una caverna accidentata\n");
  scanf("%d", &scelta);

  switch (scelta) {
    case 1:
      (*Pc)->tipo_caverna = normale;
      break;
    case 2:
      (*Pc)->tipo_caverna = speciale;
      break;
    case 3:
      (*Pc)->tipo_caverna = accidentata;
      break;
    case 4:
      printf("Comando non valido\n");
      break;
    default:
      return;
  }
}

static int prob () {
  probabilita = (rand () % 100);
  return probabilita;
}

static void fmelassa (struct Caverna **Pc) {
  probabilita = 0;
  prob ();
  if (probabilita <= 50)
    (*Pc)->melassa = nessuna;
  else if (probabilita > 50 && probabilita <= 80)
    (*Pc)->melassa = poca;
  else if (probabilita > 80 && probabilita <= 100)
    (*Pc)->melassa = molta;
}

static void fimprevisto (struct Caverna **Pc) {
  probabilita = 0;
  prob ();
  if (probabilita <= 50)
    (*Pc)->imprevisto = nessun_imprevisto;
  else if (probabilita > 50 && probabilita <= 85)
    (*Pc)->imprevisto = crollo;
  else if (probabilita > 85 && probabilita <= 100)
    (*Pc)->imprevisto = baco;
}

static void turnoArvais () {
  int scelta;
  int ppu = 0;   //probabilità progressiva uscita
  //stato giocatore Arvais
  printf("Turno Arvais\n");
  printf("Quantità serbatoio energia %d/4\n", arvais->serbatoio_energia);
  printf("Quantità serbatoio raccolta %d/10\n", arvais->serbatoio_raccolta);

  //Menù decisionale arvais
  printf("Cosa vuoi fare?\n");
  printf("Premere 1 per avanzare\n");
  printf("Premere 2 per abbattere; Consuma 1 punto energia\n");
  printf("Premere 3 per aggirare\n");
  printf("Premere 4 per uscire dalla caverna\n");
  scanf("%d", &scelta);

  switch (scelta) {
    case 1:
        avanza (&Pca, &arvais);
    break;
    case 2:
        abbatti (&Pca, &arvais);
    break;
    case 3:
        //aggira
    break;
    case 4:
        //esci
    break;
    default:
    printf("Inserire un comando valido\n");
  }
  /*prob ();
  if (prob () <= ppu)
    ppu = ppu + 5;
  else*/

}

static void turnoHartornen () {
  int scelta;
  printf("Turno Hartornen\n");
  printf("Quantità serbatoio energia %d/4\n", hartornen->serbatoio_energia);
  printf("Quantità serbatoio raccolta %d/10\n", hartornen->serbatoio_raccolta);


  printf("Cosa vuoi fare?\n");
  printf("Premere 1 per avanzare\n");
  printf("Premere 2 per abbattere; Consuma 1 punto energia\n");
  printf("Premere 3 per aggirare\n");
  printf("Premere 4 per uscire dalla caverna\n");
  scanf("%d", &scelta);

  switch (scelta) {
    case 1:
        avanza (&Pch, &hartornen);
    break;
    case 2:
        abbatti (&Pch, &hartornen);
    break;
    case 3:
        //aggira
    break;
    case 4:
        //esci
    break;
    default:
    printf("Inserire un comando valido\n");
  }
}

static void avanza (struct Caverna **Pc, struct Scavatrice **fam) {
  (*fam)->posizione = *Pc;
//puntatore non nullo = direzione
  if ((*Pc)->avanti != NULL) {
    printf("Sei andato avanti\n");
    (*fam)->posizione = (*Pc)->avanti;
  }
  else if ((*Pc)->destra != NULL) {
    printf("Hai svoltato a destra\n");
    (*fam)->posizione = (*Pc)->destra;
  }
  else {
    printf("Hai svoltato a sinistra\n");
    (*fam)->posizione = (*Pc)->sinistra;
  }

  //tipo imprevisto
  if ((*Pc)->imprevisto == crollo) {
    printf("C'è stato un crollo: consumi 1 punto energia per liberarti dalle macerie\n");
    (*fam)->serbatoio_energia--;
  }
  if ((*Pc)->imprevisto == baco) {
    printf("Hai incontrato un feroce baco: sei salvo, ma perdi tutti i punti energia e raccolta accumulati\n");
    (*fam)->serbatoio_energia = 0;
    (*fam)->serbatoio_raccolta = 0;
  }
  // tipo caverna
  if ((*Pc)->tipo_caverna == speciale) {
    printf("La caverna irradia melassa: guadagni 1 punto energia\n");
    (*fam)->serbatoio_energia++;
  }
  if ((*Pc)->tipo_caverna == accidentata) {
    printf("La caverna è accidentata: perdi 1 punto energia\n");
    (*fam)->serbatoio_energia--;
  }
  //else
    //uscita

    //quantità melassa

  if ((*Pc)->melassa == poca) {
    int scelta;
    printf("La caverna contiene poca melassa: guadagni 1 unita di melassa\n");
    printf("In quale serbatoio vuoi mettere la melassa?\n");
    printf("Premere 1 per metterla nel serbatoio di energia\n");
    printf("Premere 2 per metterla nel serbatoio di raccolta\n");
    scanf("%d", &scelta);
    switch (scelta) {
      case 1:
        (*fam)->serbatoio_energia++;
        break;
      case 2:
        (*fam)->serbatoio_raccolta++;
        break;
      default:
        printf("Comando non valido\n");
    }
  }
  if ((*Pc)->melassa == molta) {
    int scelta2;
    printf("La caverna contiene molta melassa: guadagni 3 unita di melassa\n");
    printf("In quale serbatoio vuoi mettere la melassa?\n");
    printf("Premere 1 per metterla nel serbatoio di energia\n");
    printf("Premere 2 per metterla nel serbatoio di raccolta\n");
    scanf("%d", &scelta2);

    switch (scelta2) {
      case 1:
        (*fam)->serbatoio_energia += 3;
        break;
      case 2:
        (*fam)->serbatoio_raccolta += 3;
        break;
      default:
        printf("Comando non valido\n");
    }
  }
}

static void abbatti (struct Caverna **Pc, struct Scavatrice **fam) {
  int scelta;
  //Dichiarazione nuova caverna
struct Caverna *abbatti = (struct Caverna*)malloc(sizeof(struct Caverna));
abbatti->avanti = NULL;
abbatti->destra = NULL;
abbatti->sinistra = NULL;

printf("Dove vuoi abbattere?\n");
printf("Premere 1 per abbattere avanti\n");
printf("Premere 2 per abbattere a destra\n");
printf("Premere 3 per abbattere a sinistra\n");

switch (scelta) {
  case 1:
    if ((*Pc)->avanti != NULL)
        printf("Spiacente, esiste già una caverna in quella direzione");
    else {
        abbatti->avanti = *Pc;
        abbatti->destra = NULL;
        abbatti->sinistra = NULL;
        *Pc = abbatti;
    }
  break;
  case 2:
    if ((*Pc)->destra != NULL)
        printf("Spiacente, esiste già una caverna in quella direzione");
    else {
        abbatti->avanti = NULL;
        abbatti->destra = *Pc;
        abbatti->sinistra = NULL;
        *Pc = abbatti;
    }
  break;
  case 3:
   if ((*Pc)->sinistra != NULL)
        printf("Spiacente, esiste già una caverna in quella direzione");
   else {
        abbatti->avanti = NULL;
        abbatti->destra = NULL;
        abbatti->sinistra = *Pc;
        *Pc = abbatti;
   }
   break;
   default:
        printf("Comando non valido\n");
  }
}
