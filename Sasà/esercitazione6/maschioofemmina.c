/*Leggere un carattere (char ) da tastiera e stampare “Maschio” se “M” o “m”, “Femmina” se “F” o “f”, oppure “Sesso non
specificato” se diverso da questi caratteri. Utilizzare il comando switch.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	system("clear");

char scelta;
int contatore =  0;

while (contatore == 0) {

printf("inserisci 'm' se sei un  Maschio: \n" );
printf("inserisci 'f' se sei una Femmina: \n" );
scanf("\n%s", &scelta );

			switch (scelta) {
					case 'm':

					printf("sei un maschio per tua fortuna\n" );
					contatore = 1;
					break;

					case 'f':
					printf("sei una femmina mi dispiace\n" );
					contatore = 1;
				}

 			if (scelta != 'm' && scelta != 'f') {
 					printf("sesso non specificato, riprova.\n\n" );
					contatore = 0;
				}

	}
}
