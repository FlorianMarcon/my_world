/*
** EPITECH PROJECT, 2017
** up_action
** File description:
** up_action
*/

#include "map.h"
#include <stdio.h>

void	up_action(map_t *map)
{
	if (map->type_select == summit)
		map->map[map->y][map->x]++;
	else {
		map->map[map->y][map->x]++;
		map->map[map->y + 1][map->x]++;
		map->map[map->y][map->x + 1]++;
		map->map[map->y + 1][map->x + 1]++;
	}
}
void	down_action(map_t *map)
{
	if (map->type_select == summit)
		map->map[map->y][map->x]--;
	else {
		map->map[map->y][map->x]--;
		map->map[map->y + 1][map->x]--;
		map->map[map->y][map->x + 1]--;
		map->map[map->y + 1][map->x + 1]--;
	}
}
