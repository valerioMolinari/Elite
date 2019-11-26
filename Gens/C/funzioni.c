#include <stdio.h>
#include <math.h>

int square(int y);

int main(void) {
  for(int x = 1; x <= 10; ++x){
    printf("%d\n", square(x)); // chiama la funzione
  }
}

int square(int y){
  return y*y;
}
