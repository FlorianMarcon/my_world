/*
** EPITECH PROJECT, 2017
** save_map
** File description:
** save_map
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "map.h"
#include "my.h"

void	write_caracteristique(int fd, map_t *map)
{
	char *str = transform_integer_in_str(map->width);

	if (str != NULL) {
		write(fd, str, my_strlen(str));
		write(fd, "\n", 1);
		free(str);
	}
	if ((str = transform_integer_in_str(map->height)) != NULL) {
		write(fd, str, my_strlen(str));
		write(fd, "\n", 1);
		free(str);
	}
}
void	write_map(int fd, map_t *map)
{
	char *str;

	for (unsigned int y = 0; y != map->height; y++) {
		for (unsigned int x = 0; x != map->width; x++) {
			str = transform_integer_in_str(map->map[y][x]);
			write(fd, str, my_strlen(str));
			write(fd, " ", 1);
			free(str);
		}
		write(fd, "\n", 1);
	}
}
void	save_map(map_t *map)
{
	char *name = my_strcat(map->name, ".legend");
	int flags = O_CREAT | O_TRUNC | O_WRONLY;
	mode_t mode = S_IROTH | S_IRGRP | S_IRUSR;
	int fd = open(name, flags, mode);

	if (fd == -1)
		return;
	write(fd, map->name, my_strlen(map->name));
	write(fd, "\n", 1);
	write_caracteristique(fd, map);
	write_map(fd, map);
	close(fd);
}
