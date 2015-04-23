/*
** functions.c for  in /home/yanis/Projets/C/my_printf
** 
** Made by MOHAMDI Yanis
** Login   <mohamd_y@etna-alternance.net>
** 
** Started on  Wed Mar  4 09:59:42 2015 MOHAMDI Yanis
** Last update Fri Mar  6 11:56:35 2015 LANCIEN Andrew
*/

#include        <stdarg.h>
#include        <stdio.h>
#include        <unistd.h>
#include        "struct.h"
#include        "my_header.h"

void hexamin(va_list list)
{
  int number;
  char *base;

  number = va_arg(list, int);
  base = "0123456789abcdef";
  my_putnbr_base(number, base);
}

void hexamaj(va_list list)
{
  int number;
  char *base;

  number = va_arg(list, int);
  base = "0123456789ABCDEF";
  my_putnbr_base(number, base);
}

void floatnbr(va_list list)
{
  double number;

  number = va_arg(list, double);
  myfloat(number);
}

void floathexa(va_list list)
{
  double number;

  number = va_arg(list, double);
  myfloathexa(number);
}

int my_printf(char *param, ...)
{
  int   i;
  va_list ap;

  i = 0;
  va_start(ap, param);
 while (param[i] != '\0')
   {
     if (param[i] == '%')
       {
	 check(param[i +1], ap);
	 i++;
       }
     else
       my_putchar(param[i]);
     i++;
   }
 va_end();
 return 0;
}
