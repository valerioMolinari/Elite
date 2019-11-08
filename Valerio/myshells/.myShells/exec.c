#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

void execBuild(char *fileName){
    char* compile = malloc((strlen(fileName)*3)+17);
    sprintf(compile, "gcc -o %s %s.c; ./%s\n", fileName, fileName, fileName);
    system(compile);
    free(compile);
}

void outBuild(char* fileName){
    char* compile = malloc((strlen(fileName)*2)+15);
    sprintf(compile, "gcc -o %s %s.c\n", fileName, fileName);
    system(compile);
    free(compile);
}


int main(int argc, char **argv){
    char c;
    char *fileName=NULL;
    optarg = " ";
    while((c=getopt(argc, argv, ":e:o:;"))!=-1){
        switch(c){
            case 'e':
                execBuild(optarg);
                break;
            case 'o':
                outBuild(optarg);
                break;
            case '?':
                printf("g: Illegal option \n"
                       "usage: g [-eo] [file without extension]\n");
                break;
        }
    }
    return 0;
}
