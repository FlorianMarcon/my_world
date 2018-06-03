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
	map->zoom = (map->width) * -1;
	map->x_translation = 1;
	map->y_translation = -1 * map->y_center;
	map->rotation = 15;
	map->inclinaison = 75;
	map->x = 0;
	map->y = 0;
	map->type_select = square;
}

void	create_map_map(map_t *map)
{
	if ((map->map = malloc(sizeof(*map->map) *
			(map->height + 1))) == NULL) {
		map->is_usable = false;
		return;
	}
	for (unsigned int i = 0; i != map->height; i++)
	if ((map->map[i] = malloc(sizeof(int) * (map->width + 1))) == NULL) {
		free(map->map);
		map->is_usable = false;
		return;
	}
}
void	create_map(map_t *map, unsigned int width, unsigned int height)
{
	map->width = width;
	map->height = height;
	map->is_usable = true;
	create_map_map(map);
	create_map_set_id(map);
	create_map_set_value(map);
	create_graphical_map(map);
}
