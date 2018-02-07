/*
** EPITECH PROJECT, 2017
** draw_two_d_map
** File description:
** draw_two_d_map
*/

#include "header_world.h"
#include <stdio.h>

sfVertexArray *create_line(sfVector2f point1, sfVector2f point2, sfColor color)
{
	sfVertexArray *vertex_array = sfVertexArray_create();
	sfVertex vertex1 = {.position = point1, .color = color};
	sfVertex vertex2 = {.position = point2, .color = color};

	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
	return (vertex_array);
}

sfVertexArray *create_quad(sfVector2f point1, sfVector2f point2,\
					sfVector2f point3, sfVector2f point4)
{
	sfVertexArray *vertex_array = sfVertexArray_create();
	sfVertex vertex1 = {.position = point1, .color = sfWhite,\
					.texCoords = (sfVector2f){0, 0}};
	sfVertex vertex2 = {.position = point2, .color = sfWhite,\
					.texCoords = (sfVector2f){0, 100}};
	sfVertex vertex3 = {.position = point3, .color = sfWhite,\
					.texCoords = (sfVector2f){100, 100}};
	sfVertex vertex4 = {.position = point4, .color = sfWhite,\
					.texCoords = (sfVector2f){100, 0}};

	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_append(vertex_array, vertex3);
	sfVertexArray_append(vertex_array, vertex4);
	sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
	return (vertex_array);
}

int	draw_2d_map(sfRenderWindow *window, sfVector2f **map_two_d, map_t *map, states_t *tex)
{
	for (int j = 1; j < map->height - 1; j++) {
		for (int i = 1; i < map->width - 1; i++) {
				sfRenderWindow_drawVertexArray(window,create_quad(map_two_d[j][i], map_two_d[j][i + 1], map_two_d[j + 1][i + 1], map_two_d[j + 1][i]), &tex->states);
				sfRenderWindow_drawVertexArray(window,create_line(map_two_d[j][i], map_two_d[j][i + 1], sfRed), NULL);
				sfRenderWindow_drawVertexArray(window,create_line(map_two_d[j][i], map_two_d[j][i - 1], sfRed), NULL);
				sfRenderWindow_drawVertexArray(window,create_line(map_two_d[j][i], map_two_d[j + 1][i], sfRed), NULL);
				sfRenderWindow_drawVertexArray(window,create_line(map_two_d[j][i], map_two_d[j - 1][i], sfRed), NULL);
		}
	}
	return (0);
}
