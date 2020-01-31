#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define MAX 4096

typedef struct Data {
	int value;
	double H;
} Dt;

void cesare(int k, char string[], char cypher[]);
double freqCalc(char lettera, char string[]);
double calculation(char string[]);

double freqUff [26] = {0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228, 0.02015, 0.06094, 0.06966, 0.00153, 0.00772, 0.04025, 0.02406,
0.06749, 0.07507, 0.01929, 0.00095, 0.05987, 0.06327, 0.09056, 0.02758, 0.00978, 0.02360, 0.00150, 0.01974, 0.00074};



int main(void) {
	system("clear");
	char cypher [MAX];

	printf("inserire il testo da decifrare:\n");
	fgets(cypher, sizeof (cypher), stdin);

	int lun = strlen(cypher);
	char string [lun];
	string[strlen(cypher)] = '\0';

	double Hsupp = 0;
	Dt data;
	cesare(0, string, cypher);

	data.value = 0;
	data.H = calculation(string);


	for (int k = 1; k<=25; k++){
		cesare(k, string, cypher);
		Hsupp = calculation(string);
		if ( Hsupp < data.H){
			data.H = Hsupp;
			data.value = k;
		}
	}

	cesare ( data.value, string, cypher);
	system("clear");
	printf("Testo originale: %s\n",cypher);
	printf("\n\nStringa decifrata: %s\n", string );
	printf("Rateo: %lf\n", data.H );
	printf("Key: %d\n",data.value );


}

void cesare(int k, char string[], char cypher[]){
	for(int i = 0; cypher[i] != '\0'; i++){
		cypher[i] = tolower(cypher[i]);
		if (cypher[i] >= 'a' && cypher[i] <= 'z'){
			string[i] = cypher[i]-k;

			if (string[i]< 'a'){
				string [i] = string[i]+'z'-'a'+1;
			}
		}else{
			string [i] = cypher[i];
		}
	}

}

double freqCalc(char lettera, char string[]){
	double freqSup = 0;
	double letterNumber = 0;
	for (int i = 0; i< strlen(string); i++){
		if (string[i] == lettera)
			freqSup++;
		if (string[i]>96 && string[i]< 123)
			letterNumber++;
	}
	return (freqSup/letterNumber);
}

double calculation(char string[]){
	double somma = 0;
	for (int i = 97; i<123; i++){
		somma += (freqCalc((char)i, string) * log(freqUff[i-97]));
	}
	somma = (-somma);
	return somma;
}
