#include <stdio.h>

int main(){

  char cifrario[26];

  printf("Si inserisca il cifrario che si vuole utilizzare: \n");

  for (int i = 0; i < 26; i++){

    scanf("%c\n", cifrario[i]);

    if (isdigit(cifrario[i]) != 0 || isalnum(cifrario[i]) != 0){

      printf("L'elemento inserito non e' valido.\n");
      printf("Si prega di reinserire la lettera.\n");

    }else if (cifrario[i] == cifrario[i-1]){

      printf("Le lettere devo differire nel cifrario\n");

    }

  }

}
