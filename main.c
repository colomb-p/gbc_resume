#include	<gb/gb.h>
#include	<stdio.h>
#include	"sprite.c"


#define		SCROLL_DELAY 500

int		scroll_down(int start_offset)
{
  printf("Down button pressed\n");
  delay(SCROLL_DELAY);
  return (start_offset);
}

int		scroll_up(int start_offset)
{
  printf("Up button pressed\n");
  delay(SCROLL_DELAY);
  return (start_offset);
}

void		main(void)
{
  int		(*ptr[0x81])(int);
  char		resume[16][128];
  int		start_offset;

  start_offset = 0;
  ptr[0x04] = scroll_up;
  ptr[0x08] = scroll_down;
  printf("Pierre-Loup Colombon Resume\n");
  while (1)
    start_offset = ptr[joypad()](start_offset);
}
