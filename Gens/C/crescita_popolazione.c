#include <stdio.h>
#include <string.h>

//Crescita della popolazione mondiale
//aumento popolazione mondiale 1,1% all'anno
//attuale popolazione mondiale circa 7,7 miliardi
//Scrivete un programma che calcoli la crescita della popolazione mondiale ogni anno per i prossimi 75 anni

int main(void) {

  int x = 75; // anno finale
  int anno = 0;
  float tasso = 1.1;
  float popolazione = 7.7;
  float totpopolazione;
  float aumento;

system("clear");

  printf("Crescita della popolazione mondiale\n");
  printf("Attuale popolazione mondiale: 7.7 mld\nAumento annuale: 1.1 percento\n");
  printf("\n%3s%26s%22s\n", "Anno","Popolazione in mld","Aumento in mln");

  for(int i = 0; i < x; i++){
    anno++;
    aumento = (popolazione * tasso) / 100;
    totpopolazione = popolazione + aumento;
    popolazione = totpopolazione;
    printf("%2d%20.3f%30.3f\n", anno, totpopolazione, aumento);
  }
}
