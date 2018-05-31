/*
** EPITECH PROJECT, 2017
** create_graphical_map
** File description:
** create_graphical_map
*/

#include <stdlib.h>
#include <stdio.h>
#include "map.h"

void	create_graphical_map(map_t *map)
{
	if ((map->graph_map = malloc(sizeof(sfVector2f *) * (map->height + 2))) == NULL) {
		map->is_usable = false;
		return;
	}
	for (unsigned int i = 0; i != map->height; i++) {
		if ((map->graph_map[i] = malloc(sizeof(sfVector2f) * (map->width + 1))) == NULL) {
			free(map->graph_map);
			map->is_usable = false;
			return;
		}
	}
}
