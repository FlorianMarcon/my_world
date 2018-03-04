/*
** EPITECH PROJECT, 2018
** event
** File description:
** event
*/

#include "header_world.h"
#include <stdio.h>

int	mouse_event(surface_t *win, map_t *map);

int	event(surface_t *win, map_t *map)
{
	while (sfRenderWindow_pollEvent(win->window, &win->event)) {
		if (win->event.type == sfEvtClosed)
			sfRenderWindow_close(win->window);
		if (sfMouse_isButtonPressed(sfMouseLeft))
			mouse_event(win, map);
		if (sfKeyboard_isKeyPressed(sfKeyP))
			map->rotation++;
		if (sfKeyboard_isKeyPressed(sfKeyM))
			map->rotation--;
		if (sfKeyboard_isKeyPressed(sfKeyO))
			map->inclinaison++;
		if (sfKeyboard_isKeyPressed(sfKeyL))
			map->inclinaison--;
	}
	return (0);
}
