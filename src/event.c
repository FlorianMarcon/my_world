/*
** EPITECH PROJECT, 2018
** event
** File description:
** event
*/

#include "header_world.h"
#include <stdio.h>

int	button_click(button_t *button, sfVector2f clickPosition)
{
	return (clickPosition.x < sfRectangleShape_getPosition(button->rect).x +
	sfRectangleShape_getSize(button->rect).x &&
	clickPosition.x > sfRectangleShape_getPosition(button->rect).x &&
	clickPosition.y < sfRectangleShape_getPosition(button->rect).y +
	sfRectangleShape_getSize(button->rect).y &&
	clickPosition.y > sfRectangleShape_getPosition(button->rect).y);
}

void dragged_map(map_t *map)
{
	if (sfKeyboard_isKeyPressed(sfKeyRight))
		map->transla_x += 1;
	if (sfKeyboard_isKeyPressed(sfKeyLeft))
		map->transla_x -= 1;
	if (sfKeyboard_isKeyPressed(sfKeyUp))
		map->transla_y -= 1;
	if (sfKeyboard_isKeyPressed(sfKeyDown))
		map->transla_y += 1;
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
			for (int i = 0; i < 9; i++) {
				if (button_click(elem[i], clickPosition)) {
					elem[i]->callback(map);
				}
			}
		}
		if (sfMouse_isButtonPressed(sfMouseLeft))
			mouse_event(win, map);
		dragged_map(map);
	}
}
