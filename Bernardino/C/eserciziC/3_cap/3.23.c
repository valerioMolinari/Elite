/* "Trovare il numero più grande"
fissare 10 variabili;
chiedere all'utente di inserire 10 numeri non negativi;
leggere i valori inseriti da tastiera;
assegnare i valori alle variabili corrispondenti;
calcolare qual è il numero più grande della serie;
stampare tale numero;

counter = un contatore per contare fino a 10 (cioè per tenere il conto di
quanti numeri siano stati inseriti e per determinare quando tutti e dieci i
numeri sono stati elaborati)

number = il numero corrente inserito nel programma

largest = il numero maggiore trovato fino a quel punto
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
system("clear");

float number; //il numero corrente inserito nel programma
float counter = 1;
float largest; //il numero maggiore trovato fino a quel punto

while (1) {
  printf("Inserisci un numero non negativo: \n");
  scanf("%f", &largest);

     if(largest > 0){
       while (counter < 10){

         printf("Inserisci un nuovo numero non negativo: \n");
         scanf("%f", &number);

          if(number > 0){

             if(largest > number){
               largest = largest;
               counter = counter + 1;
              }

             else if(largest < number){
               largest = number;
               counter = counter +1;
              }

             else if(largest == number){
               largest = number;
               counter = counter + 1;
              }
            }

          else {
            printf("Inserire solo numeri positivi!\n");
            }
          }

          printf("Il maggiore tra i numeri inseriti è: %f\n", largest);
          return 0;
        }
        printf("Inserire solo numeri positivi!!!\n");
      }
}
