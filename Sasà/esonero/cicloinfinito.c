#include <stdio.h>
#include <stdlib.h>

int main(void) {
	system("clear");

	int contatore = 0 ;
	while (contatore == 0){

	printf("Immetti la frase da codificare in minuscolo gentilmente:\n");
	fgets(parola_da_criptare, sizeof(parola_da_criptare), stdin);

	if (islower(parola_da_criptare) == 1 ) {
		printf("è scritto con il carattere minuscolo\n");
		contatore = 1;
	}else if(contatore = 0){
		printf("Non è scritto in carattere miniscolo\n");

	}
	}


}
