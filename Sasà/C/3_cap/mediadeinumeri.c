
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	system("clear");

  int contatore;//numero del prossimo voto da inserire
	int voto;//valeore del voto
	int somma_totale;//somma dei voti inseriti dall'utente
	int media; //media dei voti

	somma_totale=0;
	contatore=0;

	while (voto!=0) {
		printf("Inserrisci il voto dello studente: " );
		scanf("%d", &voto  );
		somma_totale= somma_totale+voto;
		contatore++;

	}

	media= somma_totale/contatore;
	printf("la media totale della classe è:%d\n", media );

}
