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
	while (sfRenderWindow_isOpen(world->window->window)) {
		event(world);
		display(world);
	}
}
