#include <stdio.h>
#include <stdlib.h>


int maximun(int a, int b, int c);

int main(void) {
	system("clear");

		int numero1;
		int numero2;
		int numero3;

		printf("inserisci tre numeri\n");
		scanf("%d%d%d", &numero1, &numero2, &numero3 );

		printf("il maggiore dei tre numeri è: %d\n",maximun(numero1, numero2, numero3));
}
int maximun(int a, int b, int c){

	int max= a;

	if (b > max) {
		max = b;
	}
	if (c > max) {
		max = c;
	}
	return max;
}
