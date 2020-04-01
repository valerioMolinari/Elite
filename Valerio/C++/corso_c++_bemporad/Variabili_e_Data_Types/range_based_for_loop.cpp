#include <iostream>

using namespace std;

int main(void) {
	system("clear");
	int valori[10];

	for (size_t i = 0; i < 10; i++)
		valori[i] = (i + 1) * 10;

	for (int x : valori)
		cout << x << " ";
	cout << endl;
}
