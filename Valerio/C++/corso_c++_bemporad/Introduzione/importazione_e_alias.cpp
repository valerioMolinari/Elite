#include <iostream>

namespace ns1 {
	int myFunc() {
		return 1;
	}
} /* ns1 */

namespace ns2 {
	struct MyStruct {
		int myVar;
	};
} /* ns2 */

namespace ns3 {
	namespace myns {
		// std::string è il tipo stringa!
		std::string myFunc() {
			return "Mario";
		}
	} /* myns */
} /* ns3 */

// Un namespace può essere immportato globalmente
using namespace ns1;

int main(void) {
	system("clear");

	// Oppure può essere importato localmente, inoltre come si può vedere,
	// è possibile importare anche soltanto parte di un namespace
	using ns2::MyStruct;

	// È possibile creare degli alias per i namespace utilizzando questa forma
	namespace ns = ns3::myns;

	struct MyStruct ms;
	std::cout << myFunc() << '\n';
	ms.myVar = 10;
	std::cout << ms.myVar << '\n';
	std::cout << ns::myFunc() << '\n';
}
