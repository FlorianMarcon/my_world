/*
** EPITECH PROJECT, 2017
** project_iso_point
** File description:
** project_iso_point
*/

#include "header_world.h"
#include <math.h>
#include <stdio.h>
/*
sfVector2f	project_iso_point(int x, int y, int z)
{
	sfVector2f two_d_point;
	double angle_one = ANGLE_X * M_PI / 180;
	double angle_two = ANGLE_Y * M_PI / 180;

	two_d_point.x = cos(angle_one) * x - cos(angle_one) * y + 400;
	two_d_point.y = sin(angle_two) * y + sin(angle_two) * x - z + 150;
	return (two_d_point);
}
*/
sfVector2f	project_iso_point(int x, int y, map_t *map)
{
	sfVector2f point;
	double angle_one = map->angle_x * M_PI / 180;
	double angle_two = map->angle_y * M_PI / 180;
	int z = map->map[y][x] * SCALING_Z;

	x = x * SCALING_X;
	y = y * SCALING_Y;
	point.x = (cos(angle_one) * x - cos(angle_one) * y + 400) * map->zoom;
	point.y = (sin(angle_two) * y + sin(angle_two) * x - z + 150)
			* map->zoom;
	return (point);
}
