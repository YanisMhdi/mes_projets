void	my_putstr(char *str);
int	my_strcmp(char *s1, char *s2);
char	*readLine();

int choice()
{
  char *choix;

  my_putstr("Faites un choix de partie (solo ou VS): ");
  choix = readLine();
  if (my_strcmp(choix, "solo") == 0)
    {
      return (0);
    }
  else
    return (1);
}
