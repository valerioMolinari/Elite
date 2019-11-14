/*  scrivere un programma:
    calcoli i quadrati da 0 a 10;
    calcoli i cubi da 0 a 10;
    e usi le tabulazione; */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
system("clear");

  printf("numero\t");
  printf("quadrato   ");
  printf("cubo\n ");

  int numero0= pow (0,1);
  printf("%d\t",numero0);
  int quadrato0= pow (0,2);
  printf("%5d\t",quadrato0 );
  int cubo0= pow (0,3);
  printf("%6d\n ",cubo0 );

  int a= pow (1,1);
  printf("%d\t",a );
  int b= pow (1,2);
  printf("%5d\t",b );
  int c= pow (1,3);
  printf("%6d\n",c );

  int d= pow (2,1);
  printf(" %d\t",d );
  int e= pow (2,2);
  printf("%5d\t",e );
  int f= pow (2,3);
  printf("%6d\n",f );

  int g= pow (3,1);
  printf(" %d\t",g );
  int h= pow (3,2);
  printf("%5d\t",h );
  int i= pow (3,3);
  printf("%6d\n",i );

  int l= pow (4,1);
  printf(" %d\t",l );
  int m= pow (4,2);
  printf("%5d\t",m );
  int n= pow (4,3);
  printf("%6d\n",n );

  int o= pow (5,1);
  printf(" %d\t",o );
  int p= pow (5,2);
  printf("%5d\t",p );
  int q= pow (5,3);
  printf("%6d\n",q );

  int r= pow (6,1);
  printf(" %d\t",r );
  int s= pow (6,2);
  printf("%5d\t",s );
  int t= pow (6,3);
  printf("%6d\n",t );

  int u= pow (7,1);
  printf(" %d\t",u );
  int v= pow (7,2);
  printf("%5d\t",v );
  int z= pow (7,3);
  printf("%6d\n",z );

  int x= pow (8,1);
  printf(" %d\t",x );
  int y= pow (8,2);
  printf("%5d\t",y );
  int w= pow (8,3);
  printf("%6d\n",w );

  int j= pow (9,1);
  printf(" %d\t",j );
  int k= pow (9,2);
  printf("%5d\t",k );
  int pasquale = pow (9,3);
  printf("%6d\n",pasquale );

  int giovanni= pow (10,1);
  printf(" %d\t",giovanni );
  int andrea= pow (10,2);
  printf("%5d\t",andrea );
  int francesco= pow (10,3);
  printf("%6d\n",francesco );
}
