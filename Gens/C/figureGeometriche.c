#include <stdio.h>

//Si realizzi un programma in linguaggio C che legga un numero intero N e
// visualizzi un quadrato di asterischi di lato N (vedi esempio con N = 5).
//Si realizzi una variante del programma per visualizzare solo i lati del quadrato (vedi esempio con N = 5).

void quad(int base, int alt);
void perimetro(int base, int alt);
void triangR(int base, int alt);
void blend(int base, int alt);
int main(void) {

  int alt, base, scelta;
  printf("Immetti base e altezza: \n");
  scanf("%d", &base);
  scanf("%d", &alt);

  printf("scegli arte:\n");
  scanf("%d", &scelta );

  switch (scelta) {
    case 1: quad(base, alt);
      break;
    case 2: perimetro(base, alt);
      break;
    case 3:triangR(base, alt);
      break;
    case 4:blend(base, alt);
      break;
  }

}



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

void triangR(int base, int alt){
  int x=1;
  for(int i=1; i<=alt; i++){

    for(int i=0; i<x; i++){
      printf("* " );
    }
    printf("\n" );
    x++;
  }
}

void blend(int base,int alt){
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
