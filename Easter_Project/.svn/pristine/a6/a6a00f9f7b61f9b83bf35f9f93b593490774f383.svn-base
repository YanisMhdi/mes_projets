/*
** earthquake.c for  in /home/regency
** 
** Made by IRICANIN Filip
** Login   <irican_f@etna-alternance.net>
** 
** Started on  Sun Apr 12 12:13:51 2015 IRICANIN Filip
** Last update Sun Apr 12 19:43:25 2015 IRICANIN Filip
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

void	decoupe_earthquake(const int EARTHQUAKE_HEIGHT, 
			  const int EARTHQUAKE_WIDTH,
			  SDL_Rect earthquake[6],
			  int i)
{
  for (i = 0; i < 6; i++)
    {
      earthquake[i].x = 0;
      earthquake[i].y = EARTHQUAKE_HEIGHT * i;
      earthquake[i].w = EARTHQUAKE_WIDTH;
      earthquake[i].h = EARTHQUAKE_HEIGHT;
    }
}

void	earthquake_animation()
{
  int		i;
  const int	EARTHQUAKE_HEIGHT = 50;
  const int	EARTHQUAKE_WIDTH = 83;
  SDL_Surface	*img;
  SDL_Rect	earthquake[6];
  SDL_Rect	position;
  
  i = 0;
  position.y = hero.y - (40 * 5);
  position.x = hero.x;
  img = IMG_Load("images/Earthquake.png");
  decoupe_earthquake(EARTHQUAKE_HEIGHT, EARTHQUAKE_WIDTH, earthquake, i);
  
  while (i < 6)
    {	
      draw_rect();
      apply_surface(position.x, position.y, img, scr.s, &earthquake[i]);
      position.y += 40;
      i++;
      SDL_Flip(scr.s);
      usleep(80000);
      my_exit();
    }
  draw_rect();
}
