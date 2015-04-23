#include        <stdarg.h>
#include        <stdio.h>
#include        <unistd.h>
#include        "struct.h"
#include        "my_header.h"

void  str(va_list list)
{
  char *format;
  format = va_arg(list, char *);
  my_putstr(format);
}

void num(va_list list)
{
  int number;
  number = va_arg(list, int);
  my_put_nbr(number);
}

void putdec(va_list list)
{
  unsigned int number;
  number = va_arg(list, unsigned int);
  decimal(number);
}

void charac(va_list list)
{
  char format;
  format = (char)va_arg(list, int);
  my_putchar(format);
}

void octal(va_list list)
{
  int number;
  char *base;
  number = va_arg(list, int);
  base = "01234567";
  my_putnbr_base(number, base);
}
