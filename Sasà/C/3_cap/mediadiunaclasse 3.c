/* poni il totale uguale a 0;
poni il contatore dei voti uguale a uno;
finche il contatore dei votiè minore o uguale a 10;
		leggo il voto successivo;
		somma il voto totale;
		somma uno al contatore dei voti;
poni la media della classe uguale al totale diviso per dieci;
stampa la media della classe;
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	system("clear");

unsigned int contatore;//numero del prossimo voto da inserire
int voto;//valeore del voto
int totale;//somma dei voti inseriti dall'utente
int media; //media dei voti

totale= 0;//inizializza il totale
contatore= 1;//inizializza il contatore dei voti

while (contatore<=10) {
	printf("%s", "inserisci i voti: " );
	scanf("%d", &voto );
	totale= totale + voto;
	contatore= contatore + 1;
}
media= totale/10;

printf("la media della classe è: %d\n", media );
}
