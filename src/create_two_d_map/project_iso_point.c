/*
** EPITECH PROJECT, 2017
** project_iso_point
** File description:
** project_iso_point
*/

#include "header_world.h"
#include "my.h"
#include <math.h>
#include <stdio.h>

sfVector2f	project_iso_point(int x, int y, map_t *map)
{
	sfVector2f point;
	double rota = map->rotation * M_PI / 180;
	double incli = map->inclinaison * M_PI / 180;
	int z = map->map[y][x];

	point.x = (map->x_center + cos(rota) * (x - map->x_center));
	point.x -= sin(rota) * (y - map->y_center);
	point.y = (map->y_center + sin(rota) * (x - map->x_center));
	point.y += cos(rota) * (y - map->y_center);
	point.y = map->y_center  + cos(incli) * (point.y - map->y_center);
	point.y -= sin(incli) * z;
	point.x += map->transla_x;
	point.y += map->transla_y;
	point.x = point.x * (map->scaling_x + map->zoom);
	point.y = point.y * (map->scaling_y + map->zoom);
	return (point);
}
