/*
** check_ship.c for  in /home/mohamd_y/Piscine/Langage_C/my_battleship
** 
** Made by MOHAMDI Yanis
** Login   <mohamd_y@etna-alternance.net>
** 
** Started on  Sat Oct  4 10:07:34 2014 MOHAMDI Yanis
** Last update Sat Oct  4 14:00:00 2014 MOHAMDI Yanis
*/
void	my_putchar(char c);
void	my_putstr(char *str);
void	my_put_nbr(int n);
void    display_map(int battlefield[10][10]);

/*
** FONCTION CHECH SHIP
** Permet de gerer si tout les bateaux sont coules
** Mets fin a la partie
*/
void	check_ship(int battlefield[10][10], int *end, int count)
{
  int	i;
  int	j;
  int	nbship;

  nbship = 0;
  for (i = 0; i < 10; ++i)
    {
      for (j = 0; j < 10; ++j)
	{
	  if (battlefield[i][j] == 1)
	    nbship++;
	}
    }
  if (nbship == 0)
    {
      display_map(battlefield);
      my_putstr("Partie termine.\nNombres total de coups : ");
      my_put_nbr(count);
      my_putchar('\n');
      *end = 1;
    }
}
