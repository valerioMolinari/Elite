#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int main(void) {
	system("clear");


	  int primaclasse[SIZE];
		int economy[SIZE];
		int primoposto = 0;
		int secondoposto = 0;
		int terzoposto = 0;
		int quartoposto = 0;
		int quintoposto = 0;
		int sestoposto = 0;
		int settimoposto = 0;
		int ottavoposto = 0;
		int nonoposto = 0;
		int decimoposto = 0;

		char nome[20];
		char cognome[20];


		int	viaggiatore= 0;
while (viaggiatore < 10) {
	printf("inserisci il tuo nome:\n");
	scanf("%s", nome);
	printf("il tuo cognome:\n");
	scanf("%s", cognome);


		int scelta;
			printf("Scegli la classe con cui viaggiare:\n\n");
			printf("> Scrivi 1 se vuoi viaggiare in prima classe\n");
			printf("> Scrivi 2 se vuoi viaggiare in classe economy\n");
			scanf("%d", &scelta );

			if (scelta == 1) {

				printf("Scegli il numero del posto in prima classe\n");
			  printf("%7s%7s%7s%7s%7s\n", "1|_|", "2|_|", "3|_|", "4|_|","5|_|" );
				scanf("%d", &primaclasse[SIZE] );


				switch (primaclasse[SIZE]) {
					case 1:
						if (primoposto == 0) {
						printf("Hai prenotato un posto per il volo 231299 per il 12/04/2020\n\n");
						printf("NOME: %s\nCOGNOME: %s\n", nome/*[viaggiatore]*/, cognome/*[viaggiatore]*/ );
						printf("PRIMA CLASSE\t POSTO NUMERO 1\n" );
						++primoposto;
					}	else
						printf("questo posto è stato già assegnato\n" );
						break;

						case 2:
							if (secondoposto == 0) {
							printf("Hai prenotato un posto per il volo 231299 per il 12/04/2020\n\n");
							printf("NOME: %c\nCOGNOME: %c\n", nome[viaggiatore], cognome[viaggiatore] );
							printf("PRIMA CLASSE\t POSTO NUMERO 2\n" );
							++secondoposto;
							break;
						}
							case 3:
								if (terzoposto == 0) {
								printf("Hai prenotato un posto per il volo 231299 per il 12/04/2020\n\n");
								printf("NOME: %c\n COGNOME: %c\n", nome[viaggiatore], cognome[viaggiatore] );
								printf("PRIMA CLASSE\t POSTO NUMERO 3\n" );
								++terzoposto;
								break;
							}
								case 4:
									if (quartoposto == 0) {
									printf("Hai prenotato un posto per il volo 231299 per il 12/04/2020\n\n");
									printf("NOME: %c\nCOGNOME: %c\n", nome[viaggiatore], cognome[viaggiatore] );
									printf("PRIMA CLASSE\t POSTO NUMERO 4\n" );
									++quartoposto;
									break;
								}
									case 5:
										if (quintoposto == 0) {
										printf("Hai prenotato un posto per il volo 231299 per il 12/04/2020\n\n");
										printf("NOME: %c\nCOGNOME: %c\n", nome[viaggiatore], cognome[viaggiatore] );
										printf("PRIMA CLASSE\t POSTO NUMERO 5\n" );
										++quintoposto;
										break;
									}
								}
							}
								else if (scelta == 2){
								printf("Scegli il numero del posto in classe economy\n");
								printf("%7s%7s%7s%7s%7s\n", "5|_|", "6|_|", "7|_|", "8|_|","9|_|" );
								scanf("%d", &economy[SIZE] );

								switch (economy[SIZE]) {
									case 5:
										if (sestoposto == 0) {
										printf("Hai prenotato un posto per il volo 231299 per il 12/04/2020\n\n");
										printf("NOME: %c\nCOGNOME: %c\n", nome[viaggiatore], cognome[viaggiatore] );
										printf("CLASSE ECONOMY\t POSTO NUMERO 1\n" );
										++sestoposto;
										break;
									}
										case 6:
											if (settimoposto == 0) {
											printf("Hai prenotato un posto per il volo 231299 per il 12/04/2020\n\n");
											printf("NOME: %c\nCOGNOME: %c\n", nome[viaggiatore], cognome[viaggiatore] );
											printf("CLASSE ECONOMY\t POSTO NUMERO 2\n" );
											++settimoposto;
											break;
										}
											case 7:
												if (ottavoposto == 0) {
												printf("Hai prenotato un posto per il volo 231299 per il 12/04/2020\n\n");
												printf("NOME: %c\nCOGNOME: %c\n", nome[viaggiatore], cognome[viaggiatore] );
												printf("CLASSE ECONOMY\t POSTO NUMERO 3\n" );
												++ottavoposto;
												break;
											}
												case 8:
													if (nonoposto == 0) {
													printf("Hai prenotato un posto per il volo 231299 per il 12/04/2020\n\n");
													printf("NOME: %c\nCOGNOME: %c\n", nome[viaggiatore], cognome[viaggiatore] );
													printf("CLASSE ECONOMY\t POSTO NUMERO 4\n" );
													++nonoposto;
													break;
												}
													case 9:
														if (decimoposto == 0) {
														printf("Hai prenotato un posto per il volo 231299 per il 12/04/2020\n\n");
														printf("NOME: %c\nCOGNOME: %c\n", nome[viaggiatore], cognome[viaggiatore] );
														printf("CLASSE ECONOMY\t POSTO NUMERO 5\n" );
														++decimoposto;
														break;
													}
												}
											}
viaggiatore++;
				}
			}
