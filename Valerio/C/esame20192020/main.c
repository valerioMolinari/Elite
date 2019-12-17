#include "gamelib.h"

int main(void) {
	system("clear");
	srand(time(NULL));

	bool keepPlay = 1;

	FirstMenu(&keepPlay);
}
