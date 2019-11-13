#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dado() {
	return rand() % 6 + 1;
}

int main(void) {
	system("clear");

	srand(time(NULL));

	int freqSomme[11] = {0};

	for (size_t i = 0; i < 36000; i++)
		freqSomme[dado()+dado()-2]++;

	puts("\n\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12");
	for (size_t i = 0; i < 11; i++)
		printf("\t%d", freqSomme[i]);
		
	puts("\n");
}
