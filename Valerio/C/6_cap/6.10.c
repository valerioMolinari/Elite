#include <stdio.h>
#include <stdlib.h>
#define SIZE 9

void aggiungiFrequenza(int vendite, int array[]) {
	vendite /= 100;
	if (vendite > 10)
		vendite = 10;
	array[vendite - 2]++;
}

int calcolaVendite(lordo) {
	int result = 200+(lordo*9)/100;
	printf("Il salario dell'agente ammonta a %d$\n\n", result);
	return result;
}

int main(void) {
	system("clear");

	int freqIntervalli[SIZE] = {0};
	const char *intervalli[SIZE] = {
		"200-299", "300-399", "400-499", "500-599",
		"600-699", "700-799", "800-899", "900-999", "oltre 1000"
	};
	int vendita;
	while (1) {
		printf("Inserisci l'ammontare lordo delle vendite dell'agente (-1 per terminare): ");
		scanf("%d", &vendita);
		if (vendita == -1) break;
		aggiungiFrequenza(calcolaVendite(vendita), freqIntervalli);
	}
	puts("");
	for (size_t i = 0; i < SIZE; i++)
		printf("%s:\t%d\n", intervalli[i], freqIntervalli[i]);
	puts("");
}
