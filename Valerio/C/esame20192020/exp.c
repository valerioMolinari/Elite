#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
enum mario {io, tu, egli};

int main(void) {
	srand(time(NULL));
	printf("%d\n", rand()%3);
}
