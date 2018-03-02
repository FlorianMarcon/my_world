/*
** EPITECH PROJECT, 2017
** create_two_d_map
** File description:
** create_two_d_map
*/

#include "header_world.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

sfVector2f	**create_two_d_map(map_t *map)
{
	sfVector2f **map_two_d = malloc(sizeof(sfVector2f*) * MAP_X);
	int i = 0;
	int j = 0;

	while (j < 10) {
		map_two_d[j] = malloc(sizeof(sfVector2f) * MAP_X);
		while (i < 10) {
			map_two_d[j][i] = project_iso_point(i, j, map);
			i++;
		}
		i = 0;
		j++;
	}
	return (map_two_d);
}
