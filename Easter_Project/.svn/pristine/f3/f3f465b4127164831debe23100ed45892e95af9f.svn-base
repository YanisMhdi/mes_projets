/*
** m_attacks.c for  in /home/regency/Midgar/irican_f
** 
** Made by IRICANIN Filip
** Login   <irican_f@etna-alternance.net>
** 
** Started on  Fri Oct 10 11:44:33 2014 IRICANIN Filip
** Last update Sun Apr 12 12:35:16 2015 IRICANIN Filip
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <time.h>
#include <unistd.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "my.h"
#include "my_hero.h"
#include "my_monster.h"

int	monster_turn()
{
  int	random;
  int	(*f[3])();
  
  f[0] = &bite;
  f[1] = &earthquake;
  f[2] = &doom;
  srand(time(NULL));
  random = (rand() % 3);
  sleep(1);
  if (monster.pv > 0)
    f[random]();
  sleep(1);
  return (0);
}

int	bite()
{
  hero.pv = hero.pv - 6;
  bite_animation();
  write_ennemy_damage(6);
  return (0);
}

int	earthquake()
{
  hero.pv = hero.pv - 15;
  monster.pv = monster.pv - 3;
  earthquake_sound();
  earthquake_animation();
  write_ennemy_damage(15);
  write_hero_damage(3);
  return (0);
}

int	doom()
{
  if (monster.pm < 5)
      return (0);
  hero.pv = hero.pv - 11;
  monster.pm = monster.pm - 5;
  doom_animation();
  write_ennemy_damage(11);
  write_ennemy_ether(-5);
  return (0);
}
