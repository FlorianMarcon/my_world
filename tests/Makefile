##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=	gcc

WAY	=	../src

SRC	=	$(WAY)/tmp.c	\

SRC_UT	=	tmp/tests_utils.c	\

OBJ	=	$(SRC:.c=.o)

OBJ_UT	=	$(SRC_UT:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -g3 -I../include --coverage

LDFLAGS	=	-lcriterion -lgcov

NAME	=	units

RM	=	rm -f

LIB	=	-L../lib/my -lmy

all:	$(OBJ) $(OBJ_UT)
	make -C./../lib/my
	$(CC) -o $(NAME) $(OBJ) $(OBJ_UT) $(LIB) $(LDFLAGS)
	./$(NAME)

clean:
	make clean -C./lib/my
	rm -f $(OBJ)

fclean: clean
	make fclean -C./lib/my
	rm -f $(NAME)

re:	fclean all
