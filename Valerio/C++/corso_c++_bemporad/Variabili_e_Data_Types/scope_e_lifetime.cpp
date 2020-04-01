#include <iostream>

using namespace std;

/*
	lifetime = arco temporale di esistenza di una variabile
	scope = zona del programma in cui una variabile è visibile

	lifetime:
		automatic storage duration:
			tendenzialmente variabili non static dichiarate in una funzione,
			durano finché la funzione è in esecuzione, dopodiché vengono
			automaticamente cancellate dalla memoria
		static storage duration:
			durano per tutta l'esecuzione del programma,
			anche da prima di eseguire main
		dynamic storage duration:
			sono le variabili allocate dinamicamente in fase di runtime;
			durano finché non vengono esplicitamente deallocate o fino
			alla fine del programma
		thread storage duration:
			riguarda la programmazione multithread che, purtroppo, non viene
			affrontata in questo corso

	Variabili globali:
		Definite al di fuori di tutte le funzioni
		Global Scope
		Static Storage Duration
		Inizializzate a zero per default
*/

int x;

int main(void) {
	system("clear");
	int x {10};
	cout << "Variabile globale: " << ::x << endl; // 0
	// quei due punti prima di x stanno ad indicare come namespace lo scope globale
	cout << "Variabile locale: " << x << endl; // 10
}
