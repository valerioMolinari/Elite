#include <iostream>

using namespace std;

int main(void) {
	system("clear");


	signed char c {1};
	signed short int s {2};
	signed int i {4};
	signed long int li {8}; // 4, 8
	signed long long lli {8};

	unsigned char uc {1};
	unsigned short int us {2};
	unsigned int ui {4};
	unsigned long int uli {8}; // 4, 8
	unsigned long long ulli {8};
	// ...Fin qui c'eravamo

	// Vediamo il separatore
	us = 15'234;
	i = -34'000;
	uli = 18'000'000L;

	cout << us << endl << i << endl << uli << endl;

	// Binary literal
	unsigned char a {0b01100001}; // 97 ;) il little endian funge

	cout << a << endl;

	// Booleans

	bool valido {true};
	bool vietato {};
	cout << valido << endl << vietato << endl;
}
