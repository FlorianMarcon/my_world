/*
** EPITECH PROJECT, 2017
** event_menu
** File description:
** event_menu
*/

#include "window.h"

void	event_menu(window_t *window)
{
	while (sfRenderWindow_pollEvent(window->window, &window->event)) {
		if (window->event.type == sfEvtClosed)
			sfRenderWindow_close(window->window);
	}
}
