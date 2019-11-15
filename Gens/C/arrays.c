#include<stdio.h>

int main(void){
  int a[10];

  for(int i=0; i<20; i++){
    printf("Element[%d]=%d\n", i+1, a[i]);
  }
}
