#include <iostream>

using namespace std;

enum class PuntoCardinale {
	Nord, Sud, Est, Ovest
};

enum class PuntoCardinalePlus {
	Nord = 5, Sud, Est = 10, Ovest
};

enum class PuntoCardinaleChar : char {
	Nord = 'N', Sud = 'S', Est = 'E', Ovest = 'O'
};

int main(void) {
	system("clear");
	PuntoCardinale pc {PuntoCardinale::Est};

	cout << static_cast<int>(pc) << endl; // per stamparli gli enum vanno castati

	PuntoCardinalePlus pcp {PuntoCardinalePlus::Ovest};

	cout << static_cast<int>(pcp) << endl; // 11

	PuntoCardinaleChar pcc {PuntoCardinaleChar::Sud};

	cout << static_cast<char>(pcc) << endl; // S
}
