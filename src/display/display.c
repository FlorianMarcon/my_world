/*
** EPITECH PROJECT, 2017
** display
** File description:
** display
*/

#include "world.h"

void	display(world_t *world)
{
	sfRenderWindow_clear(world->window->window, sfBlack);
        sfRenderWindow_display(world->window->window);
}
