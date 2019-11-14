/*
  fissare una variabile;
	chiedere all'utente di inserire un numero di 5 cifre;
	separare la cifra in numeri individuali;
	stampa le cifre una separata dall'altra  da tre spazi(\t);
	suggerimento: usare le operazioni di resto;
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	system("clear");

int cifra;
printf("Inserisci un numero da 5 cifre: " );
scanf("%d", &cifra );

int resto1 = (cifra%10000);
int resto2 = (cifra%1000);
int resto3 = (cifra%100);
int resto4 = (cifra%10);

int a = (cifra/10000);
int b = (resto1/1000);
int c = (resto2/100);
int d = (resto3/10);
int e = (resto4/1);

printf("%d\t", a );
printf("%d\t", b );
printf("%d\t", c );
printf("%d\t", d );
printf("%d\t\n\n", e );


}
