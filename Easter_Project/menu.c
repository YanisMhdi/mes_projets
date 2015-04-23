#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "my.h"
#include "my_hero.h"

void	set_select(int *k)
{
  int			i;
  TTF_Font		*plc;
  static SDL_Color	white = {255, 255, 255, 0};
  static SDL_Color	gold = {255, 215, 0, 0};
  static char		*txt[3] = {"Quitter", "Options", "Jouer"};
  static SDL_Rect	bg = {0, 0, 0, 0};
  SDL_Surface		*img;
  
  SDL_FillRect(scr.s, NULL, SDL_MapRGB(scr.s->format, 0, 0, 0));
  img = IMG_Load("images/mainbg.jpg");
  SDL_BlitSurface(img, NULL, scr.s, &bg);
  plc = TTF_OpenFont("PixelGameFont.ttf", 20);
  for (i = 0; i < 3; i++)
    {
      if (i == (*k))
	scr.m[i] = TTF_RenderText_Blended(plc, txt[i], white);
      else
	scr.m[i] = TTF_RenderText_Blended(plc, txt[i], gold);
    }
  for (i = 0; i < 3; i++)
    SDL_BlitSurface(scr.m[i], NULL, scr.s, &scr.pos[i]);
  SDL_Flip(scr.s);
}

void	main_select(SDL_Event e, int *k)
{
  if (e.key.keysym.sym == SDLK_DOWN)
    {
      move_sound();
      ((*k -= 1) < 0) ? ((*k = 2)) : (0);
    }
  else if (e.key.keysym.sym == SDLK_UP)
    {
      move_sound();
      ((*k += 1) > 2) ? ((*k = 0)) : (0);
    }
  else if (e.key.keysym.sym == SDLK_RETURN)
    {
      accept_sound();
      ((*k) == 2) ? (main_menu()) : (0);
      ((*k) == 0) ? (exit(0)) : (0);
    }
}

void	draw_menu()
{
  int			i;
  int			h;
  static char		*txt[3] = {"Quitter", "Options", "Jouer"};
  TTF_Font		*plc;
  SDL_Color		white = {255, 255, 255, 0};
  static SDL_Surface	*img;
  static SDL_Rect	bg = {0, 0, 0, 0};
  
  SDL_FillRect(scr.s, NULL, SDL_MapRGB(scr.s->format, 0, 0, 0));
  SDL_EnableKeyRepeat(100, 100);
  img = IMG_Load("images/mainbg.jpg");
  SDL_BlitSurface(img, NULL, scr.s, &bg);
  plc = TTF_OpenFont("PixelGameFont.ttf", 20);
  h = 70;
  for (i = 1; i < 4; i++)
    {
      scr.pos[i - 1].x = ((800 / 2)) - (30);
      scr.pos[i - 1].y = 400 - (h * i);
    }
  for (i = 0; i < 3; i++)
    {
      scr.m[i] = TTF_RenderText_Blended(plc, txt[i], white);
      SDL_BlitSurface(scr.m[i], NULL, scr.s, &scr.pos[i]);
    }
  SDL_Flip(scr.s);
}

void	game()
{
  int		quit;
  int		k;
  SDL_Event	e;
  
  k = 2;
  quit = 0;
  TTF_Init();
  scr.s = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
  draw_menu();
  while (!quit)
    {
      SDL_WaitEvent(&e);
      if (e.type == SDL_QUIT)
	quit++;
      else if (e.type == SDL_KEYDOWN)
	main_select(e, &k);
      set_select(&k);
    }
  SDL_FreeSurface(scr.s);
  SDL_Quit();
}
