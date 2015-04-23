/*
** libra.c for  in /home/regency
** 
** Made by IRICANIN Filip
** Login   <irican_f@etna-alternance.net>
** 
** Started on  Sun Apr 12 12:27:50 2015 IRICANIN Filip
** Last update Sun Apr 12 18:30:40 2015 IRICANIN Filip
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

void	write_hp()
{
  TTF_Font		*plc;
  SDL_Surface		*hp;
  SDL_Rect		pos;
  char			str[20];
  static SDL_Color	white = {255, 255, 255, 0};
  
  plc = TTF_OpenFont("PixelGameFont.ttf", 20);
  sprintf(str, "PV    %d/75", monster.pv);
  hp = TTF_RenderText_Blended(plc, str, white);
  pos.x = 50;
  pos.y = 65;
  SDL_BlitSurface(hp, NULL, scr.s, &pos);
}

void	write_mp()
{
  TTF_Font		*plc;
  SDL_Surface		*mp;
  SDL_Rect		pos;
  char			str[20];
  static SDL_Color	white = {255, 255, 255, 0};
  
  plc = TTF_OpenFont("PixelGameFont.ttf", 20);
  sprintf(str, "PM    %d/20", monster.pm);
  mp = TTF_RenderText_Blended(plc, str, white);
  pos.x = 50;
  pos.y = 95;
  SDL_BlitSurface(mp, NULL, scr.s, &pos);
}

int	draw_libra()
{
  TTF_Font		*plc;
  SDL_Surface		*name;
  SDL_Surface		*img;
  SDL_Rect		pos;
  static SDL_Color	white = {255, 255, 255, 0};
  
  pos.x = 0;
  pos.y = 0;
  img = IMG_Load("images/libra.png");
  SDL_BlitSurface(img, NULL, scr.s, &pos);
  pos.x = 10;
  pos.y = 10;
  plc = TTF_OpenFont("PixelGameFont.ttf", 20);
  name = TTF_RenderText_Blended(plc, monster.name, white);
  SDL_BlitSurface(name, NULL, scr.s, &pos);
  write_hp();
  write_mp();
  SDL_Flip(scr.s);
  sleep(3);
  return (0);
}
