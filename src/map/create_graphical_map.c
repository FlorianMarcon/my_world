/*
** EPITECH PROJECT, 2017
** create_graphical_map
** File description:
** create_graphical_map
*/

#include <stdlib.h>
#include <stdio.h>
#include "map.h"

void	set_graphical_map(map_t *map)
{
	for (int i = 0; i != 5; i++)
		map->vertex_mouse[i] = NULL;
	for (unsigned int i = 0; i != map->width * map->height + 1; i++)
		map->vertex_array[i] = NULL;
}

int	create_graphical_map_indexe(map_t *map)
{
	unsigned int i = 0;

	if ((map->graph_map = malloc(sizeof(sfVector2f *)
						* (map->height + 2))) == NULL) {
		map->is_usable = false;
		return (1);
	}
	for (i = 0; i != map->height; i++) {
		if ((map->graph_map[i] = malloc(sizeof(sfVector2f)
						* (map->width + 1))) == NULL) {
			free(map->graph_map);
			map->is_usable = false;
			return (1);
		}
	}
	return (0);
}
void	create_graphical_map(map_t *map)
{
	if (create_graphical_map_indexe(map))
		return;
	if ((map->vertex_array = malloc(sizeof(*map->vertex_array)
				* (map->width * map->height + 1))) == NULL) {
		free(map->graph_map);
		map->is_usable = false;
		return;
	}
	set_graphical_map(map);
	map->vertex_bottom = malloc(sizeof(*map->vertex_bottom)
					* (map->width * map->height + 1));
	create_list_floor(map->floor);
}
