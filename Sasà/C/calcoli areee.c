#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void) {

  float d; /* numero inserito */
  float aq, ac, at;
  float r; /* raggio cerchio */
  float rad3_4; /* constante pari a radice (3) /4 */

  rad3_4= sqrt(3) / 4;
  printf("calcolo di aree \n\n ");

  printf("immetti il valore di D:");

  scanf("%f", &d);

  aq= pow(d, 2);

  r= d/2;

  ac= M_PI * pow(r, 2);
  at= rad3_4 * pow(d,2);

  printf("\n");
  printf("le aree calcolate sono:"\n);
  printf("area del quadrato di lato %f = %f\n",d, aq);
  printf("area del cerchio di diametro %f=%f\n",d, ac);
  printf("area del triangolo di lato %f = %f\n",d, at);

}
