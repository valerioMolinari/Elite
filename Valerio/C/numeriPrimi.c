#include <stdio.h>
#include <stdlib.h>

unsigned short isPrime(unsigned int n);
unsigned int primes[83333];

int main(void) {
	system("clear");
	primes[0] = 2;

	for (unsigned int i = 2; i < 1000000; i++) {
		if (isPrime(i))
			printf("%u ", i);
	}
	puts("");
}

unsigned short isPrime(unsigned int n) {
	static unsigned int length = 0;
  for (size_t i = 0; i < length; i++)
    if (!(n % primes[i]))
      return 0;
  primes[length] = n;
	length++;
  return 1;
}
