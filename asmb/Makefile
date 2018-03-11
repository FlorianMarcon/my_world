##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## corewar
##

CC	=	gcc

WAY	=	./src

SRC	=	$(WAY)/main.c		\
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

CFLAGS	=	-W -Wall -Wextra -Werror -g3 -I../include

WAY_LIB	=	../lib/my

WAY_TST	=	tests

LIB	=	-L$(WAY_LIB) -lmy

NAME	=	asm

all:	$(OBJ)
	make -C./$(WAY_LIB)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	make clean -C./$(WAY_LIB)
	$(RM) $(OBJ)
	make clean -C./$(WAY_TST)

fclean:	clean
	make fclean -C./$(WAY_LIB)
	$(RM) $(NAME)
	make fclean -C./$(WAY_TST)

re:	clean all

tests_run:
	make -C./$(WAY_TST)
