#include <stdio.h>

int main ()
{
  /*
     - Fisso il numero da valutare
     - Lo divido per se stesso meno 1
     - Se il resto di questa divisione è 0 allora il numero da valutare
       non è un numero primo.
     - Se il resto è diverso da 0 per ogni numero inferiore a quello da
       valutare, ma maggiore di 1, il numero è primo.
  */

  int a=0;
  int c=1;

  printf ("Inserisci il numero da valutare: \n");
  scanf ("%d",&a);

  if (a == 2)
    printf ("%d e' un numero primo\n",a);
  else
  {

    const int b = a;  //Fisso il numero da valutare
    a = a-1;          //Creo il primo numero con cui vedere se è divisibile
    c = b%a;          //Guardo se la divisione ha o NON ha resto

    while (a>1 && c)  //(a>1 && (b%a != 0))
                      //Se a>1 e resto diverso 0
      {
        c = b%a;      //Aggiorno il resto
        a = a-1;      //Provo con un numero inferiore
      }

    if (a<=1 && (c!=0)) //Se ho finito i tentativi e resto diverso 0
      {
        printf ("%d e' un numero primo\n",b);
      }

    if (c == 0)       //Se il resto è 0
      {
        printf ("%d non e' un numero primo\n",b);
      }
  }
}
