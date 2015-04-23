#ifndef MY_HERO_H__
#define MY_HERO_H__

typedef struct s_hero
{
  char*	name;
  int	pv;
  int	pm;
  int	potion;
  int	ether;
  int	pvmax;
  int	x;
  int	y;
} t_hero;

t_hero hero;

#endif 
