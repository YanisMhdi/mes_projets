#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "my.h"
#include "my_hero.h"
#include "my_monster.h"

void	decoupe_heal(SDL_Rect *heal)
{
  const int	HEAL_HEIGHT = 192;
  const int	HEAL_WIDTH = 192;
  int		i;
  int		x;
  int		y;
  
  x = 0;
  y = 0;
  for (i = 0; i < 25; i++)
    {
      heal[i].x = x;
      heal[i].y = y;
      heal[i].w = HEAL_WIDTH;
      heal[i].h = HEAL_HEIGHT;
      x += HEAL_WIDTH;
      
      if (i % 5 == 0)
	{
	  x = 0;
	  y += HEAL_HEIGHT;
	}
    }
}

void	heal_animation()
{
  int		i;
  SDL_Surface	*img_heal;
  SDL_Rect	heal[25];
  
  img_heal = IMG_Load("images/health.png");
  decoupe_heal(heal);
  i = 0;
  heal_sound();
  while (i < 25)
    {
      draw_rect();
      apply_surface((hero.x - 50), (hero.y - 45), img_heal, scr.s, &heal[i]);
      SDL_Flip(scr.s);
      i++;
      my_exit();
    }
}
