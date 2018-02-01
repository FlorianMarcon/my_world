##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC=			./main.c

OBJ=			$(SRC:.c=.o)

CFLAGS= 		-W -Wall -Wextra -g3

NAME=			my_world

CC=			gcc

RM=			rm -f


all: 			$(NAME)

$(NAME): 		$(OBJ)
			cc -o $(NAME) $(OBJ)  -lcsfml-system -lcsfml-window -lcsfml-graphics -lm -lcsfml-audio

clean:
			rm -f $(OBJ)

fclean: 		clean
			rm -f $(NAME)

re:			fclean all
