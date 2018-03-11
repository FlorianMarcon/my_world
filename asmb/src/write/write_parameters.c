/*
** EPITECH PROJECT, 2017
** write_parameters
** File description:
** write_parameters
*/

#include <stdlib.h>
#include <unistd.h>
#include "header_asm.h"
#include "op.h"
int	write_ldi(fd_t *fd, char **arg, int count, analyse_file_t *an);
int	write_sti(fd_t *fd, char **arg, int count, analyse_file_t *an);

int	choice_write(fd_t *fd, char *arg, int count, analyse_file_t *an)
{
	switch (which_variable(arg)) {
		case T_REG: count = write_register(fd, arg, count);
			break;
		case T_DIR: count = write_direct(fd, arg, count, an);
			break;
		case T_IND: count = write_indirect(fd, arg, count);
			break;
	}
	return (count);
}

int	write_parameters_indexes(fd_t *fd, char **tab, int count, analyse_file_t *an)
{
	char **arg = parsing_str(tab[1], SEPARATOR_CHAR);

	switch (search_function(tab[0])) {
		case 9: count = write_zjmp_fork(fd, arg[0], count, an);
			break;
		case 10: count = write_ldi(fd, arg, count, an);
			break;
		case 11: count = write_sti(fd, arg, count, an);
			break;
		case 12:  count = write_zjmp_fork(fd, arg[0], count, an);
			break;
		}
	return (count);
}
int	write_parameters(fd_t *fd, char **tab, int count, analyse_file_t *an)
{
	char **arg = parsing_str(tab[1], SEPARATOR_CHAR);
	int i = 0;
	int op_c = search_function(tab[0]);
	int a = 0;

	if (arg == NULL)
		return (0);
	else if (op_c >= 9 && op_c <= 12)
		count = write_parameters_indexes(fd, tab, count, an);
	else {
		while (arg[i] != NULL) {
			if ((count = choice_write(fd, arg[i], count + a, an)) == 0)
				break;
			a += compute_size(arg[i]);
			i++;
		}
	}
	free(arg);
	return (count);
}
