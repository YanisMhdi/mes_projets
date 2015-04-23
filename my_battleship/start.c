/*
** start.c for  in /home/mohamd_y/Piscine/Langage_C/my_battleship
** 
** Made by MOHAMDI Yanis
** Login   <mohamd_y@etna-alternance.net>
** 
** Started on  Fri Oct  3 21:10:06 2014 MOHAMDI Yanis
** Last update Sat Oct  4 14:14:05 2014 MOHAMDI Yanis
*/
void    display_map(int battlefield[10][10], char *str);
void	display_count(int count);
char    *readLine();
int	check(char *coord, int *end, int battlefield[10][10]);
void	check_ship(int battlefield[10][10], int *end, int count);
void	my_putchar(char c);
void	my_putstr(char *str);
char	*my_strupcase(char *str);

/*
** FONCTION START
** Regroupe le deroulement d'une partie
** Chaque iteration du while compte comme un tour
*/
void	start(int count, int battlefield[10][10])
{
  int	end;
  char	*input;

  end = 0;
  while (end == 0)
    {
      display_map(battlefield, "");
      display_count(count);
      my_putstr("Entrez une position : ");
      input = my_strupcase(readLine());
      my_putchar('\n');
      if (check(input, &end, battlefield) == 0)
	{
	  check_ship(battlefield, &end, count);
	  count++;
	}
      else
	my_putstr("Attention vous avez entre une mauvaise position.\n");
    }
}
