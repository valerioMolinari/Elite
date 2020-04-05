#include <iostream>
#include <string>

using namespace std;

int main(void) {
	system("clear");
	string nome {"Valerio"};
	string cognome {"Molinari"};
	string fullname {nome + " " + cognome};

	cout << "String \"" << fullname << "\" is " << fullname.length() << " characters long" << endl;
}
