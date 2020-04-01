#include <iostream>

using namespace std;

void square(int& x);

int main(void) {
	system("clear");
	int x = 10;
	int& xRef = x;
	square(xRef);
	cout << x << endl;

	// Non è necessario creare esplicitamente un reference, se una funzione sa
	// che come parametro riceverà un reference, questa trasforma automaticamente
	// la variabile in un reference
	int y = 15;
	square(y);
	cout << y << endl;
}

void square(int& x) {
	x *= x;
}
