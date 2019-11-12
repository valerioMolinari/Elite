/* creare due variabili;
chiedere all'utente di inserire due numeri;
leggere gli input da tastiera e salvarli nelle variabili;
per ogni operazione crearne la variabile contenente l'operazione;
stampare ciascuna variabile;
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  system("clear");
int a,b;
printf("Inserire due numeri:");
scanf("%d%d", &a, &b );
int somma = a+b;
printf("Somma: %d\n", somma );
int prodotto = a*b;
printf("Prodotto: %d\n", prodotto );
int differenza = a-b;
printf("Differenza: %d\n", differenza );
float quoziente = (float) a/b;
printf("Quoziente: %.5f\n", quoziente );
int resto = a%b;
printf("Resto: %d\n", resto );

return 0;
}
