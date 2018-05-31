/*
** EPITECH PROJECT, 2017
** create_map
** File description:
** create_map
*/

#include <stdlib.h>
#include "map.h"

void	create_map_set_id(map_t *map)
{
	for (unsigned int y = 0; y != map->height; y++) {
		for (unsigned int x = 0; x != map->width; x++) {
			map->map[y][x] = 0;
		}
	}
}
void	create_map_set_value(map_t *map)
{
	map->x_center = map->width / 2;
	map->y_center = map->height / 2;
	map->zoom = 0;
	map->x_translation = 0;
	map->y_translation = 0;
}
void	create_map(map_t *map, unsigned int width, unsigned int height)
{
	map->width = width;
	map->height = height;
	map->is_usable = true;
	if ((map->map = malloc(sizeof(*map->map) * (height + 1))) == NULL) {
		map->is_usable = false;
		return;
	}
	for (unsigned int i = 0; i != height; i++)
		if ((map->map[i] = malloc(sizeof(int) * (width + 1))) == NULL) {
			free(map->map);
			map->is_usable = false;
			return;
		}
	create_map_set_id(map);
	create_map_set_value(map);
	create_graphical_map(map);
}
