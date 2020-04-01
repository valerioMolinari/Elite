#include <iostream>

using namespace std;

int sum(int x = 10, int y = 20);

int main(void) {
	system("clear");
	cout << sum() << endl << sum(5) << endl << sum(5, 10) << endl;
}

int sum(int x, int y) {
	return x + y;
}
