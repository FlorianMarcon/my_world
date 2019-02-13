/*
** EPITECH PROJECT, 2017
** load_map
** File description:
** load_map
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "world.h"
#include "map.h"
#include "my.h"
#include "get_next_line.h"

void	load_caracteristique(int fd, map_t *map)
{
	char *str = get_next_line(fd);

	if (str != NULL) {
		if (my_str_isnum(str))
			map->width = my_getnbr(str);
		else
			map->is_usable = false;
		free(str);
	} else
		map->is_usable = false;
	if ((str = get_next_line(fd)) != NULL) {
		if (my_str_isnum(str))
			map->height = my_getnbr(str);
		else
			map->is_usable = false;
		free(str);
	} else
		map->is_usable = false;
}

void	load_map_stock_in_map(char **tab, map_t *map, unsigned int y)
{
	for (unsigned int x = 0; x != map->width && tab[x] != NULL; x++) {
		if (my_str_isnum(tab[x])) {
			map->map[y][x] = my_getnbr(tab[x]);
		}
	}
}
void	load_map_map(int fd, map_t *map)
{
	char *str = NULL;
	char **tab = NULL;

	for (unsigned int y = 0; y != map->height; y++) {
		str = get_next_line(fd);
		if (str != NULL && (tab = parsing_str(str, ' ')) != NULL) {
			load_map_stock_in_map(tab, map, y);
			free(str);
			free(tab);
		}
	}
}
void	load_map(map_t *map, char *path)
{
	int fd = open(path, O_RDONLY);

	if (fd == -1) {
		map->is_usable = false;
		return;
	}
	map->width = 100;
	map->height = 100;
	map->name = get_next_line(fd);
	load_caracteristique(fd, map);
	create_map_map(map);
	create_map_set_id(map);
	load_map_map(fd, map);
	close(fd);
	create_map_set_value(map);
	create_graphical_map(map);
}
