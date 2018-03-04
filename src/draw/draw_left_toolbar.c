/*
** EPITECH PROJECT, 2017
** draw_left_toolbar
** File description:
** draw_left_toolbar
*/

#include "header_world.h"

int	draw_left_toolbar(surface_t *win, button_t **elem)
{
	sfVector2i clickPosition_one;

	clickPosition_one = sfMouse_getPosition((const sfWindow *)win->window);
	if (clickPosition_one.x < 100 && (clickPosition_one.y > 200 &&
						clickPosition_one.x < 710)) {
		for (int j = 0; j < 6; j++)
			sfRenderWindow_drawRectangleShape
					(win->window, elem[j]->rect, NULL);
		}
		return (1);
}
