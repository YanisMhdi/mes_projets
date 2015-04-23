/*
** DrawMagic.c for  in /home/regency
** 
** Made by IRICANIN Filip
** Login   <irican_f@etna-alternance.net>
** 
** Started on  Sun Apr 12 12:10:36 2015 IRICANIN Filip
** Last update Sun Apr 12 19:42:45 2015 IRICANIN Filip
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "my.h"
#include "my_hero.h"
#include "my_monster.h"

void	draw_sub_mag()
{
  char	*img[3];
  int	i;

  img[0] = "images/menu1.png";
  img[1] = "images/menu2.png";
  img[2] = "images/menu3.png";
  draw_rect();
  draw_player();
  for (i = 0; i < 3; i++)
    {
      if (i == 1)
	scr.m[i] = IMG_Load("images/mag1.png");
      else
	scr.m[i] = IMG_Load(img[i]);
    }
  for (i = 0; i < 3; i++)
    SDL_BlitSurface(scr.m[i], NULL, scr.s, &scr.pos[i]);
  SDL_Flip(scr.s);
}

void	set_magie(int *p)
{
  char	*magie[4];
  char	*img[3];
  int	i;
  
  img[0] = "images/menu1.png";
  img[1] = "images/menu2.png";
  img[2] = "images/menu3.png";
  magie[0] = "images/mag1.png";
  magie[1] = "images/mag2.png";
  magie[2] = "images/mag3.png";
  magie[3] = "images/mag4.png";
  SDL_FreeSurface(scr.s);
  draw_player();
  for (i = 0; i < 3; i++)
    {
      if (i == 1)
	scr.m[i] = IMG_Load(magie[(*p)]);
      else
	scr.m[i] = IMG_Load(img[i]);
    }
  for (i = 0; i < 3; i++)
    SDL_BlitSurface(scr.m[i], NULL, scr.s, &scr.pos[i]);
  SDL_Flip(scr.s);
}

void	select_mag(SDL_Event e, int *p, int *quit, int *MainQuit)
{
  if (e.key.keysym.sym == SDLK_UP)
    {
      ((--*p) < 0) ? ((*p = 3)) : (0);
      move_sound();
      set_magie(p);
    }
  else if (e.key.keysym.sym == SDLK_DOWN)
    {
      ((++*p) > 3) ? ((*p = 0)) : (0);
      move_sound();
      set_magie(p);
    }
  else if (e.key.keysym.sym == SDLK_ESCAPE)
    ++*quit;
  else if (e.key.keysym.sym == SDLK_RETURN)
    {
      accept_sound();
      use_magic(p, MainQuit);
      ++*quit;
    }
}

void	magic_menu(int *MainQuit)
{
  int		p;
  int		quit;
  SDL_Event	e;
  
  p = 0;
  quit = 0;
  draw_sub_mag();
  while (!quit)
    {
      SDL_WaitEvent(&e);
      if (e.type == SDL_QUIT)
	exit(0);
      else if (e.type == SDL_KEYDOWN)
	select_mag(e, &p, &quit, MainQuit);
    }
  SDL_FreeSurface(scr.s);
  draw_rect();
}
