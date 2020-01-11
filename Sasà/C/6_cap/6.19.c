#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 40000

int main(void) {
	system("clear");

		int somma2[SIZE];
		int somma3[SIZE];
		int somma4[SIZE];
		int somma5[SIZE];
		int somma6[SIZE];
		int somma7[SIZE];
		int somma8[SIZE];
		int somma9[SIZE];
		int somma10[SIZE];
		int somma11[SIZE];
		int somma12[SIZE];

			for (int lancio = 0; lancio < 36000; lancio++) {

					int numero1 = 1 + rand() % 6;
					int numero2 = 1 + rand() % 6;

					int somma= numero1 + numero2;

					switch (somma) {

						case 2:
						++somma2[SIZE];
						break;

						case 3:
						++somma3[SIZE];
						break;

						case 4:
						++somma4[SIZE];
						break;

						case 5:
						++somma5[SIZE];
						break;

						case 6:
						++somma6[SIZE];
						break;

						case 7:
						++somma7[SIZE];
						break;

						case 8:
						++somma8[SIZE];
						break;

						case 9:
						++somma9[SIZE];
						break;

						case 10:
						++somma10[SIZE];
						break;

						case 11:<
						++somma11[SIZE];
						break;

						case 12:
						++somma12[SIZE];
						break;

					}
				}

			 	printf("il numero delle volte in cui compaie una somma è:\n");

				printf("la somma 2 è comparsa %d volte\n", somma2[SIZE]);
				printf("la somma 3 è comparsa %d volte\n", somma3[SIZE]);
				printf("la somma 4 è comparsa %d volte\n", somma4[SIZE]);
				printf("la somma 5 è comparsa %d volte\n", somma5[SIZE]);
				printf("la somma 6 è comparsa %d volte\n", somma6[SIZE]);
				printf("la somma 7 è comparsa %d volte\n", somma7[SIZE]);
				printf("la somma 8 è comparsa %d volte\n", somma8[SIZE]);
				printf("la somma 9 è comparsa %d volte\n", somma9[SIZE]);
				printf("la somma 10 è comparsa %d volte\n", somma10[SIZE]);
				printf("la somma 11 è comparsa %d volte\n", somma11[SIZE]);
				printf("la somma 12 è comparsa %d volte\n", somma12[SIZE]);
		}
