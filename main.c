#include <stdio.h>
#include <unistd.h>

#include "term/screen.h"
#include "snake/game.h"

#define UP_ARROW 0x41
#define UP_ARROW 0x42
#define RIGHT_ARROW 0x43
#define LEFT_ARROW 0x44

int main()
{
  init_screen();


  //int choice;
  //fputs("Choice: ", stdout);
  //choice = getchar();
  //printf("You selected %c\n", choice);

  unsigned char buffer[16];
  int num_read;

  for (;;)
  {
    num_read = read(stdin, buffer, 16); 

    if (num_read >= 3 && buffer[0] == 0x1b && buffer[1] == 0x5b)
    {
      if (buffer[2] == UP_ARROW)
      {
        puts("up arrow");
      }
      else if (buffer[2] == DOWN_ARROW)
      {
        puts("down arrow");
      }
        else if (buffer[2] == RIGHT_ARROW)
      {
        puts("right arrow");
      }
      else if (buffer[2] == LEFT_ARROW)
      {
        puts("left arrow");
      }
    }
  }

  //startgame_snake();
  exit_screen();

  return 0;
}
