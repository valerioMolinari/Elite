/*
Utilizzare un ciclo while, un do. . .while, e un for per stampare tutti i numeri
tra 0 e n con il valore n letto da tastiera
(scanf()). Per esempio, se n = 10, la stampa deve essere 12345678910.

• Calcolare il massimo comune divisore (MCD) tra due valori di tipo int presi in input da tastiera.
 Per farlo, scandire tutti i valori tra 1 ed il minimo dei due valori,
controllando per ogni valore scandito se è divisore di entrambi.
Il massimo di essi corrisponde al MCD.

*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	system("clear");


	int a, b;
	int resto;

printf("inserisci 2 valori per cui calcolare il minimo comune divisore \n" );
printf("inserisci il primo valore: \n"  );
scanf("%d", &a );
printf("inserisci il secondo valore: \n");
scanf("%d", &b );


 if (a > 0 && b > 0) {
 	printf("L'MCD  sta iniziando\n" );
 }
	else if (b == 0)
		printf("L'MCD è %d\n", a );
		return 0;


			while (b != 0) {
				resto = a % b;
				a = b;
				b = resto;
			}
			printf("L'MCD è %d\n", a);

 }
