void	my_putchar(char c);
void	my_putstr(char *str);
void	my_put_nbr(int n);
void    display_map(int battlefield[10][10]);


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
