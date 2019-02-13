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
	sfRenderWindow *window = world->window->window;

	sfRenderWindow_clear(window, sfBlack);
	if (world->spr_back != NULL)
		sfRenderWindow_drawSprite(window, world->spr_back, NULL);
	display_world(world);
	display_button(world);
	display_selection(world);
	sfRenderWindow_display(window);
}
