/*
** EPITECH PROJECT, 2017
** left_toolbar
** File description:
** left_toolbar
*/

#include "header_world.h"

void	larger(map_t *map)
{
	map->zoom += 0.80;
}

void	smaller(map_t *map)
{
	map->zoom -= 0.80;
}

void	rotate_l(map_t *map)
{
	map->rotation += 4;
}

void	rotate_r(map_t *map)
{
	map->rotation -= 4;
}
void	rotate_u(map_t *map)
{
	map->inclinaison += 4;
}

void	rotate_d(map_t *map)
{
	map->inclinaison -= 4;
}
