printf("RIGA 1768. pPrimo_Hartornen_caverna: %p\n", pPrimo_Hartornen_caverna);
printf("RIGA 1768. pPrimo_Hartornen_caverna -> sinistra: %p\n", pPrimo_Hartornen_caverna -> sinistra);
printf("RIGA 1768. pPrimo_Hartornen_caverna -> avanti: %p\n"  , pPrimo_Hartornen_caverna -> avanti);
printf("RIGA 1768. pPrimo_Hartornen_caverna -> destra: %p\n"  , pPrimo_Hartornen_caverna -> destra);
printf("RIGA 1768. pUltimo_Hartornen_caverna: %p\n", pUltimo_Hartornen_caverna);

numero_caverne_Hartornen = count (pPrimo_Hartornen_caverna);
printf("RIGA 1768. numero_caverne_Hartornen: %hd\n", numero_caverne_Hartornen);

for (int a = 0; a < numero_caverne_Hartornen; a++)
  {
    if(pPrimo_Hartornen_caverna == NULL) //Non sono presenti nodi
      break;
    else
      {
        //SE E' PRESENTE ALMENO UNA CAVERNA
        struct Caverna *temp;

        if (pPrimo_Hartornen_caverna -> sinistra != NULL)
            temp = pPrimo_Hartornen_caverna -> sinistra;
        else if (pPrimo_Hartornen_caverna -> avanti != NULL)
            temp = pPrimo_Hartornen_caverna -> avanti;
        else if (pPrimo_Hartornen_caverna -> destra != NULL)
            temp = pPrimo_Hartornen_caverna -> destra;
        else temp = NULL;

        free (pPrimo_Hartornen_caverna); //Elimino l'ultima caverna creata
        pPrimo_Hartornen_caverna = temp; //Aggiorno il puntatore di testa alla caverna successiva

        printf("RIGA 1770. pPrimo_Hartornen_caverna: %p\n", pPrimo_Hartornen_caverna);
        //printf("RIGA 1770. pPrimo_Hartornen_caverna -> sinistra: %p\n", pPrimo_Hartornen_caverna -> sinistra);
        //printf("RIGA 1770. pPrimo_Hartornen_caverna -> avanti: %p\n"  , pPrimo_Hartornen_caverna -> avanti);
        //printf("RIGA 1770. pPrimo_Hartornen_caverna -> destra: %p\n"  , pPrimo_Hartornen_caverna -> destra);
        printf("RIGA 1770 PRIMA FREE. numero_caverne_Hartornen: %hd\n", numero_caverne_Hartornen);
      }
  }
pPrimo_Hartornen_caverna = NULL;

if(pUltimo_Hartornen_caverna != NULL)
  free(pUltimo_Hartornen_caverna);
pUltimo_Hartornen_caverna = NULL;

printf("RIGA 1766 DOPO FREE. pUltimo_Hartornen_caverna: %p\n", pUltimo_Hartornen_caverna);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void elimina_tutte_caverne (struct Caverna *pPrimo_Elimina, struct Caverna *pUltimo_Elimina, int i)
  {
    short int numero_caverne_da_eliminare = 0;

    printf("RIGA . pPrimo_Elimina: %p\n", pPrimo_Elimina);
    printf("RIGA . pPrimo_Elimina -> sinistra: %p\n", pPrimo_Elimina -> sinistra);
    printf("RIGA . pPrimo_Elimina -> avanti: %p\n"  , pPrimo_Elimina -> avanti);
    printf("RIGA . pPrimo_Elimina -> destra: %p\n"  , pPrimo_Elimina -> destra);
    printf("RIGA . pUltimo_Elimina: %p\n", pUltimo_Elimina);

    numero_caverne_da_eliminare = count (pPrimo_Elimina);

    printf("RIGA . numero_caverne_Hartornen: %hd\n", numero_caverne_Hartornen);

    for (int a = 0; a < numero_caverne_da_eliminare; a++)
      {
        if(pPrimo_Elimina == NULL) //Non sono presenti nodi
          break;
        else
          {
            //SE E' PRESENTE ALMENO UNA CAVERNA
            struct Caverna *temp;

            if (pPrimo_Elimina -> sinistra != NULL)
                temp = pPrimo_Elimina -> sinistra;
            else if (pPrimo_Elimina -> avanti != NULL)
                temp = pPrimo_Elimina -> avanti;
            else if (pPrimo_Elimina -> destra != NULL)
                temp = pPrimo_Elimina -> destra;
            else temp = NULL;

            free (pPrimo_Elimina); //Elimino l'ultima caverna creata
            pPrimo_Elimina = temp; //Aggiorno il puntatore di testa alla caverna successiva

            printf("RIGA . pPrimo_Elimina: %p\n", pPrimo_Elimina);
            //printf("RIGA . pPrimo_Elimina -> sinistra: %p\n", pPrimo_Elimina -> sinistra);
            //printf("RIGA . pPrimo_Elimina -> avanti: %p\n"  , pPrimo_Elimina -> avanti);
            //printf("RIGA . pPrimo_Elimina -> destra: %p\n"  , pPrimo_Elimina -> destra);
            printf("RIGA  PRIMA FREE. numero_caverne_da_eliminare: %hd\n", numero_caverne_da_eliminare);
          }
      }
    pPrimo_Elimina = NULL;

    if(pUltimo_Elimina != NULL)
      free(pUltimo_Elimina);
    pUltimo_Elimina = NULL;

    printf("RIGA  DOPO FREE. pUltimo_Elimina: %p\n", pUltimo_Elimina);

    if (i%2 == 0)
      {
        pPrimo_Elimina = pPrimo_Arvais_caverna;
        pUltimo_Elimina = pUltimo_Arvais_caverna;
      }
    else
      {
        pPrimo_Elimina = pPrimo_Hartornen_caverna;
        pUltimo_Elimina = pUltimo_Hartornen_caverna;
      }
  }
