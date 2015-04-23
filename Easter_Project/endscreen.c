#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "my.h"
#include "my_hero.h"
#include "my_monster.h"

void	defeat_sound()
{
  Mix_FreeMusic(scr.battle);
  scr.battle = Mix_LoadMUS("Sounds/Defeat.mp3");
  Mix_VolumeMusic(MIX_MAX_VOLUME - 5);
  Mix_PlayMusic(scr.battle, 1);
}

void	victory_sound()
{
  Mix_FreeMusic(scr.battle);
  scr.battle = Mix_LoadMUS("Sounds/Victory.mp3");
  Mix_VolumeMusic(MIX_MAX_VOLUME - 5);
  Mix_PlayMusic(scr.battle, 1);
}

void	victory_text()
{
  TTF_Font		*plc;
  SDL_Surface		*msg;
  static SDL_Color	gold = {255, 215, 0, 0};
  static SDL_Color	white = {255, 255, 255, 0};
  char			*str;
  
  victory_sound();
  str = "Felicitations ! Vous avez vaincu Sephiroth !";
  SDL_FillRect(scr.s, NULL, SDL_MapRGB(scr.s->format, 0, 0, 0));
  scr.pos[0].x = 80;
  scr.pos[0].y = 250;
  plc = TTF_OpenFont("PixelGameFont.ttf", 30);
  msg = TTF_RenderText_Blended(plc, str, gold);
  SDL_BlitSurface(msg, NULL, scr.s, &scr.pos[0]);
  
  scr.pos[0].x = 300;
  scr.pos[0].y = 300;
  plc = TTF_OpenFont("PixelGameFont.ttf", 18);
  msg = TTF_RenderText_Blended(plc, "Retour au menu principal", white);
  SDL_BlitSurface(msg, NULL, scr.s, &scr.pos[0]);
  SDL_Flip(scr.s);
}

void	defeat_text()
{
  TTF_Font		*plc;
  SDL_Surface		*msg;
  static SDL_Color	red = {255, 0, 0, 0};
  static SDL_Color	white = {255, 255, 255, 0};
  char			*str;
  
  defeat_sound();
  str = "Dommage ! Vous avez ete vaincu par Sephiroth !";
  SDL_FillRect(scr.s, NULL, SDL_MapRGB(scr.s->format, 0, 0, 0));
  scr.pos[0].x = 70;
  scr.pos[0].y = 250;
  plc = TTF_OpenFont("PixelGameFont.ttf", 30);
  msg = TTF_RenderText_Blended(plc, str, red);
  SDL_BlitSurface(msg, NULL, scr.s, &scr.pos[0]);
  
  scr.pos[0].x = 300;
  scr.pos[0].y = 300;
  plc = TTF_OpenFont("PixelGameFont.ttf", 18);
  msg = TTF_RenderText_Blended(plc, "Retour au menu principal", white);
  SDL_BlitSurface(msg, NULL, scr.s, &scr.pos[0]);
  SDL_Flip(scr.s); 
}

void	end_screen(int *MainQuit)
{
  SDL_Event	e;
  int		quit;
  
  quit = 0;
  (monster.pv <= 0) ? (victory_text()) : (defeat_text()); 
  while (!quit)
    {
      SDL_WaitEvent(&e);
      if (e.type == SDL_QUIT)
	exit(0);
      else if (e.type == SDL_KEYDOWN)
	{
	  if (e.key.keysym.sym == SDLK_RETURN)
	    {
	      quit++;
	      ++*MainQuit;
	    }
	}
    }
  SDL_FreeSurface(scr.s);
}
