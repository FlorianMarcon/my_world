/*
** EPITECH PROJECT, 2017
** display_world
** File description:
** display_world
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "world.h"
#include "map.h"

void	set_vertex_bottom(map_t *map)
{
	unsigned int where = 0;
	sfVector2f vec[4];

	for (unsigned int i = 0; i != map->width - 1; i++) {
		vec[0] = map->graph_map[map->height - 1][i];
		vec[1] = map->graph_map[map->height - 1][i + 1];
		vec[2] = (sfVector2f){vec[1].x, vec[1].y + 60};
		vec[3] = (sfVector2f){vec[0].x, vec[0].y + 60};
		map->vertex_bottom[where++] =
			set_vertex_array_index(vec, (sfColor){91, 22, 22, 250});
	}
	for (unsigned int i = 0; i != map->height - 1; i++) {
		vec[0] = map->graph_map[i][map->width - 1];
		vec[1] = map->graph_map[i + 1][map->width - 1];
		vec[2] = (sfVector2f){vec[1].x, vec[1].y + 60};
		vec[3] = (sfVector2f){vec[0].x, vec[0].y + 60};
		map->vertex_bottom[where++] =
			set_vertex_array_index(vec, (sfColor){91, 22, 22, 250});
	}
	map->vertex_bottom[where++] = NULL;
}
void	display_world(world_t *world)
{
	set_vector_array(world->map);
	set_vertex_array(world->map);
	set_vertex_bottom(world->map);
	for (unsigned int i = 0; world->map->vertex_array[i] != NULL; i++) {
		sfRenderWindow_drawVertexArray(world->window->window,
		world->map->vertex_array[i], &world->map->floor[0].state);
	}
	for (unsigned int i = 0; world->map->vertex_bottom[i] != NULL; i++) {
		sfRenderWindow_drawVertexArray(world->window->window,
					world->map->vertex_bottom[i], NULL);
	}
}
