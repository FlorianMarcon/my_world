/*
** EPITECH PROJECT, 2017
** event
** File description:
** event
*/

#include "world.h"

void	event_window(window_t *window)
{
	while (sfRenderWindow_pollEvent(window->window, &window->event)) {
            if (window->event.type == sfEvtClosed)
                sfRenderWindow_close(window->window);
        }
}
void	event(world_t *world)
{
	event_window(world->window);
}
