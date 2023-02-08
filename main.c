#include <stdio.h>

#include "term/screen.h"
#include "snake/game.h"

int main()
{
  int choice;

  fputs("Choice: ", stdout);
  choice = getchar();
  printf("You selected %c\n", choice);

  startgame_snake();

  return 0;
}
