/*
** EPITECH PROJECT, 2017
** display
** File description:
** display
*/

#include "header_world.h"

int	display(surface_t *win, button_t **elem)
{
	draw_background(win);
	for (int j = 0; j != 2; j++)
		sfRenderWindow_drawRectangleShape
				(win->window, elem[j]->rect, NULL);
	return (0);
}
