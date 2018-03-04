/*
** EPITECH PROJECT, 2017
** draw_water
** File description:
** draw_water
*/

#include "header_world.h"
#include <math.h>
#include <stdlib.h>

sfVector2f	project_iso_point_water(int x, int y, map_t *map)
{
	sfVector2f point;
	double rota = map->rotation * M_PI / 180;
	double incli = map->inclinaison * M_PI / 180;

	point.x = (map->x_center + cos(rota) * (x - map->x_center));
	point.x -= sin(rota) * (y - map->y_center);
	point.y = (map->y_center + sin(rota) * (x - map->x_center));
	point.y += cos(rota) * (y - map->y_center);
	point.y = map->y_center  + cos(incli) * (point.y - map->y_center);
	point.x += map->transla_x;
	point.y += map->transla_y;
	point.x = point.x * (map->scaling_x + map->zoom);
	point.y = point.y * (map->scaling_y + map->zoom);
	return (point);
}

void	evolve_two_d_map_water(map_t *map)
{
	int i = 0;
	int j = 0;

	while (j < map->height) {
		while (i < map->width) {
			map->map_two_d[j][i] = project_iso_point_water
								(i, j, map);
			i++;
		}
		i = 0;
		j++;
	}
}

sfVertexArray	*create_quad_water(sfVector2f point1, sfVector2f point2,\
					sfVector2f point3, sfVector2f point4)
{
	sfColor color = {0, 0, 255, 150};

	sfVertexArray *vertex_array = sfVertexArray_create();
	sfVertex vertex1 = {.position = point1, .color = color,\
					.texCoords = (sfVector2f){0, 0}};
	sfVertex vertex2 = {.position = point2, .color = color,\
					.texCoords = (sfVector2f){0, 100}};
	sfVertex vertex3 = {.position = point3, .color = color,\
					.texCoords = (sfVector2f){100, 100}};
	sfVertex vertex4 = {.position = point4, .color = color,\
					.texCoords = (sfVector2f){100, 0}};
	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_append(vertex_array, vertex3);
	sfVertexArray_append(vertex_array, vertex4);
	sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
	return (vertex_array);
}

int	draw_water(sfRenderWindow *window, map_t *map)
{
	sfVector2f **map_two_d;

	evolve_two_d_map_water(map);
	map_two_d = map->map_two_d;
	for (int j = 0; j < map->height - 1; j++) {
		for (int i = 0; i < map->width - 1; i++) {
			sfRenderWindow_drawVertexArray(window,
create_quad_water(map_two_d[j][i], map_two_d[j][i + 1], map_two_d[j + 1][i + 1],
map_two_d[j + 1][i]), NULL);
			sfRenderWindow_drawVertexArray(window,
create_line(map_two_d[j][i], map_two_d[j][i + 1], sfBlack), NULL);
			sfRenderWindow_drawVertexArray(window,
create_line(map_two_d[j][i], map_two_d[j + 1][i], sfBlack), NULL);
		}
	}
	draw_square_selection(window, map_two_d, map->x, map->y);
	return (0);
}
