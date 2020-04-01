#include <iostream>

using namespace std;

int main(void) {
	system("clear");
	/*
		Un reference in sostanza è un alias per una variabile e assomiglia
		ad un puntatore. Il reference punta all'indirizzo di memoria dell'oggetto
		a cui si riferisce ma non è un indirizzo di memoria, quindi non va
		dereferenziato. Fare un reference che si riferisce a un reference equivale
		a fare un altro reference per l'oggetto puntato dal primo reference.
	*/

	int x = 10;
	int& ref1 = x;
	int& ref2 = ref1;

	cout << ref2 << endl;
	return 0;
}
