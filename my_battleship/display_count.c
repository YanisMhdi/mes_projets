void	my_putchar(char c);
void	my_putstr(char *str);
void	my_put_nbr(int n);


void	display_count(int count)
{
  if (count < 2)
    my_putstr("Nombre de coup : ");
  else
    my_putstr("Nombres de coups : ");
  my_put_nbr(count);
  my_putchar('\n');
}
