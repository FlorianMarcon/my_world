/*
** EPITECH PROJECT, 2017
** create_world
** File description:
** create_world
*/

#include "world.h"
#include "map.h"
#include "window.h"
#include <stdio.h>

int	create_world(world_t *world)
{
	create_map(world->map, 10, 10);
	if (world->map->is_usable == false || create_window(world->window))
		return (1);
	world->font = sfFont_createFromFile("font/font.otf");
	create_button(world);
	create_keyboardevent(world);
	return (0);
}
