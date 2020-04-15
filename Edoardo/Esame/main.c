//
#include "gamelib.h"
void menu();
void game_over();

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
  game_over();
  endwin();
}
