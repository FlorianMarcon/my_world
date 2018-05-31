/*
** EPITECH PROJECT, 2017
** map
** File description:
** map
*/

#ifndef MAP_
#define MAP_

#include <stdbool.h>
#include <SFML/Graphics.h>

typedef struct map_s {

	unsigned int width;
	unsigned int height;
	int **map;

	unsigned int x_center;
	unsigned int y_center;

	int x_translation;
	int y_translation;

	int zoom;

	sfVector2f **graph_map;

	bool is_usable;

}map_t;

void	create_map(map_t *map, unsigned int width, unsigned int height);

void	create_graphical_map(map_t *map);

#endif
