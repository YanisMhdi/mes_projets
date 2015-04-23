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
