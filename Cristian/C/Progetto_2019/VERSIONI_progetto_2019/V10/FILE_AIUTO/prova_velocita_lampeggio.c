#include <stdio.h>
#include <stdlib.h>
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

void print_gameover(void)
 {
   printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
         "                             ***************************************************************                            ",
         "                             **  ####   #   #     # #####     ###  #       # ##### #####  **                            ",
         "                             ** #      # #  ##   ## #        #   #  #     #  #     #    # **                            ",
         "                             ** #  ## #   # # # # # #####    #   #   #   #   ##### #####  **                            ",
         "                             ** #   # ##### #  #  # #        #   #    # #    #     #  #   **                            ",
         "                             **  #### #   # #     # #####     ###      #     ##### #   #  **                            ",
         "                             ***************************************************************                            ");
 }




int main ()
  {
    for (int a=1; a<=10; a++)
      {
        if (a%2 == 0)
          red();
        else
          yellow();
        print_gameover();
        usleep(500000);
        system("clear");
      }

    sleep(3);

    for (int a=1; a<=10; a++)
      {
        if (a%2 == 0)
          red();
        else
          yellow();
        print_gameover();
        sleep(1);
        system("clear");
      }
  }
