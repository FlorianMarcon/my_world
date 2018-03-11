/*
** EPITECH PROJECT, 2017
** verification_file
** File description:
** verification_file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "header_asm.h"
#include "op.h"
int	verification_name_and_comment(int fd);
int	verification_instruction(char **tab);
int	verification_label(char *path, analyse_file_t *an);

analyse_file_t	*verification_file(char *path)
{
	analyse_file_t *fl = count_file_and_save_label(path);

	if (fl == NULL)
		return (NULL);
	if (verification_label(path, fl) == 0) {
		free(fl);
		return (NULL);
	}
	return (fl);
}
