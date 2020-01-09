#include <stdio.h>
#include <stdlib.h>

int main (void) {

  for(unsigned int a = 1; a <= 24 ; ++a){
    printf("%10d\n", 1 + (rand() % 6));
    if(a % 6 == 0){
      puts("");
    }
  }
}
