/*
** slash.c for  in /home/regency
** 
** Made by IRICANIN Filip
** Login   <irican_f@etna-alternance.net>
** 
** Started on  Sun Apr 12 12:39:13 2015 IRICANIN Filip
** Last update Sun Apr 12 20:28:18 2015 IRICANIN Filip
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <unistd.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "my.h"
#include "my_hero.h"
#include "my_monster.h"


void	attack_sound()
{
  scr.musique = Mix_LoadWAV("Sounds/Attack.wav");
  Mix_VolumeChunk(scr.musique, MIX_MAX_VOLUME);
  Mix_PlayChannel(2, scr.musique, 0);
}

void	anim_slash(SDL_Surface *img_slash,
		  SDL_Rect slash,
		  SDL_Rect position,
		  int i)
{
  slash_sound();
  while (position.x > monster.x + 20)
    {
      draw_rect();
      apply_surface(position.x, hero.y, img_slash, scr.s, &slash);
      if (position.x > 0)
	{
	  position.x -= 60;
	  i++;
	}
      SDL_Flip(scr.s);
      usleep(20000);
      my_exit();
    }
}

void	slash_animation()
{
  int		i;
  SDL_Surface*	img_slash;
  SDL_Rect	slash;
  SDL_Rect	position;
  
  i = 0;
  position.x = hero.x - 100;
  img_slash = IMG_Load("images/Slash.png");
  slash.x = 0;
  slash.y = 0;
  slash.w = 150;
  slash.h = 150;
  anim_slash(img_slash, slash, position, i);
  SDL_FreeSurface(scr.s);
  draw_rect();
}
