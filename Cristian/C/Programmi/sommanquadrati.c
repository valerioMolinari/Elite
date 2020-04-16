#include <stdio.h>

int main ()
{
  int tot_numeri = 0;
  double numero_partenza = 0.0;
  double somma = 0.0;

  printf ("Quanti numeri vuoi sommare?\n");
  scanf ("%d", &tot_numeri);
  printf ("Da quale numero vuoi partire?\n");
  scanf ("%lf", &numero_partenza);

  for (numero_partenza; tot_numeri > 0; tot_numeri-- )
    {
      somma = somma + (numero_partenza * numero_partenza);
      numero_partenza++;
    }
  printf ("La somma fa: %f\n",somma);
}
