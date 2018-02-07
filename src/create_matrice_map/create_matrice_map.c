/*
** EPITECH PROJECT, 2017
** create_matrice_map
** File description:
** create_matrice_map
*/

#include "header_world.h"
#include <stdlib.h>

map_t	*create_matrice_map(int height, int width)
{
	map_t *map = malloc(sizeof(*map));
	int i = 0;
	int j = 0;

	if (map == NULL)
		return (NULL);
	map->height = height;
	map->width = width;
	map->map = malloc(sizeof(int *) * height);
	while (i != height) {
		j = 0;
		map->map[i] = malloc(sizeof(int) * width);
		while (j != width) {
			map->map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (map);
}
