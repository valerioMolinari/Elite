#include "gamelib.h"

int main(void){
    printf("Benvenuto in Dune! \n\n Inserire: \n C - per creare cunicoli; \n G - per giocare; \n E - per terminare il gioco.\n");
    time_t t;
    srand((unsigned) time(&t));
    int start=0;
    int scelta=0;
    int creata=0;
    while(!scelta){
        start=getchar();
        if (start == 'C' || start=='c')
        {
            creata=1;
            printf("Mappa creata.\n");
            continue;
        }
        if (start=='G' || start =='g')
        {
            if (creata==0){
                printf("Prima di giocare creare la mappa!\n");
                continue;
            }
            else{
                scelta=1;
                break;
            }
        }
        if (start=='E' || start=='e')
        {
            scelta=1;
            break;
        }
        if (!scelta)
        {
            if(creata==1)
            {
                printf("Inserire G per giocare o E per uscire. Se si vuole ricreare la mappa inserire C.\n");
            }
            else{
                printf("Inserire uno tra i caratteri scelta!\n\nInserire: \n C - per creare cunicoli; \n G - per giocare; \n E - per terminare il gioco.\n");
            }
        }
        fflush(stdin);
    }
    printf("yes");
    return 0;
}
