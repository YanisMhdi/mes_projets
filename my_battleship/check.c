int	my_strcmp(char *s1, char *s2);
int     my_strncmp(char *s1, char *s2, int n);
void	my_putstr(char *str);
void	hit(int battlefield[10][10], int line, int column);

/*
** FONCTION CHECK
** Verifie les coordonnees entrees
** Retourne 0 si les coordonnes sont valides
** Retourne 1 sinon
*/
int	check(char *coord, int *end, int battlefield[10][10])
{
  int	x;
  int	y;

  if (my_strcmp(coord, "QUIT") == 0)
    {
      *end = 1;
      return (0);
    }
  else if (((coord[0] >= 'A') && (coord[0] <= 'J')) 
	   && ((coord[1] >= '1') && (coord[1] <= '9')))
    {
      y = coord[0] - 'A';
      if (my_strncmp(coord + 1, "10", 2) == 0)
	{
	  x = 9;
	}
      else
	  x = coord[1] - '0' - 1;
      hit(battlefield, y, x);
      return (0);
    }
  else
    return (1);
}
