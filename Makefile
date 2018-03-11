##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=	gcc

WAY	=	./asmb/src

WAY1	=	./src

SRC	=	$(WAY1)/main_loop.c	\
		$(WAY1)/event.c		\
		$(WAY1)/draw/display.c	\
		$(WAY1)/draw/print_file.c	\
		$(WAY1)/utilitaries/create_file.c	\
		$(WAY1)/draw/draw_background.c	\
		$(WAY1)/utilitaries/init_window.c		\
		$(WAY1)/utilitaries/set_rectangle.c	\
		$(WAY1)/utilitaries/create_button.c	\
		$(WAY1)/button/button.c		\
		$(WAY)/main.c		\
		$(WAY)/assembleur.c	\
		$(WAY)/op.c					\
		$(WAY)/create_new_file/verify_file_name.c	\
		$(WAY)/create_new_file/create_new_file.c	\
		$(WAY)/is_variable/is_registre.c		\
		$(WAY)/is_variable/is_label.c			\
		$(WAY)/is_variable/is_direct.c			\
		$(WAY)/is_variable/is_indirect.c		\
		$(WAY)/is_variable/which_variable.c		\
		$(WAY)/verification/verification_argument.c	\
		$(WAY)/verification/verification_instruction.c	\
		$(WAY)/verification/verification_file.c		\
		$(WAY)/verification/verification_name_and_comment.c	\
		$(WAY)/verification/count_file_and_save_label.c	\
		$(WAY)/verification/verification_label.c	\
		$(WAY)/size/size_function.c			\
		$(WAY)/size/size_argument.c			\
		$(WAY)/size/size_instruction.c			\
		$(WAY)/write/write_header.c			\
		$(WAY)/write/write_file.c			\
		$(WAY)/write/write_encoding_byte.c		\
		$(WAY)/write/write_function.c			\
		$(WAY)/write/write_parameters.c			\
		$(WAY)/write/write_variable.c			\
		$(WAY)/write/write_function_index.c		\
		$(WAY)/utilitaries/syntax_instruction_is_valid.c	\
		$(WAY)/utilitaries/len_tab.c			\
		$(WAY)/utilitaries/recuperate_string.c		\
		$(WAY)/utilitaries/parsing_str.c		\
		$(WAY)/utilitaries/get_next_instruction.c	\
		$(WAY)/utilitaries/search_function.c		\
		$(WAY)/utilitaries/save_label.c			\
		$(WAY)/utilitaries/my_strndup.c			\
		$(WAY)/utilitaries/little_to_big_endian.c	\
		$(WAY)/utilitaries/compute_encoding_byte.c	\
		$(WAY)/utilitaries/search_label_in_list.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -I./include -g3

LDFLAGS	=	-lcsfml-system -lcsfml-window -lcsfml-graphics -lm

WAY_LIB	=	./lib/my

LIB	=	-L$(WAY_LIB) -lmy

NAME	=	asm

RM	=	rm -f

all:	$(OBJ)
	make -C./$(WAY_LIB)
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(LDFLAGS) $(CFLAGS)

clean:
	make clean -C./tests
	make clean -C./$(WAY_LIB)
	rm -f $(OBJ)

fclean: clean
	make fclean -C./tests
	make fclean -C./$(WAY_LIB)
	rm -f $(NAME)

re:	clean all

tests_run:
	make -C./tests
