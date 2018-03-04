/*
** EPITECH PROJECT, 2017
** left_toolbar
** File description:
** left_toolbar
*/

#include <stdio.h>
#include "header_world.h"

void	rotate_d(map_t *map)
{
	map->inclinaison -= 4;
}

void	down(map_t *map)
{
	if (map->map[map->y][map->x] > -2) {
		map->map[map->y][map->x]--;
		map->map[map->y][map->x + 1]--;
		map->map[map->y + 1][map->x + 1]--;
		map->map[map->y + 1][map->x]--;
	}
}
void	up(map_t *map)
{
	if (map->map[map->y][map->x] < 8) {
		map->map[map->y][map->x]++;
		map->map[map->y][map->x + 1]++;
		map->map[map->y + 1][map->x + 1]++;
		map->map[map->y + 1][map->x]++;
	}
}
