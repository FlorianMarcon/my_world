/*
** EPITECH PROJECT, 2017
** translation
** File description:
** translation
*/

#include "map.h"

void	translation_up(map_t *map)
{
	map->y_translation--;
}
void	translation_down(map_t *map)
{
	map->y_translation++;
}
void	translation_right(map_t *map)
{
	map->x_translation++;
}
void	translation_left(map_t *map)
{
	map->x_translation--;
}
