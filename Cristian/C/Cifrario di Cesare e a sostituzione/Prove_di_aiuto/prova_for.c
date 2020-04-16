#include <stdio.h>
#include <stdlib.h>

int b=0, i=0;

int main () {

        for (i=0; i<5; i++)
          {
            for(b=0; b<10; b++)
                printf("Sono dentro al 2° FOR. [I] vale: %d; [B] vale: %d\n",i,b);
            printf("Sono dentro al 1° FOR. [I] vale: %d; [B] vale: %d\n",i,b);
          }
        printf("Sono fuori dei FOR. [I] vale: %d; [B] vale: %d\n",i,b);
}
