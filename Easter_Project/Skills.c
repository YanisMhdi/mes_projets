/*
** attacks.c for  in /home/regency/Midgar/irican_f
** 
** Made by IRICANIN Filip
** Login   <irican_f@etna-alternance.net>
** 
** Started on  Fri Oct 10 11:07:21 2014 IRICANIN Filip
** Last update Sun Apr 12 12:39:04 2015 IRICANIN Filip
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "my.h"
#include "my_hero.h"
#include "my_monster.h"

int	attack()
{
  scr.player = 0;
  srand(time(NULL));
  if ((rand() % 10 + 1) == 1)
    {
      monster.pv -= 10;
      move_animation();
      write_hero_damage(10);
      write_critical();
      sleep(1);
    }
  else
    {
      monster.pv -= 7;
      move_animation();
      write_hero_damage(7);
      sleep(1);
    }
  return (0);
}

int	slash()
{
  srand(time(NULL));
  if ((rand() % 10 + 1) == 2)
    {
      monster.pv -= 12;
      hero.pv = hero.pv - 2;
      slash_animation();
      write_hero_damage(12);
      write_ennemy_damage(2);
      write_critical();
      sleep(1);
    }
  else
    {
      monster.pv = monster.pv - 10;
      hero.pv = hero.pv - 2;
      slash_animation();
      write_hero_damage(10);
      write_ennemy_damage(2);
      sleep(1);
    }
  return (0);
}

int	fire()
{
  if (hero.pm < 3)
    return (1);
  srand(time(NULL));
  if ((rand() % 10 + 1) == 3)
    {
      monster.pv -= 12;
      hero.pm = hero.pm - 3;
      fire_animation();
      write_hero_damage(12);
      write_hero_ether(-3);
      write_critical();
      sleep(1);
    }
  else
    {
      monster.pv -= 10;
      hero.pm = hero.pm - 3;
      fire_animation();
      write_hero_damage(10);
      write_hero_ether(-3);
      sleep(1);
    }
  return (0);
}

int	thunder()
{
  if (hero.pm < 5)
    return (1);
  srand(time(NULL));
  if ((rand() % 10 + 1) == 4)
    {
      monster.pv -= 18;
      hero.pm = hero.pm - 5;
      thunder_animation();
      write_hero_damage(18);
      write_hero_ether(-5);
      write_critical();
    sleep(1);
    }
  else
    {
      monster.pv = monster.pv - 15;
      hero.pm = hero.pm - 5;
      thunder_animation();
      write_hero_damage(15);
      write_hero_ether(-5);
      sleep(1);
    }
  return (0);
}
