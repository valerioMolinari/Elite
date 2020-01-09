#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 7

int main() {

  unsigned int frequency[SIZE] = {0};
  
  srand(time(NULL));
  for(int giri = 1; giri <= 60; ++giri){
    size_t facce = 1 + rand() % 6;
    ++frequency[facce];
  }

  printf("%s%17s\n", "Facce", "Frequenza");

  for(size_t facce = 1; facce < SIZE; ++facce){
    printf("%4zu%17d\n", facce, frequency[facce]);
  }
}
