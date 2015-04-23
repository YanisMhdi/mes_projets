/*
** test.c for  in /home/yanis/Projets/C/my_printf
** 
** Made by MOHAMDI Yanis
** Login   <mohamd_y@etna-alternance.net>
** 
** Started on  Wed Mar  4 10:07:08 2015 MOHAMDI Yanis
** Last update Fri Mar  6 10:39:07 2015 LANCIEN Andrew
*/

#include        <stdarg.h>
#include        <stdio.h>
#include        <unistd.h>
#include        "struct.h"
#include        "my_header.h"

void		parse(char 	c, t_verif *t, va_list ap)
{
  int i;
  int p;
  p = 0;
  for (i = 0; t[i].car != '\0'; i++)
    {
      if (c == t[i].car){
	t[i].p(ap);
	p = 1;
      }
    }
  if (p == 0 && c != '%'){
    my_putchar('%');
    my_putchar(c);
  }
  if (p == 0 && c == '%')
    my_putchar(c);
}

void		check(char 	c, va_list ap)
{
	t_verif		p_verif[] =
	{
		{'s', &str},
		{'i', &num},
		{'d', &num},
		{'o', &octal},
		{'c', &charac},
		{'u', &putdec},
		{'x', &hexamin},
		{'X', &hexamaj},
		{'f', &floatnbr},
		{'g', &floathexa},
		{'\0', NULL}
	};
	parse(c, p_verif, ap);
};
