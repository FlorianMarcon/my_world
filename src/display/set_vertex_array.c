/*
** EPITECH PROJECT, 2017
** set_vertex_array
** File description:
** set_vertex_array
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "world.h"

sfVertexArray	*set_vertex_array_index(sfVector2f *vec)
{
	sfVertexArray *vertex_array = sfVertexArray_create();

	if (vertex_array == NULL)
		return (NULL);
	sfVertex vertex1 = {.position = vec[0], .color = sfWhite,\
					.texCoords = (sfVector2f){0, 0}};
	sfVertex vertex2 = {.position = vec[1], .color = sfWhite,\
					.texCoords = (sfVector2f){0, 100}};
	sfVertex vertex3 = {.position = vec[2], .color = sfWhite,\
					.texCoords = (sfVector2f){100, 100}};
	sfVertex vertex4 = {.position = vec[3], .color = sfWhite,\
					.texCoords = (sfVector2f){100, 0}};
	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_append(vertex_array, vertex3);
	sfVertexArray_append(vertex_array, vertex4);
	sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
	return (vertex_array);
}
void	set_vertex_array(map_t *map)
{
	sfVector2f vec[4];
	unsigned int i = 0;

	for (unsigned int y = 0; y != map->height - 2; y++) {
		for (unsigned int x = 0; x != map->width - 2; x++) {
			if (map->vertex_array[i] != NULL)
				sfVertexArray_destroy(map->vertex_array[i]);
			vec[0] = map->graph_map[y][x];
			vec[1] = map->graph_map[y][x + 1];
			vec[2] = map->graph_map[y + 1][x + 1];
			vec[3] = map->graph_map[y + 1][x];
			map->vertex_array[i++] = set_vertex_array_index(vec);
		}
	}
	map->vertex_array[i] = NULL;
}
