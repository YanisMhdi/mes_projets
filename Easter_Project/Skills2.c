#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "my.h"
#include "my_hero.h"
#include "my_monster.h"

int    	potion()
{
  if ((hero.potion - 1) < 0)
    return (1);
  hero.potion -= 1;
  hero.pv += 30;
  if (hero.pv > hero.pvmax)
    hero.pv = hero.pvmax;
  heal_animation();
  write_hero_heal(30);
  return (0);
}

int     ether()
{
  if ((hero.ether - 1) < 0)
    return (1);
  hero.ether -= 1;
  hero.pm += 12;
  if (hero.pm > 30)
    hero.pm = 30;
  ether_animation();
  write_hero_ether(12);
  return (0);
}

int	heal()
{
  int	pct;
  
  if (hero.pm < 3)
    return (1);
  srand(time(NULL));
  if ((rand() % 10 + 1) == 8)
    pct = ((45 * hero.pvmax) / hero.pvmax);
  else
    pct = ((25 * hero.pvmax) / hero.pvmax);
  hero.pm = hero.pm - 3;
  hero.pv = hero.pv + pct;
  if (hero.pv > hero.pvmax)
    hero.pv = hero.pvmax;
  heal_animation();
  write_hero_heal(pct);
  return (0);
}
