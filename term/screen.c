#include <sys/ioctl.h>
#include <termios.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>

unsigned short TERM_HEIGHT;
unsigned short TERM_WIDTH;
struct termios original_settings, new_settings;

//Binds variables `TERM_HEIGHT` and `TERM_WIDTH` to the size of the terminal, rescaling 
//automatically on receiving the SIGWINCH signal. See man page ioctl_tty(2)
void rescale_window(int sig)
{
  struct winsize w;
  ioctl(0, TIOCGWINSZ, &w);

  TERM_HEIGHT = w.ws_col;
  TERM_WIDTH = w.ws_row;
  printf("Recaled window to: %hux%hu\n", TERM_HEIGHT, TERM_WIDTH);
}

void init_screen()
{
  signal(SIGWINCH, rescale_window);
  if (tcgetattr(fileno(stdin), &original_settings) == 0)
  {
    puts("Successfully read original settings");
  }
  else
  {
    puts("Could not read original settings");
  }

  //Disable canonical mode, disabling echoing input to the screen and reading input chars immediately
  memcpy(&new_settings, &original_settings, sizeof(struct termios));
  new_settings.c_lflag &= ~(ECHO | ICANON);
  new_settings.c_cc[VTIME] = 0;
  new_settings.c_cc[VMIN] = 0;

  if (tcsetattr(fileno(stdin), TCSANOW, &new_settings) == 0)
  {
    puts("Successfully entered non-cannonical mode");
  }
  else
  {
    puts("Could not enter non-cannonical mode");
  }
}

void exit_screen()
{
  if (tcsetattr(fileno(stdin), TCSANOW, &original_settings) == 0)
  {
    puts("Successfully re-entered cannonical mode");
  }
  else
  {
    puts("Could not re-enter cannonical mode");
  }
}
