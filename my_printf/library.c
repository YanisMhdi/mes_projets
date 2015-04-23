#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "struct.h"
#include "my_header.h"

void    my_put_nbr(int n)
{
  if (n == -2147483648)
    {
      my_putstr("-2147483648");
    }
  if (n <= 9 && n >= 0)
    {
      my_putchar(n + '0');
    }
  if (n > 9 && n != -2147483648)
    {
      my_put_nbr(n / 10);
      my_put_nbr(n % 10);
    }
  if (n < 0 && n != -2147483648)
    {
      my_putchar('-');
      n = n * -1;
      if (n <= 9 && n >= 0)
        {
          my_put_nbr(n);
        }
      if (n > 9)
	{
	  my_put_nbr(n / 10);
	  my_put_nbr(n % 10);
	}
    }
}

int     my_putnbr_base(int nbr, char *base)
{
  int   i;
  int   m;

  i =  my_strlen(base);
  if (nbr < 0)
    {
      nbr = -1 * nbr;
      my_putchar('-');
    }
  m = nbr % i;
  nbr = nbr / i;
  if (nbr > 0)
    my_putnbr_base(nbr, base);
  my_putchar(base[m]);
  return (nbr);
}

void    decimal(unsigned int n)
{
  if (n == 2147483648)
    my_putstr("2147483648");
  else {
    if (n <= 9)
      my_putchar(n + '0');
    if (n > 9)
      {
	my_put_nbr(n / 10);
	my_put_nbr(n % 10);
      }
  }
}

void myfloat(double nb)
{
  int tmp;
  int rep;
  tmp = nb;
  my_put_nbr(tmp);
  nb = (nb - tmp) * 1000000;
  my_putchar('.');
  tmp = nb;
  rep = tmp % 2;
  if (rep == 0)
    my_put_nbr(tmp);
  if (rep == 1)
    my_put_nbr(tmp+1);
}

void myfloathexa(double nb)
{
  int tmp;
  int rep;
  tmp = nb;
  my_put_nbr(tmp);
  nb = (nb - tmp) * 10000;
  my_putchar('.');
  tmp = nb;
  rep = tmp;
  nb = nb / 10;
  tmp = nb;
  nb = (nb - tmp) * 10;
  tmp = nb;
  if (tmp >= 5)
    {
      rep = rep + 10 -tmp;
      my_put_nbr(rep);
    }
  else if (tmp < 5)
    {
      rep = rep - tmp;
      my_put_nbr(tmp);
    }
}
