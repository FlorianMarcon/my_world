/*
** EPITECH PROJECT, 2018
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
	map->width = width;
	map->height = height;
	map->x_center = width / 2;
	map->y_center = height / 2;
	map->scaling_x = 1100 / width;
	map->scaling_y = 1100 / height;
	map->x = 0;
	map->y = 0;
	map->rotation = 0;
	map->inclinaison = 0;
	map->zoom = 1;
	map->open = 1;
	map->transla_x = 1;
	map->transla_y = 1;
	return (map);
}

int	create_background(map_t *map)
{
	sfTexture *text = sfTexture_createFromFile(BACKGROUND, NULL);

	map->background = sfSprite_create();
	sfSprite_setTexture(map->background, text, sfTrue);
	return (1);
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
	create_two_d_map(map);
	create_background(map);
	return (map);
}
