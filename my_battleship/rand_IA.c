/*
** rand_IA.c for  in /home/mohamd_y/Piscine/Langage_C/my_battleship
** 
** Made by MOHAMDI Yanis
** Login   <mohamd_y@etna-alternance.net>
** 
** Started on  Sat Oct  4 12:44:57 2014 MOHAMDI Yanis
** Last update Sat Oct  4 13:37:09 2014 MOHAMDI Yanis
*/
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
