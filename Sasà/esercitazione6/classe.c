#include <stdio.h>
#include <stdlib.h>

int main(void) {
	system("clear");

int a, b;
int pari, dispari;
int somma;
int somma_massima;

printf("inserisci il primo numero:\n" );
scanf("%d", &a);
printf("inserisci il secondo numero:\n" );
scanf("%d", &b );

if (b > 0) {
	printf("\n%d è un numero positivo\n\n", b );
}else
 printf ("\n%d è un numero negativo\n\n", b );

 if ( a % 2 == 0 ){
 	pari = pari + 1 ;
	printf("%d è un numero pari\n\n", a );
}else
 	 dispari = dispari + 1 ;
	 printf("%d è un numero dispari\n\n", a );


	somma= a + b;
		if (a > 0 && b > 0) {
			printf("la somma di a + b è uguale a: %d \n\n", somma );
		} if (a > 0 && b < 0) {
			printf("la somma di a + b è uguale a: %d \n\n", somma );
		} if (a < 0 && b > 0) {
		printf("la somma di a + b è uguale a: %d \n\n", somma );
		}
		 if (a < 0 && b < 0) {
		 	printf("la somma di a + b è uguale a: %d \n\n", somma );
		 }


if (a > 0 && b > 0) {
	somma_massima= a + b;
	printf("il valore massimo di a + b è uguale a: %d\n\n", somma_massima );
} if (a > 0 && b < 0) {
	b=  b * -1;
	somma_massima= a + b;
	printf("il valore massimo di a + b è uguale a: %d\n\n", somma_massima );
} if (a < 0 && b > 0) {
	a= a * -1 ;
	somma_massima= a + b;
	printf("il valore massimo di a + b è uguale a: %d\n\n", somma_massima );
}
 if (a < 0 && b < 0) {
	 a= -a ;
	 b= -b ;
	 somma_massima= a + b;
	printf("il valore massimo di a + b è uguale a: %d\n\n", somma_massima );
 }




}
