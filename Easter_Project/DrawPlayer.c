#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "my.h"
#include "my_hero.h"
#include "my_monster.h"

void	draw_player()
{
  SDL_Surface	*info;
  SDL_Surface	*bg;
  SDL_Rect	pos;
  
  info = IMG_Load("images/info.png");
  bg = IMG_Load("images/background.png");
  pos.x = 800 - 350;
  pos.y = 600 - 150;
  SDL_BlitSurface(info, NULL, scr.s, &pos);
  pos.x = 0;
  pos.y = 0;
  SDL_BlitSurface(bg, NULL, scr.s, &pos);
  draw_player_stats();
  (scr.player) ? (draw_player_model()) : (0);
  draw_ennemy_model();
  SDL_Flip(scr.s);
}

void	draw_player_stats()
{
  char			str[20];
  TTF_Font*		plc;
  SDL_Surface*		stat;
  SDL_Rect		pos;
  static SDL_Color	white = {255, 255, 255, 0};
  
  pos.x = 460;
  pos.y = 600 - 140;
  plc = TTF_OpenFont("PixelGameFont.ttf", 20);
  stat = TTF_RenderText_Blended(plc, hero.name, white);
  SDL_BlitSurface(stat, NULL, scr.s, &pos);
  sprintf(str, "PV    %d/%d", hero.pv, hero.pvmax);
  stat = TTF_RenderText_Blended(plc, str, white);
  pos.x = 800 - 250;
  pos.y = 600 - 95;
  SDL_BlitSurface(stat, NULL, scr.s, &pos);
  sprintf(str, "PM    %d/30", hero.pm);
  stat = TTF_RenderText_Blended(plc, str, white);
  pos.y += 30;
  SDL_BlitSurface(stat, NULL, scr.s, &pos);
}

void	draw_player_model()
{
  SDL_Surface	*img;
  SDL_Rect	player;
  
  img = IMG_Load("images/darkknight.png");
  player.x = 90;
  player.y = 0;
  player.w = 90;
  player.h = 90;
  SDL_SetColorKey(img, SDL_SRCCOLORKEY, SDL_MapRGB(img->format, 255, 255, 255));
  apply_surface(hero.x, hero.y, img, scr.s, &player);
}

void	draw_ennemy_model()
{
  SDL_Surface	*img;
  SDL_Rect	ene;
  
  img = IMG_Load("images/Ennemis.png");
  ene.x = 0;
  ene.y = 0;
  ene.w = 200;
  ene.h = 200;
  apply_surface(monster.x, monster.y, img, scr.s, &ene);
}

void	define_stats()
{
  hero.name = "Regency";
  hero.pv = 100;
  hero.pm = 30;
  hero.pvmax = 100;
  hero.potion = 5;
  hero.ether = 5;
  hero.x = 600;
  hero.y = 250;
  monster.name = "Sephiroth";
  monster.pv = 75;
  monster.pm = 20;
  monster.x = 70;
  monster.y = 180;
  scr.player = 1;
}
