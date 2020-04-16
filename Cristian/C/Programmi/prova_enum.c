#include <stdlib.h>
#include <stdio.h>
#include <time.h>

enum Tipo_oggetto
 {
		cianfrusaglia = 1,
		bende,
		coltello,
		pistola,
		benzina,
		adrenalina
 };

int main ()
	{
		int oggetto_int;
		time_t t;
		int probabilita;

		//Inizializza il generatore di numeri casuali utilizzando il tempo attuale
		srand ((unsigned) time (&t));
		/* Funzione da chiamare una volta sola nel programma;
		Ritorna un numero tra 0 e 99 */

		printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",	"Che oggetto vuoi usare?"	,
																								"Hai a disposizione: "   	,
																								"cianfrusaglia.......1"	 	,
																								"bende...............2"	 	,
																								"coltello............3"		,
																								"pistola.............4"		,
																								"benzina.............5"		,
																								"adrenalina..........6"		);
		enum Tipo_oggetto oggetto;
		//scanf("%d", &oggetto_int);

		//Ritorna un numero tra 0 e 99;
		probabilita = rand()%100;
		printf("Probabiità: %d\n", probabilita);

		switch (probabilita)
			{
				case 0 ... 39:
				printf("Hai scelto la cianfrusaglia\n");
				oggetto = cianfrusaglia;
				break;
				case 40 ... 49:
				printf("Hai scelto le bende\n");
				oggetto = bende;
				break;
				case 50 ... 59:
				printf("Hai scelto il coltello\n");
				oggetto = coltello;
				break;
				case 60 ... 69:
				printf("Hai scelto la pistola\n");
				oggetto = pistola;
				break;
				case 70 ... 79:
				printf("Hai scelto la benzina\n");
				oggetto = benzina;
				break;
				case 80 ... 99:
				printf("Hai scelto l'adrenalina\n");
				oggetto = adrenalina;
				break;
				default:
				printf("Non hai scelto nessun oggetto!!\n");
			}
		printf("Hai scelto l'opzione n° %d\n",oggetto);
	}
