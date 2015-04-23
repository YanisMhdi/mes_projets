/*
** DrawItem.c for  in /home/regency
** 
** Made by IRICANIN Filip
** Login   <irican_f@etna-alternance.net>
** 
** Started on  Sun Apr 12 12:08:01 2015 IRICANIN Filip
** Last update Sun Apr 12 19:41:55 2015 IRICANIN Filip
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "my.h"
#include "my_hero.h"
#include "my_monster.h"

void	draw_item_count()
{
  char			str[5];
  TTF_Font		*plc;
  SDL_Surface		*ptn;
  SDL_Surface		*eth;
  SDL_Rect		pos;
  static SDL_Color	white = {255, 255, 255, 0};
  
  pos.x = 430;
  pos.y = 600 - 110;
  plc = TTF_OpenFont("PixelGameFont.ttf", 18);
  sprintf(str, "%d", hero.potion);
  ptn = TTF_RenderText_Blended(plc, str, white);
  SDL_BlitSurface(ptn, NULL, scr.s, &pos);
  sprintf(str, "%d", hero.ether);
  eth = TTF_RenderText_Blended(plc, str, white);
  pos.y += 35;
  SDL_BlitSurface(eth, NULL, scr.s, &pos);
}

void	draw_sub_item()
{
  char	*img[3];
  int	i;
  
  img[0] = "images/menu1.png";
  img[1] = "images/menu2.png";
  img[2] = "images/menu3.png";
  SDL_FreeSurface(scr.s);
  draw_player();
  for (i = 0; i < 3; i++) {
    if (i == 2)
      scr.m[i] = IMG_Load("images/item1.png");
    else
      scr.m[i] = IMG_Load(img[i]);
  }
  for (i = 0; i < 3; i++)
    SDL_BlitSurface(scr.m[i], NULL, scr.s, &scr.pos[i]);
  draw_item_count();
  SDL_Flip(scr.s);
}

void	set_item(int *p) 
{
  char	*item[2];
  char	*img[3];
  int	i;
  
  img[0] = "images/menu1.png";
  img[1] = "images/menu2.png";
  img[2] = "images/menu3.png";
  item[0] = "images/item1.png";
  item[1] = "images/item2.png";
  SDL_FreeSurface(scr.s);
  draw_player();
  for (i = 0; i < 3; i++)
    {
      if (i == 2)
	scr.m[i] = IMG_Load(item[(*p)]);
      else
	scr.m[i] = IMG_Load(img[i]);
    }
  for (i = 0; i < 3; i++)
    SDL_BlitSurface(scr.m[i], NULL, scr.s, &scr.pos[i]);
  draw_item_count();
  SDL_Flip(scr.s);
}

void	select_item(SDL_Event e, int *p, int *quit)
{
  if (e.key.keysym.sym == SDLK_UP)
    {
      ((--*p) < 0) ? ((*p = 1)) : (0);
      move_sound();
      set_item(p);
    }
  else if (e.key.keysym.sym == SDLK_DOWN)
    {
      ((++*p) > 1) ? ((*p = 0)) : (0);
      move_sound();
      set_item(p);
    }
  else if (e.key.keysym.sym == SDLK_ESCAPE)
    ++*quit;
  else if (e.key.keysym.sym == SDLK_RETURN)
    {
      accept_sound();
      use_item(p);
      ++*quit;
    }
}


void	item_menu()
{
  int		p;
  int		quit;
  SDL_Event	e;
  
  p = 0;
  quit = 0;	
  draw_sub_item();
  while (!quit)
    {
      SDL_WaitEvent(&e);
      if (e.type == SDL_QUIT)
	exit(0);
      else if (e.type == SDL_KEYDOWN)
	select_item(e, &p, &quit);
    }
  SDL_FreeSurface(scr.s);
  draw_rect();
}
