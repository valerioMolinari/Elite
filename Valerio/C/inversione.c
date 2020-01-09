#include <stdio.h>
#include <stdlib.h>

int inverti(int * const x, int n);

int main(void) {
	system("clear");

  int n;
	int a[2];
	int c;

	printf("Inserisci n di Zn : ");
	scanf("%d", &n);
	printf("\nInserisci a contenuto in Zn : ");
	scanf("%d", a);

  c = inverti(a, n);

	switch (c) {
		case 0: printf("\nL'inverso di %d in Z_%d non esiste\n\n", *a, n); break;
		case 1: printf("\nL'inverso di %d in Z_%d è %d\n\n", *a, n, *(a + 1));
	}
}

int inverti(int * const x, int n) {
	for (int i = 1; i < n; i++)
		if ((*x * i) % n == 1) {
			*(x + 1) = i;
			return 1;
		}
	return 0;
}
