#include <iostream>

namespace ns1 {
	int myFunc() {
		return 1;
	}
}

namespace ns2 {
	int myFunc() {
		return 2;
	}
}

namespace ns3 {
	namespace myns {
		int myFunc() {
			return 3;
		}
	}
}

namespace ns4::myns {
	int myFunc() {
		return 4;
	}
}


int main(void) {
	system("clear");
/*
*	L'operatore :: si chiama scope resolution operator e permette di selezionare
*	qualcosa all'interno di un namespace.
*	I namespace possono essere nidificati.
*/
	std::cout << ns1::myFunc() << '\n';
	std::cout << ns2::myFunc() << '\n';
	std::cout << ns3::myns::myFunc() << '\n';
	std::cout << ns4::myns::myFunc() << '\n';
}
