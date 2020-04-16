#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void printfile(char str[]){
    system("clear");
    char dir[50]="./ASCII/";
    printf("Nome file DOPO DOPO: %s\n",str);
    char c;
    strcat(dir, str);
    printf("Nome file: %s\n",dir);
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
    for (int i = 0; i<19; i++)
      {
        static char nome_file [40] = "Trivella[.].txt";
        printf("Nome file PRIMA: %s\n",nome_file);
        printf("Carattere 6: %c\n",nome_file[6]);
        nome_file[9] = i + 65;
        printf("Nome file DOPO: %s\n",nome_file);
        printf("Carattere 6: %c\n",nome_file[6]);
        printfile(nome_file);
      }
  }
