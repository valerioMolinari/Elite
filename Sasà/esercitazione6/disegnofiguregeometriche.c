#include <stdio.h>
#include <stdlib.h>

int main(void) {
	system("clear");

int scelta;

printf("inserisci '1' se vuoi stampare un quadrato\n" );
printf("inserisci '2' se vuoi vedere solo i lati del quadrato\n" );
scanf("%d", &scelta );

switch (scelta) {
	case 1:
	int altezza, base;
	int contatore= 0;



	printf("inserisci la base \n" );
	scanf("%d", &base );
	printf("inserisci l'altezza\n" );
	scanf("%d", &altezza );


for (int i = 0; i < altezza; ++i) {
	contatore = 0;
		while (contatore < base) {
			printf( " * " );
			contatore++;
		}
 printf("\n" );
}


 break;

	case 2:
int lato, base, altezza, riga;

	printf("inserisci la base \n" );
	scanf("%d", &base );
	printf("inserisci l'altezza\n" );
	scanf("%d", &altezza );

printf("inserisci la grandezza del lato del quadrato\n" );
scanf("%d", &lato );

if (lato <= 0) {
printf("errore, il lato l,altezza deve essere maggiore di zero\n", );

}else
contatore= 0;
	while (base < lato)
	altezza = 0

	 while (altezza < lato)

	 if (riga == 0 || riga == (lato -1)) {
	 	printf(" * " );
	}else{

		(altezza == 0 || colonna == (lato -1)){
		printf(" * " );
	}
	altezza = altezza +1;
}
printf("\n" );
}
riga= riga +1;



/*	for (int i = 0; i < altezza; ++i) {
		contatore = 0;
		if

			while (contatore < base) {
				printf( "*" );
				contatore++;
			}
		printf("\n" );
		contatore = 0;
		while (contatore > 0 && contatore < altezza) {
			printf("*", );
		}
	}*/














}
}
