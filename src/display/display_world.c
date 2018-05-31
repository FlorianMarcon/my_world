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

void	set_vertex_array_index(sfVertexArray *vertex_array, sfVector2f *vec)
{
	sfVertex vertex1 = {.position = vec[0], .color = sfWhite,\
					.texCoords = (sfVector2f){0, 0}};
	sfVertex vertex2 = {.position = vec[1], .color = sfWhite,\
					.texCoords = (sfVector2f){0, 100}};
	sfVertex vertex3 = {.position = vec[2], .color = sfWhite,\
					.texCoords = (sfVector2f){100, 100}};
	sfVertex vertex4 = {.position = vec[1], .color = sfWhite,\
					.texCoords = (sfVector2f){100, 0}};
	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_append(vertex_array, vertex3);
	sfVertexArray_append(vertex_array, vertex4);
	sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
}
void	set_vertex_array(map_t *map)
{
	sfVector2f vec[4];
	unsigned int i = 0;

	for (unsigned int y = 0; y != map->height - 2; y++) {
		for (unsigned int x = 0; x != map->width - 2; x++) {
			vec[0] = map->graph_map[y][x];
			vec[1] = map->graph_map[y][x + 1];
			vec[2] = map->graph_map[y + 1][x];
			vec[3] = map->graph_map[y + 1][x + 1];
			set_vertex_array_index(map->vertex_array[i++], vec);
		}
	}
	map->vertex_array[i] = NULL;
}

sfVector2f	project_iso_point(map_t *map, unsigned int x, unsigned int y)
{
	sfVector2f point;
	double rota = map->rotation * M_PI / 180;
	double incli = map->inclinaison * M_PI / 180;
	int z = map->map[y][x];

	point.x = (map->x_center + cos(rota) * ((float)x - map->x_center));
	point.x -= (sin(rota) * ((float)y - map->y_center));
	point.y = (map->y_center + sin(rota) * ((float)x - map->x_center));
	point.y += cos(rota) * ((float)y - map->y_center);
	point.y = map->y_center  + cos(incli) * (point.y - map->y_center);
	point.y -= sin(incli) * z;
	point.x += map->x_translation;
	point.y += map->y_translation;
	point.x = point.x * (SCALING + map->zoom);
	point.y = point.y * (SCALING + map->zoom);
	return (point);
}
void	set_simple_vertex(map_t *map)
{
	for (unsigned int y = 0; y != map->height; y++) {
		for (unsigned int x = 0; x != map->width; x++) {
			map->graph_map[y][x] = project_iso_point(map, x, y);
		}
	}
}
void	display_world(world_t *world)
{
	set_simple_vertex(world->map);
	set_vertex_array(world->map);
	for (unsigned int i = 0; world->map->vertex_array[i] != NULL; i++) {
		sfRenderWindow_drawVertexArray(world->window->window, world->map->vertex_array[i], &world->map->floor[0].state);
	}
}
