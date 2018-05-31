/*
** EPITECH PROJECT, 2017
** create_world
** File description:
** create_world
*/

#include "world.h"
#include "window.h"

int	create_world(world_t *world)
{
	create_map(world->map, 10, 10);
	if (world->map->is_usable == false || create_window(world->window))
		return (1);
	return (0);
}
