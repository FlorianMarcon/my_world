##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=	gcc

WAY	=	./src

SRC	=	$(WAY)/main.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -g3

NAME	=	my_world

RM	=	rm -f

LIB	=	-L./lib/my -lmy

all:	$(OBJ)
	make -C./lib/my
	$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	make clean -C./lib/my
	rm -f $(OBJ)

fclean: clean
	make fclean -C./lib/my
	rm -f $(NAME)

re:	fclean all

tests_run:
	make -C./tests
