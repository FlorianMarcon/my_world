##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=	gcc

WAY	=	./src

SRC	=	$(WAY)/main.c		\
		$(WAY)/loop_game.c		\
		$(WAY)/map/create_map.c	\
		$(WAY)/map/create_graphical_map.c	\
		$(WAY)/map/create_list_floor.c	\
		$(WAY)/map/save_map.c		\
		$(WAY)/window/create_window.c		\
		$(WAY)/world/create_world.c		\
		$(WAY)/world/create_button.c		\
		$(WAY)/world/create_keyboardevent.c		\
		$(WAY)/event/event.c			\
		$(WAY)/event/event_button.c			\
		$(WAY)/event/event_keyboard.c			\
		$(WAY)/display/display.c		\
		$(WAY)/display/display_world.c		\
		$(WAY)/display/display_button.c		\
		$(WAY)/button/up_action.c		\
		$(WAY)/button/is_about.c		\
		$(WAY)/menu/loop_menu.c			\
		$(WAY)/menu/menu/create_menu.c			\
		$(WAY)/menu/event/event_menu.c		\
		$(WAY)/menu/display/display_menu.c		\
		$(WAY)/utilitaries/transform_integer_in_str.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -g3 -I./include

LDFLAGS	=	-lcsfml-system -lcsfml-window -lcsfml-graphics -lm

NAME	=	my_world

RM	=	rm -f

LIB	=	-L./lib/my -lmy

all:	$(OBJ)
	make -C./lib/my
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(LDFLAGS)

$(NAME):
	$(OBJ)
	make -C./lib/my
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(LDFLAGS)
clean:
	make clean -C./tests
	make clean -C./lib/my
	rm -f $(OBJ)

fclean: clean
	make fclean -C./tests
	make fclean -C./lib/my
	rm -f $(NAME)

re:	clean all

tests_run:
	make -C./tests
