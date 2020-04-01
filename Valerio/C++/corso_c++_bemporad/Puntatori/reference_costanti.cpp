#include <iostream>

using namespace std;

void duplicate(const int& x, int& doppio);

int main(void) {
	system("clear");
	int x = 10;
	const int& xRef = x;

	// xRef = 20 restituisce un errore di compilazione
	// int& xRef2 = xRef restituisce sempre un errore di compilazione perché
	// non possiamo assegnare un reference costante ad un reference non costante

	int doubleX;
	duplicate(xRef, doubleX);

	cout << doubleX << endl;
}

void duplicate(const int& x, int& doppio) {
	doppio = x * 2;
}
