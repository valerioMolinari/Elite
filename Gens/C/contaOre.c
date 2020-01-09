#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*typedef struct ore_OTTOBRE{
	int ore_lavorative;
	int giorni_riposo;
}ottobre;

typedef struct ore_NOVEMBRE{
	int ore_lavorative;
	int giorni_riposo;
}novembre;

typedef struct ore_DICEMBRE{
	int ore_lavorative;
	int giorni_riposo;
}dicembre;*/

int main(void) {
	system("clear");

	/*ottobre mese1;
	novembre mese2;
	dicembre mese3;*/
	int mese;
	double oreinserite;
	double totaleore, totalepaga;
	double totaleore1, pagaottobre;
	double totaleore2, paganovembre;
	double totaleore3, pagadicembre;

	puts("Benvenuto nel programma di calcolo ore lavorative di Nicola Cherubini\n");

	do {
		puts("In quale mese vuoi aggiungere le ore\n\t1: Ottobre\n\t2: Novembre\n\t3: Dicembre\n\t4: Per stampare il totale dello ore e dello stipendio\n");
		scanf("%d", &mese);

system("clear");
sleep(2);

		switch(mese){
			case 1:
			puts("Ottobre");
			puts("Ore da inserire giorno per giorno\n");
			for(int i = 1; i <= 31; i++){
				printf("Inserisci orario per giorno %d/10\n", i);
				scanf("%lf", &oreinserite);
				totaleore1 = totaleore1 + oreinserite;
				pagaottobre = totaleore1 * 6;
			}
			system("clear");
			sleep(2);
			printf("Il totale delle ore lavorate é: %.2f\n", totaleore1);
			printf("La paga per Ottobre è: %.2f\n\n", pagaottobre);
			break;

			case 2:
			puts("Novembre");
			puts("Ore da inserire giorno per giorno\n");
			for(int i = 1; i < 30; i++){
				printf("Inserisci orario per giorno %d/11\n", i);
				scanf("%lf", &oreinserite);
				totaleore2 = totaleore2 + oreinserite;
				paganovembre = totaleore2 * 6;
			}
			system("clear");
			sleep(2);
			printf("Il totale delle ore lavorate é: %.2f\n", totaleore2);
			printf("La paga per Novembre è: %.2f\n\n", paganovembre);
			break;

			case 3:
			puts("Dicembre");
			puts("Ore da inserire giorno per giorno\n");
			for(int i = 1; i < 31; i++){
				printf("Inserisci orario per giorno %d/12\n", i);
				scanf("%lf", &oreinserite);
				totaleore3 = totaleore3 + oreinserite;
				pagadicembre = totaleore3 * 6;
			}
			system("clear");
			sleep(2);
			printf("Il totale delle ore lavorate é: %.2f\n", totaleore3);
			printf("La paga per Dicembre è: %.2f\n\n", pagadicembre);
			break;
		}
	} while(mese != 4);

system("clear");

totaleore = totaleore1 + totaleore2 + totaleore3;
totalepaga = pagaottobre + paganovembre + pagadicembre;
	printf("Il totale delle ore lavorative è: %.2f\n", totaleore);
	printf("Il totale dello stipendio è: %.2f\n", totalepaga);
}
