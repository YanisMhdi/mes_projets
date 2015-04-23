/*
** struct.h for  in /home/andrew/myprintf
** 
** Made by LANCIEN Andrew
** Login   <lancie_a@etna-alternance.net>
** 
** Started on  Fri Mar  6 11:45:05 2015 LANCIEN Andrew
** Last update Fri Mar  6 11:59:06 2015 LANCIEN Andrew
*/

#ifndef STRUCT_H__
#define STRUCT_H__

typedef		struct s_verif
{
  char	car;
  void (*p)(va_list ap);
}	t_verif;

#endif
