#include "gamelib.h"

static void ins_Caverna(char f);

static struct Caverna *primo_cunicolo_Arvais;
static struct Caverna *primo_cunicolo_Hartornen;


void creaCunicoli(void) {
    printf("CREA MAPPA \n\n Inserire:\nI - inserisci caverna;\nD - cancella caverna;\nS - stampa cunicolo;\nC - chiudi cunicoli.");
    int input=0;
    int scelta=0;
    while(!scelta){
        input=getchar();
        if (input == 'I' || input=='i')
        {
            scelta=1;
            int team=0;
            team=getchar();
            ins_Caverna(team);
            break;
        }
        if (input=='D' || input=='d')
        {
            scelta=1;
            break;
        }
        if (input=='S' || input=='s')
        {
            scelta=1;
            break;
        }
        if (input=='C' || input=='c')
        {
            scelta=1;
            break;
        }
        if (!scelta)
        {
            printf("Inserire uno tra i caratteri scelta!\n");
        }
        fflush(stdin);
    }
    printf("yes");
}

static void ins_Caverna(char f) {
    if (f == 'h' || f=='H')
    {
        if (primo_cunicolo_Hartornen == NULL)
        {
            primo_cunicolo_Hartornen=(Caverna*)malloc(sizeof(Caverna));
            primo_cunicolo_Hartornen->quantita_melassa=poca;
            primo_cunicolo_Hartornen->imprevisto=nessuno;
        }
        else
        {
            Caverna *pNew = (Caverna*) malloc(sizeof(Caverna));
            int perc_melassa = rand() % 100;
            int perc_imp = rand() & 100;
            if (perc_melassa<=50)
            {
                pNew->quantita_melassa=nessuna;
            }
            else if (perc_melassa>50 && perc_melassa<=80)
            {
                pNew->quantita_melassa=poca;

            }
            else
            {
                pNew->quantita_melassa=molta;
            }
            if(perc_imp <= 50)
            {
                pNew->imprevisto=nessuno;
            }
            else if (perc_imp >50 && perc_imp <=85)
            {
                pNew->imprevisto=crollo;
            }
            else
            {
                pNew->imprevisto=baco;
            }
            int direzione=getchar();

        }
    }
    if (f=='a' || f=='A')
    {
        primo_cunicolo_Arvais=(Caverna*)malloc(sizeof(Caverna));
    }
}
