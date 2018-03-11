/*
** EPITECH PROJECT, 2017
** write_file
** File description:
** write_file
*/

#include <stdlib.h>
#include <unistd.h>
#include "header_asm.h"
#include "my.h"

int	write_all(char **tab, fd_t *fd, int count, analyse_file_t *an)
{
	if (is_label(tab[0]))
		tab = &tab[1];
	if (tab[0] != NULL) {
		if ((write_function(fd, tab[0], count)) == 0  ||
			(write_encoding_byte(fd, tab, count)) == 0 ||
			(write_parameters(fd, tab, count, an)) == 0)
			return (-1);
	count += size_instruction(tab);
	}
	return (count);
}
int	write_file(fd_t *fd , analyse_file_t *an)
{
	char *str = NULL;
	char **tab = NULL;
	int count = 0;

	while ((str = get_next_instruction(fd->old)) != NULL) {
		if ((tab = parsing_str(str, ' ' | '\t')) == NULL)
			return (0);
		if ((count = write_all(tab, fd, count, an)) == -1) {
			free(tab);
			return (0);
		}
		free(tab);
	}
	return (1);
}
