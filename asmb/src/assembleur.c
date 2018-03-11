/*
** EPITECH PROJECT, 2017
** assembleur
** File description:
** assembleur
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "header_asm.h"

int	assembleur(char *path)
{
	analyse_file_t *f = verification_file(path);
	fd_t fd;
	int res = 0;

	if (f == NULL)
		return (84);
	if ((fd.old = open(path, O_RDONLY)) == -1 ||
				(fd.new = create_new_file(path)) == -1) {
		free(f);
		return (84);
	}
	if (write_header(&fd, f) == 0 || write_file(&fd, f) == 0) {
		res = 84;
	}
	close(fd.new);
	close(fd.old);
	return (res);
}
