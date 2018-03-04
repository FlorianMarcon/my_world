/*
** EPITECH PROJECT, 2017
** draw_bottom_map
** File description:
** draw_bottom_map
*/

#include "header_world.h"

sfVertexArray *create_quad_bottom_map(sfVector2f point1, sfVector2f point2)
{
	sfVector2f point3 = {point1.x, point1.y + 50};
	sfVector2f point4 = {point2.x, point2.y + 50};

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

int	draw_bottom_map(sfRenderWindow *window, map_t *map, states_t *tex)
{
	sfVector2f **map_two_d = map->map_two_d;

	for (int j = 0; j < map->height - 1; j++) {
		for (int i = 0; i < map->width - 1; i++) {
			sfRenderWindow_drawVertexArray(window,create_quad_bottom_map(map_two_d[j][i], map_two_d[j][i + 1]), &tex->states);
			sfRenderWindow_drawVertexArray(window,create_quad_bottom_map(map_two_d[j][i], map_two_d[j + 1][i]), &tex->states);
			sfRenderWindow_drawVertexArray(window,create_quad_bottom_map(map_two_d[j][i + 1], map_two_d[j + 1][i + 1]), &tex->states);
			sfRenderWindow_drawVertexArray(window,create_quad_bottom_map(map_two_d[j + 1][i], map_two_d[j + 1][i + 1]), &tex->states);

//			sfRenderWindow_drawVertexArray(window,create_line(map_two_d[j][i], map_two_d[j][i + 1], sfBlack), NULL);
//			sfRenderWindow_drawVertexArray(window,create_line(map_two_d[j][i], map_two_d[j + 1][i], sfBlack), NULL);
		}
	}
	return (0);
}
