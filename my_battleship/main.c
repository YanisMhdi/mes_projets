/*
** main.c for  in /home/mohamd_y/Piscine/Langage_C/my_battleship
** 
** Made by MOHAMDI Yanis
** Login   <mohamd_y@etna-alternance.net>
** 
** Started on  Fri Oct  3 19:39:55 2014 MOHAMDI Yanis
** Last update Sat Oct  4 13:54:45 2014 MOHAMDI Yanis
*/
void    start(int count, int battlefield[10][10]);
void    startIA(int count, int battlefield[10][10], int bf_player[10][10]);
void	my_putstr(char *str);
char	*readLine();
int	choice();

/*
** FONCTION PRINCIPALE
** Cette fonction initialise et lance une partie de jeu.
*/
int	main(int argc, char **argv)
{
  int		count;
  static int	battlefield[10][10] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 1, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
  };
  static int    bf_player[10][10] = {
    {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
  };

  (void) argc;
  (void) argv;
  count = 0;
  if (choice() == 0)
    start(count, battlefield);
  else
    startIA(count, battlefield, bf_player);
  return (0);
}
