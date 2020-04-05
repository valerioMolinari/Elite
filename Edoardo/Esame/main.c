//
#include "gamelib.h"
void menu();

int main(void)
{
  initscr();
  //noecho();
  curs_set(FALSE);
  start_color();

  bool play = true;
  do
  {
    menu(&play);
  } while (play);
  printf("Grazie per aver giocato\n");
}
