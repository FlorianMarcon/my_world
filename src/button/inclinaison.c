/*
** EPITECH PROJECT, 2017
** inclinaison
** File description:
** inclinaison
*/

#include "map.h"
#include <stdio.h>

void	inclinaison_up(map_t *map)
{
	if (map->inclinaison < 85)
		map->inclinaison++;
}
void	inclinaison_down(map_t *map)
{
	if (map->inclinaison > 64)
		map->inclinaison--;
}
