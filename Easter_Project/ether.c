#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "my.h"
#include "my_hero.h"
#include "my_monster.h"

void	decoupe_ether(SDL_Rect *ether)
{
  const int	ETHER_HEIGHT = 192;
  const int	ETHER_WIDTH = 192;
  int		i;
  int		x;
  int		y;
  
  x = 0;
  y = 0;
  for (i = 0; i < 15; i++)
    {
      ether[i].x = x;
      ether[i].y = y;
      ether[i].w = ETHER_WIDTH;
      ether[i].h = ETHER_HEIGHT;
      x += ETHER_WIDTH;
      
      if (i % 5 == 0)
	{
	  x = 0;
	  y += ETHER_HEIGHT;
	}
    }
}

void	ether_animation()
{
  int		i;
  SDL_Surface	*img;
  SDL_Rect	ether[15];

  i = 0;
  img = IMG_Load("images/Ether.png");
  decoupe_ether(ether);
  heal_sound();
  while (i < 15)
    {
      draw_rect();
      apply_surface((hero.x - 50), (hero.y - 45), img, scr.s, &ether[i]);
      SDL_Flip(scr.s);
      usleep(20000);
      i++;
      my_exit();
    }
  draw_rect();
}
