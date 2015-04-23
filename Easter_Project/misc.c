#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "my.h"
#include "my_hero.h"
#include "my_monster.h"

void	write_hero_damage(int dmg)
{
  char			str[3];
  TTF_Font		*plc;
  SDL_Surface		*damage;
  SDL_Rect		pos;
  static SDL_Color	red = {255, 0, 0, 0};
  
  pos.x = monster.x + 100;
  pos.y = monster.y - 10;
  plc = TTF_OpenFont("PixelGameFont.ttf", 20);
  sprintf(str, "%d", dmg);
  damage = TTF_RenderText_Blended(plc, str, red);
  SDL_BlitSurface(damage, NULL, scr.s, &pos);
  SDL_Flip(scr.s);
}

void	write_ennemy_damage(int dmg)
{
  char			str[3];
  TTF_Font		*plc;
  SDL_Surface		*damage;
  SDL_Rect		pos;
  static SDL_Color	red = {255, 0, 0, 0};
  
  pos.x = hero.x + 30;
  pos.y = hero.y - 30;
  plc = TTF_OpenFont("PixelGameFont.ttf", 20);
  sprintf(str, "%d", dmg);
  damage = TTF_RenderText_Blended(plc, str, red);
  SDL_BlitSurface(damage, NULL, scr.s, &pos);
  SDL_Flip(scr.s);
}

void	write_hero_heal(int dmg)
{
  char			str[3];
  TTF_Font		*plc;
  SDL_Surface		*heal;
  SDL_Rect		pos;
  static SDL_Color	green = {0, 255, 0, 0};
  
  pos.x = hero.x + 30;
  pos.y = hero.y - 30;
  plc = TTF_OpenFont("PixelGameFont.ttf", 20);
  sprintf(str, "%d", dmg);
  heal = TTF_RenderText_Blended(plc, str, green);
  SDL_BlitSurface(heal, NULL, scr.s, &pos);
  SDL_Flip(scr.s);
}

void	write_hero_ether(int dmg)
{
  char			str[3];
  TTF_Font		*plc;
  SDL_Surface		*ether;
  SDL_Rect		pos;
  static SDL_Color	green = {0, 0, 255, 0};
  
  pos.x = hero.x + 30;
  pos.y = hero.y - 30;
  plc = TTF_OpenFont("PixelGameFont.ttf", 20);
  sprintf(str, "%d", dmg);
  ether = TTF_RenderText_Blended(plc, str, green);
  SDL_BlitSurface(ether, NULL, scr.s, &pos);
  SDL_Flip(scr.s);
}

void	write_ennemy_ether(int dmg)
{
  char			str[3];
  TTF_Font		*plc;
  SDL_Surface		*ether;
  SDL_Rect		pos;
  static SDL_Color	green = {0, 0, 255, 0};
  
  pos.x = monster.x + 100;
  pos.y = monster.y - 10;
  plc = TTF_OpenFont("PixelGameFont.ttf", 20);
  sprintf(str, "%d", dmg);
  ether = TTF_RenderText_Blended(plc, str, green);
  SDL_BlitSurface(ether, NULL, scr.s, &pos);
  SDL_Flip(scr.s);
}

void	write_critical()
{
  TTF_Font		*plc;
  SDL_Surface		*damage;
  SDL_Rect		pos;
  static SDL_Color	red = {255, 0, 0, 0};
  
  pos.x = monster.x + 50;
  pos.y = monster.y - 30;
  plc = TTF_OpenFont("PixelGameFont.ttf", 20);
  damage = TTF_RenderText_Blended(plc, "CRITICAL HIT", red);
  SDL_BlitSurface(damage, NULL, scr.s, &pos);
  SDL_Flip(scr.s);
}
