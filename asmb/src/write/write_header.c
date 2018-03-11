/*
** EPITECH PROJECT, 2017
** write_header
** File description:
** write_header
*/

#include <stdlib.h>
#include <unistd.h>
#include "header_asm.h"
#include "my.h"
#include "op.h"

int	write_header(fd_t *fd, analyse_file_t *an)
{
	header_t *header = malloc(sizeof(*header));
	char *str = NULL;
	char **tab = NULL;

	header->magic = COREWAR_EXEC_MAGIC;
	integer_little_to_big_endian(&header->magic);
	header->prog_size = an->count;
	integer_little_to_big_endian(&header->prog_size);
	if ((str = get_next_instruction(fd->old)) == NULL ||
				(tab = parsing_str(str, ' ' | '\t')) == NULL) {
		return (0);
	}
	my_strncpy(header->prog_name, &tab[1][1], my_strlen(&tab[1][1]) - 1);
	free(tab);
	if ((str = get_next_instruction(fd->old)) == NULL ||
				(tab = parsing_str(str, ' ' | '\t')) == NULL) {
		return (0);
	}
	my_strncpy(header->comment, &tab[1][1], my_strlen(&tab[1][1]) - 1);
	free(tab);
	if (write(fd->new, header, sizeof(*header)) == -1) {
		free(header);
		return (0);
	}
	free(header);
	return (1);
}
