#include <iostream>

using namespace std;

int main(void) {
	system("clear");
	char nome[] = "Valerio";

	for (char c : nome)
		cout << c << " ";
	cout << endl;

	for (int c : nome)
		if (c)
			cout << c << " ";
	cout << endl;
}
