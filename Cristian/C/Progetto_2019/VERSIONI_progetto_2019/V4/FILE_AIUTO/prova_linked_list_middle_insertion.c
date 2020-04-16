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
struct Eliminacode *pFirst_first;
struct Eliminacode *pFirst_first_first;
struct Eliminacode *pLast;
struct Eliminacode *pScan;
struct Altro *pFirst_altro;
struct Altro *pLast_altro;
struct Altro *pAltro;
short int int_serbatoio_energia = 0;
short int int_serbatoio_raccolta = 0;
short int inserisci_cliente = 0;

int main ()
  {
    printf("RIGA 17. CELLA pFirst: %p\n", pFirst);
    int numero_clienti;
    printf("\nInserisci il numero totale dei clienti: ");
    scanf("%d", &numero_clienti);

    for (int i = 0; i < numero_clienti; i++)
      {
        // Creation of a new node in the heap
        struct Eliminacode *pNew = (struct Eliminacode*) malloc(sizeof(struct Eliminacode));
        printf("RIGA 25. CELLA N°[%d] pNew: %p\n",i, pNew);
        printf("\nNumero personale cliente: ");
        scanf("%d", &(pNew -> numero));
        pNew -> pNext = NULL;
        printf("RIGA 30. CELLA N°[%d] pNew -> pNext: %p\n",i, pNew -> pNext);
        if (pFirst == NULL) // No node in the list the list
          {
            pFirst = pNew; // The first node is the newly created one
            pLast = pNew;  // The last node is the newly create one
            pFirst_first = pNew;
            pFirst_first_first = pNew;
            printf("RIGA 33. CELLA pFirst: %p\n", pFirst);
            printf("RIGA 34. CELLA pLast: %p\n" , pLast);
          }
        else
          {
            // Else, there is already at least
            printf("RIGA 40. CELLA pLast: %p\n", pLast);
            pLast -> pNext = pNew; // the last node becomes the second one
            printf("RIGA 42. CELLA pLast -> pNext: %p\n", pLast -> pNext);
            pLast= pNew; // The last node is the newly created one
            printf("RIGA 44. CELLA pLast: %p\n", pLast);
          }
        printf("\nFOR -> Numero cliente: [%d] , numero personale cliente: %d\n",i+1 , pNew -> numero);
      }

    pScan = pFirst;
    for (int i = 0; i < numero_clienti; i++)
      {
        int_serbatoio_energia++;
        int_serbatoio_raccolta++;

        if (pScan == NULL) // No node in the list the list
          {
            printf("RIGA 65. Sei arrivato in fondo");
            printf("RIGA 66. CELLA pScan: %p\n", pScan);
          }
        else
          {
            // Else, there is already at least
            struct Altro *pNew_altro = (struct Altro*) malloc(sizeof(struct Altro));
            pNew_altro -> pEliminacode = NULL;
            pNew_altro -> serbatoio_energia = 0;
            pNew_altro -> serbatoio_raccolta = 0;
            printf("RIGA 79. CELLA pScan: %p\n", pScan);

            if (pFirst_altro == NULL) // No node in the list the list
              {
                pFirst_altro = pNew_altro; // The first node is the newly created one
                pLast_altro = pNew_altro;  // The last node is the newly create one
                printf("RIGA 85. CELLA pFirst_altro: %p\n", pFirst_altro);
                printf("RIGA 86. CELLA pLast_altro: %p\n" , pLast_altro);
              }
            else
              {
                // Else, there is already at least
                printf("RIGA 91. CELLA pLast_altro: %p\n", pLast_altro);
                pLast_altro -> pEliminacode = pNew_altro; // the last node becomes the second one
                printf("RIGA 93. CELLA pLast -> pNext: %p\n", pLast -> pNext);
                pLast_altro -> serbatoio_energia = int_serbatoio_energia;
                pLast_altro -> serbatoio_raccolta = int_serbatoio_raccolta;
                pLast_altro = pNew_altro; // The last node is the newly created one
                printf("RIGA 99. CELLA pLast_altro: %p\n", pLast_altro);
              }

            pScan = pFirst -> pNext; // the last node becomes the second one
            pFirst = pFirst -> pNext;
            printf("RIGA 104. CELLA pScan: %p\n", pScan);
            printf("RIGA 105. CELLA int_serbatoio_energia: %hd\n", int_serbatoio_energia);
            printf("RIGA 106. CELLA int_serbatoio_raccolta: %hd\n", int_serbatoio_raccolta);
            printf("RIGA 107. CELLA pNew_altro -> serbatoio_energia: %hd\n", pNew_altro -> serbatoio_energia);
            printf("RIGA 108. CELLA pNew_altro -> serbatoio_raccolta: %hd\n", pNew_altro -> serbatoio_raccolta);
          }
      }
    printf ("Dopo quante posizioni vuoi inserire un nuovo cliente?\n");
    scanf("%hd",&inserisci_cliente);

    pScan = pFirst_first;
    for (int i = 0; i < inserisci_cliente-1; i++)
      {
        if (pScan == NULL) // No node in the list the list
          {
            printf("RIGA 123. Sei arrivato in fondo");
            printf("RIGA 124. CELLA pScan: %p\n", pScan);
          }
        else
          {
            pScan = pFirst_first -> pNext; // the last node becomes the second one
            pFirst_first = pFirst_first -> pNext;
          }
      }
    struct Eliminacode *pNew_2 = (struct Eliminacode*) malloc(sizeof(struct Eliminacode));
    struct Eliminacode *temp = (struct Eliminacode*) malloc(sizeof(struct Eliminacode));

    temp = pScan-> pNext;
    printf("RIGA 136. CELLA temp: %p\n", temp);
    pScan-> pNext = pNew_2;
    printf("\nNumero personale cliente: ");
    scanf("%d", &(pNew_2 -> numero));
    pNew_2 -> pNext = temp;

    pScan = pFirst_first_first;
    for (int i = 0; i < numero_clienti+1; i++)
      {
        if (pScan == NULL) // No node in the list the list
          {
            printf("RIGA 149. Sei arrivato in fondo");
            printf("RIGA 150. CELLA pScan: %p\n", pScan);
          }
        else
          {
            printf("RIGA 147. CELLA N°[%d] numero personale cliente: %d\n",i, pScan-> numero);
            pScan = pFirst_first_first -> pNext; // the last node becomes the second one
            pFirst_first_first = pFirst_first_first -> pNext;
          }
      }
  }
