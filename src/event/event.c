/*
** EPITECH PROJECT, 2017
** event
** File description:
** event
*/

#include "world.h"

void	event_window(world_t *world)
{
	window_t *window = world->window;

	while (sfRenderWindow_pollEvent(window->window, &window->event)) {
		if (window->event.type == sfEvtClosed)
			sfRenderWindow_close(window->window);
		event_button(world);
		event_keyboard(world);
	}
}
void	event(world_t *world)
{
	event_window(world);
}
