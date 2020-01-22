#include "gamelib.h"

int main(void) {
	clr;
	bool keepPlay = true;
	do {
		FirstMenu(&keepPlay);
	} while(keepPlay);
	clr;
	system("less grazie.txt");
}
