#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculateCharges(double a, double p);

int main(void) {
	system("clear");


 double prezzo1, prezzo2, prezzo3;
 double prima_macchina, seconda_macchina, terza_macchina;
 double tariffa_fissa= 2.00;
 double tariffa_aggiunta= 0.50;
 double orario_max= 24.00;
 double costo_max= 10.00;
 double totale_ore;
 double totali_soldi;

 printf("inserisci l'orario della prima macchina\n" );
 scanf("%lf", &prima_macchina );
 printf("inserirsci l'orario della secondamacchina\n" );
 scanf("%lf", &seconda_macchina );
 printf("inserisci l'orario della terza macchina\n" );
 scanf("%lf", &terza_macchina );

prezzo1= calculateCharges(prima_macchina, prezzo1);
prezzo2= calculateCharges(seconda_macchina, prezzo2);
prezzo3= calculateCharges(terza_macchina, prezzo3);

 totale_ore= prima_macchina + seconda_macchina + terza_macchina;
	totali_soldi= prezzo1 + prezzo2 + prezzo3;

printf("%s%7s%15s\n", "Macchina", "Ore", "Costo" );
printf("1%15.2f%13.2f\n",prima_macchina, prezzo1 );
printf("2%15.2f%13.2f\n", seconda_macchina, prezzo2 );
printf("3%15.2f%13.2f\n", terza_macchina, prezzo3 );
printf("%s%10.2f%13.2f\n", "TOTALE", totale_ore, totali_soldi);

}
double calculateCharges(double a, double p){

double tariffa_fissa= 2;
double tariffa_aggiunta= 0.50;

if (a <= 3) {
	return p = tariffa_fissa;//prezzo1 = tariffa_fissa
}
	if (a == 24 ) {
		return p = 10;
	}
		if (a > 3) {
	 	p= ((a -3) * tariffa_aggiunta) + tariffa_fissa;
	 	return p;
	}
		}
