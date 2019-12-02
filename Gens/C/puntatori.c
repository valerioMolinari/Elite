#include <stdio.h>
#include<stdlib.h>

int main() {

short int a[4]= {1,3,[3]=1};
int *p = (int*) a;

printf("*p is equal to %d\n", *a); //*p is equal to 1
printf("*p == 0 %d\n", *p== 0); //*p == 0 0
printf("p == a %d\n", p == a); //p == a 1
printf("*(a+2)= %d\n", *(a+2) == 0); //*(a+2)= 1
printf("*p == 65536 %d\n", *(p+1) == 65536); //*p == 65536 1
printf("&a[3] > (p+1) %d\n", &a[3]> (p+1)); //&a[3] > (p+1) 1
printf("%ld\n", (a+2) - &a[0]); //2
printf("%d\n", ((int) (a+2)) - (int) (&a[0]) ); //4
}
