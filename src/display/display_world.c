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

void	display_world(world_t *world)
{
	set_vector_array(world->map);
	set_vertex_array(world->map);
	for (unsigned int i = 0; world->map->vertex_array[i] != NULL; i++) {
		sfRenderWindow_drawVertexArray(world->window->window, world->map->vertex_array[i], &world->map->floor[0].state);
	}
}
