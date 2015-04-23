/*
** hero.c for  in /home/regency
** 
** Made by IRICANIN Filip
** Login   <irican_f@etna-alternance.net>
** 
** Started on  Sun Apr 12 12:24:10 2015 IRICANIN Filip
** Last update Mon Apr 13 09:41:12 2015 IRICANIN Filip
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "my.h"
#include "my_hero.h"
#include "my_monster.h"


void	set_hero_attack(SDL_Rect knight_attack[2])
{
  const int	HERO_WIDTH = 90;
  const int	HERO_HEIGHT = 90;
  int		i;
  int		x;
  int		y;
  
  x = HERO_WIDTH * 2;
  y = 90;
  for (i = 0; i < 2; i++)
    {
      knight_attack[i].x = x;
      knight_attack[i].y = y;
      knight_attack[i].w = HERO_WIDTH;
      knight_attack[i].h = HERO_HEIGHT;
      x = 0;
      y = HERO_HEIGHT * 2;
    }
}

void	set_move(SDL_Rect knight[3])
{
  const int	HERO_WIDTH = 90;
  const int	HERO_HEIGHT = 90;
  int		i;
  int		x;
  int		y;
  
  x = HERO_WIDTH * 2;
  y = 0;
  for (i = 0; i < 3; i++)
    {
      knight[i].x = x;
      knight[i].y = y;
      knight[i].w = HERO_WIDTH;
      knight[i].h = HERO_HEIGHT;
      x += HERO_WIDTH;
    }
}

void	move_forward(SDL_Surface *img, SDL_Rect knight[3])
{
  SDL_Rect	pos;
  int		i;
  
  pos.x = hero.x;
  pos.y = hero.y;
  while (pos.x > monster.x + 200)
    {
      for (i = 0; i < 3; i++)
	{
	  pos.x -= 10;
	  draw_rect();
	  SDL_SetColorKey(img, SDL_SRCCOLORKEY,
			  SDL_MapRGB(img->format, 255, 255, 255));
	  apply_surface(pos.x, pos.y, img, scr.s, &knight[i]);
	  SDL_Flip(scr.s);
	}
    }
}

void	move_back(SDL_Surface *img, SDL_Rect knight[3])
{
  SDL_Rect	pos;
  int		i;
  
  pos.x = monster.x + 180;
  pos.y = monster.y + 70;
  while (pos.x < hero.x)
    {
      for (i = 2; i >= 0; i--)
	{
	  pos.x += 10;
	  draw_rect();
	  SDL_SetColorKey(img, SDL_SRCCOLORKEY,
			  SDL_MapRGB(img->format, 255, 255, 255));
	  apply_surface(pos.x, pos.y, img, scr.s, &knight[i]);
	  SDL_Flip(scr.s);
	}
    }
  scr.player = 1;
  SDL_FreeSurface(scr.s);
  draw_rect();
}

void	move_animation()
{
  int		i;
  int		j;
  SDL_Rect	knight[3];
  SDL_Rect	knight_attack[2];
  SDL_Surface	*img;
  
  img = IMG_Load("images/darkknight.png");
  set_move(knight);
  set_hero_attack(knight_attack);
  move_forward(img, knight);
  for (j = 0; j < 4; j++)
    {
      attack_sound();
      for (i = 0; i < 2; i++)
	{
	  draw_rect();
	  SDL_SetColorKey(img, SDL_SRCCOLORKEY,
			  SDL_MapRGB(img->format, 255, 255, 255));
	  apply_surface(monster.x + 180, monster.y + 70, img,
			scr.s, &knight_attack[i]);
	  SDL_Flip(scr.s);
	  usleep(50000);
	} 
    }
  move_back(img, knight);
}
