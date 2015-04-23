##
## Makefile for my_battleship in /home/mohamd_y/Piscine/Langage_C/my_battleship
## 
## Made by MOHAMDI Yanis
## Login   <mohamd_y@etna-alternance.net>
## 
## Started on  Fri Oct  3 19:31:07 2014 MOHAMDI Yanis
## Last update Sat Oct  4 13:23:29 2014 MOHAMDI Yanis
##
CC = gcc
NAME = battleship
SRC = 	readline.c \
	main.c \
	start.c \
	display_map.c \
	display_count.c \
	check.c \
	hit.c \
	check_ship.c \
	choice.c \
	startIA.c \
	rand_IA.c \
	check_ship_IA.c
OBJ = $(SRC:%.c=%.o)
RM = rm -f
CFLAGS = -W -Wall -ansi -pedantic -L. -I.
LDFLAGS = -lmy

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LDFLAGS)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all