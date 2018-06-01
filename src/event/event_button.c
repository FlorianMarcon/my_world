/*
** EPITECH PROJECT, 2017
** event_button
** File description:
** event_button
*/

#include "world.h"

void	event_button(world_t *world)
{
	for (unsigned int i = 0; i != world->nb_button; i++) {
		if (sfMouse_isButtonPressed(sfMouseLeft) && is_about(world->window->window, &world->button[i]) && world->button[i].ptr != NULL) {
			world->button[i].ptr(world->map);
			world->done = true;
		}
	}
}
