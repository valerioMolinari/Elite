#include<stdio.h>

int main (void){
  int age;

  printf("inserisci età:");
  scanf("%d",&age );

  if(age>=18) {
      printf("2 minuti e andiamo a puttane!\n" );
  }else if(age>=1 && age<18){
      printf("potresti andare a lloret de mar per il momento!\n");
  }else {
    printf("sei nel mondo dei puffi ancora\n" );

 }
  return 0;
}
