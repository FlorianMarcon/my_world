/*
** EPITECH PROJECT, 2017
** verify_file_name
** File description:
** verify_file_name
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "my_printf.h"
#include "header_asm.h"

int	verify_file_name(char *path)
{
	int len = my_strlen(path);
	int fd = open(path, O_RDONLY);

	if (len <= 2 || fd == -1) {
		return (-1);
	} else if (path[len - 1] != 's' || path[len - 2] != '.') {
		close(fd);
		return (-1);
	} else {
		return (fd);
	}
}
