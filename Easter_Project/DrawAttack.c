/*
** DrawAttack.c for  in /home/regency
** 
** Made by IRICANIN Filip
** Login   <irican_f@etna-alternance.net>
** 
** Started on  Sun Apr 12 12:06:08 2015 IRICANIN Filip
** Last update Sun Apr 12 19:39:24 2015 IRICANIN Filip
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "my.h"
#include "my_hero.h"
#include "my_monster.h"

void	draw_sub_attack() 
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
      if (i == 0)
	scr.m[i] = IMG_Load("images/att1.png");
      else
	scr.m[i] = IMG_Load(img[i]);
    }
  for (i = 0; i < 3; i++)
    SDL_BlitSurface(scr.m[i], NULL, scr.s, &scr.pos[i]);
  SDL_Flip(scr.s);
}

void	set_attack(int *p)
{
  char		*att[2];
  char		*img[3];
  int		i;
  
  img[0] = "images/menu1.png";
  img[1] = "images/menu2.png";
  img[2] = "images/menu3.png";
  att[0] = "images/att1.png";
  att[1] = "images/att2.png";
  SDL_FreeSurface(scr.s);
  draw_player();
  for (i = 0; i < 3; i++)
    {
      if (i == 0)
	scr.m[i] = IMG_Load(att[(*p)]);
      else
	scr.m[i] = IMG_Load(img[i]);
    }
  for (i = 0; i < 3; i++)
    SDL_BlitSurface(scr.m[i], NULL, scr.s, &scr.pos[i]);
  SDL_Flip(scr.s);
}

void	select_attack(SDL_Event e, int *p, int *quit, int *MainQuit)
{
  if (e.key.keysym.sym == SDLK_UP)
    {
      ((--*p) < 0) ? ((*p = 1)) : (0);
      move_sound();
      set_attack(p);
    }
  else if (e.key.keysym.sym == SDLK_DOWN)
    {
      ((++*p) > 1) ? ((*p = 0)) : (0);
      move_sound();
      set_attack(p);
    }
  else if (e.key.keysym.sym == SDLK_ESCAPE)
    ++*quit;
  else if (e.key.keysym.sym == SDLK_RETURN)
    {
      accept_sound();
      use_attack(p, MainQuit);
      ++*quit;
    }
}

void	attack_menu(int *MainQuit) 
{
  int		p;
  int		quit;
  SDL_Event	e;
  
  p = 0;
  quit = 0;
  draw_sub_attack();
  while (!quit)
    {
      SDL_WaitEvent(&e);
      if (e.type == SDL_QUIT)
	exit(0);
      else if (e.type == SDL_KEYDOWN)
	select_attack(e, &p, &quit, MainQuit);
    }
  SDL_FreeSurface(scr.s);
  draw_rect();
}
