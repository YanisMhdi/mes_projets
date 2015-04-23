void    my_putchar(char c);
void    my_putstr(char *str);
void    my_put_nbr(int n);
void    display_map(int battlefield[10][10], char *str);
void    check_end(int bf[10][10], int bf_player[10][10], int *end, int nb, int nbP, int count);


void    check_ship_IA(int battlefield[10][10], int bf_player[10][10], int *end, int count)
{
  int   i;
  int   j;
  int   nbship;
  int   nbship_player;

  nbship_player = nbship = 0;
  for (i = 0; i < 10; ++i)
    {
      for (j = 0; j < 10; ++j)
        {
          if (battlefield[i][j] == 1)
            nbship++;
	  if (bf_player[i][j] == 1)
            nbship_player++;
        }
    }
  check_end(battlefield, bf_player, end, nbship, nbship_player, count);
}

void	check_end(int bf[10][10], int bfp[10][10], int *nd, int nb, int nbP, int c)
{
  if ((nb == 0) || (nbP == 0))
    {
      display_map(bf, "");
      display_map(bfp, "du Joueur");
      if (nb == 0)
        my_putstr("Partie termine. Vous avez Gagne !\nNombres total de coups : ");
      else
	my_putstr("Partie termine. Vous avez Perdu !\nNombres total de coups : ");
      my_put_nbr(c);
      my_putchar('\n');
      *nd = 1;
    }
}
