#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void) {

  int a = 0;
  printf ("Quanti triangoli vuoi valutare?\n");
  scanf ("%d",&a);

  for (int b = 0; b < a; b++ )
    {
    double lato1, lato2, lato3, temp1=0, temp2=0, temp3=0,
    sum1_2=0, sum1_3=0, sum2_3=0, pit1 = 0, pit2 = 0, pit3 = 0;

    //VALORI LATI
    printf ("Inserire lato A:\n");
    scanf ("%lf",&lato1);
    printf ("Inserire lato B:\n");
    scanf ("%lf",&lato2);
    printf ("Inserire lato C:\n");
    scanf ("%lf",&lato3);

  /*
  * SE I LATI SONO NEGATIVI LI PORTO A POSITIVI COSI' CHE,
  * SE SI E' SCRITTO PER SBAGLIO UN LATO NEGATIVO, LO
  * CORREGGO AUTOMATICAMENTE.
  *
  * SE NON ANDASSE BENE QUESTO MODO DI PENSARE, BASTEREBBE
  * SCRIVERE:
  *  if (lato... < 0)
  *   {
  *     printf ("I lati devono essere positivi\n");
  *     continue;
  *   }
  */

    if (lato1 < 0)
      {
        lato1 = -lato1;
      }

    if (lato2 < 0)
      {
        lato2 = -lato2;
      }

    if (lato3<0)
      {
        lato3 = -lato3;
      }

  //SE UN LATO E' MAGGIORE DELLA SOMMA DEGLI ALTRI DUE
  //ALLORA NON E' UN TRIANGOLO
    if (lato1 > (lato2+lato3))
      {
        printf ("I lati non formano un triangolo\n");
        continue;
      }

    if (lato2 > (lato1+lato3))
      {
        printf ("I lati non formano un triangolo\n");
        continue;
      }

    if (lato3 > (lato1+lato2))
      {
        printf ("I lati non formano un triangolo\n");
        continue;
      }

  //SE UN LATO E' MINORE DELLA DIFFERENZA DEGLI ALTRI DUE
  //ALLORA NON E' UN TRIANGOLO
    if (lato1 < (lato2-lato3))   //----> potrebbe essere necessario il modulo
      {                          //      o fare lato3-lato2
        printf ("I lati non formano un triangolo\n");
        continue;
      }

    if (lato2 < (lato1-lato3))
      {
        printf ("I lati non formano un triangolo\n");
        continue;
      }

    if (lato3 < (lato1-lato2))
      {
        printf ("I lati non formano un triangolo\n");
        continue;
      }

  //GUARDO SE E' EQUILATERO
    if (lato1 == lato2)
      {
        if (lato1 == lato3)
        {
          printf ("Il triangolo è equilatero\n\n");
          continue;   // NON PU0' ESSERE  ALTRI TIPI DI TRIANGOLI
        }
      }

  //GUARDO SE E' ISOSCELE
    if (lato1 == lato2)
      {
        if ( lato1 != lato3)
        printf ("Il triangolo è isoscele\n\n");
      }

    if (lato1 == lato3)
      {
        if (lato1 != lato2)
        printf ("Il triangolo è isoscele\n\n");
      }


    if (lato3 == lato2)
      {
        if (lato3 != lato1)
        printf ("Il triangolo è isoscele\n\n");
      }

  //GUARDO SE E' SCALENO
    if (lato1 != lato2)
      {
        if (lato1 != lato3 && lato2 != lato3)
        printf ("Il triangolo è scaleno\n\n");
      }

  //GUARDO SE E' RETTANGOLO
  /****************************************************************
  *
  * SFRUTTO IL TEOREMA DI PITAGORA CHE DICE:
  * L'IPOTENUSA = radice (C^2 + c^2)
  * CATETO MINORE (c) = radice (I^2 - C^2)
  * CATETO MAGGIORE (C) = radice (I^2 - c^2)
  *
  * L'IPOTENUSA E' SEMPRE IL LATO PIU' LUNGO
  * IL CATETO MAGGIORE E' SEMPRE IL SECONDO LATO PIU' LUNGO
  *
  ****************************************************************/
  //CERCO L'IPOTENUSA (temp1), CATETO MAGGIORE (temp2) E CATETO MINORE (temp3)
    if (lato1 > lato2)
      {
        temp1 = lato1;  // Ipotenusa
        temp2 = lato2;  // Cateto maggiore
      }

    else
      {
        temp1 = lato2;  // Ipotenusa
        temp2 = lato1;  // Cateto maggiore
      }

    if (temp1 < lato3)
      {
        temp1 = lato3;  // Ipotenusa finale
      }

    if (temp2 < lato3)
      {
        temp3 = temp2;  // Cateto minore
        temp2 = lato2;  // Cateto maggiore finale
      }

//VERIFICO PITAGORA
//CREO I QUADRATI DEI LATI
      temp1 = temp1 * temp1;
      temp2 = temp2 * temp2;
      temp3 = temp3 * temp3;

//MI TROVO IL VALORE SOTTORADICE DEI LATI
      sum1_2 = temp1 - temp2;
      sum1_3 = temp1 - temp3;
      sum2_3 = temp2 + temp3;

//FACCIO LA RADICE DEI LATI
      pit1 = sqrt(sum2_3);
      pit2 = sqrt(sum1_3);
      pit3 = sqrt(sum1_2);

//RIPORTO I LATI AI VALORI ORIGINALI PER CONFRONTARLI
      temp1 = sqrt(temp1);
      temp2 = sqrt(temp2);
      temp3 = sqrt(temp3);

//VERIFICO CHE EFFETTIVAMENTE I LATI COMBACINO
      if (temp1 == pit1)
        {
          printf ("Il triangolo è rettangolo\n\n");
          continue;
        }

      if (temp2 == pit2)
        {
          printf ("Il triangolo è rettangolo\n\n");
          continue;
        }

      if (temp3 == pit3)
        {
          printf ("Il triangolo è rettangolo\n\n");
          continue;
        }
  }
  return 0;
}
