#include <stdio.h>
#include <stdlib.h>


int integerPower(int base, int esponente);

int main(void) {
	system("clear");

	int b, e; //base e esponente

	printf("inserisci la base\n" );
	scanf("%d", &b );
	printf("inserisci l'esponente\n" );
	scanf("%d", &e );

	int risultato= integerPower(b, e);
	printf("il risultato è: " );
	printf("%d\n", risultato);
	}
	int integerPower(int base, int esponente){
		int result = base;

		for ( int i = 1; i < esponente; i++) {
				result=  result * base;
		}
		return result;
}
