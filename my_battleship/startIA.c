void    display_map(int battlefield[10][10], char *str);
void    display_count(int count);
char    *readLine();
int     check(char *coord, int *end, int battlefield[10][10]);
void    check_ship(int battlefield[10][10], int *end, int count);
void    check_ship_IA(int battlefield[10][10], int bf_player[10][10], int *end, int count);
void    my_putchar(char c);
void    my_putstr(char *str);
char	*my_strupcase(char *str);
void	rand_IA(int bf_player[10][10]);


void    startIA(int count, int battlefield[10][10], int bf_player[10][10])
{
  int   end;
  char  *input;

  end = 0;
  while (end == 0)
    {
      display_map(battlefield, "");
      display_map(bf_player, "du Joueur");
      display_count(count);
      my_putstr("Entrez une position : ");
      input = my_strupcase(readLine());
      my_putchar('\n');
      if (check(input, &end, battlefield) == 0)
        {
	  if (end == 0)
	    rand_IA(bf_player);
	  count++;
	  check_ship_IA(battlefield, bf_player, &end, count);
        }
      else
        my_putstr("Attention vous avez entre une mauvaise position.");
    }
}
