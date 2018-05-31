/*
** EPITECH PROJECT, 2017
** display
** File description:
** display
*/

#include "world.h"
#include <stdio.h>

void	display(world_t *world)
{
	sfRenderWindow_clear(world->window->window, sfBlue);
	//display_world(world);
	display_button(world);
        sfRenderWindow_display(world->window->window);
}
