#include <stdio.h>
#include <stdlib.h>

int main(void) {
	system("clear");

int paga;
printf("inserisci il tuo codice paga\n\n" );

printf("inserisci 1 se sei un Manager\n\n" );
printf("inserisci 2 se sei un lavatore a ore\n\n" );
printf("inserisci 3 se sei un lavoratore a provvigione\n\n" );
printf("inserisci 4 se sei un lavatore a cottimo\n\n" );

scanf("%d", &paga );

switch (paga) {
	case 1:
	printf("la tua paga ha un valore fisso di 300$\n" );
	break;

	case 2:{
	double ore;
	double straordinario;
	double paga_fissa_ogniora= 20.0;
	double bonus;
	double paga_totale;
	printf("la tua paga fissa per ogni ora è di %lf\n", paga_fissa_ogniora );
	printf("inserisci quante ore hai lavorato questa settimana:\n");
	scanf("%lf\n", &ore );

	if (ore>40.0) {
		printf("hai un bonus del 50 percento sulla tua paga\n" );
		printf("inserisci quante ore hai fatto di staordinario \n" );
		scanf("%lf\n", & straordinario );
		bonus= paga_fissa_ogniora*1.5;
		scanf("%lf\n", &bonus );
		paga_totale= (ore + straordinario) * bonus;
		printf("la tua paga totale è di:%lf\n", paga_totale );
		}
		break;
	}
	 case 3:{
	 double paga_settimanale= 250.0;
	 double paga_totale;
	 double vendite_settimanali;
	 double bonus_vendite;
	 printf("inserisci quanti soldi hai fatto con le tue vendite settimanali lorde:\n" );
	 scanf("%lf", &vendite_settimanali );
	 bonus_vendite=(vendite_settimanali*5.7)/100;
	 paga_totale=bonus_vendite+paga_settimanale;
	 printf("la tua paga totale è di:%lf", paga_totale );
	 break;
 }

	 case 4:{
	 double articolo;
	 double denaro=500.0;
	 double paga_articoli;
	 printf("inserisci quanti articoli hai prodotto in questa settimana:\n" );
	 scanf("%lf",&articolo );
	 paga_articoli=denaro*articolo;
	 printf("la tua paga per questa settimana è di:\n" );
	 scanf("%lf\n", &paga_articoli );
	 break;
	 }
}

}
