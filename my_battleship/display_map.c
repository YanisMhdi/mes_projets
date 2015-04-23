/*
** display_map.c for  in /home/mohamd_y/Piscine/Langage_C/my_battleship
** 
** Made by MOHAMDI Yanis
** Login   <mohamd_y@etna-alternance.net>
** 
** Started on  Fri Oct  3 21:28:18 2014 MOHAMDI Yanis
** Last update Sat Oct  4 13:52:05 2014 MOHAMDI Yanis
*/
void	my_putstr(char *str);
void	my_putchar(char c);
char    char_battlefield(int i);
void    bf_display(int *i, int *j, int bf[10][10]);

/*
** FONCTION DISPLAY MAP
** Affiche le champ de bataille complet
*/
void	display_map(int battlefield[10][10], char *str)
{
  int	i;
  int	j;

  my_putchar('\n');
  my_putstr("Plan de bataille ");
  my_putstr(str);
  my_putstr(" :\n");
  for (i = 0; i <= 22; ++i)
    my_putchar('_');
  my_putchar('\n');
  bf_display(&i, &j, battlefield);
  for (i = 0; i <= 22; ++i)
    my_putchar('-');
  my_putchar('\n');
}

/*
** FONCTION BF DISPLAY
** Gere l'affichage du champ de bataille
*/
void	bf_display(int *i, int *j, int bf[10][10])
{
  for (*i = 0; *i < 10; ++(*i))
    {
      for(*j = 0; *j < 10; ++(*j))
        {
          if (*j % 10 == 0)
            {
              my_putstr("| ");
              my_putchar(char_battlefield(bf[*i][*j]));
              my_putchar(' ');
            }
          else if (*j % 10 == 9)
            {
              my_putchar(char_battlefield(bf[*i][*j]));
              my_putstr(" |\n");
            }
          else
            {
              my_putchar(char_battlefield(bf[*i][*j]));
              my_putchar(' ');
            }
        }
    }
}

/*
** FONCTION CHAR BATTLEFIELD
** Gere l'affichage du statue de chaque partie du
** champ de bataille
*/
char	char_battlefield(int i)
{
  char	c;

  if (i == 0)
    c = ' ';
  else if (i == 1)
    c = ' ';
  else if (i == 2)
    c = 'X';
  else
    c = 'T';
  return (c);
}
