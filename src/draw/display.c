/*
** EPITECH PROJECT, 2017
** display
** File description:
** display
*/

#include "header_world.h"

int	display(surface_t *win, button_t **elem)
{
	sfIntRect rect_background;
	game_object_t *obj[1];

	rect_background = set_rectangle(0, 0, 1600, 1200);
	obj[0] = create_object(BACKGROUND, (sfVector2f){0, 0}, rect_background);
	my_drawSprite(win, *obj);
	for (int j = 0; j != 2; j++)
		sfRenderWindow_drawRectangleShape
				(win->window, elem[j]->rect, NULL);
	return (0);
}
