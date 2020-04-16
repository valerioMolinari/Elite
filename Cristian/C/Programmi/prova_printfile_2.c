#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void red ()
  {
  printf("\033[1;31m");
  }

void yellow ()
  {
    printf("\033[1;33m");
  }

void green ()
  {
    printf("\033[1;32m");
  }

void blue ()
  {
    printf("\033[1;34m");
  }

void magenta ()
  {
  printf("\033[1;35m");
  }

void cyan ()
  {
    printf("\033[1;36m");
  }

void printfile(char str[]){
    system("clear");
    char dir[50]="./ASCII/";
    char c;
    strcat(dir, str);
    FILE *fors=fopen(dir, "r");
    while((c=getc(fors))!=EOF){
        printf("%c", c);
    }
    fclose(fors);
    sleep(1);
    system("clear");
}


int main ()
  {
    green();
    printfile("Ruspa.txt");
  }
