#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){

  unsigned int pippo = UINT_MAX;        //Che valore ha pippo?
  short pluto = (short) ULLONG_MAX;     //Che valore ha pluto?
  unsigned int paperino = INT_MIN;      //Che valore ha paperino?
  int topolino = (int) 0Xb.2p0;         //Che valore ha topolino?
  short paperoga = (short) FLT_MAX;     //Che valore ha pape'roga
  unsigned short gastone = 5;

  gastone = gastone - 2;                //Che regola è stata applicata qui? Conversioni?

  unsigned int paperone = gastone;
  int amelia = -2;
  long long archimede = 20LL;
  long macchianera = 56L;

  if (gastone > amelia)
    printf("Hello1\n");                //Viene stampato? Perché?

  if (paperone > amelia)
    printf("Hello2\n");                //Viene stampato? Perché?

  archimede += paperone;               //Qual è il tipo dell'espressione a destra dell'uguale?
  macchianera += paperone;             //Qual è il tipo dell'espressione a destra dell'uguale?

  printf("Value of pippo %u\n", pippo );
  printf("Value of pluto %d\n", pluto );
  printf("Value of paperino %u\n", paperino );
  printf("Value of topolino %d\n", topolino );
  printf("Value of paperoga %def\n", paperoga );
  printf("Value of gastone %u\n", gastone );
  printf("Value of archimede %lld\n", archimede );
  printf("Value of macchianera %ld\n", macchianera );

}
