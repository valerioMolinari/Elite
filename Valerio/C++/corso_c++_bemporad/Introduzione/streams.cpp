#include <iostream>
#include <string>

using namespace std;

int main(void) {
	system("clear");
	/*
		std::cout è il flusso di output che riceve dei caratteri e li passa al
		terminale. Perché funzioni è necessario usare il <<, ovvero lo
		"stream insertion operator", che incanala i flussi da destra
		verso sinistra.

		std::endl invece è un manipolatore: inserisce \n alla fine del flusso
		verso cui lo stiamo indirizzando.
		Un altro esempio è il manipolatore std::hex che converte un flusso
		numerico in entrata in formato esadecimale
	*/

	cout << "0x" << hex << 1420 << "\n\n";

	// NOTE: visto che hex è rimasto in cout per annullarne l'effetto
	// 		 dobbiamo usarlo anche in cin

	int numero;
	cout << "Inserisci un numero : ";
	cin >> hex >> numero;
	cout << "Il numero inserito è: " << numero << "\n\n";

	string myString;
	cout << "Inserisci una parola: ";
	cin >> myString;
	cout << myString << endl;
}
