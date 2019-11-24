#include <stdio.h>

void quad(int base, int alt);
void perimetro(int base, int alt);
void triangR1(int base, int alt);
void triangR2(int base, int alt);
int main(void) {

  int alt, base, scelta;
  printf("Immetti base e altezza: \n");
  scanf("%d", &base);
  scanf("%d", &alt);

  printf("Scegli tra:\n 1: Quadrato\n 2: Perimetro\n 3: Triangolo Rettangolo1\n 4: Triangolo Rettangolo2\n");
  scanf("%d", &scelta );

  switch (scelta) {
    case 1: quad(base, alt);
      break;
    case 2: perimetro(base, alt);
      break;
    case 3: triangR1(base, alt);
      break;
    case 4: triangR2(base, alt);
      break;
  }

}

//Dichiarazione funzioni

//funzione quadrato
void quad(int base, int alt) {
    int x;
    for(int i=0;i<alt;i++){
      x=0;
      while(x<base){
        printf("*" );
        x++;
      }
      printf("\n");
    }
}

//funzione perimetro
void perimetro(int base, int alt){
  for(int i=1; i<=alt; i++){
    if(i==1||i==alt){
      for(int i=1;  i<=base;i++){
        printf("* " );
      }
    }else{
      for(int i=1;  i<=base;i++){
        if(i==1||i==base){
          printf("* " );
        }else{
          printf("  " );
        }
      }
    }
    printf("\n" );
  }
}

//funzione triangolo Rettangolo1
void triangR1(int base, int alt){
  int x=1;
  for(int i=1; i<=alt; i++){
    for(int i=0; i<x; i++){
      printf("* " );
    }
    printf("\n" );
    x++;
  }
}

//funzione triangolo Rettangolo2
void triangR2(int base,int alt){
  int x=1;
  for(int i=1; i<=alt; i++){
    for(int i=0; i<base; i++){
      if(i<x){
        printf("* " );
      }else{
        printf("+ " );
      }
    }
    x++;
    printf("\n" );
  }
}
