#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "my.h"
#include "my_hero.h"
#include "my_monster.h"

void	apply_surface(int x, int y, SDL_Surface* source, 
		      SDL_Surface* destination, SDL_Rect* clip)
{
  SDL_Rect	offset;
  
  offset.x = x;
  offset.y = y;
  
  SDL_BlitSurface(source, clip, destination, &offset);
}

void	my_exit(void)
{
  SDL_Event e;
  while (SDL_PollEvent(&e))
    {
      if (e.type == SDL_KEYDOWN)
	{
	  if (e.key.keysym.sym == SDLK_ESCAPE)
	    {
	      SDL_Quit();
	      exit(0);
	      break;
	    }
	  
	}
    }	
}

void	anim_doom(SDL_Rect doom[81])
{
  int		t;
  SDL_Surface	*img;
  
  t = 0;
  img = IMG_Load("images/explosion.png");
  draw_rect();
  explosion_sound();
  while (t < 81)
    {
      draw_rect();
      SDL_SetColorKey(img, SDL_SRCCOLORKEY,
		      SDL_MapRGB(img->format, 0, 255, 255));
      apply_surface(hero.x, hero.y, img, scr.s, &doom[t]);
      SDL_Flip(scr.s);
      t++;
      my_exit();
    }
  draw_rect();
}

void	doom_animation()
{
  const int	DOOM_WIDTH = 100;
  const int	DOOM_HEIGHT = 100;
  int		j;
  int		x;
  int		y;
  SDL_Rect	doom[81];
  
  x = 0;
  y = 0;
  for (j = 0; j < 81; j++)
    {
      doom[j].x = x;
      doom[j].y = y;
      doom[j].w = DOOM_WIDTH;
      doom[j].h = DOOM_HEIGHT;
      x += DOOM_WIDTH;
      
      if (j % 9 == 0)
	{
	  x = 0;
	  y += DOOM_HEIGHT;
	}
    }
  anim_doom(doom);
}
