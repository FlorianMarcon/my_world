/*
** EPITECH PROJECT, 2017
** type_select
** File description:
** type_select
*/

#include "map.h"
#include "my.h"

void	select_summit(map_t *map)
{
	map->type_select = summit;
	my_printf("SUMMIT\n");
}
void	select_square(map_t *map)
{
	map->type_select = square;
	my_printf("SQUARE\n");
}
