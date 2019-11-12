/*
  chiedere all'utente di inserire 1 intero;
  leggere l'input da tastiera;
	se il voto dello studente è uguale o maggiore a 90:
	  stampa "A";
	altrimenti
	se il voto dello studente è uguale o maggiore a 80:
		stampa "B";
 	altrimenti
	se il voto dello studente è uguale o maggiore a 70:
		stampa "C";
	altrimenti
	se il voto dello studente è uguale o maggiore a 60:
		stampa "D";
	altrimenti
		stampa "F";
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	system("clear");

int  voto;
printf("inserisci il tuo voto: " );
scanf("%d", &voto );

if (voto >=90) {
	   printf("A" );
	 	 }
		 else{
 	      if (voto>=80) {
		 			printf( "B\n" );
				}
				else{
	 				if (voto>=70) {
	 	 				printf("C\n" );
	 				}
					else{
						if (voto>=60) {
							printf("D\n" );
						}
						else{
		 						printf( "F\n" );

						}
					}
				}
			}
}
