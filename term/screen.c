#include <sys/ioctl.h>
#include <signal.h>
#include <stdio.h>

unsigned short TERM_HEIGHT;
unsigned short TERM_WIDTH;

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
}
