#include <stdio.h>
#include <stdlib.h>


int square(int y);

int main(void) {
	system("clear");


	for ( int x = 1; x <= 10; x++) {
		printf("%d\n", square(x) );
	}

}
int square(int y){

return y * y;
}
