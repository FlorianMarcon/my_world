/*
** EPITECH PROJECT, 2017
** create_new_file
** File description:
** create_new_file
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "header_asm.h"
#include "my.h"

char	*create_name_new_file(char *path_old)
{
	int len;
	char *new = NULL;

	if (path_old == NULL)
		return (NULL);
	len = my_strlen(path_old);
	path_old[len - 2] = '\0';
	new = my_strcat(path_old, ".cor");
	if (new == NULL)
		return (NULL);
	len = my_strlen(new) - 1;
	while (len != 0 && new[len] != '/')
		len--;
	if (new[len] == '/')
		new = &new[len + 1];
	return (new);
}
int	create_new_file(char *path_old)
{
	char *path = create_name_new_file(path_old);
	int fd;

	if (path == NULL)
		return (-1);
	fd = open(path, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
//	free(path);
	return (fd);
}
