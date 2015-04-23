#ifndef __MY_MONSTER_H__
#define __MY_MONSTER_H__

typedef struct s_monster
{
  char *name;
  int   pv;
  int   pm;
  int 	x;
  int 	y;
}t_monster;

t_monster monster;
#endif
