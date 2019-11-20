#include <stdio.h>

int main(void){

  unsigned int aCount = 0;
  unsigned int bCount = 0;
  unsigned int cCount = 0;
  unsigned int dCount = 0;
  unsigned int fCount = 0;

  puts("Immetti il voto (in lettere):\n");
  puts("Scrivi EOF per terminare\n");

  char voto;

  while((voto = getchar()) != EOF){
    switch (voto){
      case 'A':
      case 'a':
      ++aCount;
      break;

      case 'B':
      case 'b':
      ++bCount;
      break;

      case 'C':
      case 'c':
      ++cCount;
      break;

      case 'D':
      case 'd':
      ++dCount;
      break;

      case 'F':
      case 'f':
      ++fCount;
      break;

      case '\n':
      case '\t':
      case ' ':
      break;

      default:
      printf("%s","Lettera Incorretta\n");
      puts("Immetti nuovo voto.");
      break;
    }
  }
  printf("Il totale per ogni voto sono:\n");
  printf("A: %u\n", aCount);
  printf("B: %u\n", bCount);
  printf("C: %u\n", cCount);
  printf("D: %u\n", dCount);
  printf("F: %u\n", fCount);
}
