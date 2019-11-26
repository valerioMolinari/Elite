#include <stdio.h>

int main(void) {

  double introito;
  double percentuale;
  double paga_settimanale[] = {'\0'};
  int a; // quanti agenti hanno lavorato
  double contatore[a + 1];

  printf("Quanti agenti hanno lavorato oggi?\n");
  scanf("%d", &a);
  for(int x = 0; x < a; ++x){

    printf("Inserisci il tuo introito lordo: \n");
    scanf("%lf",&introito);

    percentuale = (introito * 9) /100; // percentuale che prende l'agente in base a quanto a venduto
    paga_settimanale[x] = 200 + percentuale;
  }
  for(int y = 0; y < a; ++y){
    contatore[y] = paga_settimanale[y];
    printf("Paga settimanale per ogni agente: %.2lf\n", contatore[y]);
  }
}
