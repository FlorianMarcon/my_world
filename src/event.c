/*
** EPITECH PROJECT, 2017
** event
** File description:
** event
*/

#include "header_world.h"

int	mouse_event(surface_t *win, map_t *map);

int	event(surface_t *win, map_t *map)
{
	while (sfRenderWindow_pollEvent(win->window, &win->event)) {
		if (win->event.type == sfEvtClosed)
			sfRenderWindow_close(win->window);
//		if (sfMouse_isButtonPressed(sfMouseLeft))
			mouse_event(win, map);
	}
	return (0);
}
