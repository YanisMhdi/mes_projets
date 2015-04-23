/*
** hit.c for  in /home/mohamd_y/Piscine/Langage_C/my_battleship
** 
** Made by MOHAMDI Yanis
** Login   <mohamd_y@etna-alternance.net>
** 
** Started on  Sat Oct  4 09:37:42 2014 MOHAMDI Yanis
** Last update Sat Oct  4 13:59:18 2014 MOHAMDI Yanis
*/
void	my_putstr(char *str);

/*
** FONCTION HIT
** Gere si les coups ont touches ou non
** Peut gerer le already shoot
*/
void	hit(int battlefield[10][10], int line, int column)
{
  if (battlefield[line][column] == 1)
    {
      my_putstr("\n\nTouche\n\n");
      battlefield[line][column] = 3;
    }
  else if (battlefield[line][column] == 0)
    {
      my_putstr("\n\nManque\n\n");
      battlefield[line][column] = 2;
    }
}
