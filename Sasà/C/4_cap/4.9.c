#include <stdio.h>
#include <stdlib.h>

int main(void) {
	system("clear");

int conto;// numero di conto del cliente
int limite;//limite di credito del cliente prima della recessione
int saldo;//saldo attuale di credito del cliente
int nuovo_limite_saldo;


for (unsigned int counter=1; counter<=3; counter++) {
	printf("immetti il numero del tuo conto: " );
	scanf("%d", &conto );
	printf("inserisci il tuo limite di credito: " );
	scanf("%d", &limite );
	printf("inserisci il tuo saldo attuale: " );
	scanf("%d", &saldo );
	nuovo_limite_saldo=limite/2;
	printf(" il nuovo limite del saldo è: %d\n", nuovo_limite_saldo);
	if (saldo>nuovo_limite_saldo) {
		printf("numero del conto in cui il saldo supera il nuovo limite di credito: %d\n", conto );
	}

	}
}
