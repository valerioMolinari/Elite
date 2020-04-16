#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

struct Eliminacode
  {
     int numero;
     struct Eliminacode *pNext;
  };

struct Altro
  {
     struct Eliminacode *pEliminacode;
     short int serbatoio_energia;
     short int serbatoio_raccolta;
  };

struct Eliminacode *pFirst;
struct Eliminacode *pLast;
struct Eliminacode *pScan;

int main ()
  {
    struct Altro *pHartornen = (struct Altro*) malloc(sizeof(struct Altro));
    //struct Altro *pArvais = (struct Altro*) malloc(sizeof(struct Altro));
    printf("RIGA 17. CELLA pHartornen: %p\n", pHartornen);
    //printf("RIGA 17. CELLA pArvais: %p\n", pArvais);
    printf("RIGA 17. CELLA pFirst: %p\n", pFirst);
    pHartornen -> pEliminacode = NULL;
    pHartornen -> serbatoio_energia = 0;
    pHartornen -> serbatoio_raccolta = 0;

    //pArvais -> pEliminacode = NULL;
    //pArvais -> int_serbatoio_energia = 0;
    //pArvais -> int_serbatoio_raccolta = 0;

    int numero_clienti;
    printf("\nInserisci il numero totale dei clienti: ");
    scanf("%d", &numero_clienti);

    do {
    for (int i = 0; i < numero_clienti; i++)
      {
        struct Eliminacode *pNew = (struct Eliminacode*) malloc(sizeof(struct Eliminacode));
        printf("\nNumero personale cliente: ");
        scanf("%d", &(pNew -> numero));
        pNew -> pNext = NULL;
        if (pFirst == NULL) // No node in the list the list
          {
            pFirst = pNew; // The first node is the newly created one
            pLast = pNew;  // The last node is the newly create one
            pHartornen -> pEliminacode = pNew;
          }
        else
          {
            pLast -> pNext = pNew; // the last node becomes the second one
            pLast= pNew; // The last node is the newly created one
            printf("PRIMA AGGIORNAMENTO pHartornen -> serbatoio_energia: %d\n", pHartornen -> serbatoio_energia);
            printf("PRIMA AGGIORNAMENTO pHartornen -> pEliminacode: %p\n", pHartornen -> pEliminacode);
            pHartornen -> pEliminacode = pNew;
            printf("DOPO AGGIORNAMENTO PUNTATORE pHartornen -> pEliminacode: %p\n", pHartornen -> pEliminacode);
            pHartornen -> serbatoio_energia += 2;
            printf("DOPO AGGIORNAMENTO SERBATOIO pHartornen -> serbatoio_energia: %d\n", pHartornen -> serbatoio_energia);
          }
      }

      printf("VUOI AGGIUNGERE PIU' CLIENTI? SE SI QUANTI?\n");
      scanf("%d", &numero_clienti);
    } while (numero_clienti != 0);
    struct Eliminacode *pScan_1 = pFirst;
    int a = 0;
    while (pScan_1 != NULL)
      {
        printf("\nNumero cliente: [%d] , numero personale cliente: %d\n",a+1 , pScan_1 -> numero);
        pScan_1 = pScan_1 -> pNext;
        a++;
      }
  }
