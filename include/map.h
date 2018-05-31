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
#include "floor.h"

#define NB_FLOOR 3
#define SCALING 110

typedef struct map_s {

	unsigned int width;
	unsigned int height;
	int **map;

	unsigned int x_center;
	unsigned int y_center;

	int x_translation;
	int y_translation;

	int rotation;
	int inclinaison;

	int zoom;

	sfVector2f **graph_map;
	sfVertexArray **vertex_array;

	floor_t floor[3];

	bool is_usable;

}map_t;

void	create_map(map_t *map, unsigned int width, unsigned int height);

void	create_graphical_map(map_t *map);

// button action

void	up_action(map_t *map);

#endif
