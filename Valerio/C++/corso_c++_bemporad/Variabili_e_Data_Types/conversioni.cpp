#include <iostream>

using namespace std;

int main(void) {
	system("clear");
	int x {8};
	double d {15};
	double e {d / x}; // conversione implicita, x convertito a double

	double e2 {d / (double) x}; // old-style Cast; conversione esplicita

	int e3 {static_cast<int>(d) + x}; // new-style cast;

	cout << e << endl << e2 << endl << e3 << endl;

}
