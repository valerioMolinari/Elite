#include <stdio.h>
#include <stdlib.h>

int main(void) {
	system("clear");

	int k, n, s;
	int valore_piu_piccolo;
	int valore_piu_piccolo2;

printf("inserisci il valore di quanti numeri restanti vuoi inserire\n" );
scanf("%d", &k );

printf("inserisci il primo numero \n" );
scanf("%d", &n );

for (size_t i = 0; i < (k -1); i++) {
	 printf("inserisci il numero successivo:\n" );
	 scanf("%d", &s );

	 if (n < s) {
	 	 valore_piu_piccolo= n;
	 }else if (valore_piu_piccolo > s)
	  valore_piu_piccolo2= s;
	}

		if (valore_piu_piccolo < valore_piu_piccolo2) {
			printf("il valore più piccolo è:%d\n", valore_piu_piccolo );
		}else
		printf("il valore più piccolo è:%d\n", valore_piu_piccolo2 );

}
