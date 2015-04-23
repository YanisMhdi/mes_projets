#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void	hit(int battlefield[10][10], int line, int column);

void	rand_IA(int bf_player[10][10])
{
  int	x;
  int	y;

  srand(time(NULL));
  x = rand() % 10;
  y = rand() % 10;
  hit(bf_player, x, y);
}
