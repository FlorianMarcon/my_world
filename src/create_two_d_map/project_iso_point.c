/*
** EPITECH PROJECT, 2017
** project_iso_point
** File description:
** project_iso_point
*/

#include "header_world.h"
#include <math.h>

/*
sfVector2f	project_iso_point(int x, int y, int z)
{
	sfVector2f two_d_point;

	two_d_point.x = x;
	two_d_point.y = y - z + z;
	return (two_d_point);
}
*/
sfVector2f	project_iso_point(int x, int y, int z)
{
	sfVector2f two_d_point;
	double angle_one = ANGLE_X * M_PI / 180;
	double angle_two = ANGLE_Y * M_PI / 180;

	two_d_point.x = cos(angle_one) * x - cos(angle_one) * y + 400;
	two_d_point.y = sin(angle_two) * y + sin(angle_two) * x - z + 150;
	return (two_d_point);
}
