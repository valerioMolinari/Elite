#include <iostream>

using namespace std;

int main(void) {
	system("clear");
	// Inizializzare una variabile
	// Assignment notation
	int a = 15;

	// Functional notation
	int b(15);

	// Braced notation
	int c {15};

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	// int d {15.3}; genera un errore

	// Zero Initializzation
	int x {0};
	// può essere fatto più semplicemente così
	int y {};
}
