#include <stdio.h>
#include <stdlib.h>

int main(void) {
	system("clear");

int totale;//quanti numeri saranno inseriti
int numero;//ultimo numero inserito
int numero_precedente;// penultimo numero inserito
int N;//contatore per scandire i  umeri della serquenza;
int positivi, negativi, nulli;/*contatori numeri positi, negativi o nulli */
int pari, dispari;//contatori numeri pari o dispari
int crescente, decrescente; /*flag per indicare se la sequenza crescente o decrescente*/

/* LEGGI QUANTI NUMERI SARANNO INSERITI */
printf("Quanti numeri saranno inseriti? ") ;
scanf("%d", &totale) ;

positivi=0,
negativi=0;
nulli=0;
pari=0;
dispari=0;
crescente = 1 ;
decrescente = 1 ;

 /* INIZIALIZZA IL CONTATORE DEI NUMERI GIA’ INSERITI */
 N = 0 ;

 /* RIPETI IL SEGUENTE CICLO FINO A QUANDO NON SONO STATI INSERITI TUTTI
    I NUMERI DELLA SEQUENZA */
 while( N < totale )
 { /* LEGGI UN NUMERO */
 printf("Inserisci il numero %d: ", N++) ;
 scanf("%d", &numero) ;

 /* SE IL NUMERO E’ UGUALE A ZERO INCREMENTA IL CONTATORE "nulli" */
 if ( numero == 0 )
 	nulli = nulli + 1 ;
 		else{
 /* IL NUMERO E’ DIVERSO DA ZERO. SE NUMERO E’ POSITIVO
    INCREMENTA IL CONTATORE "positivi" ALTRIMENTI INCREMENTA
    IL CONTATORE "negativi" */
 			if ( numero > 0 )
 			positivi = positivi + 1 ;
 				else
 				negativi = negativi + 1 ;
 }
 /* SE IL NUMERO E’ PARI INCREMENTA IL CONTATORE "pari"
 ALTRIMENTI INCREMENTA IL CONTATORE "dispari" */
 if ( numero % 2 == 0 )
 	 pari = pari + 1 ;
 		else
 		dispari = dispari + 1 ;

 /* PER VERIFICARE SE LA SEQUENZA E’ CRESCENTE O DECRESENTE
 CONFRONTA IL NUMERO CORRENTE CON IL PENULTIMO NUMERO INSERITO.
 LA VERIFICA PUO’ ESSERE FATTA SOLO QUANDO SONO STATI INSERITI
 ALMENO DUE NUMERI DELLA SEQUENZA, OSSIA N>1. INFATTI,
 N==0 QUANDO VIENE INSERITO IL PRIMO NUMERO E N==1 QUANDO VIENE
 INSERITO IL SECONDO NUMERO */
 if ( N > 1 ){

 /* SE IL NUMERO CORRENTE E’ MAGGIORE DEL PRECEDENTE LA
 SEQUENZA NON E’ DECRESCENTE */
 if ( numero > numero_precedente )
 decrescente=0;
 else {
 /* SE IL NUMERO CORRENTE E’ MINORE DEL PRECEDENTE LA
 SEQUENZA NON E’ CRESCENTE */
    if (numero < numero_precedente)
    crescente=0;
 			else{
 /* SE IL NUMERO CORRENTE E’ UGUALE AL PRECEDENTE LA
 SEQUENZA NON E’ STRETTAMENTE CRESCENTE NE’
 STRETTAMENTE DECRESCENTE */
 					crescente=0;
 					decrescente=0;
 					}
 			}
 }
 /* IL NUMERO CORRENTE SARA’ IL PENULTIMO NUMERO INSERITO NELLA PROSSIMA
  ITERAZIONE DEL CICLO */
 numero_precedente=numero;

  /* INCREMENTA IL CONTATORE DEI NUMERI INSERITI */
 N = N + 1 ;}

  /* STAMPA IL RISULTATO */
  printf("Hai inserito: %d positivi, %d negativi, %d uguali a zero\n",positivi, negativi, nulli) ;
  printf("Hai inserito: %d numeri pari e %d numeri dispari\n",pari, dispari) ;

  if ( crescente == 1 )
    printf("La sequenza e’ crescente\n") ;
  else{
		if ( decrescente == 1 )
      printf("La sequenza e’ decrescente\n") ;
      else
         printf("La sequenza non e’ ne‘ crescente ne‘ decrescente\n") ;
      }
 exit(0) ;
}
