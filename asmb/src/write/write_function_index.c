/*
** EPITECH PROJECT, 2017
** write_function_index
** File description:
** write_function_index
*/

#include <unistd.h>
#include "header_asm.h"
#include "my.h"

int	write_zjmp_fork(fd_t *fd, char *arg, int count, analyse_file_t *an)
{
	short a;
	label_t *lab;

	if (is_label_variable(arg)) {
		if ((lab = search_label_in_list(an, &arg[2])) == NULL)
			return (0);
		a = lab->position - count;
		short_little_to_big_endian(&a);
		if ((write(fd->new, &a, 2)) == -1)
			return (0);
	} else {
		a = my_getnbr(&arg[1]);
		short_little_to_big_endian(&a);
		if ((write(fd->new, &a, 2)) == -1)
			return (0);
	}
	return (1);
}

int	write_sti(fd_t *fd, char **arg, int count, analyse_file_t *an)
{
	int i = 1;
	int a;

	if ((a = write_register(fd, arg[0], count)) == 0)
		return (0);
	while (i != 3) {
		if (is_registre(arg[i])) {
			a = write_register(fd, arg[i], count);
			count += 1;
		} else if (is_direct(arg[i])) {
			a = write_zjmp_fork(fd, arg[i], count, an);
			count += 2;
		} else {
			arg[i] = my_strcat("%", arg[i]);
			a = write_zjmp_fork(fd, arg[i], count, an);
			count += 2;
		}
		if (a == 0)
			return (0);
		i++;
	}
	return (1);
}
int	write_ldi(fd_t *fd, char **arg, int count, analyse_file_t *an)
{
	int i = 0;
	int a;

	while (i != 2) {
		if (is_registre(arg[i])) {
			a = write_register(fd, arg[i], count);
			count += 1;
		} else if (is_direct(arg[i])) {
			a = write_zjmp_fork(fd, arg[i], count, an);
			count += 2;
		} else {
			arg[i] = my_strcat("%", arg[i]);
			a = write_zjmp_fork(fd, arg[i], count, an);
			count += 2;
		}
		if (a == 0)
			return (0);
		i++;
	}
	a = write_register(fd, arg[2], count);
	return (a);
}
