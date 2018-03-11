/*
** EPITECH PROJECT, 2017
** write_variable
** File description:
** write_variable
*/
#include <stdlib.h>
#include <unistd.h>
#include "header_asm.h"
#include "op.h"

int	write_register(fd_t *fd, char *arg, int count)
{
	char val = my_getnbr(&arg[1]);

	if (write(fd->new, &val, 1) == -1)
		return (0);
	count += 1;
	return (count);
}

int	write_direct(fd_t *fd, char *arg, int count, analyse_file_t *an)
{
	int a = 0;
	label_t *lab;

	if (is_label_variable(arg)) {
		if ((lab = search_label_in_list(an, &arg[2])) == NULL)
			return (0);
		a = lab->position - count;
		integer_little_to_big_endian(&a);
		if ((write(fd->new, &a, 4)) == -1)
			return (0);
	} else {
		a = my_getnbr(&arg[1]);
		integer_little_to_big_endian(&a);
		if ((write(fd->new, &a, 4)) == -1)
			return (0);
	}
	count += 4;
	return (count);
}

int	write_indirect(fd_t *fd, char *arg, int count)
{
	short a = my_getnbr(arg);

	short_little_to_big_endian(&a);
	if ((write(fd->new, &a, sizeof(a))) == -1)
		return (0);
	count += 2;
	return (count);
}
