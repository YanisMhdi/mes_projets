#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "my.h"
#include "my_hero.h"
#include "my_monster.h"

void	decoupebite(SDL_Rect bite[4])
{
  bite[3].x = 800;
  bite[3].y = 0;
  bite[3].w = 130;
  bite[3].h = 192;
  
  bite[2].x = 660;
  bite[2].y = 0;
  bite[2].w = 180;
  bite[2].x = 192;
  
  bite[1].x = 510;
  bite[1].y = 0;
  bite[1].w = 130;
  bite[1].h = 192;
  
  bite[0].x = 0;
  bite[0].y = 192;
  bite[0].w = 110;
  bite[0].h = 192;
}

void	bite_animation()
{
  int		i;
  int		j;
  SDL_Surface	*img;
  SDL_Rect	bite[4];
  
  i = 0;
  j = 0;
  img = IMG_Load("images/Crunch.png");
  decoupebite(bite);
  while (j < 6)
    {
      draw_rect();
      apply_surface(hero.x - 20, hero.y - 55, img, scr.s, &bite[i]);
      i++;
      if (i > 3)
	i = 0;
      j++;
      usleep(100000);
      SDL_Flip(scr.s);
      my_exit();
    }
  draw_rect();
}
