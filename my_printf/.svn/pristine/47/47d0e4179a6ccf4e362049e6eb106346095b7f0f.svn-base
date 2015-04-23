CC =	gcc
SRC =	functions.c	\
		fonction.c	\
		test.c 		\
		library.c 	\
		library1.c
OBJ =	$(SRC:%.c=%.o)
RM =	rm -f
CFLAGS =	-W -Wall -Werror -FPIC
STATIC =	libmy_printf_`uname -m`-`uname -s`.a
DYNAMIC =	libmy_printf_`uname -m`-`uname -s`.so

name:	my_printf_static
		my_printf_dynamic

my_printf_static:	$(OBJ)
					ar r $(STATIC) $(OBJ)
					ranlib $(STATIC)

my_printf_dynamic:	$(OBJ)
					$(CC) $(CFLAGS) -shared $(OBJ) -o $(DYNAMIC)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all