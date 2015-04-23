/*
** CombatMenu.c for  in /home/regency
** 
** Made by IRICANIN Filip
** Login   <irican_f@etna-alternance.net>
** 
** Started on  Sun Apr 12 12:00:03 2015 IRICANIN Filip
** Last update Sun Apr 12 19:38:23 2015 IRICANIN Filip
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "my.h"
#include "my_hero.h"
#include "my_monster.h"

void	set_color(int *k) 
{
  int	i;
  char	*img_s[3];
  char	*img[3];
  
  img[0] = "images/menu1.png";
  img[1] = "images/menu2.png";
  img[2] = "images/menu3.png";
  img_s[0] = "images/menu1_s.png";
  img_s[1] = "images/menu2_s.png";
  img_s[2] = "images/menu3_s.png";
  SDL_FreeSurface(scr.s);
  draw_player();
  for (i = 0; i < 3; i++)
    {
      if (i == (*k))
	scr.m[i] = IMG_Load(img_s[i]);
      else
	scr.m[i] = IMG_Load(img[i]);
    }
  for (i = 0; i < 3; i++)
    SDL_BlitSurface(scr.m[i], NULL, scr.s, &scr.pos[i]);
  SDL_Flip(scr.s);
}

void	select_cbt(SDL_Event e, int *k, int *quit)
{
  if (e.key.keysym.sym == SDLK_LEFT)
    {
      ((--*k) < 0) ? ((*k = 2)) : (0);
      move_sound();
      set_color(k);
    }
  else if (e.key.keysym.sym == SDLK_RIGHT)
    {
      ((++*k) > 2) ? ((*k = 0)) : (0);
      move_sound();
      set_color(k);
    }
  else if (e.key.keysym.sym == SDLK_RETURN)
    {
      accept_sound();
      ((*k) == 0) ? (attack_menu(quit)) : (0);
      ((*k) == 1) ? (magic_menu(quit)) : (0);
      ((*k) == 2) ? (item_menu()) : (0);
    }
}

void	draw_rect() 
{
  int	i;
  int	h;
  char	*img[3];
  
  img[0] = "images/menu1.png";
  img[1] = "images/menu2.png";
  img[2] = "images/menu3.png";
  SDL_FreeSurface(scr.s);
  SDL_EnableKeyRepeat(100, 100);
  draw_player();
  h = 150;
  for (i = 0; i < 3; i++)
    {
      scr.pos[i].x = 0 + (h * i);
      scr.pos[i].y = 600 - 150;
    }
  for (i = 0; i < 3; i++)
    {
      scr.m[i] = IMG_Load(img[i]);
      SDL_BlitSurface(scr.m[i], NULL, scr.s, &scr.pos[i]);
    }
  SDL_Flip(scr.s);
}

void	main_menu() 
{
  int		quit;
  int		k;
  SDL_Event	e;
  
  k = 0;
  quit = 0;
  scr.s = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
  define_stats();
  draw_rect();
  draw_player();
  battle_sound();
  while (!quit)
    {
      SDL_WaitEvent(&e);
      if (e.type == SDL_QUIT)
	exit(0);
      else if (e.type == SDL_KEYDOWN)
	select_cbt(e, &k, &quit);
    }
  Mix_FreeMusic(scr.battle);
  SDL_FreeSurface(scr.s);
  draw_menu();
}
