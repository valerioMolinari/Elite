#include <iostream>

using namespace std;

void swap(int *x, int& y);

int main(void) {
	system("clear");
	int *a = new int;
	*a = 10;
	int b = 20;
	swap(a, b);
	cout << *a << endl << b << endl;
	delete a; // Cazzo l'avevo dimenticato! 

	return 0;
}

void swap(int *x, int& y) {
	int temp = *x;
	*x = y;
	y = temp;
}
