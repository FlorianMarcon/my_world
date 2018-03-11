/*
** EPITECH PROJECT, 2017
** write_encoding_byte
** File description:
** write_encoding_byte
*/

#include <unistd.h>
#include "header_asm.h"

int	write_encoding_byte(fd_t *fd, char **tab, int count)
{
	int op_c = search_function(tab[0]);
	char c;

	if (op_c == 1 || op_c == 9 || op_c == 12 || op_c == 15)
		return (count);
	c = compute_encoding_byte(tab[1]);
	if (write(fd->new, &c, 1) == -1)
		return (0);
	count += 1;
	return (count);
}
