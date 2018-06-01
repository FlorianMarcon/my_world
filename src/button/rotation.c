/*
** EPITECH PROJECT, 2017
** rotation
** File description:
** rotation
*/

#include "map.h"
#include <stdio.h>

void	rotation_right(map_t *map)
{
	if (map->rotation < 90)
		map->rotation++;
}
void	rotation_left(map_t *map)
{
	if (map->rotation > 0)
		map->rotation--;
}
