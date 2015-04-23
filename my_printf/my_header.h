#ifndef __MY_HEADER_H__
#define __MY_HEADER_H__

#include <unistd.h>

void my_put_nbr(int n);
void my_putchar(char c);
void my_putstr(char *str);
int  my_strcmp(char *s1, char *s2);
void charac(va_list list);
void num(va_list list);
void str(va_list list);
void octal(va_list list);
int  my_strlen(char *str);
int  my_putnbr_base(int nbr, char *base);
void check(char c, va_list ap);
void putdec(va_list list);
void decimal(unsigned int n);
void hexamin(va_list list);
void hexamaj(va_list list);
void myfloat(double nb);
void floatnbr(va_list list);
void myfloathexa(double nb);
void floathexa(va_list list);

#endif
