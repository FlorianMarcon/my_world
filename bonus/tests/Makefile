##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=	gcc

WAY	=	../src

SRC	=	$(WAY)/create_matter/create_matter.c	\
		$(WAY)/create_two_d_map/project_iso_point.c	\
		$(WAY)/create_two_d_map/create_two_d_map.c	\
		$(WAY)/utilitaries/my_getstr.c			\

SRC_UT	=	my_getstr/tests_utils.c			\

OBJ	=	$(SRC:.c=.o)

OBJ_UT	=	$(SRC_UT:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -g3 -I../include --coverage

LDFLAGS	=	-lcriterion -lgcov -lcsfml-system -lcsfml-window -lcsfml-graphics -lm

NAME	=	units

RM	=	rm -f

LIB	=	-L../lib/my -lmy

all:	$(OBJ) $(OBJ_UT)
	make -C./../lib/my
	$(CC) -o $(NAME) $(OBJ) $(OBJ_UT) $(LIB) $(LDFLAGS)
	./$(NAME)

clean:
	rm -f $(SRC:.c=.gcda)
	rm -f $(SRC:.c=.gcno)
	rm -f $(SRC_UT:.c=.gcda)
	rm -f $(SRC_UT:.c=.gcno)
	rm -f $(OBJ)
	rm -f $(OBJ_UT)

fclean: clean
	rm -f $(NAME)

re:	fclean all
