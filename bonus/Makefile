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
		$(WAY)/draw/display.c	\
		$(WAY)/draw/print_file.c	\
		$(WAY)/utilitaries/create_file.c	\
		$(WAY)/draw/draw_background.c	\
		$(WAY)/utilitaries/init_window.c		\
		$(WAY)/utilitaries/set_rectangle.c	\
		$(WAY)/utilitaries/create_button.c	\
		$(WAY)/button/button.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -I./include -g3

LDFLAGS	=	-lcsfml-system -lcsfml-window -lcsfml-graphics -lm

NAME	=	my_world

RM	=	rm -f

all:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	make clean -C./tests
	rm -f $(OBJ)

fclean: clean
	make fclean -C./tests
	rm -f $(NAME)

re:	clean all

tests_run:
	make -C./tests
