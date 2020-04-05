#include <iostream>
#include <string>

using namespace std;

class Persona {
public:
	string nome;
	string cognome;
	void saluta() {
		cout << nome + " " + cognome + " ti saluta!" << endl;
	}
};

int main(void) {
	system("clear");
	// Allocazione statica
	Persona mario;
	mario.nome = "Mario";
	mario.cognome = "Rossi";
	mario.saluta();

	// Allocazione dinamica (possiamo accedere indirettamente per dereferenziazione o con freccia)
	Persona* luigi = new Persona;
	luigi->nome = "Luigi";
	luigi->cognome = "Mario";
	(*luigi).saluta();

	delete luigi;
}
