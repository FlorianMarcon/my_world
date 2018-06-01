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

typedef enum selection_s {
	summit,
	square
}selection_t;

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

	// selection
	unsigned int x;
	unsigned int y;
	selection_t type_select;

	sfVertexArray *vertex_mouse[5];
}map_t;

//create map

void	create_map(map_t *map, unsigned int width, unsigned int height);

void	create_graphical_map(map_t *map);

void	create_map_map(map_t *map);

void	create_map_set_value(map_t *map);

void	create_map_set_id(map_t *map);

// save
void	save_map(map_t *map);

// load_map

void	load_map(map_t *map, char *path);

// button action

void	up_action(map_t *map);
void	down_action(map_t *map);

void	rotation_right(map_t *map);
void	rotation_left(map_t *map);

void	inclinaison_down(map_t *map);
void	inclinaison_up(map_t *map);

void	zoom_in(map_t *map);
void	zoom_out(map_t *map);

void	translation_left(map_t *map);
void	translation_right(map_t *map);
void	translation_up(map_t *map);
void	translation_down(map_t *map);

void	select_square(map_t *map);
void	select_summit(map_t *map);

//utilitaries
char	*transform_integer_in_str(int nb);

// other
void	set_vertex_array(map_t *map);
void	set_vector_array(map_t *map);
#endif
