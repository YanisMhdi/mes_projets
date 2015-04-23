#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "struct.h"
#include "my_header.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void    my_putstr(char *str)
{
  int i;
  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}

int     my_strlen(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

int     my_strcmp(char *s1, char *s2)
{
  int   i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0')
      i++;
  return (s1[i] - s2[i]);
}
