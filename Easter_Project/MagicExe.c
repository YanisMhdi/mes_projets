/*
** MagicExe.c for  in /home/regency
** 
** Made by IRICANIN Filip
** Login   <irican_f@etna-alternance.net>
** 
** Started on  Sun Apr 12 12:28:21 2015 IRICANIN Filip
** Last update Sun Apr 12 20:22:37 2015 IRICANIN Filip
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "my.h"
#include "my_hero.h"
#include "my_monster.h"


void	use_magic(int *p, int *MainQuit)
{
  int	(*f[4])();
  int	ret;
  
  f[0] = &fire;
  f[1] = &thunder;
  f[2] = &draw_libra;
  f[3] = &heal;
  ret = f[(*p)]();
  if (hero.pv <= 0 || monster.pv <= 0)
    end_screen(MainQuit);
  else if (ret == 0)
    monster_turn();
  
  if(hero.pv <= 0)
    end_screen(MainQuit);
}

void	use_item(int *p)
{
  int	(*f[2])();
  
  f[0] = &potion;
  f[1] = &ether;
  if (f[(*p)]() == 0)
    monster_turn();
}

void	use_attack(int *p, int *MainQuit)
{
  int	(*f[2])();
  int	ret;

  f[0] = &attack;
  f[1] = &slash;
  ret = f[(*p)]();
  if (hero.pv <= 0 || monster.pv <= 0)
    end_screen(MainQuit);
  else if (ret == 0)
    monster_turn();
  
  if (hero.pv <= 0)
    end_screen(MainQuit);
}
