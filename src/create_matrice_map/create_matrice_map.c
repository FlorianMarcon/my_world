/*
** EPITECH PROJECT, 2017
** create_matrice_map
** File description:
** create_matrice_map
*/

#include "header_world.h"
#include <stdlib.h>
#include <stdio.h>

map_t	*initialisation_map(int height, int width)
{
	map_t *map = malloc(sizeof(*map));

	if (map == NULL)
		return (NULL);
	map->height = height;
	map->width = width;
	map->angle_x = ANGLE_X;
	map->angle_y = ANGLE_Y;
	map->zoom = 1;
	return (map);
}
map_t	*create_matrice_map(int height, int width)
{
	map_t *map = initialisation_map(height, width);

	if (map == NULL)
		return (NULL);
	if ((map->map = malloc(sizeof(int *) * height)) == NULL) {
		free(map);
		return (NULL);
	}
	for (int i = 0; i != height; i++) {
		if ((map->map[i] = malloc(sizeof(int *) * width)) == NULL) {
			free(map);
			return (NULL);
		}
		for (int j = 0; j != width; j++) {
			map->map[i][j] = 0;
		}
	}
	return (map);
}
