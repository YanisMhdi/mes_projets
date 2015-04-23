/*
** thunder.c for  in /home/regency
** 
** Made by IRICANIN Filip
** Login   <irican_f@etna-alternance.net>
** 
** Started on  Sun Apr 12 12:40:41 2015 IRICANIN Filip
** Last update Sun Apr 12 18:46:27 2015 IRICANIN Filip
*/

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


void	decoupe_thunder(SDL_Rect thunder[3])
{
  thunder[0].x = 641;
  thunder[0].y = 0;
  thunder[0].w = 40;
  thunder[0].h = 142;
  
  thunder[1].x = 811;
  thunder[1].y = 0;
  thunder[1].w = 89;
  thunder[1].h = 181;

  thunder[2].x = 28;
  thunder[2].y = 200;
  thunder[2].w = 102;
  thunder[2].h = 175;	
}

void	anim_thunder(SDL_Surface *img_thunder, SDL_Rect thunder[3]) 
{
  int	i;
  int	j;
  
  i = 0;
  j = 0;
  thunder_sound();
  while (j < 5)
    {
      draw_rect();
      apply_surface(monster.x + 60, monster.y - 20,
		    img_thunder, scr.s, &thunder[i]);
      SDL_Flip(scr.s);
      i++;
      
      if (i == 3)
	{
	  i = 0;
	  j++;
	}
      my_exit();
    }
}

void thunder_animation()
{
  SDL_Surface	*img_thunder;
  SDL_Rect	thunder[3];
  
  img_thunder = IMG_Load("images/thunder.png");
  decoupe_thunder(thunder);
  anim_thunder(img_thunder, thunder);
  SDL_FreeSurface(scr.s);
  draw_rect();
}
