/*
** EPITECH PROJECT, 2017
** set_vector_array
** File description:
**  set_vector_array
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "world.h"

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
void	set_vector_array(map_t *map)
{
	for (unsigned int y = 0; y != map->height; y++) {
		for (unsigned int x = 0; x != map->width; x++) {
			map->graph_map[y][x] = project_iso_point(map, x, y);
		}
	}
}
