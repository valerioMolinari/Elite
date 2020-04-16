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

struct Eliminacode *pFirst;

int main ()
  {
    do
      {
        printf("RIGA 17. CELLA pFirst: %p\n", pFirst);
        int numero_clienti;
        int scelta;

        scelta = 0;

        printf("\nVuoi inserire o eliminare i clienti? (1 o 2)");
        scanf("%d", &scelta);

        if (scelta == 1)
          {
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
                    printf("RIGA 33. CELLA pFirst: %p\n", pFirst);
                  }
                else
                  {
                    // Else, there is already at least
                    printf("RIGA 40. CELLA pFirst: %p\n", pFirst);
                    pNew -> pNext = pFirst; // the first node becomes the second one
                    printf("RIGA 42. CELLA pNew -> pNext: %p\n", pNew -> pNext);
                    pFirst= pNew; // The first node is the newly created one
                    printf("RIGA 44. CELLA pFirst: %p\n", pFirst);
                  }
                printf("\nFOR -> Numero cliente: [%d] , numero personale cliente: %d\n",i+1 , pNew -> numero);
              }
          }
        else
          {
            printf("RIGA 60. CELLA pFirst: %p\n", pFirst);
            int numero_clienti;
            printf("\nInserisci il numero totale dei clienti da eliminare: (minore di quello inseriti)");
            scanf("%d", &numero_clienti);

            for (int i = 0; i < numero_clienti; i++)
              {
                if(pFirst == NULL) // No node in the list
                  {
                    printf("No node in the list!\n");
                  }
                else
                  {
                    struct Eliminacode *temp = pFirst -> pNext;
                    printf("RIGA 74. CELLA N°[%d] pFirst -> pNext: %p\n",i, pFirst -> pNext);
                    // Else, there is at least a node in the list
                    // Remember the pointer to the second node, which will become
                    // the first one
                    // Memory is deallocated (node canceled from memory)
                    free (pFirst);
                    // The first node becomes the former second node
                    pFirst = temp;
                    printf("RIGA 82. CELLA N°[%d] pFirst -> pNext: %p\n",i, pFirst -> pNext);
                  }
              }
          }
      } while(1);

  }
