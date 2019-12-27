#include "gamelib.h"

static struct caverna *Pca = NULL;        //primo cunicolo arvais
static struct caverna *Pch = NULL;    //primo cunicolo hartornen;
static struct Scavatrice *arvais;
static struct Scavatrice *hartornen;
void crea_cunicoli ();
static void ins_caverna (struct caverna **Pc);
static void stampa_lista (struct caverna **Pc);
static void canc_caverna (struct caverna **Pc);
static int prob ();    //probabilità
static void stato_caverna (struct caverna **Pc);   //tipo caverna
static void fmelassa (struct caverna **Pc);  // randomizzazione quantità melassa
static void fimprevisto (struct caverna **Pc);  // randomizzazione imprevisto
static int probabilita;

static void ins_caverna (struct caverna **Pc) {
  int scelta;
//Dichiarazione nuova caverna
struct caverna *nc =(struct caverna*) malloc(sizeof(struct caverna));  //nuova caverna
  printf("Inserire un valore di a\n");
  scanf("%d", &(nc-> a));
  nc-> avanti = NULL;
  nc-> destra = NULL;
  nc-> sinistra = NULL;

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
      }
      else {
  switch (scelta) {
    //Caverna avanti
    case 1:
      nc-> avanti = *Pc;
      nc-> destra = NULL;
      nc-> sinistra = NULL;
      *Pc = nc;
      stato_caverna (&Pca);
      fmelassa (&Pca);
      fimprevisto (&Pca);
    break;
    //caverna a destra
    case 2:
      nc-> avanti = NULL;
      nc-> destra = *Pc;
      nc-> sinistra = NULL;
      *Pc = nc;
      stato_caverna (&Pca);
      fmelassa (&Pca);
      fimprevisto (&Pca);
    break;
    //caverna a sinistra
    case 3:
      nc-> avanti = NULL;
      nc-> destra = NULL;
      nc-> sinistra = *Pc;
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
  int scelta;
  printf("Creazione caverne famiglia Arvais\n");
  while (scelta != 4) {
    //menù scelta iniziale
  printf("Effettuare una scelta\n");
  printf("Premere 1 per creare cunicolo\n");
  printf("Premere 2 per cancellare un cunicolo precedente\n");
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
      return;
    break;
    default:
      printf("Comando non valido\n");
       }
  }
  printf("Creazione caverne famiglia Hartornen\n");
  while (scelta != 4) {
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

static void stampa_lista (struct caverna **Pc) {
  if(*Pc == NULL) {
      printf("Non ci sono caverne\n"); }
  else {
    struct caverna* sonda = *Pc;

    do {
      if (sonda->tipo_caverna == 0)
        printf("Valore: %d, Tipo: Normale\n", sonda-> a);
      else if (sonda->tipo_caverna == 1)
        printf("Valore: %d, Tipo: Speciale\n", sonda-> a);
      else
        printf("Valore: %d, Tipo: Accidentata\n", sonda-> a);
          if (sonda-> avanti != NULL)
            sonda = sonda -> avanti;
          else if (sonda-> destra != NULL)
            sonda = sonda -> destra;
          else
            sonda = sonda -> sinistra;
        //sonda = sonda -> destra;
        //sonda = sonda -> sinistra;
    }while(sonda != NULL);
  }
      return;
}

static void canc_caverna (struct caverna **Pc) {
  *Pc = Pca;
  if (*Pc == NULL)
    printf("Non ci sono caverne\n");
  else if ((*Pc)-> avanti != NULL) {
      struct caverna *temp = (*Pc)-> avanti;
      free(*Pc);
      *Pc = temp;
    }
  else if ((*Pc)-> destra != NULL) {
      struct caverna *temp = (*Pc)-> destra;
      free(*Pc);
      *Pc = temp;
  }
  else {
      struct caverna *temp = (*Pc)-> sinistra;
      free(*Pc);
      *Pc = temp;
  }
    system("clear");
    return;
  }

static void stato_caverna (struct caverna **Pc) {
  int scelta;
  //Menù stato caverna
  printf("Di che tipo deve essere la caverna?\n");
  printf("Premere 1 per creare una caverna normale\n");
  printf("Premere 2 per creare una caverna speciale\n");
  printf("Premere 3 per creare una caverna accidentata\n");
  scanf("%d", &scelta);

  switch (scelta) {
    case 1:
      (*Pc)-> tipo_caverna = normale;
      break;
    case 2:
      (*Pc)-> tipo_caverna = speciale;
      break;
    case 3:
      (*Pc)-> tipo_caverna = accidentata;
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

static void fmelassa (struct caverna **Pc) {
  *Pc = Pca;
  probabilita = 0;
  prob ();
  if (probabilita <= 50)
    (*Pc)->melassa = nessuna;
  else if (probabilita > 50 && probabilita <= 80)
    (*Pc)->melassa = poca;
  else if (probabilita > 80 && probabilita <= 100)
    (*Pc)->melassa = molta;
}

static void fimprevisto (struct caverna **Pc) {
  *Pc = Pca;
  probabilita = 0;
  prob ();
  if (probabilita <= 50)
    (*Pc)-> imprevisto = nessun_imprevisto;
  else if (probabilita > 50 && probabilita <= 85)
    (*Pc)-> imprevisto = crollo;
  else if (probabilita > 85 && probabilita <= 100)
    (*Pc)-> imprevisto = baco;
}
