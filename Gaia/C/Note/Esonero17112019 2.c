#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void parole(char parola[]){

	char parola[256];
	
	printf ("Immettere la parola da cifrare: %s \n");
	printf ("(per terminare l'inserimento immettere il terminatore '\0')");

	for (int i = 0; parola[i] != '\0'; i++){
		
		scanf("%s \n", parola[i]);
	}
}

int chiave(){

	int k = 0;

	printf ("Inserire la chiave con cui si vuole cifrare la parola: %d \n");
	scanf ("%d", &k);
}

int lunghezza(parola, int len){

	len = strlen(parola);

	printf ("La lunghezza della parola che si e' immessa, e': %d", &len);

}

void cesare(parola, len){

	int k = len;
	char codifica[256];

	printf("In questa parte del programma verra' codificata la parola inserita precedentemente!");

	for (int i = 0; i < len; i++){
		
		int c = 0;
		
		c = (parola[i]+k)%26;
		
		codifica[i] = parola[i] + c;

	}
		
}
void main(){

	char parola[256];
	int len = 0;

	parole(parola);
	chiave();
	lunghezza(parola);

