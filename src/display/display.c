/*
** EPITECH PROJECT, 2017
** display
** File description:
** display
*/

#include "world.h"
#include <stdio.h>
void	display_button(world_t *world)
{
	for (unsigned int i = 0; i != world->nb_button; i++) {
		if (world->button[i].sprite != NULL)
			sfRenderWindow_drawSprite(world->window->window, world->button[i].sprite, NULL);
	}
}
void	display(world_t *world)
{
	sfRenderWindow_clear(world->window->window, sfWhite);
	display_world(world);
	display_button(world);
        sfRenderWindow_display(world->window->window);
}
