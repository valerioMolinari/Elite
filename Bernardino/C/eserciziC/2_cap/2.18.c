/* fissare due variabili;
chiedere all'utente di inserire due numeri interi;
se il primo numero è maggiore del secondo;
stampare il primo numero seguito dalle parole "is larger";
se i due numeri sono uguali;
stampare il messaggio "These numbers are equal";
se il secondo numero è maggiore del secondo;
stampare il secondo numero seguito dalle parole "is larger";
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  system("clear");
 int a,b;
 printf("Inserire due numeri interi:");
 scanf("%d%d", &a, &b);
 if (a > b){
   printf("%d is larger\n", a);
 }
 if (a == b){
   printf("These numbers are equal\n");
 }
 if (b > a){
   printf("%d is larger\n", b);
 }
}
