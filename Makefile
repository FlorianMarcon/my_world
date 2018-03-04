##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=	gcc

WAY	=	./src

SRC	=	$(WAY)/main.c		\
		$(WAY)/main_loop.c	\
		$(WAY)/event.c		\
		$(WAY)/create_matter/create_matter.c	\
		$(WAY)/create_matrice_map/create_matrice_map.c	\
		$(WAY)/create_two_d_map/project_iso_point.c	\
		$(WAY)/create_two_d_map/create_two_d_map.c	\
		$(WAY)/draw/draw_two_d_map.c		\
		$(WAY)/draw/draw_square_selection.c	\
		$(WAY)/draw/draw_bottom_map.c	\
		$(WAY)/draw/draw_background.c	\
		$(WAY)/draw/display.c	\
		$(WAY)/draw/draw_left_toolbar.c	\
		$(WAY)/key_event/mouse.c		\
		$(WAY)/save_map/save_map.c		\
		$(WAY)/utilitaries/my_getstr.c		\
		$(WAY)/utilitaries/init_window.c		\
		$(WAY)/utilitaries/set_rectangle.c	\
		$(WAY)/utilitaries/create_button.c	\
		$(WAY)/button/left_toolbar.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -g3 -I./include

LDFLAGS	=	-lcsfml-system -lcsfml-window -lcsfml-graphics -lm

NAME	=	my_world

RM	=	rm -f

LIB	=	-L./lib/my -lmy

all:	$(OBJ)
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
