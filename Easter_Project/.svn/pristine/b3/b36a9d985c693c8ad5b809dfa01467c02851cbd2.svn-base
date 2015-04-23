/*
** fireball.c for  in /home/regency
** 
** Made by IRICANIN Filip
** Login   <irican_f@etna-alternance.net>
** 
** Started on  Sun Apr 12 12:18:06 2015 IRICANIN Filip
** Last update Sun Apr 12 19:45:44 2015 IRICANIN Filip
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "my.h"
#include "my_hero.h"
#include "my_monster.h"

void	decoupecatfire(SDL_Rect fire[4])
{
  fire[3].x = 0;
  fire[3].y = 100;
  fire[3].h = 40;
  fire[3].w = 55;
  
  fire[2].x = 70;
  fire[2].y = 100;
  fire[2].h = 40;
  fire[2].w = 50;
  
  fire[1].x = 130;
  fire[1].y = 100;
  fire[1].h = 40;
  fire[1].w = 43;
  
  fire[0].x = 175;
  fire[0].y = 100;
  fire[0].h = 40;
  fire[0].w = 50;
}

void	anim_fireball(SDL_Surface *img_fire,
		     SDL_Surface *img_explose,
		     SDL_Rect fire[4],
		     SDL_Rect explose[12])
{
  int		i;
  SDL_Rect	pos;
 
  i = 3;
  pos.x = hero.x;
  pos.y = hero.y + 45;
  while (pos.x > monster.x + 100) {
    draw_rect();
    apply_surface(pos.x, pos.y, img_fire, scr.s, &fire[i]);
    SDL_Flip(scr.s);
    i--;
    pos.x -= 30;
    (i == 0) ? (i = 3) : (0);
  }
  explosion_sound();
  for (i = 0; i < 12; i++) {
    draw_rect();
    apply_surface(pos.x, pos.y, img_explose, scr.s, &explose[i]);
    SDL_Flip(scr.s);
  }
}

void boucle_explose(SDL_Rect explose[12],
		    const int EXPLOSE_WIDTH,
		    const int EXPLOSE_HEIGHT)
{
  int	x;
  int	y;
  int	j;
  
  x = 0;
  y = 0;
  for (j = 0; j < 12; j++)
    {
      explose[j].x = x;
      explose[j].y = y;
      explose[j].w = EXPLOSE_WIDTH;
      explose[j].h = EXPLOSE_HEIGHT;
      x += EXPLOSE_WIDTH;
      
      if (j % 3 == 0)
	{
	  x = 0;
	  y += EXPLOSE_HEIGHT;
	}
    }
}

void	fire_animation()
{
  const int	EXPLOSE_WIDTH = 78;
  const int	EXPLOSE_HEIGHT = 51;
  SDL_Surface*	img_fire;
  SDL_Surface*	img_explose;
  SDL_Rect	fire[4];
  SDL_Rect	explose[12];
  
  img_fire = IMG_Load("images/fireball1.png");
  img_explose = IMG_Load("images/fire_explose.png");
  decoupecatfire(fire);
  fireball_sound();
  boucle_explose(explose, EXPLOSE_WIDTH, EXPLOSE_HEIGHT);
  anim_fireball(img_fire, img_explose, fire, explose);
  draw_rect();
}






