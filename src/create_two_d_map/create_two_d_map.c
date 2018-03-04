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

void	create_two_d_map(map_t *map)
{
	int i = 0;
	int j = 0;

	map->map_two_d = malloc(sizeof(sfVector2f*) * map->width);
	while (j < 10) {
		map->map_two_d[j] = malloc(sizeof(sfVector2f) * map->height);
		while (i < 10) {
			map->map_two_d[j][i] = project_iso_point(i, j, map);
			i++;
		}
		i = 0;
		j++;
	}
}

void	evolve_two_d_map(map_t *map)
{
	int i = 0;
	int j = 0;

	while (j < 10) {
		while (i < 10) {
			map->map_two_d[j][i] = project_iso_point(i, j, map);
			i++;
		}
		i = 0;
		j++;
	}
}
