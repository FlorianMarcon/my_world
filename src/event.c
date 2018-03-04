/*
** EPITECH PROJECT, 2018
** event
** File description:
** event
*/

#include "header_world.h"
#include <stdio.h>

int	buttonIsClicked(button_t *button, sfVector2f clickPosition)
{
	return (clickPosition.x < sfRectangleShape_getPosition(button->rect).x +
	sfRectangleShape_getSize(button->rect).x &&
	clickPosition.x > sfRectangleShape_getPosition(button->rect).x &&
	clickPosition.y < sfRectangleShape_getPosition(button->rect).y +
	sfRectangleShape_getSize(button->rect).y &&
	clickPosition.y > sfRectangleShape_getPosition(button->rect).y);
}

void	analyse_event(surface_t *win, button_t **elem, map_t *map)
{
	sfVector2i clickPosition_one;
	sfVector2f clickPosition;

	while (sfRenderWindow_pollEvent(win->window, &win->event)) {
		if (win->event.type == sfEvtClosed)
			sfRenderWindow_close(win->window);
		clickPosition_one = sfMouse_getPosition((const sfWindow *)
								win->window);
		clickPosition.x = clickPosition_one.x;
		clickPosition.y = clickPosition_one.y;
		if (win->event.type == sfEvtMouseButtonPressed) {
			for (int i = 0; i < 8; i++) {
				if (buttonIsClicked(elem[i], clickPosition)) {
					elem[i]->callback(map);
				}
			}
		}
		if (sfMouse_isButtonPressed(sfMouseLeft))
			mouse_event(win, map);
	}
}
