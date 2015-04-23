void	my_putstr(char *str);
void	my_putchar(char c);
char    char_battlefield(int i);
void    bf_display(int *i, int *j, int bf[10][10]);


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
