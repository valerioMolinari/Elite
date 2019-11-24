#include <stdio.h>
#include <string.h>

//Trovare il valore più grande

int main(void) {

  int n;
  printf("Scrivere il numero di valore da immettere:\n");
  scanf("%d", &n);

  int valore;
  int valore1 = 0;
  for(int i = 0; i < n; i++){
    printf("Immettere valore:\n");
    scanf("%d", &valore);
    if(valore >= valore1){
      valore1 = valore;
    }
  }
  printf("Il valore più grande é: %d", valore1);
}
