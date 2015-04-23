CC 	= 	gcc 

NAME 	= 	ragnarok

SRC 	= 	main.c 			\
		DrawMagic.c 		\
		DrawItem.c 		\
		DrawAttack.c 		\
		CombatMenu.c 		\
		DrawPlayer.c 		\
		menu.c 			\
		Skills.c 		\
		Skills2.c 		\
		MonsterAttacks.c 	\
		MagicExe.c 		\
		doom.c 			\
		fireball.c 		\
		health.c 		\
		ether.c 		\
		thunder.c 		\
		earthquake.c 		\
		hero.c 			\
		libra.c 		\
		slash.c 		\
		bite.c 			\
		Sounds.c 		\
		endscreen.c 		\
		misc.c

OBJ 	= 	$(SRC:%.c=%.o)

CFLAGS 	= 	-W -Wall -Werror

LDFLAGS = 	-lSDL -lSDL_image -lSDL_ttf -lSDL_mixer

RM 	= 	rm -rf

$(NAME) :  	$(OBJ)
		$(CC) $(LDFLAGS) $(OBJ) -o $(NAME)

all 	:	$(NAME)

clean 	:		
		$(RM) $(OBJ)

fclean 	:	clean
		$(RM) $(NAME)

re 	: 	fclean all