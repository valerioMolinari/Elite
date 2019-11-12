/* Calcolatore dell'indice di massa corporea:

BMI = (weightInPounds * 703) / (heightInInches * heightInInches);
BMI = (weightInKilograms) / (heightInMeters * heightInMeters);

fissare due variabile;
chiedere all'utente di inserire il valore del suo peso in libbre (in alternativa in kilogrammi);
leggere il valore inserito da tastiera;
assegnare tale valore ad una variabile;
chiedere all'utente di inserire il valore della sua altezza in pollici (in alternativa in metri);
leggere il valore inserito da tastiera;
assegnare tale valore ad una variabile;
fissare una nuova variabile che calcoli l'indice di massa corporea dell'utente;
stampare il valore dell'BMI;
stampare le informazioni tratte dal Department of Health and Human Services/National Institutes of Health;
così che l'utente possa valutare il suo BMI;

VALORI DEL BMI
Sottopeso:     meno di 18.5
Normale:       tra 18.5 e 24.9
Sovrappeso:    tra 25 e 29.9
Obeso:         30 o oltre
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  system("clear");
    printf("Calcolatore dell'indice di massa corporea\n");
    printf("Premi 1 per utilizzare il calcolatore di BMI in libbre e pollici\n");
    printf("Premi 2 per utilizzare il calcolatore di BMI in kilogrammi e metri\n");

    int a;
    scanf("%d", &a);

  if (a == 1){
   system("clear");
   float libbre; //peso in libbre
   float pollici; //altezza in pollici

   printf("Inserisci il tuo peso in libbre\n");
   scanf("%f", &libbre);
   printf("Inserisci la tua altezza in pollici\n");
   scanf("%f", &pollici);

   float BMI = ((libbre * 703) / (pollici * pollici));
   printf("Il tuo indice di massa corporea corrisponde a: %f\n", BMI);

   printf("\nVALORI DEL BMI"
   "\nSottopeso:     meno di 18.5\n"
   "Normale:       tra 18.5 e 24.9\n"
   "Sovrappeso:    tra 25 e 29.9\n"
   "Obeso:         30 o oltre\n");
 }

   if(a == 2){
     system("clear");
     float kg; //peso in kilogrammi
     float metri; //altezza in metri

     printf("Inserisci il tuo peso in kilogrammi\n");
     scanf("%f", &kg);
     printf("Inserisci la tua altezza in metri\n");
     scanf("%f", &metri);

     float BMI = ((kg) / (metri * metri));
     printf("Il tuo indice di massa corporea corrisponde a: %f\n", BMI);

     printf("\nVALORI DEL BMI"
     "\nSottopeso:     meno di 18.5\n"
     "Normale:       tra 18.5 e 24.9\n"
     "Sovrappeso:    tra 25 e 29.9\n"
     "Obeso:         30 o oltre\n");

   }

    if (a != 1 && a != 2){
      return 0;
    }
}
