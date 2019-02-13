/*
** EPITECH PROJECT, 2017
** loop_game
** File description:
** loop_game
*/

#include "world.h"
#include <stdio.h>

void	loop_game(world_t *world)
{
	map_t *map = world->map;
	window_t *window = world->window;

	map->do_exit = false;
	while (sfRenderWindow_isOpen(window->window) && map->do_exit != true) {
		event(world);
		display(world);
	}
}
