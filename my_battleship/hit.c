void	my_putstr(char *str);


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
